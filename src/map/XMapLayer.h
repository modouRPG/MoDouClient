#ifndef _XMAPLAYER_H_
#define _XMAPLAYER_H_
#include <guichan.hpp>

namespace modou
{
    class XActor;
    class XMapLayer 
    {
        public:
            XMapLayer(const int x, const int y, const int width, const int height, 
                    const bool isFringeLayer, const int mask);
            virtual ~XMapLayer();

            void draw(gcn::Graphics *graphics, int startX, int startY, int endX, int endY,
                    const int scrollX, const int scrollY, const int layerDrawFlags) const;

            void drawFringe(gcn::Graphics *graphics, int startX, int startY, int endX, int endY,
                    const int scrollX, const int scrollY, std::list<XActor*> *actors, const int layerDrawFlags) const;

            void setTile(int x, int y, gcn::Image *img);

            bool isFringeLayer()
            { return mIsFringeLayer; }

        private:
            int mX, mY, mWidth, mHeight, mMask;
            bool mIsFringeLayer;
            gcn::Image **mTiles;
    };
}

#endif
