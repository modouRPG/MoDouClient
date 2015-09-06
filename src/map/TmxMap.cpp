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

    tile_width = this->GetWidth();
    tile_height = this->GetHeight();

    for(i=0; i< this->GetNumTilesets(); i++) {
      const Tmx::Tileset *tileset = this->GetTileset(i);
      firstGid = tileset->GetFirstGid();
      tiles = tileset->GetTiles();
      for(j=0; j < tiles.size(); j++) {
	tmp_tile = tiles.at(j);
	//all_tiles.insert(tmp_tile->GetId() + firstGid, tmp_tile);
	all_tiles.push_back(tmp_tile);
	all_tiles_image.push_back(gcn::Image::load(tmp_tile->GetImage()->GetSource()));
	//	std::cout << tmp_tile->GetId() + firstGid << std::endl;
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

  void TmxMap::draw(gcn::Graphics *graphics, int scrollX, int scrollY, int width, int height)
  {
    int i=0, j=0, x=0, y=0;
    int ind = 0;
    std::string color = this->GetBackgroundColor();
    gcn::Image *gcn_image = NULL;
    
    if (!color.empty()) {
      color.replace(0, 1, "0x");
      gcn::Color old_color = graphics->getColor();
      graphics->setColor(gcn::Color(strtol(color.c_str(), NULL, 16)));
      graphics->fillRectangle(gcn::Rectangle(0, 0, width, height));
      graphics->setColor(old_color);
    }
    
    for(i=0; i< this->GetNumTileLayers(); i++) {
      const Tmx::TileLayer *tileLayer = this->GetTileLayer(i);
      if (tileLayer->GetName() == "block") {
	continue;
      }
      for(y=0; y<tileLayer->GetHeight(); y++) {
    	for(x =0; x< tileLayer->GetWidth(); x++) {
	  if (tileLayer->GetTileTilesetIndex(x, y) == -1) {
	    //	    printf("..........      ");
	  } else {
	    //printf("%03d(%03d)", tileLayer->GetTileId(x, y), tileLayer->GetTileGid(x, y));
	    //	    ind = tileLayer->GetTileGid(x, y) + tileLayer->GetTileId(x, y) - 1;
	    ind = tileLayer->GetTileGid(x, y) - 1;
	    gcn_image = all_tiles_image.at(ind);
	    graphics->drawImage(gcn_image, x * 32 - scrollX, y * 32 - scrollY);
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
