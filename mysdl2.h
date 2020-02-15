//SDL2を利用した自己定義のヘッダファイル
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

//SDL_Window レンダリングデータ保持用　構造体
struct MyStructSDLWindowData {
 char *title;
 int x, y, w, h;
 Uint32 flags;
};
					   
void MySDLDrawSquare(SDL_Renderer *render, int* square_xyrxly ) {
 enum {x, y, rx, lry}; // x, y, right x, lower right y;
 
 SDL_RenderDrawLine(render, square_xyrxly[x], square_xyrxly[y] , square_xyrxly[x], square_xyrxly[lry]);
 SDL_RenderDrawLine(render, square_xyrxly[rx], square_xyrxly[y], square_xyrxly[rx], square_xyrxly[lry]);
 SDL_RenderDrawLine(render, square_xyrxly[x], square_xyrxly[y], square_xyrxly[rx], square_xyrxly[y]);
 SDL_RenderDrawLine(render, square_xyrxly[x], square_xyrxly[lry], square_xyrxly[rx], square_xyrxly[lry]);

};

TTF_Font *MyFuncInitTTF(TTF_Font *font, char *font_path_name) {
 
 if (TTF_Init() < 0) {
  printf("TTF_InitError: %s\n", TTF_GetError());
 }
 
 font = TTF_OpenFont(font_path_name, 30);
 
 if (!font) {
	  printf("TTF_OpenFont: %s\n", TTF_GetError());
 }
 
 return font;
}

void MySDLTextureRenderCopy(SDL_Texture *texture, SDL_Renderer *render, int x, int y) {

 int iw,ih;
 SDL_QueryTexture(texture, NULL, NULL, &iw, &ih);
 SDL_Rect txtRect = (SDL_Rect) {0,0,iw,ih};	  
 //文字列の表示座標
 SDL_Rect pasteRect = (SDL_Rect){x,y,iw,ih}; 
 //レンダーにコピー
 SDL_RenderCopy(render,texture,&txtRect, &pasteRect);

}
