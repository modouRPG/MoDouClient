#include "XListModel.h"

namespace modou
{
  XListModel::XListModel()
  {

  }

  XListModel::~XListModel()
  {

  }

  int XListModel::getNumberOfElements()
  {
    return sels.size();
  }

  std::string XListModel::getElementAt(int i)
  {
    return sels.at(i);
  }

  void XListModel::addElement(std::string sel)
  {
    sels.push_back(sel);
  }
}
