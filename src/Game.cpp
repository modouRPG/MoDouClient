#include "Game.h"
#include "main.h"
#include "being/XSpirit.h"

namespace modou
{
    XViewport *viewport = NULL;
    Game::Game()
    {
      std::string default_map = "./pinganzhen.tmx";
      globals::map = XMapReader::readMap(default_map);
      globals::map->map_name = "pinganzhen";

      globals::localPlayer = new XLocalPlayer();
      XVector pos(100, 100, 0);
      globals::localPlayer->setPosition(pos);
      globals::localPlayer->setMap(globals::map);
      
      viewport = new XViewport();
      viewport->setSize(800, 600);
      gcn::Container *const top = static_cast<gcn::Container *>(globals::gui->getTop());
      viewport->setMap(globals::map);
      top->add(viewport);
    }

    Game::~Game()
    {
    
    }
}
