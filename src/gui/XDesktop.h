#ifndef _DESKTOP_H_
#define _DESKTOP_H_
#include <guichan.hpp>

namespace modou
{
    class XDesktop : public gcn::Container
    {
        public:
            XDesktop();
            virtual ~XDesktop();

            void draw(gcn::Graphics *graphics);
        private:
            gcn::Image *mWallpaper;
    };
}

#endif
