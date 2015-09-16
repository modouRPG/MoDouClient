#ifndef _CHAT_WINDOW_H
#define _CHAT_WINDOW_H
#include "gui/XWindow.h"
#include "gui/XTextBox.h"
#include "gui/XTextField.h"

namespace modou
{
  class ChatWindow : public XWindow,
    public gcn::ActionListener,
    public gcn::KeyListener
  {
  public:
    ChatWindow();
    virtual ~ChatWindow();

    void action(const gcn::ActionEvent &event);
    void keyPressed(gcn::KeyEvent &event);

  private:
    XTextBox *mTextBox;
    XTextField *mSayTextField;
  };
}


#endif
