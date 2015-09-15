#ifndef NPCDIALOG_H
#define NPCDIALOG_H
#include "gui/XWindow.h"
#include "gui/XTextBox.h"
#include "gui/XListBox.h"
#include "gui/XListModel.h"


namespace modou
{
  class NpcDialog : public XWindow,
    public gcn::ActionListener
  {
  public:
    NpcDialog();
    virtual ~NpcDialog();

    void close();
    
    void action(const gcn::ActionEvent &event);

  private:
    XTextBox *mTextBox;
    XListBox *mListBox;
    XListModel *mListModel;
  };
}

#endif
