#include <stdbool.h>
#include <math.h>
#include "player.h"
#include "map.h"

bool can_move(float x, float y) {
    if (map[(int)y][(int)x] != '1') {
        return true; // Empty space
    }
    return false; // Wall
}

