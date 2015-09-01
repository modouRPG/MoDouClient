#include "XWindow.h"

namespace modou
{
    XWindow::XWindow() : gcn::Window()
    {
      setBaseColor(gcn::Color(190, 208, 247, 128));
    }
    XWindow::XWindow(const std::string& caption) : gcn::Window(caption)
    {
      setBaseColor(gcn::Color(190, 208, 247, 128));
    }
    XWindow::~XWindow()
    {
    
    }

    void XWindow::close()
    {
        setVisible(false);
    }
  void XWindow::center()
  {
    
  }
}
