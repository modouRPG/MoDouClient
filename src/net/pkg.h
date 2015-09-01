#ifndef _PKG_H_
#define _PKG_H_

#define GET_FLAG(s) (*(uint8_t *)(s->in_buf + s->in_data_pos))
#define GET_DATA(s) ((void *)(s->in_buf + s->in_data_pos))

#define MIN_FLAG 0x00

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define LOGIN_FLAG (MIN_FLAG + 1)
typedef struct _login_req_pkg
{
    uint8_t flag;
    char email[64];
    char pass[64];
}login_req_pkg;

#define LOGIN_RESP_FLAG (MIN_FLAG + 2)
typedef struct _login_resp_pkg
{
    uint8_t flag;
    uint8_t ecode;
    char token[33];
    uint8_t num;
}login_resp_pkg;

typedef struct _char_server
{
    char name[128];
    in_addr_t ip;
    uint16_t port;
    uint16_t unum;
}char_server;

#endif
