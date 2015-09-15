#ifndef _XLISTMODEL_H
#define _XLISTMODEL_H
#include <guichan.hpp>

namespace modou
{
  class XListModel : public gcn::ListModel
  {
  public:
    XListModel();
    virtual ~XListModel();

    int getNumberOfElements();

    std::string getElementAt(int i);

    void addElement(std::string sel);

  private:
    std::vector< std::string > sels;
  };
}

#endif
