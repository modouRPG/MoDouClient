#include "XTilePoint.h"
#include <stdio.h>
#include <math.h>

namespace modou
{
  XTilePoint::XTilePoint()
  {
    x=y=F=G=H=0;
    mparent = NULL;
  }

  XTilePoint::XTilePoint(int x0, int y0, XTilePoint *mparent0)
  {
    x = x0;
    y = y0;
    mparent = mparent0;

    F=G=H=0;

    if (x == mparent->x || y == mparent->y) {
      G = mparent->G + 10;
    } else {
      G = mparent->G + 14;
    }
  }

  XTilePoint::~XTilePoint()
  {}

  void XTilePoint::calcF(XTilePoint *endPoint)
  {
    H = int(sqrt((endPoint->x - x)*(endPoint->x -x)*100 + (endPoint->y - y) * (endPoint->y - y)*100));
    F = G + H;
  }

}
