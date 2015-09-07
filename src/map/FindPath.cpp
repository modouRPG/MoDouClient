#include "FindPath.h"
#include "main.h"
#include "map/XTilePoint.h"

namespace modou
{
  FindPath::FindPath()
  {

  }

  FindPath::~FindPath()
  {

  }

  void getChildrenList(TmxMap *map,
		       XTilePoint *tmpPoint,
		       std::list< XTilePoint* > &childrenList)
  {
    XTilePoint *cPoint = NULL;
    int i, j;
    
    if (map->isBlock(tmpPoint->x - 1, tmpPoint->y)) {
      for(j = tmpPoint->y - 1; j <= tmpPoint->y + 1; j++) {
	for(i = tmpPoint->x; i<= tmpPoint->x + 1; i++) {
	  if (!map->isBlock(i, j) && map->inMap(i, j) &&
	      ! (i == tmpPoint->x && j == tmpPoint->y)) {
	    cPoint = new XTilePoint(i, j, tmpPoint);
	    childrenList.push_back(cPoint);
	  }
	}
      }
    } else if (map->isBlock(tmpPoint->x + 1, tmpPoint->y)) {
      for(j = tmpPoint->y - 1; j <= tmpPoint->y + 1; j++) {
	for(i = tmpPoint->x - 1; i<= tmpPoint->x; i++) {
	  if (!map->isBlock(i, j) && map->inMap(i, j) &&
	      ! (i == tmpPoint->x && j == tmpPoint->y)) {
	    cPoint = new XTilePoint(i, j, tmpPoint);
	    childrenList.push_back(cPoint);
	  }
	}
      } 
    } else if (map->isBlock(tmpPoint->x, tmpPoint->y - 1)) {
      for(j = tmpPoint->y; j <= tmpPoint->y + 1; j++) {
	for(i = tmpPoint->x - 1; i<= tmpPoint->x + 1; i++) {
	  if (!map->isBlock(i, j) && map->inMap(i, j) &&
	      ! (i == tmpPoint->x && j == tmpPoint->y)) {
	    cPoint = new XTilePoint(i, j, tmpPoint);
	    childrenList.push_back(cPoint);
	  }
	}
      } 
    } else if (map->isBlock(tmpPoint->x, tmpPoint->y + 1)) {
      for(j = tmpPoint->y - 1; j <= tmpPoint->y; j++) {
	for(i = tmpPoint->x - 1; i<= tmpPoint->x + 1; i++) {
	  if (!map->isBlock(i, j) && map->inMap(i, j) &&
	      ! (i == tmpPoint->x && j == tmpPoint->y)) {
	    cPoint = new XTilePoint(i, j, tmpPoint);
	    childrenList.push_back(cPoint);
	  }
	}
      } 
    } else {
      for(j = tmpPoint->y - 1; j <= tmpPoint->y + 1; j++) {
	for(i = tmpPoint->x - 1; i<= tmpPoint->x + 1; i++) {
	  if (!map->isBlock(i, j) && map->inMap(i, j) &&
	      ! (i == tmpPoint->x && j == tmpPoint->y)) {
	    cPoint = new XTilePoint(i, j, tmpPoint);
	    childrenList.push_back(cPoint);
	  }
	}
      } 
    }
  }

  XTilePoint* pointInList(XTilePoint *point,
		   std::list< XTilePoint* > &openList)
  {
    std::list< XTilePoint* >::iterator it;

    for(it = openList.begin(); it != openList.end(); it++) {
      if ((*it) == point) {
	return (*it);
      }
    }
    return NULL;
  }

  
  XTilePoint* getBestPoint(std::list< XTilePoint* > &openList)
  {
    XTilePoint *best = NULL;
    std::list< XTilePoint* >::iterator it;
    int small = -1;

    for( it = openList.begin(); it != openList.end(); it++) {
      if (small == -1 || (*it)->F < small) {
	small = (*it)->F;
	best = *it;
      }
    }
    
    return best;
  }

  void FindPath::getPath(TmxMap *map,
			 int sx,
			 int sy,
			 int ex,
			 int ey,
			 std::list< XTilePoint* > &path)
  {
    XTilePoint *start_point, *end_point;

    start_point = new XTilePoint();
    end_point = new XTilePoint();

    start_point->x = (sx + mapTileSize - 1) / mapTileSize;
    start_point->y = (sy + mapTileSize - 1) / mapTileSize;
    start_point->mparent = NULL;

    end_point->x = (ex + mapTileSize - 1) / mapTileSize;
    end_point->y = (ey + mapTileSize - 1) / mapTileSize;

    std::list< XTilePoint* > openList, childrenList;
    std::list< XTilePoint* >::iterator it;
    XTilePoint *tmpPoint, *findPoint;

    openList.push_back(start_point);
    while(openList.size() != 0) {
      tmpPoint = getBestPoint(openList);
      openList.remove(tmpPoint);
      path.push_back(tmpPoint);
      if (tmpPoint->x == end_point->x &&
	  tmpPoint->y == end_point->y) {
	std::cout << " find it . " << path.size() <<  std::endl;
	break;
      }
      childrenList.clear();
      getChildrenList(map, tmpPoint, childrenList);
      for(it = childrenList.begin(); it != childrenList.end(); it++) {
	(*it)->calcF(end_point);
	findPoint = pointInList(*it, openList);
	if (findPoint != NULL) {
	  if ((*it)->F < findPoint->F) {
	    findPoint->F = (*it)->F;
	    findPoint->mparent = tmpPoint;
	  }
	} else {
	  findPoint = pointInList(*it, path);
	  if (findPoint != NULL) {
	    continue;
	  } else {
	    openList.push_back(*it);
	  }
	}
      }// end for
    }// end while
  }
}
