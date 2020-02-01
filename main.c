#include "function.h"
#include "view.h"
#include "specific.h"

int main(int argc, char* argv[]) {
 SDL_Window* window = NULL; // 描画ウィンドウ
 SDL_Surface* screenSurface = NULL; // windowのサーフェイス
 
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
   //window サーフェイス取得
   screenSurface = SDL_GetWindowSurface(window);
     
   //Fill 
   SDL_FillRect(screenSurface, NULL,
                SDL_MapRGB(screenSurface->format,
                           0xFF, 0xFF, 0xFF));

   //サーフェイスを交信 
   SDL_UpdateWindowSurface(window);
     
   //wait
   SDL_Delay(2000);
  }  
 } 
 /* ... */
 //window 開放
 SDL_DestroyWindow(window);  
 SDL_Quit(); // 全てのサブシステムの終了
 
 return EXIT_SUCCESS;
}
