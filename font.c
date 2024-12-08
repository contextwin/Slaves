#include "common.h"
#include "MyImlib2.h"

void MyBlendMenueStrings1(char positionnum) {
 char text[4096];

 // 白色を設定 (R=255, G=255, B=255, A=255)
 imlib_context_set_color(255, 255, 255, 255);
 // 四角形を塗りつぶす
 imlib_image_fill_rectangle( 0, 0, 279, 188 );

 if ( positionnum == 1 ) {
  imlib_context_set_color( 0, 255, 255, 255 );
  sprintf( text, "アイテム" );
 } else
 {
  imlib_context_set_color(0, 0, 0, 255);
  sprintf( text, "アイテム" );
 }
 imlib_text_draw( 15, 15, text );

 if ( positionnum == 2 ) { 
  imlib_context_set_color( 0, 255, 255, 255 );
  sprintf( text, "つよさ" );
 } else
 {
  imlib_context_set_color(0, 0, 0, 255);
  sprintf( text, "つよさ" );
 }
 imlib_text_draw( 145, 15, text ); 

 if ( positionnum == 3 ) {
  imlib_context_set_color( 0, 255, 255, 255 );
  sprintf( text, "まほう" );
 } else
 {
  imlib_context_set_color(0, 0, 0, 255);
  sprintf( text, "まほう" );
 }
 imlib_text_draw( 15, 55, text );

 if ( positionnum == 4 ) {
  imlib_context_set_color( 0, 255, 255, 255 );
  sprintf( text, "とくぎ" );
 } else {
  imlib_context_set_color(0, 0, 0, 255);
  sprintf( text, "とくぎ" );
 }
 imlib_text_draw( 145, 55, text ); 

 if ( positionnum == 5 ) {
  imlib_context_set_color( 0, 255, 255, 255 );
  sprintf( text, "そうび" );
 } else {
  imlib_context_set_color(0, 0, 0, 255);
  sprintf( text, "そうび" );
 }
 imlib_text_draw( 15, 95, text ); 
 
 if ( positionnum == 6 ) {
  imlib_context_set_color( 0, 255, 255, 255 );
  sprintf( text, "ならび" );
 } else {
  imlib_context_set_color(0, 0, 0, 255);
  sprintf( text, "ならび" );
 }
 imlib_text_draw( 145, 95, text );  

}

void MyBlendMenueStrings2( void ) {
 char text[4096];

imlib_context_set_color(255, 255, 255, 255);
imlib_image_fill_rectangle( 0, 0, 127, 218);

imlib_context_set_color(0, 0, 0, 255);
sprintf( text, "所持金" );
imlib_text_draw( 5, 5, text );
sprintf( text, "500G" );
imlib_text_draw(  70, 50, text );
sprintf( text, "経過時間" );
imlib_text_draw( 5, 95, text );
sprintf( text, "00:00:00" );
imlib_text_draw( 15, 140, text );

}

void MyBlendMenueStrings3( void ) {
 char text[4096];

imlib_context_set_color(255, 255, 255, 255);
imlib_image_fill_rectangle( 0, 0, MyWidth, (MyHeight - (MyHeight - 80)) );

imlib_context_set_color(0, 0, 0, 255);
sprintf( text, "[esc] - メニュー終了。   [↑↓←→] - 選択。  [space] - キャンセル。   [enter] - 決定。" );
imlib_text_draw( 60, 30, text );
}