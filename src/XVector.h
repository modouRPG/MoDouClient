#ifndef _XVECTOR_H_
#define _XVECTOR_H_

namespace modou
{
  class XVector
  {
  public:
  XVector():
    x(0.0F),
      y(0.0F),
      z(0.0F)
	{}
    
  XVector(const float x0, const float y0, const float z0) :
    x(x0),
      y(y0),
      z(z0)
      {}
    
    virtual ~XVector() {}

    float x,y,z;
  };
}

#endif
