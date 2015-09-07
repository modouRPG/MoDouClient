#include "XViewport.h"
#include "main.h"
#include <sstream>
#include <guichan/sdl.hpp>
#include <SDL.h>

namespace modou
{
    XViewport::XViewport() : gcn::Container(),
        mMap(NULL),
        mPixelViewX(0),
        mPixelViewY(0)
    {
        addMouseListener(this);
        //mMap = new XMap(320, 240, mapTileSize, mapTileSize);
    }

    XViewport::~XViewport()
    {
        if (mMap)
            delete(mMap);
    }

    void XViewport::setMap(TmxMap *map)
    {
        mMap = map;
    }

    void XViewport::draw(gcn::Graphics *graphics)
    {
        if (!mMap) {
            graphics->setColor(gcn::Color(64, 64, 64));
            graphics->fillRectangle(gcn::Rectangle(0, 0, getWidth(), getHeight()));
            return;
        }
        
        if (globals::localPlayer) {
            XVector pos = globals::localPlayer->getPosition();
            mPixelViewX = static_cast<int>(pos.x) - screenWidth/2;
            mPixelViewY = static_cast<int>(pos.y) - screenHeight/2;
        }
        
        const int viewMaxX = mMap->GetWidth() * mMap->GetTileWidth() - getWidth();
        const int viewMaxY = mMap->GetHeight() * mMap->GetTileHeight() - getHeight();

        if (mPixelViewX < 0)
            mPixelViewX = 0;
        if (mPixelViewY < 0)
            mPixelViewY = 0;
        if (mPixelViewX > viewMaxX)
            mPixelViewX = viewMaxX;
        if (mPixelViewY > viewMaxY)
            mPixelViewY = viewMaxY;

        mMap->draw(graphics, mPixelViewX, mPixelViewY, getWidth(), getHeight());
	//        gcn::SDLGraphics *g = static_cast<gcn::SDLGraphics *>(graphics);
        std::stringstream ss;
        ss << "X:" << mPixelViewX << ", Y:" << mPixelViewY;
        graphics->drawText(ss.str(), 0, 0);

	if (!path.empty()) {
	  std::list< XTilePoint* >::reverse_iterator rit;
	  XTilePoint *tmpPoint = NULL;
	  int oldx=-1, oldy=-1;
	  for(rit = path.rbegin(); rit != path.rend(); rit++) {
	    if (tmpPoint == NULL) {
	      tmpPoint = *rit;
	      //graphics->drawPoint((*rit)->x * 32 - mPixelViewX, (*rit)->y * 32 - mPixelViewY);
	      continue;
	    } else {
	      if (tmpPoint->mparent == *rit) {
		graphics->drawLine(tmpPoint->x * 32 - mPixelViewX,
				   tmpPoint->y * 32 - mPixelViewY,
				   (*rit)->x * 32 - mPixelViewX,
				   (*rit)->y * 32 - mPixelViewY);
		tmpPoint = *rit;
		//graphics->drawPoint((*rit)->x * 32 - mPixelViewX, (*rit)->y * 32 - mPixelViewY);
	      }
	    }

	    // if (oldx == -1) {
	    //   oldx = (*it)->x;
	    //   oldy = (*it)->y;
	    //   continue;
	    // }
	    // //graphics->drawLine(oldx * 32 - mPixelViewX, oldy * 32 - mPixelViewY, (*it)->x * 32 - mPixelViewX, (*it)->y * 32 - mPixelViewY);
	    // oldx = (*it)->x;
	    // oldy = (*it)->y;
	  }
	}
    }

    void XViewport::mousePressed(gcn::MouseEvent &event)
    {
        if (event.getSource() != this || event.isConsumed())
            return;
        if (!mMap)
            return;
        if (event.getButton() == gcn::MouseEvent::LEFT)
        {
            leftMouseAction();
        }
    }

    bool XViewport::leftMouseAction()
    {
        followMouse();
        return true;
    }

    void XViewport::followMouse()
    {
        if (globals::localPlayer) {
            int px, py;
            SDL_GetMouseState(&px, &py);
            XVector pos = globals::localPlayer->getPosition();
	    path.clear();
	    std::cout << "init path size: " << path.size() << endl;
	    modou::FindPath::getPath(globals::map, int(pos.x), int(pos.y), px, py, path);
	    std::cout << "path size: " << path.size() << endl;
            if (px > pos.x) {
                pos.x += mapTileSize;
                if (pos.x > globals::map->GetWidth() * mapTileSize)
                    pos.x = globals::map->GetWidth() * mapTileSize;
            } else {
                pos.x -= mapTileSize;
                if (pos.x < 0)
                    pos.x = 0;
            }
	    if (py > pos.y) {
                pos.y += mapTileSize;
                if (pos.y > globals::map->GetHeight() * mapTileSize)
                    pos.y = globals::map->GetHeight() * mapTileSize;
            } else {
                pos.y -= mapTileSize;
                if (pos.y < 0)
                    pos.y = 0;
            }
            globals::localPlayer->setPosition(pos);
            //globals::localPlayer->navigateTo(pos.x, pos.y);
        } else {
            std::cout << "local Player is no init " << std::endl;
        }
    }
}
