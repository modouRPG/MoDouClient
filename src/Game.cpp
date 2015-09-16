#include "Game.h"
#include "main.h"
#include "being/XSpirit.h"
#include "gui/XViewport.h"
#include "map/XMapReader.h"
#include "gui/ChatWindow.h"

namespace modou
{
  XViewport *viewport = NULL;
  Game::Game()
  {
    std::string default_map = "./pinganzhen.tmx";
    globals::map = XMapReader::readMap(default_map);
    globals::map->map_name = "平安镇";
    
    globals::localPlayer = new XLocalPlayer();
    XVector pos(100, 100, 0);
    globals::localPlayer->setPosition(pos);
    globals::localPlayer->setMap(globals::map);
    
    viewport = new XViewport();
    viewport->setSize(800, 600);
    gcn::Container *const top = static_cast<gcn::Container *>(globals::gui->getTop());
    viewport->setMap(globals::map);
    top->add(viewport);

    globals::gChatWindow->setVisible(true);
    top->add(globals::gChatWindow, 0, 399);

    mState = STATE_GAME;
  }

  Game::~Game()
  {
    
  }

  void Game::handleInput()
  {
    handleMove();
  }

  void Game::handleMove()
  {
    if (!globals::localPlayer) {
      return;
    }
    globals::localPlayer->logic();
    
  }

  void Game::logic()
  {
    handleInput();
  }

  void Game::loop()
  {
    switch(mState) {
    case STATE_GAME:
      logic();
      break;
    }
  }
}
