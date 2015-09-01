#ifndef _XFONT_H
#define _XFONT_H
#include <SDL_ttf.h>
#include <guichan.hpp>
#include <string>


namespace modou 
{
    class Graphics;

    class XFont : public gcn::Font
    {
        public:
            XFont(std::string filename, const int size, const int style = 0);

            virtual ~XFont();

            virtual int getWidth(const std::string &text) const;

            virtual void drawString(gcn::Graphics* graphics, const std::string& text, 
                                    int x, int y);
            
            virtual int getHeight() const;

            virtual int getStringIndexAt(const std::string &text, int x) const;
        private:
            static TTF_Font *openFont(const char *const name, const int size);
            TTF_Font *mFont;

    };
}
#endif
