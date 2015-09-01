#ifndef _XMAPREADER_H_
#define _XMAPREADER_H_
#include "map/XMap.h"

namespace modou
{
    class XMapReader
    {
        public:
            static XMap* readMap(std::string file_path);
    };
}

#endif
