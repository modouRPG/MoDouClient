#ifndef _WORLD_SELECT_DLG_CPP_
#define _WORLD_SELECT_DLG_CPP_

#include "gui/XWindow.h"

namespace modou
{
  class WorldSelectDlg : public XWindow
  {
  public:
    WorldSelectDlg();
    virtual ~WorldSelectDlg();

    void close();
  };
}

#endif
