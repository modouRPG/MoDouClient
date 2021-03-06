#ifndef TMX_MAP_H
#define TMX_MAP_H

#include <guichan.hpp>
#include <tmxparser/Tmx.h>
//#include "XMapLayer.h"

namespace modou
{
  class XActor;
  class XLocalPlayer;
  
  class TmxMap : public Tmx::Map
  {
  public:
    TmxMap();
    virtual ~TmxMap();

    std::string map_name;
    int tile_width, tile_height;

    void loadResource();

    void setActor(XActor *actor);
    void addActor(XActor *actor);

    void draw(gcn::Graphics *graphics, int scrollX, int scrollY, int container_width, int container_height);

    bool isBlock(int tx, int ty);
    bool inMap(int tx, int ty);
    int click(int px, int py);
    XActor* clickNpc(int px, int py);

    void setMapId(int id);

  private:
    std::vector< Tmx::Tile* > all_tiles;
    std::vector< gcn::Image* > all_tiles_image;
    std::vector< int > map_block_flag;
    std::vector< XActor* > actor_array;
    XActor *m_pActor;
    bool first;
    int mapId;
  };
}

#endif
