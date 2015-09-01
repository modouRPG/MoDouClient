#ifndef _XMAP_H_
#define _XMAP_H_
#include <guichan.hpp>
#include <stdint.h>
#include "XMapLayer.h"

namespace modou
{
    struct MapHeader {
        uint8_t width;
        uint8_t height;
        uint8_t tileWidth;
        uint8_t tileHeight;
    };

    class XActor;

    class XMap
    {
        public:
            XMap(const int width, const int height, const int tileWidth, const int tileHeight);
            virtual ~XMap();

            int getWidth()
            { return mWidth; }

            int getHeight()
            { return mHeight; }

            int getTileWidth()
            { return mTileWidth; }

            int getTileHeight()
            { return mTileHeight; }

            void addActor(XActor *actor);


            void draw(gcn::Graphics *graphics, int scrollX, int scrollY);
            std::vector<XMapLayer *> mLayers;

            void addLayer(XMapLayer *layer);

            std::string name;

        private:
            int mWidth, mHeight, mTileWidth, mTileHeight;
            std::list<XActor *> mActors;

    };
}
#endif
