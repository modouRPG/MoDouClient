#include "XMapLayer.h"
#include "main.h"
#include <guichan/sdl.hpp>
#include <unistd.h>

namespace modou
{
    XMapLayer::XMapLayer(const int x, const int y, const int width, const int height,
            const bool isFringeLayer, const int mask) : mX(x),
            mY(y),
            mWidth(width),
            mHeight(height),
            mIsFringeLayer(isFringeLayer),
            mMask(mask),
            mTiles(new gcn::Image*[mWidth * mHeight])
    {
        std::fill_n(mTiles, mWidth * mHeight, static_cast<gcn::Image *>(NULL));
    }

    XMapLayer::~XMapLayer()
    {
        delete[] mTiles;
    }

    void XMapLayer::setTile(int x, int y, gcn::Image *img)
    {
        mTiles[x + y * mWidth] = img;
    }

    void XMapLayer::draw(gcn::Graphics *graphics, int startX, int startY, int endX, int endY,
                        const int scrollX, const int scrollY, const int layerDrawFlags) const
    {
        gcn::SDLGraphics *g = static_cast<gcn::SDLGraphics *>(graphics);

        startX -= mX;
        startY -= mY;
        endX -= mX;
        endY -= mY;

        if (startX < 0)
            startX = 0;
        if (startY < 0)
            startY = 0;
        if (endX > mWidth)
            endX = mWidth;
        if (endY > mHeight)
            endY = mHeight;

        const int dx = (mX * mapTileSize) - scrollX;
        const int dy = (mY * mapTileSize) - scrollY;

        for(int y = startY; y < endY; y++) {
            gcn::Image **tilePtr = mTiles + static_cast<size_t>(startX + y * mWidth);
            for(int x = startX; x < endX; x++, tilePtr++) {
                const gcn::Image *img = *tilePtr;
                if (img) {
                    const int px = x * mapTileSize + dx;
                    const int py = y * mapTileSize + dy;
                    g->drawImage(img, px, py);
                }
            }
        }
    }
    void XMapLayer::drawFringe(gcn::Graphics *graphics, int startX, int startY, int endX, int endY,
            const int scrollX, const int scrollY, std::list<XActor*> *actors, const int layerDrawFlags) const
    {
        std::list<XActor*>::const_iterator ai = actors->begin();

        while(ai != actors->end()) {
            (*ai)->draw(graphics, -scrollX, -scrollY);
            ++ai;
        }
    }
}
