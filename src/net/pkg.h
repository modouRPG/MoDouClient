#ifndef _PKG_H_
#define _PKG_H_

#define GET_FLAG(s) (*(uint8_t *)(s->in_buf + s->in_data_pos))
#define GET_DATA(s) ((void *)(s->in_buf + s->in_data_pos))

#define MIN_FLAG 0x00

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

typedef struct _char_server
{
    char name[128];
    in_addr_t ip;
    uint16_t port;
    uint16_t unum;
}char_server;

typedef struct _npc_info
{
  char name[128];
  uint16_t picId;
  uint16_t posX;
  uint16_t posY;
  uint16_t width;
  uint16_t height;
}npc_info;

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

#define SAY_TO_NPC_FLAG (MIN_FLAG + 3)
typedef struct _say_to_npc_pkg
{
  uint8_t flag;
  char token[33];
  uint16_t npcId;
  uint16_t playerId;
}say_to_npc_pkg;

#define GET_NPC_BY_MAP_POS (MIN_FLAG + 4)
typedef struct _get_npc_by_map_pos_pkg
{
  uint8_t flag;
  char token[33];
  uint16_t playerId;
  uint16_t mapId;
  uint16_t posX;
  uint16_t posY;
}get_npc_by_map_pos_pkg;

#define NPCS_LIST (MIN_FLAG + 5)
typedef struct _npcs_list_pkg
{
  uint8_t flag;
  uint8_t num;  //npcs list num
}npcs_list_pkg;




#endif
