#include "common.h"
#include "menue.h"
#include "MyImlib2.h"

/* グローバル変数の定義 */
/* X Windowの設定変数 */
Display *display;
Window window;
XEvent event;
KeySym keysym;
GC gc, gc1;
int screen;
Visual *vis;
Colormap cm;
Imlib_Image main_buffer;

int MyWidth;
int MyHeight;

int main(void)
{
 /* 画面サイズを保持するグローバル変数 */
 MyWidth = MyWindowsize(14);
 MyHeight = MyWindowsize(11);

 display = XOpenDisplay( NULL );
 vis   = DefaultVisual(display, DefaultScreen(display));
 cm    = DefaultColormap(display, DefaultScreen(display));
 screen = DefaultScreen( display );
 window = XCreateSimpleWindow( display,
        RootWindow( display, screen ),
        /* WIDHT == 839, HEIGHT == 659 */
        100, 50, MyWidth, MyHeight, 4,
        BlackPixel( display, screen ),
        WhitePixel( display, screen));

 /* Imlib2 設定 */
 imlib_set_cache_size(2048 * 1024);
 imlib_set_color_usage(128);
 imlib_context_set_dither(1);
 imlib_context_set_display(display);
 imlib_context_set_visual(vis);
 imlib_context_set_colormap(cm);
 imlib_context_set_drawable(window);

 main_buffer = imlib_create_image( MyWidth, MyHeight );
 imlib_context_set_image( main_buffer );
 imlib_context_set_color( 255, 255, 255, 255 ); // main_bufferを白く塗りつぶす
 imlib_image_fill_rectangle( 0, 0, MyWidth, MyHeight);

 /* メニュー1の表示 */
 MyDrawMenue();

 //getchar();

 XDestroyWindow( display, window );
 XCloseDisplay( display );

 return 0;
}
