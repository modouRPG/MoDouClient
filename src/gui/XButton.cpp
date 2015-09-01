#include "XButton.h"

namespace modou
{
    XButton::XButton() : gcn::Button()
    {}

    XButton::XButton(const std::string& caption) : gcn::Button(caption)
    {}

    XButton::XButton(const std::string& caption, const std::string& actionEventId, gcn::ActionListener * listener) : gcn::Button(caption)
    {
        setActionEventId(actionEventId);
        if (listener) {
            addActionListener(listener);
        }
    }

    XButton::~XButton()
    {}
}
