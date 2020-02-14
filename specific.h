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
#define MyMENUE2SELECT_STRINGSNUM 4
#define MyMENUE2VIEW1_STRINGSNUM 8
#define MyTEXTRENDER_ARRAYNUM 2
#define MyRENDER_X 0
#define MyRENDER_Y 1

//メニュー画面2 レンダリングデータ保持用構造体構造体変数
struct MyStructRenderData {
 SDL_Surface *image; // 画像のサーフェイス
 SDL_Surface *screenSurface; // windowのサーフェイス
 char img_path_name[FILE_NAME_MAX],
 font_path_name[FILE_NAME_MAX],
 select_square_strings[MyMENUE2SELECT_STRINGSNUM][STRINGS_MAX],
 view_square_strings1[MyMENUE2VIEW1_STRINGSNUM][STRINGS_MAX];
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
 //select_square
 char select_square_strings[MyMENUE2SELECT_STRINGSNUM][STRINGS_MAX] = {"つよさ", "そうび", "とくぎ", "アビリティUP"};
 //view_square
 char view_square_strings1[MyMENUE2VIEW1_STRINGSNUM][STRINGS_MAX] = {"Chipo       Lv 1",
	                                                                 "        HP 23/23",
	                                                                 "        MP 15/15",
	                                                                 "       ABP 15/15",
	                                                                 "   STR  3  SPD 5",
	                                                                 "   VIT  3  MGC 5",
	                                                                 "   INT  3 LUCK 5",
	                                                                 "NextLvUP   8 exp"};
 
 
 Menue2_s.user_cursor_position = 0;
 
 MyFuncStringsAssignment(Menue2_s.img_path_name, IMAGE_DIR);
 MyFuncStringsAssignment(Menue2_s.font_path_name, FONT_DIR);
 
 for(i = 0; i <= MyMENUE2SELECT_STRINGSNUM; i++){
  MyFuncStringsAssignment(Menue2_s.select_square_strings[i], select_square_strings[i]);
 };

 for(i = 0; i <= MyMENUE2VIEW1_STRINGSNUM; i++){
  MyFuncStringsAssignment(Menue2_s.view_square_strings1[i], view_square_strings1[i]);
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
 int select_square_xyrxlry[4] = {100, 550, 950, 800},
     view_square_xyrxlry[4] = {500, 50, 950, 500};
  
 MySDLDrawSquare(render, select_square_xyrxlry); //select_square
 MySDLDrawSquare(render, view_square_xyrxlry);   //view_square
};

void MySpeciSelectSquareTexterBleadAndCreateSurface_UserSelecting(struct MyStructRenderData* data_s) {
 data_s->screenSurface = TTF_RenderUTF8_Blended(data_s->font10px, 
                         data_s->select_square_strings[data_s->user_cursor_position],
                         data_s->TTFColor1);  
 data_s->texture = SDL_CreateTextureFromSurface(data_s->render, data_s->screenSurface);
};

void MySpeciSelectSquareTexterBleadAndCreateSurface(struct MyStructRenderData* data_s, unsigned char num) {
  data_s->screenSurface = TTF_RenderUTF8_Blended(data_s->font10px, data_s->select_square_strings[num], data_s->TTFColor2);  
  data_s->texture = SDL_CreateTextureFromSurface(data_s->render, data_s->screenSurface);
};

void MySpeciViewSquareTexterBleadAndCreateSurface(struct MyStructRenderData* data_s, unsigned char num) {
  data_s->screenSurface = TTF_RenderUTF8_Blended(data_s->font10px, data_s->view_square_strings1[num], data_s->TTFColor2);  
  data_s->texture = SDL_CreateTextureFromSurface(data_s->render, data_s->screenSurface);
};

void MySpeciRenderTextMenue2SelectSquare(struct MyStructRenderData* data_s) {
 unsigned char i;
 int xy[MyMENUE2SELECT_STRINGSNUM][MyTEXTRENDER_ARRAYNUM] = {{150, 575},{440, 575},{730, 575},{150, 675}};
 
 //select square
 for(i = 0; i < MyMENUE2SELECT_STRINGSNUM; i++) {
	 
	 if ( i == data_s->user_cursor_position ) {
	  MySpeciSelectSquareTexterBleadAndCreateSurface_UserSelecting(data_s);
	 } else { 
	  MySpeciSelectSquareTexterBleadAndCreateSurface(data_s, i);
     };
     
     MySDLTextureRenderCopy(data_s->texture, data_s->render, xy[i][MyRENDER_X], xy[i][MyRENDER_Y]);
 };
};

void MySpeciRenderTextMenue2ViewSquare(struct MyStructRenderData* data_s) {
 unsigned char i;
 int xy[MyMENUE2VIEW1_STRINGSNUM][MyTEXTRENDER_ARRAYNUM] = {{550,75},{550,125},
	                                                        {550,170},{550,220},
	                                                        {550,270},{550,320},
	                                                        {550,370},{550,440}};
 
 for (i = 0; MyMENUE2VIEW1_STRINGSNUM > i; i++) {
  MySpeciViewSquareTexterBleadAndCreateSurface(data_s, i);
  MySDLTextureRenderCopy(data_s->texture, data_s->render, xy[i][MyRENDER_X], xy[i][MyRENDER_Y]);
 }
};

void MySpeciMenue2UserInput(struct MyStructRenderData* data_s, long sym) {
	
	if (SDLK_UP == sym) {
		if (3 != data_s->user_cursor_position) {
			data_s->user_cursor_position = 3;
		} else {
			data_s->user_cursor_position = 0;
		}
	} else if (SDLK_DOWN == sym) {
		if (0 == data_s->user_cursor_position) {
			data_s->user_cursor_position = 3;
		} else {
			data_s->user_cursor_position = 0;
		}
	} else if (SDLK_RIGHT == sym) {
		if (3 > data_s->user_cursor_position) {
			data_s->user_cursor_position++;
		} else {
			data_s->user_cursor_position = 0;
		}
	} else if (SDLK_LEFT == sym) {
		if (0 < data_s->user_cursor_position) {
			data_s->user_cursor_position--;
		} else {
			data_s->user_cursor_position = 3;
		}
	}
	MySpeciRenderTextMenue2SelectSquare(data_s);
}

void MySpeciMenue2UserInpuLoop(struct MyWindowAndRenderData* data_s) {

 SDL_Event event;
 SDL_bool done = SDL_FALSE;
 
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
	   MySpeciMenue2UserInput(&data_s->Menue2_s, event.key.keysym.sym);
	   SDL_UpdateWindowSurface(data_s->slaves_window);
	  }
   }
  }
 }
 
};

//void () {
//void MySpeciRenderMenue2()
