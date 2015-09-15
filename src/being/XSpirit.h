#ifndef _XSPIRIT_H_
#define _XSPIRIT_H_
#include "being/XActor.h"

namespace modou
{
    class XSpirit : public XActor
    {
        public:
      XSpirit(std::string name,
	      std::string pic_path,
	      int x,
	      int y,
	      int width,
	      int height);
            virtual ~XSpirit();

            void draw(gcn::Graphics *const graphics, const int offsetX, const int offsetY) const;
	    void action() const;
    private:
            std::string mImageFile;
	    gcn::Image *mImage;
    };
}

#endif
