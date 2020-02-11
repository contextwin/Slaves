//SDL2を利用した自己定義のヘッダファイル
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

void MyDrawSquare(SDL_Renderer *render, int x, int y, int right_x, int lower_right_y ) {
 
 SDL_RenderDrawLine(render, x, y, x, lower_right_y);
 SDL_RenderDrawLine(render, right_x, y, right_x, lower_right_y);
 SDL_RenderDrawLine(render, x, y, right_x, y);
 SDL_RenderDrawLine(render, x, lower_right_y, right_x, lower_right_y);

};

TTF_Font *MyFuncInitTTF(TTF_Font *font, char *font_path_name) {
 
 if (TTF_Init() < 0) {
  printf("TTF_InitError: %s\n", TTF_GetError());
 }
 
 font = TTF_OpenFont(font_path_name, 40);
 
 if (!font) {
	  printf("TTF_OpenFont: %s\n", TTF_GetError());
 }
 
 return font; // ?
}

void MyTextureRenderCopy(SDL_Texture *texture, SDL_Renderer *render, int x, int y) {

 int iw,ih;
 SDL_QueryTexture(texture, NULL, NULL, &iw, &ih);
 SDL_Rect txtRect = (SDL_Rect) {0,0,iw,ih};	  
 //文字列の表示座標
 SDL_Rect pasteRect = (SDL_Rect){x,y,iw,ih}; 
 //レンダーにコピー
 SDL_RenderCopy(render,texture,&txtRect, &pasteRect);

}
