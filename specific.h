//Slaves固有の振る舞いのヘッダ

//描画マクロ
#define MyWIDTH (521 * 2) + 1
#define MyHEIGHT 351 * 3

// limt
#define FILE_NAME_MAX 256
#define STRINGS_MAX 256

//ゲーム情報
#define MyGAME_TITLE "Slaves"

//フォントデータ関連マクロ
#define FONT_DIR "./fonts/"
#define TTF_FONT1 "PixelMplus-20130602/PixelMplus12-Regular.ttf"
#define TTF_FONT2 "PixelMplus-20130602/PixelMplus10-Regular.ttf"

//画像データ関連マクロ
#define IMAGE_DIR "./image/"
#define PNG_FILE01 "chipo_center01.png"
#define PNG_FILE02 "chipo_side01.png"

//出力文言データ関連マクロ
#define MyMENUE2_STRINGSNUM 4

SDL_Window* MyFuncSpeciInitSlavesWindow (SDL_Window* window) {
 window = SDL_CreateWindow("Slaves", 
                           SDL_WINDOWPOS_UNDEFINED,
                           SDL_WINDOWPOS_UNDEFINED,
                           MyWIDTH,
                           MyHEIGHT,
                           SDL_WINDOW_SHOWN);
  
 if(window == NULL){
  printf("Window 生成処理失敗. SDL_Error: %s\n", SDL_GetError());
  exit(EXIT_FAILURE);
 }
 return window;
};

/*
//Slaves SDL_Window作成
void MySDLCreateWindowSLaves () {
 struct MyStructSDLWindowData window_data_s;
	
 MyStringsAssignment(window_data_s.title, MyGAME_TITLE);
 window_data_s.x = SDL_WINDOWPOS_UNDEFINED;
 window_data_s.y = SDL_WINDOWPOS_UNDEFINED;
 window_data_s.w = MyWIDTH;
 window_data_s.h = MyHEIGHT;
 window_data_s.flags = SDL_WINDOW_SHOWN;
};
*/

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
struct MyStructMenue2 MyFuncInitMenue2(struct MyStructMenue2 MyMenue2_s) {
 
 unsigned char i = 0;

 //メニュー画面2 出力文言
 char select_square2_strings[MyMENUE2_STRINGSNUM][STRINGS_MAX] = {"つよさ", "そうび", "とくぎ", "アビリティUP"};
 
 MyStringsAssignment(MyMenue2_s.img_path_name, IMAGE_DIR);
 
 MyStringsAssignment(MyMenue2_s.font_path_name, FONT_DIR);
 
 for(i = 0; i <= MyMENUE2_STRINGSNUM; i++){
  MyStringsAssignment(MyMenue2_s.select_square2_strings[i], select_square2_strings[i]);
 }
 
 MyMenue2_s.image = NULL;
 strcat(MyMenue2_s.img_path_name, PNG_FILE02);
 
 //画像データ読み込み
 MyMenue2_s.image = IMG_Load(MyMenue2_s.img_path_name);
 if(!MyMenue2_s.image){
  printf("IMG_GetError: %s\n", IMG_GetError());
 }

 //TTF初期化
 strcat(MyMenue2_s.font_path_name, TTF_FONT1);
 MyMenue2_s.font12px = MyFuncInitTTF(MyMenue2_s.font12px, MyMenue2_s.font_path_name);
 memset(MyMenue2_s.font_path_name, '\0', sizeof(MyMenue2_s.font_path_name));
 memcpy(MyMenue2_s.font_path_name, FONT_DIR, strlen(FONT_DIR)); 
 strcat(MyMenue2_s.font_path_name, TTF_FONT2);
 MyMenue2_s.font10px = MyFuncInitTTF(MyMenue2_s.font10px, MyMenue2_s.font_path_name);
 
 return MyMenue2_s;
}
