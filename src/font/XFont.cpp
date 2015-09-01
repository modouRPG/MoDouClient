#include "XFont.h"
#include "utils/stringutils.h"
#include <guichan/sdl.hpp>

namespace modou
{
    XFont::XFont(std::string filename, const int size, const int style) : mFont(NULL)
    {
        if (TTF_Init() == -1) {
            std::cout << "TTF_Init() error: " << std::string(TTF_GetError()) << std::endl;
        }
        mFont = openFont(filename.c_str(), size);
        TTF_SetFontStyle(mFont, style);
    }

    XFont::~XFont()
    {
        TTF_CloseFont(mFont);
        mFont = NULL;
        TTF_Quit();
    }

    int XFont::getWidth(const std::string &text) const
    {
        if (text.empty())
            return 0;
        const char *buf = getSafeUtf8String(text);
        int w,h;
        TTF_SizeUTF8(mFont, buf, &w, &h);
        delete(buf);
        return w;
    }

    int XFont::getHeight() const
    {
        return TTF_FontHeight(mFont);
    }


    TTF_Font* XFont::openFont(const char *const name, const int size)
    {
        return TTF_OpenFontIndex(name, size, 0);
    }

    void XFont::drawString(gcn::Graphics* graphics, const std::string& text, int x, int y)
    {
        if (text.empty())
            return;

        const char *utext = getSafeUtf8String(text);

        gcn::SDLGraphics *g = dynamic_cast<gcn::SDLGraphics *>(graphics);

        gcn::Color col = graphics->getColor();  
        SDL_Color col2;
        col2.r = col.r;
        col2.g = col.g;
        col2.b = col.b;
        //col2.a = col.a;
        const float alpha = (float)col.a;
        SDL_Surface *surface = TTF_RenderUTF8_Blended(mFont, utext, col2);

        SDL_Rect source = {0, 0, surface->w, surface->h}, dest= {x, y, surface->w, surface->h};
        g->drawSDLSurface(surface, source, dest);
        


//        SDL_Texture *const texture = SDL_CreateTextureFromSurface(
//                mRenderer, tmpImage);
//
//        SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
//
//        gcn::Image *img = new Image(texture, surface->w, surface->h);
//        img->setAlpha(alpha);
//        
//        SDL_FreeSurface(surface);
//
//        if (img)
//            graphics->drawImage(img, x, y);

        delete(utext);
        utext = NULL;
        return;
    }

    int XFont::getStringIndexAt(const std::string& text, int x) const
    {
        unsigned int i;
        int size = 0;

        for (i = 0; i < text.size(); ++i)
        {
            size = getWidth(text.substr(0,i));

            if (size > x)
            {
                return i;
            }
        }

        return text.size();
    }

}
