#ifndef _CHAT_CONN_H
#define _CHAT_CONN_H
#include <stdint.h>
#include <string>
#include "net/pkg.h"
#include <vector>
#include <pthread.h>
#include "gui/ChatWindow.h"

typedef struct _thread_arg
{
  int sock;
  modou::ChatWindow *chatWindow;
}thread_arg;

namespace modou
{
  class ChatConn
  {
  public:
    ChatConn(std::string ip, uint16_t port);
    virtual ~ChatConn();

    int sendMsg(std::string &msg);

    static void* chat_recev_thread(void *data);
    
  private:
    int mSock;
    pthread_t pid;
    thread_arg arg;

  };
}


#endif
