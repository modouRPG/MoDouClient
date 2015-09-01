#include "being/XActor.h"

namespace modou
{
    XActor::XActor()
    {}

    XActor::~XActor()
    {}

    void XActor::setMap(XMap *map)
    {
        //TODO: if mMap if not null. need remove actor from mMap first.
        mMap = map;
        if (mMap) {
            mMap->addActor(this);
        }
    }
}
