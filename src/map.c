#include <stdio.h>
#include <stdlib.h>
#include "map.h"
/*
 * parse_map - This function parses the map in the game
 *
 * Description: This function is used to parse a map and
 * store the parsed data in a 2D array. The functions will be
 * read from a stored source file.
 *
 * @filename: The name of the file containing the map coordinates.
 */
void parse_map(const char *filename)
{
	FILE *file = fopen(filename, "r");
	int value;

	if (file == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", filename);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < SCREEN_HEIGHT / TILE_SIZE; ++i)
	{
		for (int j = 0; j < SCREEN_WIDTH / TILE_SIZE; ++j)
		{
			fscanf(file, "%d", &value);
			map[i][j] = value;
		}
	}
	fclose(file);
}
