#include "MyImlib2.h"
#include "common.h"

#define MyImagePath "./image/current/menue/status"

#define MyHogeSide "/hoge.jpg"
#define MyChipoSide "/chipo_side01.png"
#define MyPiyoSide "/piyo.png"

void MyDrawStatus( char positionnum2 ) {
 char imagepath[100];
 //Imlib_Image image;

 // 作成した画像を設定
 imlib_context_set_image( main_buffer );
 
 // 半透明の白い四角形を設定
 imlib_context_set_color( 255, 255, 255, 180 ); // 半透明の白
 imlib_image_fill_rectangle( 0, 0, MyWidth, MyHeight);

 imlib_render_image_on_drawable( 0, 0 );

 if ( positionnum2 == 1 ) {
  snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyHogeSide );
  MyBlendImage( imagepath, 60, 0, 625 / 1.5 , 750 / 1.5 );  
 } else
 if ( positionnum2 == 2 ) {
  snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyChipoSide );
  MyBlendImage( imagepath, 60, 0, 625 / 1.5 , 750 / 1.5 );
 } else
 if ( positionnum2 == 3 ) {
  snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyPiyoSide );
  MyBlendImage( imagepath, 60, 0, 625 / 1.5 , 750 / 1.5 );
 }
 
 /* ステータス 領域1 (ウィンドウ右部半透明) */
 imlib_context_set_color( 255, 255, 255, 180 ); // 半透明の白
 imlib_image_fill_rectangle(  MyWidth / 1.75 + 1, MyHeight / 10 + 1, 300 - 1, 350 - 1);
 
 char text[4096];

 imlib_context_set_color(0, 0, 0, 255);
 sprintf( text, "chipo          Lv 1" );
 imlib_text_draw( ( MyWidth / 1.75  ) + 15, ( MyHeight / 10 ) + 15, text );
 sprintf( text, "          HP  23/23" );
 imlib_text_draw( ( MyWidth / 1.75  ) + 15, ( MyHeight / 10 ) + 50, text );
 sprintf( text, "          MP  15/15" );
 imlib_text_draw( ( MyWidth / 1.75  ) + 15, ( MyHeight / 10 ) + 85, text );
 sprintf( text, "         ABP  15/15" );
 imlib_text_draw( ( MyWidth / 1.75  ) + 15, ( MyHeight / 10 ) + 115, text );
 sprintf( text, "     STR  3  SPD  5" );
 imlib_text_draw( ( MyWidth / 1.75  ) + 15, ( MyHeight / 10 ) + 150, text );
 sprintf( text, "     VIT  3  MGC  5" );
 imlib_text_draw( ( MyWidth / 1.75  ) + 15, ( MyHeight / 10 ) + 185, text ); 
 sprintf( text, "     INT  3  LUC  5" );
 imlib_text_draw( ( MyWidth / 1.75  ) + 15, ( MyHeight / 10 ) + 220, text );
 sprintf( text, "NextLvUP      8 exp" );
 imlib_text_draw( ( MyWidth / 1.75  ) + 15, ( MyHeight / 10 ) + 315, text );

 /* ステータス 領域2 (ウィンドウ下部半透明) */
 imlib_context_set_color( 255, 255, 255, 180 ); // 半透明の白
 imlib_image_fill_rectangle( MyWidth / 9 + 1, MyHeight / 1.5 + 1, MyWidth / 1.275 - 1, 150 - 1 );

 imlib_context_set_color(0, 255, 255, 255);
 sprintf( text, "つよさ" );
 imlib_text_draw( ( MyWidth / 9  ) + 15, ( MyHeight / 1.5 ) + 15, text );
 imlib_context_set_color(0, 0, 0, 255);
 sprintf( text, "そうび" );
 imlib_text_draw( ( MyWidth / 9  ) + 195, ( MyHeight / 1.5 ) + 15, text );
 sprintf( text, "まほう" );
 imlib_text_draw( ( MyWidth / 9  ) + 375, ( MyHeight / 1.5 ) + 15, text );
 sprintf( text, "とくぎ" );
 imlib_text_draw( ( MyWidth / 9  ) + 555, ( MyHeight / 1.5 ) + 15, text );
 sprintf( text, "アビリティUP" );
 imlib_text_draw( ( MyWidth / 9  ) + 15, ( MyHeight / 1.5 ) + 80, text );

 MyBlendMenueStrings3();

 imlib_render_image_on_drawable( 0, 0 );

 /* ステータス 領域1 (ウィンドウ右部)*/
 XDrawRectangle(display, window, gc, ( MyWidth / 1.75 ) - 5, ( MyHeight / 10 ) - 5, 300 + 10, 350 + 10);
 XDrawRectangle(display, window, gc, MyWidth / 1.75, MyHeight / 10, 300, 350);
 
 /* ステータス 領域2 (ウィンドウ下部) */
 XDrawRectangle(display, window, gc, ( MyWidth / 9 ) - 5 , ( MyHeight / 1.5 ) - 5 , ( MyWidth / 1.275 ) + 10, 150 + 10);
 XDrawRectangle(display, window, gc, MyWidth / 9, MyHeight / 1.5, MyWidth / 1.275, 150);
 
 XDrawLine( display, window, gc, 0, ( MyHeight - 80 ) - 1, ( MyWidth / 9 ) - 5, ( MyHeight - 80 ) - 1 );
 XDrawLine( display, window, gc, ( MyWidth / 1.275 ) + 99, ( MyHeight - 80 ) - 1, MyWidth, ( MyHeight - 80 ) - 1 );

 for(;;) {
  XNextEvent( display, &event );
  keysym = XLookupKeysym( &event.xkey, 0 );

  if ( event.type == KeyPress ) {
   if ( keysym == XK_space ) {
    keysym = NoSymbol;
    break;
   }
  }
 }
}