#include <stdio.h>
#include <stdlib.h>
#include "map.h"

char map[SCREEN_HEIGHT / TILE_SIZE][SCREEN_WIDTH / TILE_SIZE];

void parse_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < SCREEN_HEIGHT / TILE_SIZE; ++i) {
        for (int j = 0; j < SCREEN_WIDTH / TILE_SIZE; ++j) {
            int value;
            fscanf(file, "%d", &value);
            map[i][j] = value;
        }
    }

    fclose(file);
}

