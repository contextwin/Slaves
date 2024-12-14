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
 imlib_context_set_color( 255, 255, 255, 180 ); // 半透明の白 (50%透明)
 imlib_image_fill_rectangle( 0, 0, MyWidth, MyHeight);

 imlib_context_set_drawable( window );
 imlib_render_image_on_drawable( 0, 0 );
 
 if ( positionnum2 == 1 ) {
  snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyHogeSide );
  MyBlendImage( imagepath, 0, 0, 625, 750);  
 } else
 if ( positionnum2 == 2 ) {
  snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyChipoSide );
  MyBlendImage( imagepath, 60, 0, 625 / 1.5 , 750 / 1.5 );
 } else
 if ( positionnum2 == 3 ) {
  snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyPiyoSide );
  MyBlendImage( imagepath, 0, 0, 625, 750);
 }

 imlib_render_image_on_drawable( 0, 0 );
 //imlib_free_image();

 /* ステータス 領域1 */
 XDrawRectangle(display, window, gc, ( MyWidth / 1.75 ) - 5, ( MyHeight / 10 ) - 5, 300 + 10, 350 + 10);
 XDrawRectangle(display, window, gc, MyWidth / 1.75, MyHeight / 10, 300, 350);

 /* ステータス 領域2 */
 XDrawRectangle(display, window, gc, ( MyWidth / 9 ) - 5 , ( MyHeight / 1.5 ) - 5 , ( MyWidth / 1.275 ) + 10, 150 + 10);
 XDrawRectangle(display, window, gc, MyWidth / 9, MyHeight / 1.5, MyWidth / 1.275, 150);

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