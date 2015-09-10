#ifndef _XLOCALPLAYER_H_
#define _XLOCALPLAYER_H_
#include "XVector.h"
#include "map/XMap.h"
#include "being/XActor.h"

namespace modou
{
  class XLocalPlayer : public XActor
  {
  public:
    XLocalPlayer();
    
    virtual ~XLocalPlayer();
    
    void draw(gcn::Graphics *const graphics, const int offsetX, const int offsetY) const;
    
    bool setTarget(const int x, const int y);

    void logic();
  };
}

#endif
