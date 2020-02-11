#include "mysdl2.h"

int main(int argc, char* argv[]) {
 // 自己定義型宣言
 MyMenue2Struct MyMenue2_s;

 SDL_Event event;
 SDL_Window *window = NULL; // 描画ウィンドウ
 SDL_Surface *screenSurface = NULL; // windowのサーフェイス
 SDL_Surface *image = NULL; // 画像のサーフェイス
 SDL_Rect rect = {100, 600, 850, 200}, scr_rect;
 SDL_Renderer* render;
 TTF_Font *font12px, // 12px
          *font10px; // 10px
 SDL_Texture *texture;
 SDL_bool done = SDL_FALSE;
 
 
 //メニュー2表示処理
 //TTF初期化
 strcat(font_path_name, TTF_FONT1);
 font12px = MyInitTTF(font12px, font_path_name);
 
 memset(font_path_name, '\0', strlen(font_path_name));
 memcpy(font_path_name, FONT_DIR, strlen(FONT_DIR)); 
 
 strcat(font_path_name, TTF_FONT2);
 font10px = MyInitTTF(font10px, font_path_name);
 
 //画像データ読み込み
 strcat(img_path_name, PNG_FILE02);
 image = IMG_Load(img_path_name);
 if(!image){
  printf("IMG_GetError: %s\n", IMG_GetError());
 }
 
 window = SDL_CreateWindow("Slaves", 
                             SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED,
                             MyWIDTH,
                             MyHEIGHT,
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
 
 // 引数1のサーフェイスを引数3のサーフェイスにコピーする
 SDL_BlitSurface(image, NULL, screenSurface, NULL);
   
 SDL_SetRenderDrawColor(render, 0,0,0,0);
 MyDrawSquare(render, 100, 550, 950, 800); //select_square2
 MyDrawSquare(render, 500, 50, 950, 500); //view_square
   
 //文字列表示処理
 //select_square2
 screenSurface = TTF_RenderUTF8_Blended(font10px, select_square2_strings[0], (SDL_Color){0,255,255,255});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	 
 //テクスチャーをx,yの座標にレンダーコピー
 MyTextureRenderCopy(texture, render, 150, 575);
 
 screenSurface = TTF_RenderUTF8_Blended(font10px, select_square2_strings[1], (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 
 MyTextureRenderCopy(texture, render, 440, 575);
 
 screenSurface = TTF_RenderUTF8_Blended(font10px, select_square2_strings[2], (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 730, 575);

 screenSurface = TTF_RenderUTF8_Blended(font10px, select_square2_strings[3], (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 150, 675);
 
 //view_square
 screenSurface = TTF_RenderUTF8_Blended(font10px, "Chipo       Lv 1", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 75);
 
 screenSurface = TTF_RenderUTF8_Blended(font10px, "        HP 23/23", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 125);
 
 screenSurface = TTF_RenderUTF8_Blended(font10px, "        MP 15/15", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 170);
 
 screenSurface = TTF_RenderUTF8_Blended(font10px, "       ABP 15/15", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 220);
 
 screenSurface = TTF_RenderUTF8_Blended(font10px, "   STR  3  SPD 5", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 270);
 
 screenSurface = TTF_RenderUTF8_Blended(font10px, "   VIT  3  MGC 5", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 320);
 
 screenSurface = TTF_RenderUTF8_Blended(font10px, "   INT  3 LUCK 5", (SDL_Color){0,0,0,0});	  
 texture = SDL_CreateTextureFromSurface(render, screenSurface);	
 MyTextureRenderCopy(texture, render, 550, 370);
 
 screenSurface = TTF_RenderUTF8_Blended(font10px, "NextLvUP   8 exp", (SDL_Color){0,0,0,0});	  
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
