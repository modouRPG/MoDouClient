#include "XTextField.h"

namespace modou
{
    XTextField::XTextField() : gcn::TextField()
    {
        setWidth(150);
        setHeight(getFont()->getHeight() + 4);
    }

    XTextField::XTextField(const std::string &text) : gcn::TextField(text)
    {
        setWidth(150);
        setHeight(getFont()->getHeight() + 4);
    }

    XTextField::~XTextField()
    {}

    void XTextField::keyPressed(gcn::KeyEvent& keyEvent)
    {
        gcn::Key key = keyEvent.getKey();
        const int val = key.getValue();

        if (key.getValue() == gcn::Key::LEFT && mCaretPosition > 0)
        {
            while(mCaretPosition > 0) {
                --mCaretPosition;
                if ((mText[mCaretPosition] & 192) != 128)
                    break;
            }
        }

        else if (key.getValue() == gcn::Key::RIGHT && mCaretPosition < mText.size())
        {
            while(mCaretPosition < mText.size()) {
                ++mCaretPosition;
                if (mCaretPosition == mText.size() ||
                   (mText[mCaretPosition] & 192) != 128)
                    break;
            }
        }

        else if (key.getValue() == gcn::Key::DELETE && mCaretPosition < mText.size())
        {
            size_t sz = mText.size();
            while(mCaretPosition < sz) {
                --sz;
                mText.erase(mCaretPosition, 1);
                if (mCaretPosition == sz ||
                        (mText[mCaretPosition] & 192 ) != 128)
                    break;
            }
        }

        else if (key.getValue() == gcn::Key::BACKSPACE && mCaretPosition > 0)
        {
            while(mCaretPosition > 0) {
                --mCaretPosition;
                const int v = mText[mCaretPosition];
                mText.erase(mCaretPosition, 1);
                if ((v & 192) != 128)
                    break;
            }
        }

        else if (key.getValue() == gcn::Key::ENTER)
        {
            distributeActionEvent();
        }

        else if (key.getValue() == gcn::Key::HOME)
        {
            mCaretPosition = 0;
        }

        else if (key.getValue() == gcn::Key::END)
        {
            mCaretPosition = mText.size();
        }

        else if (key.isCharacter()
                 && key.getValue() != gcn::Key::TAB)
        {
            mText.insert(mCaretPosition, std::string(1,(char)key.getValue()));
            ++mCaretPosition;
        } else if (val > gcn::Key::DOWN) {
            int len;
            if (val < 128)
                len = 1;               // 0xxxxxxx
            else if (val < 0x800)
                len = 2;               // 110xxxxx 10xxxxxx
            else if (val < 0x10000)
                len = 3;               // 1110xxxx 10xxxxxx 10xxxxxx
            else
                len = 4;               // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

            char buf[4];
            for (int i = 0; i < len; ++ i)
            {
                buf[i] = static_cast<char>(val >> (6 * (len - i - 1)));
                if (i > 0)
                    buf[i] = static_cast<char>((buf[i] & 63) | 128);
            }

            if (len > 1)
                buf[0] |= static_cast<char>(255U << (8 - len));

            mText.insert(mCaretPosition, std::string(buf, buf + len));
            mCaretPosition += len;
        }

        if (key.getValue() != gcn::Key::TAB)
        {
            keyEvent.consume();
        }
        
        fixScroll();

    }
    
}
