#include <SDL2/SDL.h>
#include <math.h>
#include "render.h"
#include "map.h"

void draw_map(SDL_Renderer *renderer)
{
	for (int i = 0; i < SCREEN_HEIGHT / TILE_SIZE; ++i)
	{
		for (int j = 0; j < SCREEN_WIDTH / TILE_SIZE; ++j)
		{
			SDL_Rect rect = {j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE};

			if (map[i][j] == '1')
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			}
			SDL_RenderFillRect(renderer, &rect);
		}
	}
}
