#include "gui/NpcDialog.h"

namespace modou
{
  NpcDialog::NpcDialog():
    XWindow(),
    gcn::ActionListener()
  {
    setBaseColor(gcn::Color(190, 208, 247, 128));
    setPadding(3);
    setSize(300, 400);
    //setAlignment(gcn::Graphics::LEFT);
    setShowCloseBtn(true);
    setVisible(true);
    setTitleBarHeight(25);

    mTextBox = new XTextBox();
    mTextBox->setWidth(300);
    mTextBox->setTextWrapped("你好，小伙子。你能帮我挑点水么？我老了，干不动体力活儿了。如果你能帮助我，我会给你一些奖励的。");
    mTextBox->setEditable(false);

    this->add(mTextBox, 0, 0);

    mListBox = new XListBox();
    mListModel = new XListModel();
    mListModel->addElement("好的。");
    mListModel->addElement("不了，谢谢！");
    mListBox->setListModel(mListModel);
    this->add(mListBox, 0, mTextBox->getHeight() + 20);
  }

  NpcDialog::~NpcDialog()
  {}

  void NpcDialog::action(const gcn::ActionEvent &event)
  {

  }

  void NpcDialog::close()
  {
    XWindow::close();
  }
}
