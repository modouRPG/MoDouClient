#ifndef _XLOCALPLAYER_H_
#define _XLOCALPLAYER_H_
#include "XVector.h"
#include "map/XMap.h"
#include "being/XActor.h"
#include "menum.h"

namespace modou
{
  class XLocalPlayer : public XActor
  {
  public:
    XLocalPlayer();
    
    virtual ~XLocalPlayer();
    
    void draw(gcn::Graphics *const graphics, const int offsetX, const int offsetY) const;

    void action() const;
    
    bool setTarget(const int x, const int y);

    void directTo(int x, int y);

    void logic();
  private:
    void getPicPos(int &x, int &y) const;
    std::string pic_path;
    adirection::actor_direction mdirection;
    aaction::actor_action maction;
    gcn::Image *image;
  };
}

#endif
