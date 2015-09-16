#include "being/XSpirit.h"
#include "main.h"
#include <guichan/sdl.hpp>
#include "gui/NpcDialog.h"

namespace modou
{
  XSpirit::XSpirit(std::string mName,
		   std::string pic_path,
		   int x,
		   int y,
		   int width,
		   int height) :
      XActor()
    {
      name = mName;
      mImageFile = pic_path;
      mImage = gcn::Image::load(mImageFile, true);
      mPos.x = x;
      mPos.y = y;
      mWidth = width;
      mHeight = height;
    }

    XSpirit::~XSpirit()
    {}

    void XSpirit::draw(gcn::Graphics *const graphics, const int offsetX, const int offsetY) const
    {
        // gcn::SDLGraphics *g = static_cast<gcn::SDLGraphics *>(graphics);

        const int px = getPixelX() + offsetX;
        const int py = getPixelY() + offsetY;

        graphics->drawImage(mImage, px, py);
        // gcn::Rectangle rect(getPixelX()+offsetX, getPixelY() + offsetY, mWidth, mHeight);
        // g->drawRectangle(rect);

        gcn::Font *font = globals::gui->getTop()->getFont();
        graphics->drawText(name, px + mWidth/2, py-font->getHeight(), gcn::Graphics::CENTER);
    }

  void XSpirit::action() const {
    globals::gNpcDlg->setCaption(name);
    gcn::Container *const top = static_cast<gcn::Container *>(globals::gui->getTop());
    globals::gNpcDlg->setVisible(true);
    top->add(globals::gNpcDlg, 20, 20);
    std::cout << "Click npc: " << name << std::endl;
  }
}
