#ifndef _XACTOR_H_
#define _XACTOR_H_
#include <guichan.hpp>
#include <list>
#include "map/TmxMap.h"
#include "map/XTilePoint.h"
#include "XVector.h"
//#include "being/XActor.h"

namespace modou
{
    class XActor
    {
        public:
            XActor();
            virtual ~XActor();

            void setMap(TmxMap *map);
	    void addToMap(TmxMap *map);
	    
            int getWidth() const
            { return mWidth; }
            int getHeight() const
            { return mHeight; }

            const XVector &getPosition() const
            { return mPos; }

            int getPixelX() const
            { return static_cast<int>(mPos.x); }
            int getPixelY() const
            { return static_cast<int>(mPos.y); }

            void setPosition(XVector &pos)
            { mPos = pos; }

	    bool isClickMe(int x, int y);
	    bool isArroundMe(XActor *actor);

            virtual void draw(gcn::Graphics *const graphics, const int offsetX, const int offsetY) const = 0;
	    virtual void action() const = 0;

            int mWidth;
            int mHeight;

	    std::list< XTilePoint* > mPath;

            std::string name;
        protected:
            TmxMap *mMap;
            XVector mPos;
    };
}

#endif
