#include "being/XActor.h"

namespace modou
{
    XActor::XActor()
    {}

    XActor::~XActor()
    {}

    void XActor::setMap(TmxMap *map)
    {
        //TODO: if mMap if not null. need remove actor from mMap first.
        mMap = map;
        if (mMap) {
            mMap->setActor(this);
        }
    }

  bool XActor::isClickMe(int x, int y)
  {
    if (x > mPos.x &&
	x < mPos.x + mWidth &&
	y > mPos.y &&
	y < mPos.y + mHeight) {
      return true;
    } else {
      return false;
    }
  }

  bool XActor::isArroundMe(XActor *actor)
  {
    if (actor->getPixelX() > mPos.x - mWidth &&
	actor->getPixelX() < mPos.x + 2 * mWidth &&
	actor->getPixelY() > mPos.y - mHeight &&
	actor->getPixelY() < mPos.y + 2 * mHeight) {
      return true;
    } else {
      return false;
    }
  } 

  void XActor::addToMap(TmxMap *map)
  {
    if (map) {
      map->addActor(this);
    }
  }
}
