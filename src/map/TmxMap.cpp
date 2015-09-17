#include "TmxMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "being/XActor.h"
#include "being/XSpirit.h"
#include "main.h"
#include "net/pkg.h"

namespace modou
{
  TmxMap::TmxMap() : Tmx::Map()
  {
    m_pActor = NULL;
    first = true;
  }

  TmxMap::~TmxMap()
  {

  }

  void TmxMap::setMapId(int id)
  {
    mapId = id;
  }

  void TmxMap::setActor(XActor *actor)
  {
    m_pActor = actor;
  }

  void TmxMap::loadResource()
  {
    int i=0, j=0, x=0, y=0;
    int firstGid = 0;
    std::vector< Tmx::Tile *> tiles;
    Tmx::Tile *tmp_tile = NULL;

    tile_width = this->GetWidth();
    tile_height = this->GetHeight();

    for(i=0; i< this->GetNumTilesets(); i++) {
      const Tmx::Tileset *tileset = this->GetTileset(i);
      firstGid = tileset->GetFirstGid();
      tiles = tileset->GetTiles();
      for(j=0; j < tiles.size(); j++) {
	tmp_tile = tiles.at(j);
	all_tiles.push_back(tmp_tile);
	all_tiles_image.push_back(gcn::Image::load(tmp_tile->GetImage()->GetSource()));
      }
    }

    for(i=0; i< this->GetNumTileLayers(); i++) {
      const Tmx::TileLayer *tileLayer = this->GetTileLayer(i);
      if (tileLayer->GetName() != "block") {
	continue;
      }
      for(y=0; y<tileLayer->GetHeight(); y++) {
    	for(x =0; x< tileLayer->GetWidth(); x++) {
    	  if (tileLayer->GetTileTilesetIndex(x, y) == -1) {
	    map_block_flag.push_back(0);
    	  } else {
	    map_block_flag.push_back(1);
    	  }
    	}
      }
    }

    // TODO: load npcs from server;
    std::vector< npc_info* > npcs;
    std::vector< npc_info* >::iterator it;
    globals::mapConn->netGetMapNpcs(npcs);
    for(it = npcs.begin(); it != npcs.end(); it++) {
      std::cout << (*it)->name << std::endl;
      std::cout << (*it)->posX << ":" << (*it)->posY << std::endl;
      XSpirit *sp = new XSpirit((*it)->name,
				"./data/img/aa2186.png",
				(*it)->posX,
				(*it)->posY,
				(*it)->width,
				(*it)->height);
      actor_array.push_back(sp);
    }
  }

  bool TmxMap::isBlock(int tx, int ty)
  {
    int ind = 0;

    ind = ty * 100 + tx;
    if (map_block_flag.at(ind) == 0) {
      return false;
    } else {
      return true;
    }
  }

  bool TmxMap::inMap(int tx, int ty)
  {
    if (tx < 0 || tx >= tile_width) {
      return false;
    }
    if (ty < 0 || ty >= tile_height) {
      return false;
    }
    return true;
  }

  void TmxMap::addActor(XActor *actor)
  {
    actor_array.push_back(actor);
  }

  XActor* TmxMap::clickNpc(int px, int py) {
    std::vector< XActor* >::iterator it;

    std::cout << "in click npc. " << std::endl;
    for(it = actor_array.begin(); it != actor_array.end(); it++) {
      if ((*it)->isArroundMe(m_pActor) &&
	  (*it)->isClickMe(px, py)) {
	return (*it);
      }
    }
    std::cout << "no click npc." << std::endl;
    return NULL;
  }

  int TmxMap::click(int realx, int realy)
  {
    globals::localPlayer->directTo(realx, realy);
    XActor *a = clickNpc(realx, realy);
    if (a != NULL) {
      a->action();
    } else if (globals::localPlayer) {
      globals::localPlayer->setTarget(realx, realy);
    } else {
      std::cout << "local Player is no init " << std::endl;
    }
    return 0;
  }
  
  void TmxMap::draw(gcn::Graphics *graphics, int scrollX, int scrollY, int width, int height)
  {
    int i=0, j=0, x=0, y=0;
    int ind = 0;
    std::string color = this->GetBackgroundColor();
    gcn::Color old_color;
    gcn::Image *gcn_image = NULL;
    
    if (!color.empty()) {
      color.replace(0, 1, "0x");
      gcn::Color old_color = graphics->getColor();
      graphics->setColor(gcn::Color(strtol(color.c_str(),
					   NULL,
					   16)));
      graphics->fillRectangle(gcn::Rectangle(0, 0, width, height));
      graphics->setColor(old_color);
    }
    
    for(i=0; i< this->GetNumTileLayers(); i++) {
      const Tmx::TileLayer *tileLayer = this->GetTileLayer(i);
      if (tileLayer->GetName() == "block") {
    	continue;
      }

      for(y = (int)(floor(scrollY/32.0)); y<(int)(ceil(scrollY + height)/32.0); y++) {
	for(x = (int)(floor(scrollX/32.0)); x<(int)(ceil(scrollX + width)/32.0); x++) {
    	  if (tileLayer->GetTileTilesetIndex(x, y) == -1) {
    	    //	    printf("..........      ");
    	  } else {
    	    ind = tileLayer->GetTileGid(x, y) - 1;
    	    gcn_image = all_tiles_image.at(ind);
    	    graphics->drawImage(gcn_image,
				x * 32 - scrollX,
				y * 32 - scrollY);
    	  }
    	}
      }
    }

    for (i=0; i< this->GetNumObjectGroups(); i++) {
      const Tmx::ObjectGroup *objectGroup = this->GetObjectGroup(i);
      for (int j = 0; j < objectGroup->GetNumObjects(); ++j) {
    	// Get an object.
    	const Tmx::Object *object = objectGroup->GetObject(j);
	Tmx::Tile *tile = all_tiles.at(object->GetGid());
	const Tmx::Image *image = tile->GetImage();

	if (object->GetX() - scrollX >= 0 &&
	    object->GetX() - scrollX <= width &&
	    object->GetY() - scrollY >= 0 &&
	    object->GetY() - scrollY <= height) {
	  graphics->drawImage(gcn::Image::load(image->GetSource(), true),
			      object->GetX() - scrollX,
			      object->GetY() - scrollY);
	}
      }
    }
    std::vector< XActor* >::iterator it;
    for( it = actor_array.begin(); it != actor_array.end(); it++) {
      (*it)->draw(graphics, -scrollX, -scrollY);
    }
    
    if (m_pActor) {
      m_pActor->draw(graphics, -scrollX, -scrollY);
    }

    old_color = graphics->getColor();
    graphics->setColor(gcn::Color(255, 255, 0));
    graphics->drawText(map_name, 800/2, 80, gcn::Graphics::CENTER);
    graphics->setColor(old_color);
  }
}
