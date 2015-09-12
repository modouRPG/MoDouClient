#ifndef MENUM_H
#define MENUM_H

enum State {
  STATE_EXIT,
  STATE_LOGIN,
  STATE_GAME,
};

namespace aaction {
  enum actor_action {
    STAND = 0,
    MOVE,
    ATTACK,
    SIT,
    DEAD,
    HURT,
    SPAWN,
    PRESTAND
  };
}

namespace adirection {
  enum actor_direction {
    LEFT,
    UP,
    RIGHT,
    DOWN
  };
}

#endif
