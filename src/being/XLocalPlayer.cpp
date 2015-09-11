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
        mWidth = 60;
        mHeight = 60;
    }

    XLocalPlayer::~XLocalPlayer()
    {
      std::list< XTilePoint* >::iterator it;
      for(it = mPath.begin(); it != mPath.end(); it++) {
	delete(*it);
      }
      mPath.clear();
    }

    void XLocalPlayer::draw(gcn::Graphics *const graphics, const int offsetX, const int offsetY) const
    {
        gcn::SDLGraphics *g = static_cast<gcn::SDLGraphics *>(graphics);

        int px = getPixelX() + offsetX - getWidth();
        int py = getPixelY() + offsetY - getHeight();

        if (px <= 0)
            px = 0;
        if (py <= 0)
            py = 0;

        g->drawImage(gcn::Image::load("./data/img/aa2186.png", true), px, py);
	std::stringstream ss;
	ss << "Player X: " << px << ", Y: " << py;
	g->drawText(ss.str(), 0, 20);
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
      return;
    }
    if (globals::tick % 10 != 0) {
      return;
    }
    XTilePoint *point = mPath.front();
    mPos.x = point->x * 32;
    mPos.y = point->y * 32;
    mPath.pop_front();
    delete(point);
  }
}
