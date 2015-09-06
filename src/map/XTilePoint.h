#ifndef XTILE_POINT_H
#define XTILE_POINT_H

namespace modou
{
  class XTilePoint
  {
  public:
    XTilePoint();
    XTilePoint(int x0, int y0, XTilePoint *mparent0);
    virtual ~XTilePoint();

    bool operator==(XTilePoint *point);

    void calcF(XTilePoint *endPoint);

    int F, G, H;
    int x, y;

    XTilePoint *mparent;
  };
}

#endif
