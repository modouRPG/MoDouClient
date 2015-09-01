#include "XDesktop.h"
#include <guichan/sdl.hpp>

namespace modou
{
    XDesktop::XDesktop() : gcn::Container()
    {
        mWallpaper = gcn::Image::load("./data/img/bkg.jpg", true);
        setDimension(gcn::Rectangle(0, 0, 800, 600));
    }

    XDesktop::~XDesktop()
    {
        delete(mWallpaper);
    }

    void XDesktop::draw(gcn::Graphics *graphics)
    {
        gcn::SDLGraphics *ghs = static_cast<gcn::SDLGraphics *>(graphics);
        if (mWallpaper) {
            gcn::Rectangle &rect = mDimension; 
            graphics->drawImage(mWallpaper, 0, 0);
        }
    }
}
