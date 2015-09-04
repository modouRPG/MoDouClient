#ifndef _GAME_H_
#define _GAME_H_
#include "gui/XViewport.h"
#include "map/XMap.h"
#include "map/TmxMap.h"
#include "map/XMapReader.h"

namespace modou
{
    class Game 
    {
        public:
            Game();
            virtual ~Game();
    };
}

#endif
