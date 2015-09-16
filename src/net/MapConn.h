#ifndef _MAP_CONN_H
#define _MAP_CONN_H
#include <stdint.h>
#include <string>
#include "net/pkg.h"

namespace modou
{
  class MapConn
  {
  public:
    MapConn(std::string ip, uint16_t port);
    virtual ~MapConn();

    int sendGetMapNpcs();

  private:
    int mSock;

  };
}


#endif
