#ifndef _XPASSWORLDFIELD_H_
#define _XPASSWORLDFIELD_H_

#include <guichan.hpp>
#include "XTextField.h"

namespace modou
{
    class XPassworldField : public XTextField
    {
        public:
            XPassworldField(const std::string& text="");

            void draw(gcn::Graphics *graphics);
    };
}
#endif
