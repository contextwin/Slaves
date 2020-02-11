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

//メニュー画面2　出力文言
const char select_square2_strings[4][STRINGS_MAX] = {"つよさ", "そうび", "とくぎ", "アビリティUP"};

//メニュー画面2 レンダリングデータ保持用 構造体
struct MyStructMenue2 {
 SDL_Surface *image; // 画像のサーフェイス
 char img_path_name[FILE_NAME_MAX],
 font_path_name[FILE_NAME_MAX],
 select_square2_strings[4][STRINGS_MAX];
 TTF_Font *font12px, // 12px
          *font10px; // 10px
 SDL_Texture *texture;
};

//メニュー画面2 レンダリングデータ初期化処理
struct MyStructMenue2 MyFuncInitMenue2() {
 struct MyStructMenue2 MyMenue2_s;
 
 MyMenue2_s.image = NULL;
 
 memset(MyMenue2_s.img_path_neme, '\0', sizeof(MyMenue2_s.img_path_name));
 memcopy(MyMenue2_s.img_path_name, IMAGE_DIR);
 
 memset(MyMenue2_s.font_path_name, '\0', sizeof(MyMenue2_s.font_path_name));
 memcopy(MyMenue2_s.font_path_name, FONT_DIR);
 
 memset(MyMenue2_s.select_square2_strings, '\0', sizeof(MyMenue2_s.select_square2_strings));
 memcopy(MyMenue2_s.select_square2_strings, select_square2_strings);
 
 
 //TTF初期化
 strcat(MyMenue2_s.font_path_name, TTF_FONT1);
 MyMenue2_s.font12px = MyFuncInitTTF(MyMenue2_s.font12px, MyMenue2_s.font_path_name);
 memset(MyMenue2_s.font_path_name, '\0', sizeof(MyMenue2_s.font_path_name));
 memcpy(MyMenue2_s.font_path_name, FONT_DIR, strlen(FONT_DIR)); 
 strcat(MyMenue2_s.font_path_name, TTF_FONT2);
 MyMenue2_s.font10px = MyFuncInitTTF(MyMenue2_s.font10px, MyMenue2_s.font_path_name);
 
 return MyMenue2_s;
}
