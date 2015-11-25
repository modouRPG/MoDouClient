#ifndef _DIALOG_H
#define _DIALOG_H

#include "gui/LoginDlg.h"
#include "gui/NpcDialog.h"
#include "gui/ChatWindow.h"

//LoginDlg *gLoginDlg = new LoginDlg();
namespace modou {
  modou::NpcDialog *gNpcDlg = new modou::NpcDialog();
  modou::ChatWindow *gChatWindow = new modou::ChatWindow();
}


#endif
