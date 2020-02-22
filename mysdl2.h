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

void MySDLDrawSquareAndFill(SDL_Renderer *render, int* square_xyrxly, int* line_color, int* fill_color ) {
 
 SDL_SetRenderDrawColor(render, line_color[0], line_color[1], line_color[2], line_color[3]);

 MySDLDrawSquare(render, square_xyrxly);
  
 SDL_SetRenderDrawColor(render, fill_color[0], fill_color[1], fill_color[2], fill_color[3]);

 SDL_Rect rect = (SDL_Rect){square_xyrxly[0] + 1,
	     square_xyrxly[1] + 1, (square_xyrxly[2] - square_xyrxly[0]) - 1, (square_xyrxly[3] - square_xyrxly[1]) -1};
	     
 SDL_RenderFillRect(render,&rect); 
 SDL_SetRenderDrawColor(render, line_color[0], line_color[1], line_color[2], line_color[3]);
 
}
;
	
TTF_Font *MyFuncInitTTF(TTF_Font *font, char *font_path_name) {
 
 if (TTF_Init() < 0) {
  printf("TTF_InitError: %s\n", TTF_GetError());
 }
 
  font = TTF_OpenFont(font_path_name, 30);
  //font = TTF_OpenFont(font_path_name, 17);

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

void MySDLDrawCircle(SDL_Renderer * renderer, int centreX, int centreY, int radius)
{
   int diameter = (radius * 2);
   int x = (radius - 1);
   int y = 0;
   int tx = 1;
   int ty = 1;
   int error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}
