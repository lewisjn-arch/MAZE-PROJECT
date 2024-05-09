#include <stdbool.h>
#include <math.h>
#include "player.h"
#include "map.h"
/*
 * can_move - This function controls the movement of the player in
 * the game along the stated axes.
 * Description: This function is used to control the movement of a
 * player in the view port using the x and y axis
 * @y: This is the y-axis
 * @x: This is the x-axis
 * Return: This function returns a boolean value
 */
bool can_move(float x, float y)
{
	if (map[(int)y][(int)x] != '1')
	{
		return (true);
	}
	return (false);
}
