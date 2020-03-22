//Slaves固有の振る舞いのヘッダ

//描画マクロ
#define MyROOT_NUM 59
#define MyPADDING 1
#define MyMAXDIVISIONALIA_5 5
#define MyMAXDIVISIONALIA_6 6
#define MySpeciAddPixelSize(n) (MyROOT_NUM + ((n - 1) * (MyROOT_NUM + MyPADDING)))
#define MyWIDTH MySpeciAddPixelSize(13) // 779 (0 ~ 778)
#define MyHEIGHT MySpeciAddPixelSize(10) // 599 (0 ~ 598)
#define MyGetFirstDivisionPixel_5(n) ((n / MyMAXDIVISIONALIA_5) + MyPADDING) 
#define MyGetFirstDivisionPixel_6(n) ((n / MyMAXDIVISIONALIA_6) + MyPADDING)
#define MyFIRSTDIVISIONPIXEL5_X (MyGetFirstDivisionPixel_5(MyWIDTH)) //  5分割=155
#define MyFIRSTDIVISIONPIXEL5_Y (MyGetFirstDivisionPixel_5(MyHEIGHT)) // 5分割=119
#define MyFIRSTDIVISIONPIXEL6_X (MyGetFirstDivisionPixel_6(MyWIDTH)) //  6分割=129
#define MyFIRSTDIVISIONPIXEL6_Y (MyGetFirstDivisionPixel_6(MyHEIGHT)) // 6分割 =99

#define MyMENUE2SELECTSQUARE6_X (MyFIRSTDIVISIONPIXEL6_X / 4)
#define MyMENUE2SELECTSQUARE6_Y (MyFIRSTDIVISIONPIXEL6_Y * 4) - ((MyFIRSTDIVISIONPIXEL6_Y / 4) - 1)
#define MyMENUE2VIEWSQUARE6_X MyFIRSTDIVISIONPIXEL6_X * 3
#define MyMENUE2VIEWSQUARE6_Y (MyFIRSTDIVISIONPIXEL6_Y / 4) + 1

// limt
#define FILE_NAME_MAX 256
#define STRINGS_MAX 256

//ゲーム情報
#define MyGAME_TITLE "Slaves"

//フォントデータ関連マクロ
#define FONT_DIR "./fonts/"
#define TTF_FONT1 "PixelMplus-20130602/PixelMplus10-Regular.ttf"
#define TTF_FONT2 "ipaexm00201/ipaexm.ttf"
#define FIXED 0 // 固定値
#define DYNAMIC 1 // 変動値
//#define TTF_FONT1 "BauhausModern/BauhausModern-Regular.ttf"
//#define TTF_FONT1 "ipaexg00201/ipaexg.ttf"
//#define TTF_FONT1 "RictyDiminished-for-Powerline/RictyDiminished-Regular.ttf"
//#define TTF_FONT1 "JF-Dot-Shinomoe14/JF-Dot-Shinonome14.ttf"

//画像データ関連マクロ
#define IMAGE_DIR "./image/"
#define PNG_FILE01 "chipo_center01.png"
#define PNG_FILE02 "chipo_side_75.png"

//色指定関連マクロ & 広域変数
#define MyRGBCOLOR_ARRYNUM 4
int line_color[MyRGBCOLOR_ARRYNUM] = {0, 0, 0, 0};
int fill_color[MyRGBCOLOR_ARRYNUM] = {255, 255, 255, 255};

//出力文言データ関連マクロ
#define MyMENUE2SELECT_STRINGSNUM 4
#define MyMENUE2VIEW1_STRINGSNUM 8
#define MyTEXTRENDER_ARRAYNUM 2
#define MySQUARESIZE_ARRYNUM 4
#define MyRENDER_X 0
#define MyRENDER_Y 1

//メニュー画面2 レンダリングデータ保持用構造体構造体変数
struct MyStructRenderData {
 SDL_Surface *image; // 画像のサーフェイス
 SDL_Surface *screenSurface; // windowのサーフェイス
 char img_path_name[FILE_NAME_MAX],
 font_path_name[FILE_NAME_MAX],
 select_square_strings[STRINGS_MAX][STRINGS_MAX],
 view_square_strings[STRINGS_MAX][STRINGS_MAX];
 TTF_Font *font_data[STRINGS_MAX];
 SDL_Texture *texture;
 SDL_Color TTFColor1,
           TTFColor2;
 unsigned char user_cursor_position;
 SDL_Renderer* render;
};

//SDL_Window データと各画面レンダリングデータ保持用構造体変数
struct MyWindowAndRenderData {
	SDL_Window* slaves_window;
    struct MyStructRenderData Menue1_s, Menue2_s;
};

void MySpeciInitSlavesWindow (struct MyWindowAndRenderData* data_s) {
 data_s->slaves_window = SDL_CreateWindow("Slaves", 
                           SDL_WINDOWPOS_UNDEFINED,
                           SDL_WINDOWPOS_UNDEFINED,
                           MyWIDTH,
                           MyHEIGHT,
                           SDL_WINDOW_SHOWN);
 
 if(data_s->slaves_window == NULL){
  printf("Window 生成処理失敗. SDL_Error: %s\n", SDL_GetError());
  exit(EXIT_FAILURE);
 };
      
};

//メニュー画面1 レンダリングデータ初期化処理
struct MyStructRenderData MySpeciInitMenue1(struct MyStructRenderData Menue1_s, SDL_Window* slaves_window) {

 //Menue画面1 レンダリング用 サーフェイス取得 表示
 Menue1_s.screenSurface = SDL_GetWindowSurface(slaves_window);
                   
 Menue1_s.user_cursor_position = 0;

 //Menue画面1 レンダリング用 サーフェイス取得 表示
 Menue1_s.screenSurface = SDL_GetWindowSurface(slaves_window);
 
 //サーフェイスの背景を白にする
 SDL_FillRect(Menue1_s.screenSurface, NULL,
              SDL_MapRGB(Menue1_s.screenSurface->format,
                         0xFF, 0xFF, 0xFF)); 
                         //  95, 95, 95)); 

 MyFuncStringsAssignment(Menue1_s.img_path_name, IMAGE_DIR);
 MyFuncStringsAssignment(Menue1_s.font_path_name, FONT_DIR);           
 
 Menue1_s.image = NULL;
 strcat(Menue1_s.img_path_name, PNG_FILE01);
 
 //画像データ読み込み
 Menue1_s.image = IMG_Load(Menue1_s.img_path_name);
 if(!Menue1_s.image){
  printf("IMG_GetError: %s\n", IMG_GetError());
 };

 //TTF初期化
 strcat(Menue1_s.font_path_name, TTF_FONT1);
 Menue1_s.font_data[0] = MySDLInitTTF(Menue1_s.font_data[0], Menue1_s.font_path_name);
 MyFuncStringsAssignment(Menue1_s.font_path_name, FONT_DIR);
 strcat(Menue1_s.font_path_name, TTF_FONT2);
 Menue1_s.font_data[1] = MySDLInitTTF(Menue1_s.font_data[1], Menue1_s.font_path_name);

 //SDL_Renderer 初期化
 Menue1_s.render = SDL_CreateRenderer(slaves_window, -1, SDL_RENDERER_SOFTWARE);
 SDL_SetRenderDrawColor(Menue1_s.render, 0,0,0,0);
  
 Menue1_s.TTFColor1.r = 0;
 Menue1_s.TTFColor1.g = 255;
 Menue1_s.TTFColor1.b = 255;
 Menue1_s.TTFColor1.a = 255;
 
 Menue1_s.TTFColor2.r = 0;
 Menue1_s.TTFColor2.g = 0;
 Menue1_s.TTFColor2.b = 0;
 Menue1_s.TTFColor2.a = 0;

 return Menue1_s;
 
};

//メニュー画面2 レンダリングデータ初期化処理
struct MyStructRenderData MySpeciInitMenue2(struct MyStructRenderData Menue2_s, SDL_Window* slaves_window) {
 
 unsigned char i = 0;

 //メニュー画面2 出力文言
 //select_square
 char select_square_strings[MyMENUE2SELECT_STRINGSNUM][STRINGS_MAX] = {"つよさ", "そうび", "とくぎ", "アビリティUP"};
 //view_square
 char view_square_strings[2][MyMENUE2VIEW1_STRINGSNUM][STRINGS_MAX] = {
	                                                                    // 固定値
	                                                                   {"Chipo         Lv 1",
	                                                                   "        HP  23/ 23",
	                                                                   "        MP  15/ 15",
	                                                                   "       ABP  15/ 15",
	                                                                   "    STR  3  SPD  5",
	                                                                   "    VIT  3  MGC  5",
	                                                                   "    INT  3 LUCK  5",
	                                                                   "NextLvUP     8 exp"},
	                                                                   // 変動値
	                                                                   {}};
 
 //サーフェイス取得
 Menue2_s.screenSurface = SDL_GetWindowSurface(slaves_window);
 SDL_FillRect(Menue2_s.screenSurface, NULL,
              SDL_MapRGB(Menue2_s.screenSurface->format,
                           0xFF, 0xFF, 0xFF));

 Menue2_s.user_cursor_position = 0;
 
 MyFuncStringsAssignment(Menue2_s.img_path_name, IMAGE_DIR);
 MyFuncStringsAssignment(Menue2_s.font_path_name, FONT_DIR);
 
 for(i = 0; i <= MyMENUE2SELECT_STRINGSNUM; i++){
  MyFuncStringsAssignment(Menue2_s.select_square_strings[i], select_square_strings[i]);
 };

 for(i = 0; i <= MyMENUE2VIEW1_STRINGSNUM; i++){
  MyFuncStringsAssignment(Menue2_s.view_square_strings[i], view_square_strings[FIXED][i]);
 };
 
 Menue2_s.image = NULL;
 strcat(Menue2_s.img_path_name, PNG_FILE02);
 
 //画像データ読み込み
 Menue2_s.image = IMG_Load(Menue2_s.img_path_name);
 if(!Menue2_s.image){
  printf("IMG_GetError: %s\n", IMG_GetError());
 };
 
 //引数1のサーフェイスを引数3のサーフェイスにコピーする
 SDL_BlitSurface(Menue2_s.image, NULL, Menue2_s.screenSurface, NULL);

 //TTF初期化
 strcat(Menue2_s.font_path_name, TTF_FONT1);
 Menue2_s.font_data[0] = MySDLInitTTF(Menue2_s.font_data[0], Menue2_s.font_path_name);
 MyFuncStringsAssignment(Menue2_s.font_path_name, FONT_DIR);
 strcat(Menue2_s.font_path_name, TTF_FONT2);
 Menue2_s.font_data[1] = MySDLInitTTF(Menue2_s.font_data[1], Menue2_s.font_path_name);
 
 //SDL_Renderer 初期化
 Menue2_s.render = SDL_CreateRenderer(slaves_window, -1, SDL_RENDERER_SOFTWARE);
 SDL_SetRenderDrawColor(Menue2_s.render, 0,0,0,0);
  
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
 int select_square_xyrxlry[MySQUARESIZE_ARRYNUM] = {MyMENUE2SELECTSQUARE6_X, 
	                             MyMENUE2SELECTSQUARE6_Y, 
	                             ((MyFIRSTDIVISIONPIXEL6_X * 5) + (MyFIRSTDIVISIONPIXEL6_X - (MyFIRSTDIVISIONPIXEL6_X / 4))),
	                             ((MyFIRSTDIVISIONPIXEL6_Y * 5) + ((MyFIRSTDIVISIONPIXEL6_Y / 1.5) + 1))},
	                             
     view_square_xyrxlry[MySQUARESIZE_ARRYNUM] = {MyMENUE2VIEWSQUARE6_X,
		                       MyMENUE2VIEWSQUARE6_Y, 
		                       ((MyFIRSTDIVISIONPIXEL6_X * 5) + ((MyFIRSTDIVISIONPIXEL6_X / 2) + 1)), 
		                       (MyFIRSTDIVISIONPIXEL6_Y * 3) + ((MyFIRSTDIVISIONPIXEL6_Y / 2) + 1)};
  
 MySDLDrawSquare(render, select_square_xyrxlry); //select_square
 MySDLDrawSquare(render, view_square_xyrxlry);   //view_square
};

void MySpeciSelectSquareTexterBleadAndCreateSurface_UserSelecting(struct MyStructRenderData* data_s) {
 data_s->screenSurface = TTF_RenderUTF8_Blended(data_s->font_data[0], 
                         data_s->select_square_strings[data_s->user_cursor_position],
                         data_s->TTFColor1);  
 data_s->texture = SDL_CreateTextureFromSurface(data_s->render, data_s->screenSurface);
};

void MySpeciSelectSquareTexterBleadAndCreateSurface(struct MyStructRenderData* data_s, unsigned char num) {
  data_s->screenSurface = TTF_RenderUTF8_Blended(data_s->font_data[0], data_s->select_square_strings[num], data_s->TTFColor2);  
  data_s->texture = SDL_CreateTextureFromSurface(data_s->render, data_s->screenSurface);
};

void MySpeciViewSquareTexterBleadAndCreateSurface(struct MyStructRenderData* data_s, unsigned char num) {
  data_s->screenSurface = TTF_RenderUTF8_Blended(data_s->font_data[0], data_s->view_square_strings[num], data_s->TTFColor2);  
  data_s->texture = SDL_CreateTextureFromSurface(data_s->render, data_s->screenSurface);
 // data_s->screenSurface = TTF_RenderUTF8_Blended(data_s->font_data[1], data_s->view_square_strings[num], data_s->TTFColor2);  
 // data_s->texture = SDL_CreateTextureFromSurface(data_s->render, data_s->screenSurface);
};

void MySpeciRenderTextMenue2SelectSquare(struct MyStructRenderData* data_s) {
 int x_num = (MyMENUE2SELECTSQUARE6_X + 50), y_num = ((MyMENUE2SELECTSQUARE6_Y) + 20);
 unsigned char i;
 
 int xy[MyMENUE2SELECT_STRINGSNUM][MyTEXTRENDER_ARRAYNUM];

 for (i = 0; i < MyMENUE2SELECT_STRINGSNUM; i++) {
  xy[i][0] = x_num;
  xy[i][1] = y_num;
  
  if (i == 2) {
   x_num = (MyMENUE2SELECTSQUARE6_X + 50);
   y_num = y_num + 70;
  } else {
   x_num = (x_num + 240);
  }
 }
 	 
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
 int x_num = (MyMENUE2VIEWSQUARE6_X + 29), y_num = ((MyMENUE2VIEWSQUARE6_Y) + 10);
 unsigned char i;
 
 int xy[MyMENUE2VIEW1_STRINGSNUM][MyTEXTRENDER_ARRAYNUM];

 for (i = 0; i < MyMENUE2VIEW1_STRINGSNUM; i++) {
	 xy[i][0] = x_num;
	 xy[i][1] = y_num;
	 y_num = y_num + 37;
 }
 
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

void MySpeciResourceRelease(struct MyStructRenderData* data_s) {
 SDL_FreeSurface(data_s->screenSurface);
 SDL_DestroyTexture(data_s->texture);
 SDL_DestroyRenderer(data_s->render);
}
	
void MySpeciCloseSlavesWindow(struct MyWindowAndRenderData* data_s) {
 SDL_DestroyWindow(data_s->slaves_window);  
 SDL_Quit(); // 全てのサブシステムの終了
 exit(EXIT_SUCCESS);
}

void MySpeciMenue1UserInpuLoop(struct MyWindowAndRenderData* data_s) {

 SDL_Event event;
 SDL_bool done = SDL_FALSE;
 
 while (!done) {
  while (SDL_PollEvent(&event)) {
   if (event.type == SDL_QUIT) {
	MySpeciResourceRelease(&data_s->Menue1_s);
	MySpeciCloseSlavesWindow(data_s);
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

void MySpeciMenue2UserInpuLoop(struct MyWindowAndRenderData* data_s) {

 SDL_Event event;
 SDL_bool done = SDL_FALSE;
 
 while (!done) {
  while (SDL_PollEvent(&event)) {
   if (event.type == SDL_QUIT) {
    MySpeciResourceRelease(&data_s->Menue1_s);
	MySpeciCloseSlavesWindow(data_s);
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

void MySpeciDrawMenue1BackGround(struct MyStructRenderData* data_s) {

 MySDLDrawCircle(data_s->render, MyFIRSTDIVISIONPIXEL5_X + (MyFIRSTDIVISIONPIXEL5_X / 2),
                                                   (MyFIRSTDIVISIONPIXEL5_Y * 3),
                                                   (158 / 2));
 MySDLDrawCircle(data_s->render, MyFIRSTDIVISIONPIXEL5_X + (MyFIRSTDIVISIONPIXEL5_X / 2) * 3,
                                                   (MyFIRSTDIVISIONPIXEL5_Y * 3),
                                                   (158 / 2));
 MySDLDrawCircle(data_s->render, MyFIRSTDIVISIONPIXEL5_X + (MyFIRSTDIVISIONPIXEL5_X / 2) * 5,
                                                   (MyFIRSTDIVISIONPIXEL5_Y * 3),
                                                   (158 / 2));

 // ロマネスクアーチ塗りつぶし
 MySDLSetDrawColor(data_s->render, fill_color);
 SDL_Rect rect2 = (SDL_Rect){MyFIRSTDIVISIONPIXEL5_X,(MyFIRSTDIVISIONPIXEL5_Y * 3),MyFIRSTDIVISIONPIXEL5_X,200};
 SDL_RenderFillRect(data_s->render,&rect2);
 rect2 = (SDL_Rect){(MyFIRSTDIVISIONPIXEL5_X * 2),(MyFIRSTDIVISIONPIXEL5_Y * 3),MyFIRSTDIVISIONPIXEL5_X,200};
 SDL_RenderFillRect(data_s->render,&rect2);
 rect2 = (SDL_Rect){(MyFIRSTDIVISIONPIXEL5_X * 3),(MyFIRSTDIVISIONPIXEL5_Y * 3),MyFIRSTDIVISIONPIXEL5_X,200};
 SDL_RenderFillRect(data_s->render,&rect2);

// MySDLSetDrawColor(data_s->render, line_color);
// SDL_RenderDrawLine(data_s->render, 0, (MyFIRSTDIVISIONPIXEL5_Y), MyWIDTH, (MyFIRSTDIVISIONPIXEL5_Y * 4));

 // 画像描画
 MySDLSetDrawColor(data_s->render, line_color);
 SDL_Rect rect;
 rect.x = MyFIRSTDIVISIONPIXEL5_X;
 rect.y = (MyFIRSTDIVISIONPIXEL5_Y * 3);            
 SDL_BlitSurface(data_s->image, NULL, data_s->screenSurface, &rect);
 
 // キャラ選択ロマネスアーチ部                                                  
 SDL_RenderDrawLine(data_s->render, MyFIRSTDIVISIONPIXEL5_X, (MyFIRSTDIVISIONPIXEL5_Y * 3), MyFIRSTDIVISIONPIXEL5_X, MyHEIGHT);
 SDL_RenderDrawLine(data_s->render, (MyFIRSTDIVISIONPIXEL5_X * 2), (MyFIRSTDIVISIONPIXEL5_Y * 3), (MyFIRSTDIVISIONPIXEL5_X * 2), MyHEIGHT);
 SDL_RenderDrawLine(data_s->render, (MyFIRSTDIVISIONPIXEL5_X * 3), (MyFIRSTDIVISIONPIXEL5_Y * 3), (MyFIRSTDIVISIONPIXEL5_X * 3), MyHEIGHT);
 SDL_RenderDrawLine(data_s->render, (MyFIRSTDIVISIONPIXEL5_X * 4), (MyFIRSTDIVISIONPIXEL5_Y * 3), (MyFIRSTDIVISIONPIXEL5_X * 4), MyHEIGHT);
 
 SDL_RenderDrawLine(data_s->render, (MyFIRSTDIVISIONPIXEL5_X /2), (MyFIRSTDIVISIONPIXEL5_Y * 2),
                                    (MyFIRSTDIVISIONPIXEL5_X /2), MyHEIGHT);
 SDL_RenderDrawLine(data_s->render, (MyFIRSTDIVISIONPIXEL5_X * 4) + (MyFIRSTDIVISIONPIXEL5_X /2), (MyFIRSTDIVISIONPIXEL5_Y * 2),
                                    (MyFIRSTDIVISIONPIXEL5_X * 4) + (MyFIRSTDIVISIONPIXEL5_X /2), MyHEIGHT);
 
 MySDLDrawCircle(data_s->render, (MyFIRSTDIVISIONPIXEL5_X / 2),
                                                   (MyFIRSTDIVISIONPIXEL5_Y * 2) - (MyFIRSTDIVISIONPIXEL5_Y / 2),
                                                   (60));
 MySDLDrawCircle(data_s->render, (MyFIRSTDIVISIONPIXEL5_X * 4) + (MyFIRSTDIVISIONPIXEL5_X /2),
                                                   (MyFIRSTDIVISIONPIXEL5_Y * 2) - (MyFIRSTDIVISIONPIXEL5_Y / 2),
                                                   (60));
 SDL_RenderDrawLine(data_s->render, (MyFIRSTDIVISIONPIXEL5_X / 2) + 60, (MyFIRSTDIVISIONPIXEL5_Y * 2) - (MyFIRSTDIVISIONPIXEL5_Y / 2), (((MyFIRSTDIVISIONPIXEL5_X * 4) + (MyFIRSTDIVISIONPIXEL5_X /2)) - 60), (MyFIRSTDIVISIONPIXEL5_Y * 2) - (MyFIRSTDIVISIONPIXEL5_Y / 2));

 MySDLSetDrawColor(data_s->render, fill_color);
 rect2 = (SDL_Rect){0, (MyFIRSTDIVISIONPIXEL5_Y), (MyFIRSTDIVISIONPIXEL5_X /2), 200};
 SDL_RenderFillRect(data_s->render,&rect2);
 rect2 = (SDL_Rect){0, (MyFIRSTDIVISIONPIXEL5_Y), (MyFIRSTDIVISIONPIXEL5_X), 60};
 SDL_RenderFillRect(data_s->render,&rect2);
 
 // 下部丸め
 MySDLSetDrawColor(data_s->render, line_color);
 /*MySDLDrawCircle(data_s->render, (MyFIRSTDIVISIONPIXEL5_X /2) + 59,
                (MyFIRSTDIVISIONPIXEL5_Y * 3) - 59,
                (60));*/
 MySDLSetDrawColor(data_s->render, fill_color);
 
 rect2 = (SDL_Rect){(((MyFIRSTDIVISIONPIXEL5_X * 4) + (MyFIRSTDIVISIONPIXEL5_X /2)) + 1),
	     ((MyFIRSTDIVISIONPIXEL5_Y)), (MyFIRSTDIVISIONPIXEL5_X /2), 200};
 SDL_RenderFillRect(data_s->render,&rect2); 
 rect2 = (SDL_Rect){(MyFIRSTDIVISIONPIXEL5_X * 4),
	     (MyFIRSTDIVISIONPIXEL5_Y), (MyFIRSTDIVISIONPIXEL5_X), 60};
 SDL_RenderFillRect(data_s->render,&rect2);

 // userl_select レンダリング	                   
 int square_xyrxly[MySQUARESIZE_ARRYNUM] = { MyFIRSTDIVISIONPIXEL5_X + (MyFIRSTDIVISIONPIXEL5_X / 2),
	                   (MyFIRSTDIVISIONPIXEL6_Y / 3),
	                   MyFIRSTDIVISIONPIXEL5_X + (MyFIRSTDIVISIONPIXEL5_X / 2) * 5,
	                   (MyFIRSTDIVISIONPIXEL6_Y * 2.5)};
 MySDLDrawSquareAndFill(data_s->render, square_xyrxly, line_color, fill_color);
 MySDLDrawCircle(data_s->render, square_xyrxly[0] + 59,
                square_xyrxly[1] + 59,
                (60));
 MySDLDrawCircle(data_s->render, square_xyrxly[2] - 59,
                square_xyrxly[1] + 59,
                (60));
 
 // 丸角塗りつぶし処理
 MySDLSetDrawColor(data_s->render, fill_color);
 SDL_RenderDrawLine(data_s->render, square_xyrxly[0], square_xyrxly[1], square_xyrxly[0] + 47, square_xyrxly[1]);
 SDL_RenderDrawLine(data_s->render, square_xyrxly[0], square_xyrxly[1], square_xyrxly[0], square_xyrxly[1] + 47);
 SDL_RenderDrawLine(data_s->render, square_xyrxly[2] - 46, square_xyrxly[1] , square_xyrxly[2], square_xyrxly[1]);
 SDL_RenderDrawLine(data_s->render, square_xyrxly[2], square_xyrxly[1], square_xyrxly[2], square_xyrxly[1] + 47);

 square_xyrxly[0] = (square_xyrxly[0] + 1);
 square_xyrxly[1] = (square_xyrxly[1] + 48);
 square_xyrxly[2] = (square_xyrxly[2] - 1);
 square_xyrxly[3] = (square_xyrxly[3] - 1);
 MySDLDrawSquareAndFill(data_s->render, square_xyrxly, fill_color, fill_color);

 square_xyrxly[0] = (square_xyrxly[0] + 47);
 square_xyrxly[1] = (square_xyrxly[1] - 47);
 square_xyrxly[2] = (square_xyrxly[2] - 46);
 MySDLDrawSquareAndFill(data_s->render, square_xyrxly, fill_color, fill_color);
                
 // 通貨表示ウィンドウ レンダリング
 square_xyrxly[0] = ((MyFIRSTDIVISIONPIXEL5_X * 4) + 5);
 square_xyrxly[1] = (MyFIRSTDIVISIONPIXEL6_Y * 2);
 square_xyrxly[2] = (MyWIDTH - 5);
 square_xyrxly[3] = ((MyFIRSTDIVISIONPIXEL6_Y * 4) + (MyFIRSTDIVISIONPIXEL6_Y / 2));
 MySDLDrawSquareAndFill(data_s->render, square_xyrxly, line_color, fill_color);
 
 MySDLDrawCircle(data_s->render, square_xyrxly[2] - 59,
                square_xyrxly[1] + 59,
                (60));
 // 丸角塗りつぶし処理
 MySDLSetDrawColor(data_s->render, fill_color);
 SDL_RenderDrawLine(data_s->render, square_xyrxly[2] - 46, square_xyrxly[1], square_xyrxly[2], square_xyrxly[1]);
 SDL_RenderDrawLine(data_s->render, square_xyrxly[2], square_xyrxly[1], square_xyrxly[2], square_xyrxly[1] + 47);

 square_xyrxly[0] = (square_xyrxly[0] + 1);
 square_xyrxly[1] = (square_xyrxly[1] + 47);
 square_xyrxly[2] = (square_xyrxly[2] - 1);
 square_xyrxly[3] = (square_xyrxly[3] - 1);
 MySDLDrawSquareAndFill(data_s->render, square_xyrxly, fill_color, fill_color);

 //square_xyrxly[0] = (square_xyrxly[0] + 46);
 square_xyrxly[1] = (square_xyrxly[1] - 46);
 square_xyrxly[2] = (square_xyrxly[2] - 46);
 MySDLDrawSquareAndFill(data_s->render, square_xyrxly, fill_color, fill_color);

}

void MySpeciMenue1Start(struct MyWindowAndRenderData* data_s) {
 
 //画面 Menue1 データ初期化処理
 data_s->Menue1_s = MySpeciInitMenue1(data_s->Menue1_s, data_s->slaves_window);
 //画面 Menue1 枠描画処理
 MySpeciDrawMenue1BackGround(&data_s->Menue1_s);
 //MySpeciDrawMenue2Square(data_s->Menue2_s.render);
 
 //文字列表示処理
 //select_square TTFの出力文字とカラーを設定、テクスチャーをx,yの座標にレンダーコピー 
 //MySpeciRenderTextMenue2SelectSquare(&data_s->Menue2_s); 
 //view_square1
 //MySpeciRenderTextMenue2ViewSquare(&data_s->Menue2_s);
 //サーフェイスを更新
 SDL_UpdateWindowSurface(data_s->slaves_window);
 //画面 Menue1 キーイベントループ
 MySpeciMenue1UserInpuLoop(data_s);
 //リソース開放
 MySpeciResourceRelease(&data_s->Menue1_s);
 
};

void MySpeciMenue2Start(struct MyWindowAndRenderData* data_s) {
 
 //画面 Menue2 データ初期化処理
 data_s->Menue2_s = MySpeciInitMenue2(data_s->Menue2_s, data_s->slaves_window);
 //画面 Menue2 枠描画処理
 MySpeciDrawMenue2Square(data_s->Menue2_s.render);
 //文字列表示処理
 //select_square TTFの出力文字とカラーを設定、テクスチャーをx,yの座標にレンダーコピー 
 MySpeciRenderTextMenue2SelectSquare(&data_s->Menue2_s); 
 //view_square
 MySpeciRenderTextMenue2ViewSquare(&data_s->Menue2_s);
 //サーフェイスを更新
 SDL_UpdateWindowSurface(data_s->slaves_window);
 //画面 Menue2 キーイベントループ
 MySpeciMenue2UserInpuLoop(data_s);
 //リソース開放
 MySpeciResourceRelease(&data_s->Menue2_s);
 
};


