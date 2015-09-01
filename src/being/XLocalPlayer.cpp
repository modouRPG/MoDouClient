#include "XLocalPlayer.h"
#include <guichan/sdl.hpp>
#include "main.h"

namespace modou
{
    XLocalPlayer::XLocalPlayer() :
        XActor()
    {
        mWidth = 60;
        mHeight = 60;
    }

    XLocalPlayer::~XLocalPlayer()
    {}

    void XLocalPlayer::draw(gcn::Graphics *const graphics, const int offsetX, const int offsetY) const
    {
        gcn::SDLGraphics *g = static_cast<gcn::SDLGraphics *>(graphics);

        int px = getPixelX() + offsetX - getWidth();
        int py = getPixelY() + offsetY - getHeight();

        if (px <= 0)
            px = 0;
        if (py <= 0)
            py = 0;

        g->drawImage(gcn::Image::load("./data/img/aa2186.png", true), px, py);
        //g->setColor(gcn::Color(255, 0, 0, 255));
        //g->fillRectangle(gcn::Rectangle(getPixelX(), getPixelY(), 10, 10));
    }

    bool XLocalPlayer::navigateTo(const int x, const int y)
    {
        
    }
}
