#include "MyImlib2.h"
#include "common.h"

#define MyImagePath "./image/current/menue/status"

#define MyHogeSide "/hoge.jpg"
#define MyChipoSide "/chipo_side01.png"
#define MyPiyoSide "/piyo.png"

void MyDrawStatus( char positionnum2 ) {
 char imagepath[100];

 if ( positionnum2 == 1 ) {
  snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyHogeSide );
  MyDrawImage( imagepath, 0, 0, 625, 750);  
 } else
 if ( positionnum2 == 2 ) {
  snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyChipoSide );
  MyDrawImage( imagepath, 0, 0, 625, 750);
 } else
 if ( positionnum2 == 3 ) {
  snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyPiyoSide );
  MyDrawImage( imagepath, 0, 0, 625, 750);
 }

 XDrawRectangle(display, window, gc, MyWidth / 8, MyHeight / 1.5, MyWidth / 1.325, 150);

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