#include "Game.h"
#include "main.h"
#include "being/XSpirit.h"

namespace modou
{
    XViewport *viewport = NULL;
    Game::Game()
    {
        globals::localPlayer = new XLocalPlayer();
        XVector pos(512, 384, 0);
        globals::localPlayer->setPosition(pos);
        globals::localPlayer->setMap(globals::map);

        // init npc
        XSpirit *guyanwu = new XSpirit();
        guyanwu->mImageFile = "./data/img/aa2248.png";
        XVector pos3(640, 318, 0);
        guyanwu->setPosition(pos3);
        guyanwu->setMap(globals::map);
        guyanwu->mWidth = 128;
        guyanwu->mHeight = 128;
        guyanwu->name = "顾炎武";

        XSpirit *panxiaolan = new XSpirit();
        panxiaolan->mImageFile = "./data/img/aa2202.png";
        XVector pos2(158, 358, 0);
        panxiaolan->setPosition(pos2);
        panxiaolan->setMap(globals::map);
        panxiaolan->mWidth = 42;
        panxiaolan->mHeight = 80;
        panxiaolan->name = "潘小莲";


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
