#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 64

extern char map[SCREEN_HEIGHT / TILE_SIZE][SCREEN_WIDTH / TILE_SIZE];

void parse_map(const char *filename);
char map[SCREEN_HEIGHT / TILE_SIZE][SCREEN_WIDTH / TILE_SIZE];

#endif /* MAP_H */

