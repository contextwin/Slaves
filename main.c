#include "function.h"
#include "view.h"
#include "mysdl2.h"
#include "specific.h"

int main(int argc, char* argv[]) {
 // 自己定義型宣言
 struct MyWindowAndRenderData WinAndRender_s;
 SDL_Event event;
 SDL_bool done = SDL_FALSE;

 //Slaves SDL_Window データ初期化処理
 WinAndRender_s.slaves_window = NULL; // warning 対策
 WinAndRender_s.slaves_window = MySpeciInitSlavesWindow(WinAndRender_s.slaves_window);
 
 //Menue2レンダリング用 サーフェイス取得 表示
 WinAndRender_s.Menue2_s.screenSurface = SDL_GetWindowSurface(WinAndRender_s.slaves_window);
 //サーフェイスの背景を白にする
 SDL_FillRect(WinAndRender_s.Menue2_s.screenSurface, NULL,
              SDL_MapRGB(WinAndRender_s.Menue2_s.screenSurface->format,
                           0xFF, 0xFF, 0xFF));
 //画面 Menue2 データ初期化処理
 WinAndRender_s.Menue2_s = MySpeciInitMenue2(WinAndRender_s.Menue2_s, WinAndRender_s.slaves_window);
 //画面 Menue2 枠描画処理
 MySpeciDrawMenue2Square(WinAndRender_s.Menue2_s.render);
 
 //文字列表示処理
 //select_square TTFの出力文字とカラーを設定、テクスチャーをx,yの座標にレンダーコピー 
 MySpeciRenderTextMenue2Square(&WinAndRender_s.Menue2_s);
 
 //view_square
 WinAndRender_s.Menue2_s.screenSurface = TTF_RenderUTF8_Blended(WinAndRender_s.Menue2_s.font10px, "Chipo       Lv 1", (SDL_Color){0,0,0,0});	  
 WinAndRender_s.Menue2_s.texture = SDL_CreateTextureFromSurface(WinAndRender_s.Menue2_s.render, WinAndRender_s.Menue2_s.screenSurface);	
 MySDLTextureRenderCopy(WinAndRender_s.Menue2_s.texture, WinAndRender_s.Menue2_s.render, 550, 75);
 
 WinAndRender_s.Menue2_s.screenSurface = TTF_RenderUTF8_Blended(WinAndRender_s.Menue2_s.font10px, "        HP 23/23", (SDL_Color){0,0,0,0});	  
 WinAndRender_s.Menue2_s.texture = SDL_CreateTextureFromSurface(WinAndRender_s.Menue2_s.render, WinAndRender_s.Menue2_s.screenSurface);	
 MySDLTextureRenderCopy(WinAndRender_s.Menue2_s.texture, WinAndRender_s.Menue2_s.render, 550, 125);
 
 WinAndRender_s.Menue2_s.screenSurface = TTF_RenderUTF8_Blended(WinAndRender_s.Menue2_s.font10px, "        MP 15/15", (SDL_Color){0,0,0,0});	  
 WinAndRender_s.Menue2_s.texture = SDL_CreateTextureFromSurface(WinAndRender_s.Menue2_s.render, WinAndRender_s.Menue2_s.screenSurface);	
 MySDLTextureRenderCopy(WinAndRender_s.Menue2_s.texture, WinAndRender_s.Menue2_s.render, 550, 170);
 
 WinAndRender_s.Menue2_s.screenSurface = TTF_RenderUTF8_Blended(WinAndRender_s.Menue2_s.font10px, "       ABP 15/15", (SDL_Color){0,0,0,0});	  
 WinAndRender_s.Menue2_s.texture = SDL_CreateTextureFromSurface(WinAndRender_s.Menue2_s.render, WinAndRender_s.Menue2_s.screenSurface);	
 MySDLTextureRenderCopy(WinAndRender_s.Menue2_s.texture, WinAndRender_s.Menue2_s.render, 550, 220);
 
 WinAndRender_s.Menue2_s.screenSurface = TTF_RenderUTF8_Blended(WinAndRender_s.Menue2_s.font10px, "   STR  3  SPD 5", (SDL_Color){0,0,0,0});	  
 WinAndRender_s.Menue2_s.texture = SDL_CreateTextureFromSurface(WinAndRender_s.Menue2_s.render, WinAndRender_s.Menue2_s.screenSurface);	
 MySDLTextureRenderCopy(WinAndRender_s.Menue2_s.texture, WinAndRender_s.Menue2_s.render, 550, 270);
 
 WinAndRender_s.Menue2_s.screenSurface = TTF_RenderUTF8_Blended(WinAndRender_s.Menue2_s.font10px, "   VIT  3  MGC 5", (SDL_Color){0,0,0,0});	  
 WinAndRender_s.Menue2_s.texture = SDL_CreateTextureFromSurface(WinAndRender_s.Menue2_s.render, WinAndRender_s.Menue2_s.screenSurface);	
 MySDLTextureRenderCopy(WinAndRender_s.Menue2_s.texture, WinAndRender_s.Menue2_s.render, 550, 320);
 
 WinAndRender_s.Menue2_s.screenSurface = TTF_RenderUTF8_Blended(WinAndRender_s.Menue2_s.font10px, "   INT  3 LUCK 5", (SDL_Color){0,0,0,0});	  
 WinAndRender_s.Menue2_s.texture = SDL_CreateTextureFromSurface(WinAndRender_s.Menue2_s.render, WinAndRender_s.Menue2_s.screenSurface);	
 MySDLTextureRenderCopy(WinAndRender_s.Menue2_s.texture, WinAndRender_s.Menue2_s.render, 550, 370);
 
 WinAndRender_s.Menue2_s.screenSurface = TTF_RenderUTF8_Blended(WinAndRender_s.Menue2_s.font10px, "NextLvUP   8 exp", (SDL_Color){0,0,0,0});	  
 WinAndRender_s.Menue2_s.texture = SDL_CreateTextureFromSurface(WinAndRender_s.Menue2_s.render, WinAndRender_s.Menue2_s.screenSurface);	
 MySDLTextureRenderCopy(WinAndRender_s.Menue2_s.texture, WinAndRender_s.Menue2_s.render, 550, 440);
 
 //サーフェイスを更新
 SDL_UpdateWindowSurface(WinAndRender_s.slaves_window);
     
 while (!done) {
  while (SDL_PollEvent(&event)) {
   if (event.type == SDL_QUIT) {
	done = SDL_TRUE;
   } else if (event.type == SDL_KEYDOWN) {
      if (event.key.keysym.sym == SDLK_RETURN) {
	   done = SDL_TRUE;
	  } else if (event.key.keysym.sym == SDLK_UP    ||
	             event.key.keysym.sym == SDLK_DOWN  || 
	             event.key.keysym.sym == SDLK_RIGHT ||
	             event.key.keysym.sym == SDLK_LEFT) {
	   MySpeciMenue2UserInput(&WinAndRender_s.Menue2_s, event.key.keysym.sym);
	   SDL_UpdateWindowSurface(WinAndRender_s.slaves_window);
	  }
  }
  }
 }
     
 /* ... */
 SDL_FreeSurface(WinAndRender_s.Menue2_s.screenSurface);
 SDL_DestroyTexture(WinAndRender_s.Menue2_s.texture);
 SDL_DestroyRenderer(WinAndRender_s.Menue2_s.render);
 //window 開放
 SDL_DestroyWindow(WinAndRender_s.slaves_window);  
 SDL_Quit(); // 全てのサブシステムの終了

 return EXIT_SUCCESS;
}
