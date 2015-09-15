#include "XTextBox.h"
#include <sstream>

namespace modou
{
  XTextBox::XTextBox() : gcn::TextBox()
  {
    
  }

  XTextBox::~XTextBox()
  {

  }

  void XTextBox::setTextWrapped(const std::string &text)
  {
    std::stringstream ss;
    std::string line;
    size_t newlinepos;
    int i=0;

    newlinepos = text.find("\n");

    const gcn::Font *const font = getFont();

    for(i=0; i< text.size(); i++) {
      if (font->getWidth(line + text[i]) > getWidth()) {
	ss << "\n" << text[i];
	line = text[i];
      } else {
	ss << text[i];
	line += text[i];
      } 
    }
    setText(ss.str());
  }
}
