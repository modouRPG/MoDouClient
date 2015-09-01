#include "XPassworldField.h"

namespace modou
{
    XPassworldField::XPassworldField(const std::string &text) : XTextField(text)
    {}

    void XPassworldField::draw(gcn::Graphics *graphics)
    {
        const std::string original = mText;
        char mask = '*';

        mText.assign(mText.length(), mask);

        XTextField::draw(graphics);
        mText = original;
    }
}
