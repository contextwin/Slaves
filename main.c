#include "common.h"
#include "menue1.h"

/* グローバル変数の定義 */
Display *display;
Window window;
XEvent event;
KeySym keysym;
int MyWidth;
int MyHeight;

int main(void)
{
 /* 画面サイズを保持するグローバル変数 */
 MyWidth = MyWindowsize(14);
 MyHeight = MyWindowsize(11);

 /* メニュー1の表示 */
 MyDrawMenue1();

 //getchar();

 XDestroyWindow( display, window );
 XCloseDisplay( display );

 return 0;
}
