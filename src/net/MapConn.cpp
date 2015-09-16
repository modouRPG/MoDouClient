#include "MapConn.h"
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

namespace modou
{
  MapConn::MapConn(std::string ip, uint16_t port)
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
    serverAddr.sin_port = htons(2048);
    
    ret = connect(mSock, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr));
    if (ret < 0) {
      std::cerr << "connect error" << strerror(errno) << std::endl;
      return;
    }
    flag = fcntl(mSock, F_GETFL, 0);
    fcntl(mSock, F_SETFL, flag | O_NONBLOCK);
  }
  
  MapConn::~MapConn()
  {
    
  }

  int MapConn::sendGetMapNpcs()
  {
    
    return 0;
  }

  
  
}
