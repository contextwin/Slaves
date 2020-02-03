#include "mysdl2.h"

// limt
#define FILE_NAME_MAX 256

int main(int argc, char* argv[]) {
 char img_dir_name[FILE_NAME_MAX] = IMAGE_DIR;
 SDL_Event event;
 SDL_Window* window = NULL; // 描画ウィンドウ
 SDL_Surface* screenSurface = NULL; // windowのサーフェイス
 SDL_Surface* image = NULL; // 画像のサーフェイス
 SDL_Rect rect = {0, 0, 100, 100}, scr_rect;
 SDL_Renderer *render;

 strcat(img_dir_name, PNG_FILE02);
 image = IMG_Load(img_dir_name);
 if(!image){
  printf("IMG_Load: %s\n", IMG_GetError());
 }

// SDL_SetColorKey( image, SDL_TRUE, SDL_MapRGB(image->format, 255, 0, 255));
 
 /* 初期化処理 */
 if(SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS)
 {
  printf("SDL初期化失敗. SDL_Error: %s\n", SDL_GetError());
 } else {
  // window生成
  window = SDL_CreateWindow("Slaves", 
                             SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED,
                             WIDTH,
                             HEIGHT,
                             SDL_WINDOW_SHOWN);

  if(window == NULL)
  {
   printf("Window 生成処理失敗. SDL_Error: %s\n", SDL_GetError());
  } else {
   render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

   //window サーフェイス取得 表示
   screenSurface = SDL_GetWindowSurface(window);
     
   //Fill 
   SDL_FillRect(screenSurface, NULL,
                SDL_MapRGB(screenSurface->format,
                           0xFF, 0xFF, 0xFF));

   SDL_BlitSurface(image, NULL, screenSurface, NULL);
   
   SDL_RenderFillRect(render, &rect);
   
   //サーフェイスを更新
   SDL_UpdateWindowSurface(window);
     
   //wait
   SDL_Delay(2000);
   /*
   while(SDL_PollEvent(&event)){
    switch(event.key.keysym.sym) {
	 case SDL_QUIT: break;
	default: break;
	}
   }*/
  }  
 } 
 /* ... */
 //window 開放
 SDL_DestroyWindow(window);  
 SDL_Quit(); // 全てのサブシステムの終了

 return EXIT_SUCCESS;
}
