#include "mysdl2.h"

// limt
#define FILE_NAME_MAX 256

int main(int argc, char* argv[]) {
 char img_path_name[FILE_NAME_MAX] = IMAGE_DIR,
      font_path_name[FILE_NAME_MAX] = FONT_DIR;
 SDL_Event event;
 SDL_Window* window = NULL; // 描画ウィンドウ
 SDL_Surface* screenSurface = NULL; // windowのサーフェイス
 SDL_Surface* image = NULL; // 画像のサーフェイス
 SDL_Rect rect = {100, 600, 850, 200}, scr_rect;
 SDL_Renderer* render;
 TTF_Font *font;
 SDL_Texture *texture;

 SDL_bool done = SDL_FALSE;
 
 //TTF初期化
 strcat(font_path_name, TTF_FONT1);
 if (TTF_Init() < 0) {
  printf("TTF_InitError: %s\n", TTF_GetError());
 }
 
 font = TTF_OpenFont(font_path_name, 40);
 
 if (!font) {
	  printf("TTF_OpenFont: %s\n", TTF_GetError());
 }
 
 //画像データ読み込み
 strcat(img_path_name, PNG_FILE02);
 image = IMG_Load(img_path_name);
 if(!image){
  printf("IMG_GetError: %s\n", IMG_GetError());
 }
 
 //SDL初期化
/*  if(SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS)
 {
  printf("SDL初期化失敗. SDL_Error: %s\n", SDL_GetError());
 }
 */
 
 window = SDL_CreateWindow("Slaves", 
                             SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED,
                             WIDTH,
                             HEIGHT,
                             SDL_WINDOW_SHOWN);
  
 if(window == NULL){
   printf("Window 生成処理失敗. SDL_Error: %s\n", SDL_GetError());
 }
 render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

 //window サーフェイス取得 表示
 screenSurface = SDL_GetWindowSurface(window);

 //サーフェイスの背景を白にする
 SDL_FillRect(screenSurface, NULL,
              SDL_MapRGB(screenSurface->format,
                           0xFF, 0xFF, 0xFF));

 SDL_BlitSurface(image, NULL, screenSurface, NULL);
   
 SDL_SetRenderDrawColor(render, 0,0,0, SDL_ALPHA_OPAQUE);
 DrawSquare(render, 100, 550, 950, 800);
 DrawSquare(render, 500, 50, 950, 500);
   
 //文字列表示処理
 screenSurface = TTF_RenderUTF8_Blended(font, "hello, world!\n", (SDL_Color){0,255,255,255});
	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);
	 
 int iw,ih;
 SDL_QueryTexture(texture, NULL, NULL, &iw, &ih);
 SDL_Rect txtRect = (SDL_Rect) {0,0,iw,ih};
	  
 //文字列の表示座標
 SDL_Rect pasteRect = (SDL_Rect){370,650,iw,ih};
  
 //レンダーにコピー
 SDL_RenderCopy(render,texture,&txtRect, &pasteRect);
  
 //サーフェイスを更新
 SDL_UpdateWindowSurface(window);
     
while(!done) {
    while(SDL_PollEvent(&event)){
     if(event.type == SDL_QUIT) {
	  done = SDL_TRUE;
	 }
 }

   }
     
 /* ... */
 SDL_FreeSurface(screenSurface);
 SDL_DestroyTexture(texture);
 SDL_DestroyRenderer(render);
 //window 開放
 SDL_DestroyWindow(window);  
 SDL_Quit(); // 全てのサブシステムの終了

 return EXIT_SUCCESS;
}
