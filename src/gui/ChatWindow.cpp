#include "ChatWindow.h"

namespace modou
{
  ChatWindow::ChatWindow() :
    XWindow()
  {
    setBaseColor(gcn::Color(190, 208, 247, 128));
    setPadding(3);

    setSize(500, 200);
    setVisible(true);
    setTitleBarHeight(3);

    mTextBox = new XTextBox();
    mTextBox->setSize(500, 170);
    mTextBox->setBaseColor(gcn::Color(190, 208, 247, 128));
    mTextBox->setBackgroundColor(gcn::Color(190, 208, 247, 128));
    mTextBox->setEditable(false);
    
    mSayTextField = new XTextField();
    mSayTextField->setSize(500, 30);
    mSayTextField->setBackgroundColor(gcn::Color(199, 255, 236));
    mSayTextField->setActionEventId("chatinput");
    mSayTextField->addActionListener(this);

    add(mTextBox, 0, 0);
    add(mSayTextField, 0, 170);
  }

  ChatWindow::~ChatWindow()
  {

  }

  void ChatWindow::action(const gcn::ActionEvent  &event)
  {
    const std::string &eventId = event.getId();
    if (eventId == "chatinput") {
      std::string msg = mSayTextField->getText();
      if (!msg.empty()) {
	if (mTextBox->getText().empty()) {
	  mTextBox->setTextRow(0, msg);
	} else {
	  mTextBox->addRow(msg);
	}
	mSayTextField->setText("");
      }
    }

  }

  void ChatWindow::keyPressed(gcn::KeyEvent &event)
  {

  }
}
