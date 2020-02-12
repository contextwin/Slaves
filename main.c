#include "function.h"
#include "view.h"
#include "mysdl2.h"
#include "specific.h"

int main(int argc, char* argv[]) {
 // 自己定義型宣言
 struct MyStructMenue2 MyMenue2_s;

 SDL_Event event;
 SDL_Window* window = NULL; // 描画ウィンドウ

 SDL_Rect rect = {100, 600, 850, 200}, scr_rect;
 SDL_Renderer* render;
 SDL_Texture *texture;
 
 SDL_Surface *screenSurface = NULL; // windowのサーフェイス
 SDL_bool done = SDL_FALSE;

 //Slaves SDL_Window データ初期化処理
 window = MyFuncSpeciInitSlavesWindow(window);
 //window サーフェイス取得 表示
 screenSurface = SDL_GetWindowSurface(window);
  //サーフェイスの背景を白にする
 SDL_FillRect(screenSurface, NULL,
              SDL_MapRGB(screenSurface->format,
                           0xFF, 0xFF, 0xFF));
 //画面 Menue2 データ初期化処理
 MyMenue2_s = MyFuncInitMenue2(MyMenue2_s);
                   
 // 引数1のサーフェイスを引数3のサーフェイスにコピーする
 SDL_BlitSurface(MyMenue2_s.image, NULL, screenSurface, NULL);
 
 render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
 SDL_SetRenderDrawColor(render, 0,0,0,0);
 MyDrawSquare(render, 100, 550, 950, 800); //select_square2
 MyDrawSquare(render, 500, 50, 950, 500); //view_square
   
 //文字列表示処理
 //select_square2
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, MyMenue2_s.select_square2_strings[0], (SDL_Color){0,255,255,255});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	 
 //テクスチャーをx,yの座標にレンダーコピー
 MyTextureRenderCopy(texture, render, 150, 575);
 
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, MyMenue2_s.select_square2_strings[1], (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 
 MyTextureRenderCopy(texture, render, 440, 575);
 
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, MyMenue2_s.select_square2_strings[2], (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 730, 575);

 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, MyMenue2_s.select_square2_strings[3], (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 150, 675);
 
 //view_square
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, "Chipo       Lv 1", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 75);
 
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, "        HP 23/23", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 125);
 
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, "        MP 15/15", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 170);
 
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, "       ABP 15/15", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 220);
 
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, "   STR  3  SPD 5", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 270);
 
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, "   VIT  3  MGC 5", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 320);
 
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, "   INT  3 LUCK 5", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 370);
 
 screenSurface = TTF_RenderUTF8_Blended(MyMenue2_s.font10px, "NextLvUP   8 exp", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 440);

 
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
