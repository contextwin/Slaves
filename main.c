#include "common.h"
#include "menue1.h"

/* グローバル変数の定義 */
Display *display;
Window window;
XEvent event;
KeySym keysym;

int main(void)
{

/* メニュー1の表示 */
 MyDrawMenue1();

 //getchar();

 XDestroyWindow( display, window );
 XCloseDisplay( display );

 return 0;
}
