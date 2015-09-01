#ifndef _XACTOR_H_
#define _XACTOR_H_
#include <guichan.hpp>
#include "map/XMap.h"
#include "XVector.h"
#include "being/XActor.h"

namespace modou
{
    class XActor
    {
        public:
            XActor();
            virtual ~XActor();

            void setMap(XMap *map);
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

            virtual void draw(gcn::Graphics *const graphics, const int offsetX, const int offsetY) const = 0;

            int mWidth;
            int mHeight;

            std::string name;
        protected:
            XMap *mMap;
            XVector mPos;
    };
}

#endif
