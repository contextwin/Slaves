#include "common.h"
#include "menue1.h"

/* グローバル変数の定義 */
Display *display;
Window window;

int main(void)
{

/* メニュー1の表示 */
 MyDrawMenue1();

 getchar();

 XDestroyWindow( display, window );
 XCloseDisplay( display );

 return 0;
}
