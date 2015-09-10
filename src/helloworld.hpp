/**
 * Code to populate a global Gui object with a simple
 * Hello World example.
 */
#include <guichan.hpp>
#include "main.h"
#include "gui/LoginDlg.h"
#include "gui/XDesktop.h"
#include "map/XMap.h"
#include "map/XMapReader.h"

namespace modou
{
    gcn::Container* top;
    modou::XFont *font;
  modou::LoginDlg *gLoginDlg;
  modou::XDesktop *gDesktop;

    /**
     * Initialises the Hello World example by populating the global Gui
     * object.
     */
    void init()
    {
        // We first create a container to be used as the top widget.
        // The top widget in Guichan can be any kind of widget, but
        // in order to make the Gui contain more than one widget we
        // make the top widget a container.
        top = new gcn::Container();
        // We set the dimension of the top container to match the screen.
        top->setDimension(gcn::Rectangle(0, 0, screenWidth, screenHeight));
        // Finally we pass the top widget to the Gui object.
        globals::gui->setTop(top);

        // Now we load the font used in this example.
        //font = new gcn::ImageFont("fixedfont.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
        //font = new modou::XFont("./font/wqy-microhei.ttf", 16, 1);
        font = new modou::XFont("./font/abc.ttf", 16, 1);
        // Widgets may have a global font so we don't need to pass the
        // font object to every created widget. The global font is static.
        gcn::Widget::setGlobalFont(font);
        globals::gui->getGraphics()->setFont(font);

        //globals::map = new XMap(32, 24, 32, 32);
        //globals::map = XMapReader::readMap("./m1.conf");
        //globals::map->name = "平安镇";
	gDesktop = new modou::XDesktop();
	top->add(gDesktop);
	
	gLoginDlg = new modou::LoginDlg();
	top->add(gLoginDlg, (top->getWidth() - gLoginDlg->getWidth()) / 2, (top->getHeight() - gLoginDlg->getHeight())/2);
    }
    
    /**
     * Halts the Hello World example.
     */
    void halt()
    {
        delete font;
        delete top;
    }
}
