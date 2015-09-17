#include "ChatConn.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <iostream>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

namespace modou
{
  ChatConn::ChatConn(std::string ip, uint16_t port)
  {
    struct in_addr addr;
    int flag, ret;
    struct sockaddr_in serverAddr;
    if (inet_aton(ip.c_str(), &addr) == 0) {
      std::cerr << "error loing server ip" << std::endl;
      return;
    }
    mSock = socket(AF_INET, SOCK_STREAM, 0);
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = addr.s_addr;
    serverAddr.sin_port = htons(port);
    
    ret = connect(mSock, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr));
    if (ret < 0) {
      std::cerr << "connect error" << strerror(errno) << std::endl;
      return;
    }
    flag = fcntl(mSock, F_GETFL, 0);
    fcntl(mSock, F_SETFL, flag | O_NONBLOCK);

    arg.sock = mSock;
    arg.chatWindow = globals::gChatWindow;
    
    pthread_create(&pid, NULL, ChatConn::chat_recev_thread, (void *)(&arg));
  }
  
  ChatConn::~ChatConn()
  {
    
  }

  int ChatConn::sendMsg(std::string &msg)
  {
    int len;

    say_msg_pkg *pkg = (say_msg_pkg *)calloc(1, sizeof(*pkg));

    pkg->flag = SAY_MSG;
    strncpy(pkg->msg, msg.c_str(), 2047);

    send(mSock, pkg, sizeof(*pkg), 0);
  }

  void* ChatConn::chat_recev_thread(void *data)
  {
    thread_arg *arg = (thread_arg *)data;
    int len;
    std::string mm;
    msg_list_pkg *pkg = (msg_list_pkg *)calloc(1, sizeof(*pkg));

    while(true) {
      len = recv(arg->sock, pkg ,sizeof(*pkg), 0);
      if (len > 0) {
	switch(pkg->flag) {
	case MSG_LIST:
	  std::cout << pkg->msg << std::endl;
	  mm = pkg->msg;
	  arg->chatWindow->addMsg(mm);
	  break;
	}
      } else {
	sleep(1);
      }
    }
    return NULL;
  }

}
