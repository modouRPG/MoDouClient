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

            virtual void close();
    protected:
	    void center();
    };
}

#endif
