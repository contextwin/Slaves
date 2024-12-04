#include "common.h"
#include "MyImlib2.h"

void MyBlendMenueStrings1(char positionnum) {
 char text[4096];

 // 白色を設定 (R=255, G=255, B=255, A=255)
 imlib_context_set_color(255, 255, 255, 255);
 // 四角形を塗りつぶす
 imlib_image_fill_rectangle((MyWidth / 3) + 1 , (MyHeight / 14) + 1, 279, 188);
 imlib_image_fill_rectangle((MyWidth / 1.25) + 1 , (MyHeight / 3) + 1, 127, 218);

 if ( positionnum == 1 ) {
  imlib_context_set_color( 0, 255, 255, 255 );
  sprintf( text, "アイテム" );
 } else
 {
  imlib_context_set_color(0, 0, 0, 255);
  sprintf( text, "アイテム" );
 }
 imlib_text_draw( ( MyWidth / 2.5 ) - 35, MyHeight / 9, text );

 if ( positionnum == 2 ) { 
  imlib_context_set_color( 0, 255, 255, 255 );
  sprintf( text, "つよさ" );
 } else
 {
  imlib_context_set_color(0, 0, 0, 255);
  sprintf( text, "つよさ" );
 }
 imlib_text_draw( ( MyWidth / 2.5 ) + 95, MyHeight / 9, text ); 

 if ( positionnum == 3 ) {
  imlib_context_set_color( 0, 255, 255, 255 );
  sprintf( text, "まほう" );
 } else
 {
  imlib_context_set_color(0, 0, 0, 255);
  sprintf( text, "まほう" );
 }
 imlib_text_draw( ( MyWidth / 2.5 ) - 35, ( MyHeight / 9 ) + 45, text );

 if ( positionnum == 4 ) {
  imlib_context_set_color( 0, 255, 255, 255 );
  sprintf( text, "とくぎ" );
 } else {
  imlib_context_set_color(0, 0, 0, 255);
  sprintf( text, "とくぎ" );
 }
 imlib_text_draw( ( MyWidth / 2.5 ) + 95, ( MyHeight / 9 ) + 45, text ); 

if ( positionnum == 5 ) {
 imlib_context_set_color( 0, 255, 255, 255 );
 sprintf( text, "そうび" );
} else {
 imlib_context_set_color(0, 0, 0, 255);
 sprintf( text, "そうび" );
}
imlib_text_draw( ( MyWidth / 2.5 ) - 35, ( MyHeight / 9 ) + 90, text ); 
 
 
 imlib_context_set_color(0, 0, 0, 255);
 sprintf( text, "所持金" );
 imlib_text_draw( ( MyWidth / 1.25 ) + 5, ( MyHeight / 3 ) + 5, text );
 sprintf( text, "500G" );
 imlib_text_draw( ( MyWidth / 1.25 ) + 70, ( MyHeight / 3 ) + 50, text );
 sprintf( text, "経過時間" );
 imlib_text_draw( ( MyWidth / 1.25 ) + 5, ( MyHeight / 3 ) + 95, text );
 sprintf( text, "00:00:00" );
 imlib_text_draw( ( MyWidth / 1.25 ) +15, ( MyHeight / 3 ) + 140, text );

}
