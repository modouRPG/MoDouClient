#ifndef _LOGINCONN_H_
#define _LOGINCONN_H_
#include <stdint.h>
#include <string>
#include "net/pkg.h"

namespace modou
{
    using namespace std;
    class LoginConn
    {
        public:
            LoginConn(string ip, uint16_t port);
            virtual ~LoginConn();

            void Send(login_req_pkg *pkg);

            int mSock;
    };
}

#endif
