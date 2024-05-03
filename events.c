#include <SDL2/SDL.h>
#include <math.h>
#include "events.h"
#include "map.h"
#include "player.h"
#include "render.h"

void handle_events(bool *quit, float *playerX, float *playerY, float *playerAngle, float moveSpeed, bool *drawMapEnabled) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            *quit = true;
        }
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_w: // Move forward
                    if (can_move(*playerX + cos(*playerAngle * (M_PI / 180.0f)) * moveSpeed, *playerY + sin(*playerAngle * (M_PI / 180.0f)) * moveSpeed)) {
                        *playerX += cos(*playerAngle * (M_PI / 180.0f)) * moveSpeed;
                        *playerY += sin(*playerAngle * (M_PI / 180.0f)) * moveSpeed;
                    }
                    break;
                case SDLK_s: // Move backward
                    if (can_move(*playerX - cos(*playerAngle * (M_PI / 180.0f)) * moveSpeed, *playerY - sin(*playerAngle * (M_PI / 180.0f)) * moveSpeed)) {
                        *playerX -= cos(*playerAngle * (M_PI / 180.0f)) * moveSpeed;
                        *playerY -= sin(*playerAngle * (M_PI / 180.0f)) * moveSpeed;
                    }
                    break;
                case SDLK_a: // Strafe left
                    if (can_move(*playerX - cos((*playerAngle - 90.0f) * (M_PI / 180.0f)) * moveSpeed, *playerY - sin((*playerAngle - 90.0f) * (M_PI / 180.0f)) * moveSpeed)) {
                        *playerX -= cos((*playerAngle - 90.0f) * (M_PI / 180.0f)) * moveSpeed;
                        *playerY -= sin((*playerAngle - 90.0f) * (M_PI / 180.0f)) * moveSpeed;
                    }
                    break;
                case SDLK_d: // Strafe right
                    if (can_move(*playerX + cos((*playerAngle - 90.0f) * (M_PI / 180.0f)) * moveSpeed, *playerY + sin((*playerAngle - 90.0f) * (M_PI / 180.0f)) * moveSpeed)) {
                        *playerX += cos((*playerAngle - 90.0f) * (M_PI / 180.0f)) * moveSpeed;
                        *playerY += sin((*playerAngle - 90.0f) * (M_PI / 180.0f)) * moveSpeed;
                    }
                    break;
                case SDLK_q: // Rotate left
                    *playerAngle -= 5.0f;
                    if (*playerAngle < 0) {
                        *playerAngle += 360.0f;
                    }
                    break;
                case SDLK_e: // Rotate right
                    *playerAngle += 5.0f;
                    if (*playerAngle >= 360) {
                        *playerAngle -= 360.0f;
                    }
                    break;
                case SDLK_m: // Toggle draw map
                    *drawMapEnabled = !(*drawMapEnabled);
                    break;
                default:
                    break;
            }
        }
    }
}

