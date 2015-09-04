#ifndef _XMAPREADER_H_
#define _XMAPREADER_H_
#include "map/TmxMap.h"

namespace modou
{
    class XMapReader
    {
        public:
            static TmxMap* readMap(std::string file_path);
    };
}

#endif
