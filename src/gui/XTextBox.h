#ifndef XTEXTBOX_H
#define XTEXTBOX_H
#include <guichan.hpp>

namespace modou
{
  class XTextBox: public gcn::TextBox
  {
  public:
    XTextBox();
    XTextBox(std::string txt);
    virtual ~XTextBox();

    void setTextWrapped(const std::string &text);

  };
}

#endif
