#include "LoginConn.h"
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
    LoginConn::LoginConn(string ip, uint16_t port)
    {
        struct in_addr addr;
        int flag, ret;
        struct sockaddr_in serverAddr;
        if (inet_aton(ip.c_str(), &addr) == 0)
        {
            cerr << "error loing server ip" << endl;
            return;
        }
        mSock = socket(AF_INET, SOCK_STREAM, 0);

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = addr.s_addr;
        serverAddr.sin_port = htons(2048);

        ret = connect(mSock, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr));
        if (ret < 0) {
            cerr << "connect error" << strerror(errno) << endl;
            return;
        }
        flag = fcntl(mSock, F_GETFL, 0);
        fcntl(mSock, F_SETFL, flag | O_NONBLOCK);
    }

    LoginConn::~LoginConn()
    {
    
    }

    void LoginConn::Send(login_req_pkg *pkg)
    {
        login_resp_pkg pkg2;
        int len;
        char_server *cs;

        memset(&pkg2, 0, sizeof(pkg2));

        send(mSock, pkg, sizeof(login_req_pkg), 0);
        while (len = recv(mSock, &pkg2, sizeof(pkg2), 0)) {
            if (len > 0) {
                cout << pkg2.token << endl;
                void *buf = malloc(pkg2.num * sizeof(char_server));
                while  (len = recv(mSock, buf, pkg2.num * sizeof(char_server), 0))
                {
                    if (len > 0) {
                        cs = (char_server *)buf;
                        cout << "name: " << cs->name << endl;
                        struct in_addr inip;
                        inip.s_addr = cs->ip;
                        cout << "ip :" << inet_ntoa(inip) << endl;
                        cout << "port :" << cs->port << endl;
                        cout << "num: " << cs->unum << endl;
                        break;
                    }
                }
                break;
            }
        }
    }
}
