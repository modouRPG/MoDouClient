#include "map/XMapReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include "main.h"

namespace modou
{
    TmxMap* XMapReader::readMap(std::string file_path)
    {
      TmxMap *map = new TmxMap();
      map->ParseFile(file_path);

      if (map->HasError()) {
	printf("error code: %d\n", map->GetErrorCode());
        printf("error text: %s\n", map->GetErrorText().c_str());
	return NULL;
      }

      map->loadResource();
      return map;
    }
}
