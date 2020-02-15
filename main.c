#include "function.h"
#include "view.h"
#include "mysdl2.h"
#include "specific.h"

int main(int argc, char* argv[]) {
 // 自己定義型宣言
 struct MyWindowAndRenderData WinAndRender_s;

 //Slaves SDL_Window データ初期化処理
 WinAndRender_s.slaves_window = NULL; // warning 対策
 WinAndRender_s.slaves_window = MySpeciInitSlavesWindow(WinAndRender_s.slaves_window);
 
 //Menue2レンダリング用 サーフェイス取得 表示
 WinAndRender_s.Menue2_s.screenSurface = SDL_GetWindowSurface(WinAndRender_s.slaves_window);
 //サーフェイスの背景を白にする
 SDL_FillRect(WinAndRender_s.Menue2_s.screenSurface, NULL,
              SDL_MapRGB(WinAndRender_s.Menue2_s.screenSurface->format,
                           0xFF, 0xFF, 0xFF));
 
 //画面 Menue2 遷移
 MySpeciMenue2Start(&WinAndRender_s);
 
 /* ... */
 SDL_FreeSurface(WinAndRender_s.Menue2_s.screenSurface);
 SDL_DestroyTexture(WinAndRender_s.Menue2_s.texture);
 SDL_DestroyRenderer(WinAndRender_s.Menue2_s.render);
 //window 開放
 SDL_DestroyWindow(WinAndRender_s.slaves_window);  
 SDL_Quit(); // 全てのサブシステムの終了

 return EXIT_SUCCESS;
}
