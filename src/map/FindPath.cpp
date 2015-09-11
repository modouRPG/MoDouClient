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
	      !(i == tmpPoint->x && j == tmpPoint->y)) {
	    cPoint = new XTilePoint(i, j, tmpPoint);
	    childrenList.push_back(cPoint);
	  }
	}
      }
    } else if (map->isBlock(tmpPoint->x + 1, tmpPoint->y)) {
      for(j = tmpPoint->y - 1; j <= tmpPoint->y + 1; j++) {
	for(i = tmpPoint->x - 1; i<= tmpPoint->x; i++) {
	  if (!map->isBlock(i, j) && map->inMap(i, j) &&
	      !(i == tmpPoint->x && j == tmpPoint->y)) {
	    cPoint = new XTilePoint(i, j, tmpPoint);
	    childrenList.push_back(cPoint);
	  }
	}
      } 
    } else if (map->isBlock(tmpPoint->x, tmpPoint->y - 1)) {
      for(j = tmpPoint->y; j <= tmpPoint->y + 1; j++) {
	for(i = tmpPoint->x - 1; i<= tmpPoint->x + 1; i++) {
	  if (!map->isBlock(i, j) && map->inMap(i, j) &&
	      !(i == tmpPoint->x && j == tmpPoint->y)) {
	    cPoint = new XTilePoint(i, j, tmpPoint);
	    childrenList.push_back(cPoint);
	  }
	}
      } 
    } else if (map->isBlock(tmpPoint->x, tmpPoint->y + 1)) {
      for(j = tmpPoint->y - 1; j <= tmpPoint->y; j++) {
	for(i = tmpPoint->x - 1; i<= tmpPoint->x + 1; i++) {
	  if (!map->isBlock(i, j) && map->inMap(i, j) &&
	      !(i == tmpPoint->x && j == tmpPoint->y)) {
	    cPoint = new XTilePoint(i, j, tmpPoint);
	    childrenList.push_back(cPoint);
	  }
	}
      } 
    } else {
      for(j = tmpPoint->y - 1; j <= tmpPoint->y + 1; j++) {
	for(i = tmpPoint->x - 1; i<= tmpPoint->x + 1; i++) {
	  if (!map->isBlock(i, j) && map->inMap(i, j) &&
	      !(i == tmpPoint->x && j == tmpPoint->y)) {
	    cPoint = new XTilePoint(i, j, tmpPoint);
	    childrenList.push_back(cPoint);
	  }
	}
      } 
    }
  }

  XTilePoint* pointInList(XTilePoint *point,
		   std::list< XTilePoint* > &tList)
  {
    std::list< XTilePoint* >::iterator it;

    for(it = tList.begin(); it != tList.end(); it++) {
      if ((*it)->x == point->x && (*it)->y == point->y) {
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

    if (map->isBlock(end_point->x, end_point->y)) {
      delete(start_point);
      delete(end_point);
      return;
    }

    std::list< XTilePoint* > openList, childrenList;
    std::list< XTilePoint* >::iterator it;
    XTilePoint *tmpPoint, *findOpenPoint, *findClosePoint;


    openList.push_back(start_point);

    while(openList.size() != 0) {
      tmpPoint = getBestPoint(openList);
      openList.remove(tmpPoint);
      path.push_back(tmpPoint);
      if (tmpPoint->x == end_point->x &&
	  tmpPoint->y == end_point->y) {
	std::cout << "find it open lise size: " << openList.size() <<  ", closed list size: " << path.size() <<  std::endl;
	break;
      }
      childrenList.clear();
      getChildrenList(map, tmpPoint, childrenList);
      for(it = childrenList.begin(); it != childrenList.end(); it++) {
	(*it)->calcF(end_point);
	findOpenPoint = pointInList(*it, openList);
	findClosePoint = pointInList(*it, path);

	if (findOpenPoint == NULL && findClosePoint == NULL) {
	  openList.push_back(*it);
	} else if (findOpenPoint != NULL) {
	  if ((*it)->G < findOpenPoint->G) {
	    findOpenPoint->G = (*it)->G;
	    findOpenPoint->calcF(end_point);
	    findOpenPoint->mparent = tmpPoint;
	  }
	  delete(*it);
	} else if (findClosePoint != NULL) {
	  delete(*it);
	  continue;
	  // if ((*it)->F < findClosePoint->F) {
	  //   findClosePoint->F = (*it)->F;
	  //   findClosePoint->mparent = tmpPoint;
	  // }
	}
      }// end for
    }// end while
    // start point and some of children point has been added to open list or path list. So we delete end point and some
    // of children point.
    delete(end_point);
    for(it = openList.begin(); it != openList.end(); it++) {
      delete(*it);
    }
    openList.clear();
  }
}
