#include "function.h"
#include "view.h"
#include "mysdl2.h"
#include "specific.h"

int main(int argc, char* argv[]) {
 // 自己定義型宣言
 struct MyWindowAndRenderData WinAndRender_s;
 WinAndRender_s.slaves_window = NULL; // warning 対策

 //Slaves SDL_Window データ初期化処理
 MySpeciInitSlavesWindow(&WinAndRender_s);

 //画面 Menue2 遷移開始
 MySpeciMenue2Start(&WinAndRender_s);
	
 return EXIT_SUCCESS;
}
