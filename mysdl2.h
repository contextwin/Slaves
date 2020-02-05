//SDL2を利用した自己定義のヘッダファイル
#include "specific.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

void DrawSquare(SDL_Renderer* render, int x, int y, int right_x, int lower_right_y ) {
 SDL_RenderDrawLine(render, x, y, x, lower_right_y);
 SDL_RenderDrawLine(render, right_x, y, right_x, lower_right_y);
 SDL_RenderDrawLine(render, x, y, right_x, y);
 SDL_RenderDrawLine(render, x, lower_right_y, right_x, lower_right_y);
};
