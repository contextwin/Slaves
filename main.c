#include "function.h"
#include "view.h"
#include "mysdl2.h"
#include "specific.h"

int main(int argc, char* argv[]) {
 // 自己定義型宣言
 struct MyStructMenue2 Menue2_s;
 SDL_Window* slaves_window = NULL; // 描画ウィンドウ

 SDL_Event event;
 SDL_Rect rect = {100, 600, 850, 200}, scr_rect;
 SDL_Texture *texture;
 
 SDL_Surface *screenSurface = NULL; // windowのサーフェイス
 SDL_bool done = SDL_FALSE;

 //Slaves SDL_Window データ初期化処理
 slaves_window = MyFuncSpeciInitSlavesWindow(slaves_window);
 //window サーフェイス取得 表示
 screenSurface = SDL_GetWindowSurface(slaves_window);
  //サーフェイスの背景を白にする
 SDL_FillRect(screenSurface, NULL,
              SDL_MapRGB(screenSurface->format,
                           0xFF, 0xFF, 0xFF));
 //画面 Menue2 データ初期化処理
 Menue2_s = MySpeciInitMenue2(Menue2_s, slaves_window);
                   
 //引数1のサーフェイスを引数3のサーフェイスにコピーする
 SDL_BlitSurface(Menue2_s.image, NULL, screenSurface, NULL);
 
 MySDLDrawSquare(Menue2_s.render, 100, 550, 950, 800); //select_square2
 MySDLDrawSquare(Menue2_s.render, 500, 50, 950, 500); //view_square
   
 //文字列表示処理
 //select_square2
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, Menue2_s.select_square2_strings[0], (SDL_Color){0,255,255,255});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	 
 //テクスチャーをx,yの座標にレンダーコピー
 MyTextureRenderCopy(texture, Menue2_s.render, 150, 575);
 
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, Menue2_s.select_square2_strings[1], (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 
 MyTextureRenderCopy(texture, Menue2_s.render, 440, 575);
 
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, Menue2_s.select_square2_strings[2], (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 MyTextureRenderCopy(texture, Menue2_s.render, 730, 575);

 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, Menue2_s.select_square2_strings[3], (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 MyTextureRenderCopy(texture, Menue2_s.render, 150, 675);
 
 //view_square
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, "Chipo       Lv 1", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 MyTextureRenderCopy(texture, Menue2_s.render, 550, 75);
 
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, "        HP 23/23", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 MyTextureRenderCopy(texture, Menue2_s.render, 550, 125);
 
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, "        MP 15/15", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 MyTextureRenderCopy(texture, Menue2_s.render, 550, 170);
 
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, "       ABP 15/15", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 MyTextureRenderCopy(texture, Menue2_s.render, 550, 220);
 
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, "   STR  3  SPD 5", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 MyTextureRenderCopy(texture, Menue2_s.render, 550, 270);
 
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, "   VIT  3  MGC 5", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 MyTextureRenderCopy(texture, Menue2_s.render, 550, 320);
 
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, "   INT  3 LUCK 5", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 MyTextureRenderCopy(texture, Menue2_s.render, 550, 370);
 
 screenSurface = TTF_RenderUTF8_Blended(Menue2_s.font10px, "NextLvUP   8 exp", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(Menue2_s.render, screenSurface);	
 MyTextureRenderCopy(texture, Menue2_s.render, 550, 440);

 
 //サーフェイスを更新
 SDL_UpdateWindowSurface(slaves_window);
     
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
 SDL_DestroyRenderer(Menue2_s.render);
 //window 開放
 SDL_DestroyWindow(slaves_window);  
 SDL_Quit(); // 全てのサブシステムの終了

 return EXIT_SUCCESS;
}
