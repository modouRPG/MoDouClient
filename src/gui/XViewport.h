#ifndef _XVIEWPORT_H_
#define _XVIEWPORT_H_
#include <guichan.hpp>
#include "map/XMap.h"
#include "map/TmxMap.h"
#include "map/FindPath.h"

namespace modou
{
    class XViewport : public gcn::Container,
                      public gcn::MouseListener
    {
        public:
            XViewport();
            virtual ~XViewport();

            void draw(gcn::Graphics *graphics);
            void setMap(TmxMap *map);
            TmxMap *mMap;

            void mousePressed(gcn::MouseEvent &event);

        private:
            int mPixelViewX, mPixelViewY;
            bool leftMouseAction();
            void followMouse();
	    //std::list< XTilePoint* > path;
    };
}

#endif
