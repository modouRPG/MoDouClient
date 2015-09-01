#include "XMap.h"
#include <guichan/sdl.hpp>

namespace modou
{
    XMap::XMap(const int width, const int height, const int tileWidth, const int tileHeight) :
        mWidth(width),
        mHeight(height),
        mTileWidth(tileWidth),
        mTileHeight(tileHeight),
        mLayers(),
        mActors()
    {
//        XMapLayer *background = new XMapLayer(0, 0, width, height, false, 0);
//        int i, j;
//        std::string pic_name;
//        for(i=0; i< mWidth; i++) {
//            if (i%2 == 0) {
//                pic_name = "./data/img/aa0001.png";
//            } else {
//                pic_name = "./data/img/aa0037.png";
//            }
//            for (j=0; j<mHeight; j++) {
//                background->setTile(i, j, gcn::Image::load(pic_name, true));
//            }
//        }
//        mLayers.push_back(background);
//        XMapLayer *actor_layer= new XMapLayer(0, 0, width, height, true, 0);
//        actor_layer->setTile(16, 12, gcn::Image::load("./data/img/aa0638.png", true));
//        mLayers.push_back(actor_layer);
    }

    void XMap::draw(gcn::Graphics *graphics, int scrollX, int scrollY)
    {
        const int startX = scrollX / mTileWidth - 2;
        const int startY = scrollY / mTileHeight;
        const int endX = (800 + scrollX + mTileWidth - 1) / mTileWidth + 1;

        const int endPixelY = 600 + scrollY + mTileHeight - 1;
        const int endY = endPixelY / mTileHeight + 1;

        std::vector<XMapLayer*>::const_iterator it;
        for(it = mLayers.begin(); it != mLayers.end(); it++)
        {
            XMapLayer *const layer = *it;
            if (layer->isFringeLayer()) {
                layer->drawFringe(graphics, startX, startY, endX, endY, scrollX, scrollY, &mActors, 0);
            } else {
                layer->draw(graphics, startX, startY, endX, endY, scrollX, scrollY, 0);
            }
        }
        // draw text
        graphics->drawText(name, 800/2, 80, gcn::Graphics::CENTER);


    }

    XMap::~XMap()
    {}

    void XMap::addActor(XActor *actor)
    {
        mActors.push_front(actor);
    }

    void XMap::addLayer(XMapLayer *layer)
    {
        if (layer)
            mLayers.push_back(layer);
    }
}
