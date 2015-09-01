#ifndef _XSPIRIT_H_
#define _XSPIRIT_H_
#include "being/XActor.h"

namespace modou
{
    class XSpirit : public XActor
    {
        public:
            XSpirit();
            virtual ~XSpirit();

            void draw(gcn::Graphics *const graphics, const int offsetX, const int offsetY) const;

            std::string mImageFile;
    };
}

#endif
