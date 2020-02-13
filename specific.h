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
#define MyRENDER_X 0
#define MyRENDER_Y 1

//メニュー画面2 レンダリングデータ保持用構造体構造体変数
struct MyStructRenderData {
 SDL_Surface *image; // 画像のサーフェイス
 SDL_Surface *screenSurface; // windowのサーフェイス
 char img_path_name[FILE_NAME_MAX],
 font_path_name[FILE_NAME_MAX],
 select_square2_strings[MyMENUE2_STRINGSNUM][STRINGS_MAX];
 TTF_Font *font12px, // 12px
          *font10px; // 10px
 SDL_Texture *texture;
 SDL_Color TTFColor1,
           TTFColor2;
 unsigned char user_cursor_position;
 SDL_Renderer* render;
};

//SDL_Window データと各画面レンダリングデータ保持用構造体変数
struct MyWindowAndRenderData {
	SDL_Window* slaves_window;
	struct MyStructRenderData Menue2_s;
};

SDL_Window* MySpeciInitSlavesWindow (SDL_Window* window) {
 window = SDL_CreateWindow("Slaves", 
                           SDL_WINDOWPOS_UNDEFINED,
                           SDL_WINDOWPOS_UNDEFINED,
                           MyWIDTH,
                           MyHEIGHT,
                           SDL_WINDOW_SHOWN);
  
 if(window == NULL){
  printf("Window 生成処理失敗. SDL_Error: %s\n", SDL_GetError());
  exit(EXIT_FAILURE);
 };
 return window;
};

//メニュー画面2 レンダリングデータ初期化処理
struct MyStructRenderData MySpeciInitMenue2(struct MyStructRenderData Menue2_s, SDL_Window* window) {
 
 unsigned char i = 0;

 //メニュー画面2 出力文言
 char select_square2_strings[MyMENUE2_STRINGSNUM][STRINGS_MAX] = {"つよさ", "そうび", "とくぎ", "アビリティUP"};
 
 Menue2_s.user_cursor_position = 0;
 
 MyFuncStringsAssignment(Menue2_s.img_path_name, IMAGE_DIR);
 MyFuncStringsAssignment(Menue2_s.font_path_name, FONT_DIR);
 
 for(i = 0; i <= MyMENUE2_STRINGSNUM; i++){
  MyFuncStringsAssignment(Menue2_s.select_square2_strings[i], select_square2_strings[i]);
 };

 Menue2_s.image = NULL;
 strcat(Menue2_s.img_path_name, PNG_FILE02);
 
 //画像データ読み込み
 Menue2_s.image = IMG_Load(Menue2_s.img_path_name);
 if(!Menue2_s.image){
  printf("IMG_GetError: %s\n", IMG_GetError());
 };

 //TTF初期化
 strcat(Menue2_s.font_path_name, TTF_FONT1);
 Menue2_s.font12px = MyFuncInitTTF(Menue2_s.font12px, Menue2_s.font_path_name);
 MyFuncStringsAssignment(Menue2_s.font_path_name, FONT_DIR);
 strcat(Menue2_s.font_path_name, TTF_FONT2);
 Menue2_s.font10px = MyFuncInitTTF(Menue2_s.font10px, Menue2_s.font_path_name);
 
 //SDL_Renderer 初期化
 Menue2_s.render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
 SDL_SetRenderDrawColor(Menue2_s.render, 0,0,0,0);
 
 //引数1のサーフェイスを引数3のサーフェイスにコピーする
 SDL_BlitSurface(Menue2_s.image, NULL, Menue2_s.screenSurface, NULL);
  
 Menue2_s.TTFColor1.r = 0;
 Menue2_s.TTFColor1.g = 255;
 Menue2_s.TTFColor1.b = 255;
 Menue2_s.TTFColor1.a = 255;
 
 Menue2_s.TTFColor2.r = 0;
 Menue2_s.TTFColor2.g = 0;
 Menue2_s.TTFColor2.b = 0;
 Menue2_s.TTFColor2.a = 0;

 return Menue2_s;
};

void MySpeciDrawMenue2Square(SDL_Renderer* render) {
 int select_square2_xyrxlry[4] = {100, 550, 950, 800},
     view_square_xyrxlry[4] = {500, 50, 950, 500};
  
 MySDLDrawSquare(render, select_square2_xyrxlry); //select_square2
 MySDLDrawSquare(render, view_square_xyrxlry);  //view_square
};

void MySpeciTexterBleadAndCreateSurface_UserSelecting(struct MyStructRenderData* data_s) {
 data_s->screenSurface = TTF_RenderUTF8_Blended(data_s->font10px, 
                         data_s->select_square2_strings[data_s->user_cursor_position],
                         data_s->TTFColor1);  
 data_s->texture = SDL_CreateTextureFromSurface(data_s->render, data_s->screenSurface);
};

void MySpeciTexterBleadAndCreateSurface(struct MyStructRenderData* data_s, unsigned char num) {
  data_s->screenSurface = TTF_RenderUTF8_Blended(data_s->font10px, data_s->select_square2_strings[num], data_s->TTFColor2);  
  data_s->texture = SDL_CreateTextureFromSurface(data_s->render, data_s->screenSurface);
};

void MySpeciRenderTextMenue2Square(struct MyStructRenderData* data_s) {
 unsigned char i;
 int xy[MyMENUE2_STRINGSNUM][2] ={{150, 575,},{440, 575},{730, 575},{150, 675}};
 
 for(i = 0; i < MyMENUE2_STRINGSNUM; i++) {
	 
	 if ( i == data_s->user_cursor_position ) {
	  MySpeciTexterBleadAndCreateSurface_UserSelecting(data_s);
	 } else { 
	  MySpeciTexterBleadAndCreateSurface(data_s, i);
     }
     MySDLTextureRenderCopy(data_s->texture, data_s->render, xy[i][MyRENDER_X], xy[i][MyRENDER_Y]);
 }
 
};


//void MyspeciCreateSlavesMainWindow()
