#ifndef _XWINDOW_H_
#define _XWINDOW_H_
#include <guichan.hpp>

namespace modou
{
    class XWindow : public gcn::Window
    {
    public:
      XWindow();
      XWindow(const std::string& caption);
      
      virtual ~XWindow();
      
      void setShowCloseBtn(bool show);
      
      virtual void close();
      
      void draw(gcn::Graphics *graphics);

      void mousePressed(gcn::MouseEvent &event);
    protected:
      void center();
    private:
      bool mShowCloseBtn;
      gcn::Rectangle mCloseRect;
    };
}

#endif
