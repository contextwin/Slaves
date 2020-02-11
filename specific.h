//Slaves固有の振る舞いのヘッダ
//#include "mysdl2.h"

//描画マクロ
#define MyWIDTH (521 * 2) + 1
#define MyHEIGHT 351 * 3

// limt
#define FILE_NAME_MAX 256
#define STRINGS_MAX 256

//フォントデータ関連マクロ
#define FONT_DIR "./fonts/"
#define TTF_FONT1 "PixelMplus-20130602/PixelMplus12-Regular.ttf"
#define TTF_FONT2 "PixelMplus-20130602/PixelMplus10-Regular.ttf"

//画像データ関連マクロ
#define IMAGE_DIR "./image/"
#define PNG_FILE01 "chipo_center01.png"
#define PNG_FILE02 "chipo_side01.png"

//メニュー画面2 レンダリングデータ保持用 構造体
struct MyStructMenue2 {
SDL_Surface *image = NULL; // 画像のサーフェイス
char img_path_name[FILE_NAME_MAX] = IMAGE_DIR,
 font_path_name[FILE_NAME_MAX] = FONT_DIR,
 select_square2_strings[4][STRINGS_MAX] = {"つよさ", "そうび", "とくぎ", "アビリティUP"};
 SDL_Rect rect = {100, 600, 850, 200}, scr_rect;
 SDL_Renderer* render;
 TTF_Font *font12px, // 12px
          *font10px; // 10px
 SDL_Texture *texture;
}

//メニュー画面2 レンダリングデータ初期化処理
short int MyFuncInitMenue2(struct MyStructMenue2 MyMenue2_s) {
 //TTF初期化
 strcat(font_path_name, TTF_FONT1);
 font12px = MyFuncInitTTF(font12px, font_path_name);
 memset(font_path_name, '\0', strlen(font_path_name));
 memcpy(font_path_name, FONT_DIR, strlen(FONT_DIR)); 
 strcat(font_path_name, TTF_FONT2);
 font10px = MyFuncInitTTF(font10px, font_path_name);
 
 return EXIT_SUCCESS;
}
