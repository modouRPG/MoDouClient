#ifndef _XTextField_H_
#define _XTextField_H_
#include <guichan.hpp>

namespace modou
{
    class XTextField : public gcn::TextField
    {
        public:
            XTextField();
            XTextField(const std::string &text);

            virtual ~XTextField();

            virtual void keyPressed(gcn::KeyEvent& keyEvent);
    };
}

#endif
