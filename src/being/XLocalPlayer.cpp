#include "XLocalPlayer.h"
#include <guichan/sdl.hpp>
#include <sstream>
#include "main.h"
#include "map/FindPath.h"

namespace modou
{
    XLocalPlayer::XLocalPlayer() :
        XActor()
    {
        // mWidth = 48;
        // mHeight = 64;
	mWidth = 40;
	mHeight = 80;
	pic_path = "./data/being/actor3.png";
	//pic_path = "./data/img/aa2186.png";
	mdirection = adirection::DOWN;
	image = gcn::Image::load(pic_path, true);
	maction = aaction::STAND;
    }

    XLocalPlayer::~XLocalPlayer()
    {
      std::list< XTilePoint* >::iterator it;
      for(it = mPath.begin(); it != mPath.end(); it++) {
	delete(*it);
      }
      mPath.clear();
    }

  void XLocalPlayer::getPicPos(int &x, int &y) const
  {
    if (maction == aaction::STAND) {
      x = 0;
    } else {
      int range = globals::tick % 16;
      if (range < 4) {
	x = 0;
      } else if (range < 8) {
	x = mWidth;
      } else if (range < 12) {
	x = 2 * mWidth;
      } else if (range < 16) {
	x = 3 * mWidth;
      }
    }
    switch(mdirection) {
    case adirection::LEFT:
      y = mHeight;
      break;
    case adirection::UP:
      y = 3 * mHeight;
      break;
    case adirection::RIGHT:
      y = 2 * mHeight;
      break;
    case adirection::DOWN:
      y = 0;
      break;
    }
  }

    void XLocalPlayer::draw(gcn::Graphics *const graphics,
			    const int offsetX,
			    const int offsetY) const
    {
      //gcn::SDLGraphics *g = static_cast<gcn::SDLGraphics *>(graphics);

        int px = getPixelX() + offsetX - getWidth();
        int py = getPixelY() + offsetY - getHeight();

        if (px <= 0)
            px = 0;
        if (py <= 0)
            py = 0;

        //graphics->drawImage(gcn::Image::load("./data/img/aa2186.png", true), px, py);
	int sx = 0, sy = 0;
	getPicPos(sx, sy);
	graphics->drawImage(image, sx, sy, px, py, mWidth, mHeight);
	std::stringstream ss;
	ss << "Player X: " << px << ", Y: " << py;
	graphics->drawText(ss.str(), 0, 20);
        //g->setColor(gcn::Color(255, 0, 0, 255));
        //g->fillRectangle(gcn::Rectangle(getPixelX(), getPixelY(), 10, 10));
    }
  
  bool XLocalPlayer::setTarget(const int px, const int py)
  {
    std::list< XTilePoint* >::iterator it;
    for(it = mPath.begin(); it != mPath.end(); it++) {
      delete(*it);
    }
    mPath.clear();
    std::list< XTilePoint* > tPath;
    modou::FindPath::getPath(mMap,
			     int(mPos.x),
			     int(mPos.y),
			     px,
			     py,
			     tPath);
    std::list< XTilePoint* >::reverse_iterator rit;

    XTilePoint *point=NULL;

    for(rit = tPath.rbegin(); rit != tPath.rend(); rit++) {
      if (point == NULL) {
	point = *rit;
	mPath.push_front(*rit);
	continue;
      } else {
	if (point->mparent == *rit) {
	  mPath.push_front(*rit);
	  point = *rit;
	} else {
	  delete(*rit);
	}
      }
    }
    tPath.clear();
  }
  
  void XLocalPlayer::logic()
  {
    if (mPath.empty()) {
      maction = aaction::STAND;
      return;
    }
    if (globals::tick % 8 != 0) {
      return;
    }
    maction = aaction::MOVE;
    XTilePoint *point = mPath.front();
    int dx, dy;
    dx = point->x * 32;
    dy = point->y * 32;
    
    directTo(dx, dy);
    
    mPos.x = dx;
    mPos.y = dy;
    mPath.pop_front();
    delete(point);
  }

  void XLocalPlayer::directTo(int x, int y)
  {
    if (x > mPos.x) {
      mdirection = adirection::RIGHT;
    } else if (x < mPos.x) {
      mdirection = adirection::LEFT;
    } else if (y > mPos.y) {
      mdirection = adirection::DOWN;
    } else {
      mdirection = adirection::UP;
    }
  }

  void XLocalPlayer::action() const
  {
    std::cout << "click me " << name << std::endl;
  }
}
