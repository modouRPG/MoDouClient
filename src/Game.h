#ifndef _GAME_H_
#define _GAME_H_
#include "menum.h"

namespace modou
{
    class Game 
    {
    public:
      Game();
      virtual ~Game();

      void handleInput();
      void handleMove();

      void logic();

      State mState;
      void loop();
    };
}

#endif
