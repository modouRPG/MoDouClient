#include "being/XSpirit.h"
#include "main.h"
#include <guichan/sdl.hpp>

namespace modou
{
    XSpirit::XSpirit() :
        mImageFile("./data/img/aa0001.png")
    {}

    XSpirit::~XSpirit()
    {}

    void XSpirit::draw(gcn::Graphics *const graphics, const int offsetX, const int offsetY) const
    {
        gcn::SDLGraphics *g = static_cast<gcn::SDLGraphics *>(graphics);

        const int px = getPixelX() + offsetX;
        const int py = getPixelY() + offsetY;

        g->drawImage(gcn::Image::load(mImageFile, true), px, py);
        gcn::Rectangle rect(getPixelX()+offsetX, getPixelY() + offsetY, mWidth, mHeight);
        g->drawRectangle(rect);

        gcn::Font *font = globals::gui->getTop()->getFont();
        graphics->drawText(name, px + mWidth/2, py-font->getHeight(), gcn::Graphics::CENTER);
    }
}
