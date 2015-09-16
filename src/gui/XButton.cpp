#include "XButton.h"

namespace modou
{
    XButton::XButton() : gcn::Button()
    {
      setBaseColor(gcn::Color(216, 249, 132));
    }

    XButton::XButton(const std::string& caption) : gcn::Button(caption)
    {
      setBaseColor(gcn::Color(216, 249, 132));
    }

    XButton::XButton(const std::string& caption, const std::string& actionEventId, gcn::ActionListener * listener) : gcn::Button(caption)
    {
      
      setBaseColor(gcn::Color(216, 249, 132));
        setActionEventId(actionEventId);
        if (listener) {
            addActionListener(listener);
        }
    }

    XButton::~XButton()
    {}
}
