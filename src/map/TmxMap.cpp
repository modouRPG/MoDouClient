#include "TmxMap.h"
#include <stdlib.h>
#include <stdio.h>
#include "being/XActor.h"

namespace modou
{
  TmxMap::TmxMap() : Tmx::Map()
  {
    m_pActor = NULL;
  }

  TmxMap::~TmxMap()
  {

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

    for(i=0; i< this->GetNumTilesets(); i++) {
      const Tmx::Tileset *tileset = this->GetTileset(i);
      firstGid = tileset->GetFirstGid();
      tiles = tileset->GetTiles();
      for(j=0; j < tiles.size(); j++) {
	tmp_tile = tiles.at(j);
	//all_tiles.insert(tmp_tile->GetId() + firstGid, tmp_tile);
	all_tiles.push_back(tmp_tile);
	//	std::cout << tmp_tile->GetId() + firstGid << std::endl;
      }
    }

    // for(i=0; i< this->GetNumTileLayers(); i++) {
    //   const Tmx::TileLayer *tileLayer = this->GetTileLayer(i);
    //   for(y=0; y<tileLayer->GetHeight(); y++) {
    // 	for(x =0; x< tileLayer->GetWidth(); x++) {
    // 	  if (tileLayer->GetTileTilesetIndex(x, y) == -1) {
    // 	    //	    printf("..........      ");
    // 	  } else {
    // 	    // printf("%03d(%03d)", tileLayer->GetTileId(x, y), tileLayer->GetTileGid(x, y));
    // 	  }
    // 	}
    //   }
    //   // printf("\n");
    // }

    // for (i=0; i< this->GetNumObjectGroups(); i++) {
    //   const Tmx::ObjectGroup *objectGroup = this->GetObjectGroup(i);
    //   for (int j = 0; j < objectGroup->GetNumObjects(); ++j) {
    // 	// Get an object.
    // 	const Tmx::Object *object = objectGroup->GetObject(j);
    // 	// printf("X: %d, Y: %d, Gid: %d.\n", object->GetX(),
    // 	//        object->GetY(),
    // 	//        object->GetGid());
    //   }
    // }
  }

  void TmxMap::draw(gcn::Graphics *graphics, int scrollX, int scrollY, int width, int height)
  {
    int i=0, j=0, x=0, y=0;
    std::string color = this->GetBackgroundColor();
    
    if (!color.empty()) {
      color.replace(0, 1, "0x");
      gcn::Color old_color = graphics->getColor();
      graphics->setColor(gcn::Color(strtol(color.c_str(), NULL, 16)));
      graphics->fillRectangle(gcn::Rectangle(0, 0, width, height));
      graphics->setColor(old_color);
    }
    
    for(i=0; i< this->GetNumTileLayers(); i++) {
      const Tmx::TileLayer *tileLayer = this->GetTileLayer(i);
      for(y=0; y<tileLayer->GetHeight(); y++) {
    	for(x =0; x< tileLayer->GetWidth(); x++) {
    	  if (tileLayer->GetTileTilesetIndex(x, y) == -1) {
    	    //	    printf("..........      ");
    	  } else {
    	    // printf("%03d(%03d)", tileLayer->GetTileId(x, y), tileLayer->GetTileGid(x, y));
    	  }
    	}
      }
      // printf("\n");
    }

    for (i=0; i< this->GetNumObjectGroups(); i++) {
      const Tmx::ObjectGroup *objectGroup = this->GetObjectGroup(i);
      for (int j = 0; j < objectGroup->GetNumObjects(); ++j) {
    	// Get an object.
    	const Tmx::Object *object = objectGroup->GetObject(j);
	Tmx::Tile *tile = all_tiles.at(object->GetGid());
	const Tmx::Image *image = tile->GetImage();

	graphics->drawImage(gcn::Image::load(image->GetSource(), true), object->GetX() - scrollX, object->GetY() - scrollY);
    	// printf("X: %d, Y: %d, Gid: %d.\n", object->GetX(),
    	//        object->GetY(),
    	//        object->GetGid());
      }
    }

    if (m_pActor) {
      m_pActor->draw(graphics, -scrollX, -scrollY);
    }
    graphics->drawText(map_name, 800/2, 80, gcn::Graphics::CENTER);
  }
}
