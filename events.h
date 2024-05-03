#ifndef EVENTS_H
#define EVENTS_H

#include <stdbool.h>

void handle_events(bool *quit, float *playerX, float *playerY, float *playerAngle, float moveSpeed, bool *drawMapEnabled);

#endif /* EVENTS_H */

