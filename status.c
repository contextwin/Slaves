#include "MyImlib2.h"
#include "common.h"

#define MyImagePath "./image/current/menue/status"

#define MyChipoSide "/chipo_side01.png"

void MyDrawStatus( char positionnum2 ) {
 char imagepath[100];

 if ( positionnum2 == 2 ) {
  snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyChipoSide );
   MyDrawImage( imagepath, 0, 0, 625, 750);

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

}