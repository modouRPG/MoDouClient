#ifndef _XBUTTON_H_
#define _XBUTTON_H_
#include <guichan.hpp>

namespace modou
{
    class XButton : public gcn::Button
    {
        public:
            XButton();
            XButton(const std::string& caption);
            XButton(const std::string& caption, const std::string& actionEventId, gcn::ActionListener * listener);

            virtual ~XButton();

    };
}

#endif
