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

    void loadResource();

    void setActor(XActor *actor);

    void draw(gcn::Graphics *graphics, int scrollX, int scrollY, int container_width, int container_height);

  private:
    std::vector< Tmx::Tile* > all_tiles;
    std::vector< gcn::Image* > all_tiles_image;
    XActor *m_pActor;
  };
}

#endif
