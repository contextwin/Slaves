#include "common.h"
#include "MyImlib2.h"

void MyBlendMenue1Strings1() {
 char text[4096];

 sprintf( text, "アイテム" );
 imlib_text_draw( ( MyWidth / 2.5 ) - 35, MyHeight / 9, text ); 
 sprintf( text, "つよさ" );
 imlib_text_draw( ( MyWidth / 2.5 ) + 95, MyHeight / 9, text ); 
 sprintf( text, "まほう" );
 imlib_text_draw( ( MyWidth / 2.5 ) - 35, ( MyHeight / 9 ) + 45, text ); 
 sprintf( text, "とくぎ" );
 imlib_text_draw( ( MyWidth / 2.5 ) + 95, ( MyHeight / 9 ) + 45, text ); 
 sprintf( text, "そうび" );
 imlib_text_draw( ( MyWidth / 2.5 ) - 35, ( MyHeight / 9 ) + 90, text ); 
 sprintf( text, "所持金" );
 imlib_text_draw( ( MyWidth / 1.25 ) + 5, ( MyHeight / 3 ) + 5, text );
 sprintf( text, "500G" );
 imlib_text_draw( ( MyWidth / 1.25 ) + 70, ( MyHeight / 3 ) + 50, text );
 sprintf( text, "経過時間" );
 imlib_text_draw( ( MyWidth / 1.25 ) + 5, ( MyHeight / 3 ) + 95, text );
 sprintf( text, "00:00:00" );
 imlib_text_draw( ( MyWidth / 1.25 ) +15, ( MyHeight / 3 ) + 140, text );

}