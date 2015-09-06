#ifndef FIND_PATH_H
#define FIND_PATH_H

#include "map/TmxMap.h"
#include "map/XTilePoint.h"
#include <list>

namespace modou
{
  class FindPath
  {
  public:
    FindPath();
    virtual ~FindPath();

    static void getPath(TmxMap *map,
			int sx,
			int sy,
			int ex,
			int ey,
			std::list< XTilePoint* > &path);

  };
}

#endif
