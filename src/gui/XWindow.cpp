#include "XWindow.h"

namespace modou
{
  XWindow::XWindow() : gcn::Window()
  {
    mShowCloseBtn = false;
  }
  
  XWindow::XWindow(const std::string& caption) :
    gcn::Window(caption)
  {
    mShowCloseBtn = false;
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

  void XWindow::setShowCloseBtn(bool show)
  {
    mShowCloseBtn = show;
  }

  void XWindow::draw(gcn::Graphics *graphics)
  {
    gcn::Window::draw(graphics);
    
    if (mShowCloseBtn) {
      mCloseRect.x = getWidth() - 20 - 5;
      mCloseRect.y = 5;
      mCloseRect.width = 20;
      mCloseRect.height = 20;
      graphics->drawText("X", mCloseRect.x, mCloseRect.y);
    }
  }

  void XWindow::mousePressed(gcn::MouseEvent &event)
  {
    if (event.getSource() != this || event.isConsumed())
      return;
    if (event.getButton() == gcn::MouseEvent::LEFT) {
      const int x = event.getX();
      const int y = event.getY();
      
      if (mShowCloseBtn && mCloseRect.isPointInRect(x, y)) {
	close();
      }
    }
    
    Window::mousePressed(event);
  }
}
