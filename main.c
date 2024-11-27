#include <X11/Xlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <Imlib2.h>

/* xbmデータのインクルード */
#include "./image/current/menue1/test.xbm"

/* 画像格納ディレクトリへのパス */
#define MyImagePath "./image/current/menue1"

/* キャラクター正面画像変数 */
#define MyHogeFront "/test3.jpg"
#define MyChipoFront "/test2.png"
#define MyPiyoFront "/test1.png"


/* ウィンドウ描画に関する宣言 */
#define MyROOT_NUM 59
#define MyPADDING 1

#define TEST_TEXT "test"

/* ウィンドウサイズを計算する関数 */
int MyWindowsize( int n ) {
 return MyROOT_NUM + ((n - 1) * (MyROOT_NUM + MyPADDING));
}

/* 画像を描画する */
void MyDrawImage( char *imagepath, int x, int y, int width, int height ) {
 
 Imlib_Image buffer, image;
 int w, h;

 buffer = imlib_create_image( width, height );
 image = imlib_load_image( imagepath );
 imlib_context_set_image(image);
 w = imlib_image_get_width();
 h = imlib_image_get_height();
 imlib_context_set_image( buffer );
 imlib_blend_image_onto_image( image, 0, 
                                         0, 0, w, h, 
                                          0, 0, width, height );
 imlib_render_image_on_drawable( x, y );
 imlib_free_image();

}

int main(void)
{
 /* X Windowの設定変数 */
 Display *display;
 int screen;
 Window window;
 XEvent ev;
 GC gc, gc1;
 Visual *vis;
 Colormap cm;
 int i;

 /* フォント関連の変数 */
 //Font font;

/* 画像描画関連の変数 */
char imagepath[100];
memset(imagepath, 0, sizeof(imagepath)); ;

 /* xbmび関連の変数 */
 Pixmap pat;

 /* ウィンドウサイズ計算、保持 */
 int MyWidth = MyWindowsize(14);
 int MyHeight = MyWindowsize(11);

 /* ウィンドウの設定 */
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
gc = XCreateGC( display, window, 0, 0 );
gc1 = XCreateGC( display, window, 0, 0 );
XSetForeground( display, gc1, WhitePixel( display, 0 ) );

XSelectInput( display, window, ExposureMask );
XMapWindow( display, window );

/* xbm 設定 */
 pat = XCreatePixmapFromBitmapData( display, window, test_bits, test_width, test_height,
                                        BlackPixel( display, 0 ), WhitePixel( display, 0 ),
                                        DefaultDepth( display, 0 ) );


/* Imlib2 設定 image*/
 imlib_set_cache_size(2048 * 1024);
 imlib_set_color_usage(128);
 imlib_context_set_dither(1);
 imlib_context_set_display(display);
 imlib_context_set_visual(vis);
 imlib_context_set_colormap(cm);
 imlib_context_set_drawable(window);
 
/* XサーバからExposeイベントが送られてくるまで待つ */
do{
        XNextEvent( display, &ev);
}while( ev.type != Expose );

for ( i = 0; i < ( MyWidth / 3 ); i++ ) {
 XDrawPoint( display, window, gc, ( ( MyWidth / 2 ) - i ), ( ( MyHeight / 5 ) ) );
 XDrawPoint( display, window, gc, ( ( MyWidth / 2 ) - i ), ( ( MyHeight / 1.25 ) ) );
 XDrawPoint( display, window, gc, ( ( MyWidth / 2 ) + i ), ( ( MyHeight / 5 ) ) );
 XDrawPoint( display, window, gc, ( ( MyWidth / 2 ) + i ), ( ( MyHeight / 1.25 ) ) );

 XFlush( display );
 usleep(300);
}

int centrex1 = ( ( ( ( ( MyWidth / 2 ) - i ) / 1.5 ) + 2 ) / 2 );   /* 原点のx座標1 */
int centrex2 = ( ( ( ( MyWidth / 2 ) + i ) + centrex1 ) - 2);   /* 原点のy座標2 */

/* 円の半径の長さ */
int r = ( centrex1 );

 int diameter = ( r * 2 );
 int x = (r - 1);
 int y = 0;
 int tx = 1;
 int ty = 1;
 int error = ( tx - diameter );


for ( i = 0 ; x >= y; i++ ) {
 XDrawPoint( display, window, gc, ( centrex1 * 2 ) + x, ( ( MyHeight / 5 ) ) + y );
 XDrawPoint( display, window, gc, ( centrex2 ) - x, ( ( MyHeight / 5 ) ) + y );
 
 /* 下線部描画(左) */
 XDrawPoint( display, window, gc, ( ( centrex1 * 3 ) - y ) , ( ( MyHeight / 1.25 ) ) );

 XDrawPoint( display, window, gc, ( centrex1 * 2 ) + y, ( ( MyHeight / 5 ) ) + x );
 XDrawPoint( display, window, gc, ( centrex2 ) - y, ( ( MyHeight / 5 ) ) + x );
 
 /* 下線部描画(右) */
 XDrawPoint( display, window, gc, ( ( centrex2 - 45 ) + y ) , ( ( MyHeight / 1.25 ) ) );

 if (error <= 0)
 {
  ++y;
  error += ty;
  ty += 2;
 }

 if (error > 0)
 {
  --x;
  tx += 2;
  error += (tx - diameter);
 }

 XFlush( display );
 usleep(300);
}
/* 側面の線を描画 */
for( i = 0 ; i < ( ( MyHeight / 2 ) + 21 ); i++ ) {
 XDrawPoint( display, window, gc, centrex1 * 2, ( ( ( MyHeight / 4 ) + 13 ) + i ) );
 XDrawPoint( display, window, gc, centrex2, ( ( ( MyHeight / 4 ) + 13 ) + i ) );
 XFlush( display );
 usleep(300);
}

for ( i = 0; i < 15; i++ ) {
 XDrawPoint( display, window, gc, centrex1 + 47 + i, (MyHeight / 1.25));
 XDrawPoint( display, window, gc, centrex2 - i, (MyHeight / 1.25));
 XFlush( display );
 usleep(300); 
}
/* キャラグラ表示領域 */
for( i = 0; i < 200; i++ ) {
 XDrawPoint( display, window, gc, ( MyWidth / 2 ) , ( ( MyHeight / 1.25 ) - i  ));
 XDrawPoint( display, window, gc, ( MyWidth / 2 ) + 100 , ( ( MyHeight / 1.25 ) - i  ));
 XDrawPoint( display, window, gc, ( MyWidth / 2 ) - 100 , ( ( MyHeight / 1.25 ) - i  ));
 XDrawPoint( display, window, gc, ( MyWidth / 2 ) + 200 , ( ( MyHeight / 1.25 ) - i  ));
 XDrawPoint( display, window, gc, ( MyWidth / 2 ) - 200 , ( ( MyHeight / 1.25 ) - i  ));

 XFlush( display );
 usleep(300);
}

centrex1 = ( MyWidth / 2 );   /* 原点のx座標1 */

/* 円の半径の長さ */
r = 51;

diameter = ( r * 2 );
x = (r - 1);
y = 0;
tx = 1;
ty = 1;
error = ( tx - diameter );

/* キャラグラ表示領域、丸天井描画 */
for ( i = 0 ; x >= y; i++ ) {
 XDrawPoint( display, window, gc, ( centrex1 + x ) + 50, ( ( MyHeight / 2 ) - 1) - y );
 XDrawPoint( display, window, gc, ( centrex1 + x ) + 150, ( ( MyHeight / 2 ) - 1) - y );
 XDrawPoint( display, window, gc, ( centrex1 + x ) - 50, ( ( MyHeight / 2 ) - 1) - y );
 XDrawPoint( display, window, gc, ( centrex1 + x ) - 150, ( ( MyHeight / 2 ) - 1) - y );
 
 XDrawPoint( display, window, gc, ( centrex1 - x ) + 50, ( ( MyHeight / 2 ) - 1) - y );
 XDrawPoint( display, window, gc, ( centrex1 - x ) + 150, ( ( MyHeight / 2 ) - 1) - y );
 XDrawPoint( display, window, gc, ( centrex1 - x ) - 50, ( ( MyHeight / 2 ) - 1) - y );
 XDrawPoint( display, window, gc, ( centrex1 - x ) - 150, ( ( MyHeight / 2 ) - 1) - y );
 
 XDrawPoint( display, window, gc, ( centrex1 - y ) + 50, ( ( MyHeight / 2 ) - 1) - x );
 XDrawPoint( display, window, gc, ( centrex1 - y ) + 150, ( ( MyHeight / 2 ) - 1) - x );
 XDrawPoint( display, window, gc, ( centrex1 - y ) - 50, ( ( MyHeight / 2 ) - 1) - x );
 XDrawPoint( display, window, gc, ( centrex1 - y ) - 150, ( ( MyHeight / 2 ) - 1) - x );

 XDrawPoint( display, window, gc, ( centrex1 + y ) + 50, ( ( MyHeight / 2 ) - 1) - x );
 XDrawPoint( display, window, gc, ( centrex1 + y ) + 150, ( ( MyHeight / 2 ) - 1) - x );
 XDrawPoint( display, window, gc, ( centrex1 + y ) - 50, ( ( MyHeight / 2 ) - 1) - x );
 XDrawPoint( display, window, gc, ( centrex1 + y ) - 150, ( ( MyHeight / 2 ) - 1) - x );

 if (error <= 0)
 {
  ++y;
  error += ty;
  ty += 2;
 }

 if (error > 0)
 {
  --x;
  tx += 2;
  error += (tx - diameter);
 }

 XFlush( display );
 usleep(300);
}

 /* キャラ1正面絵描画 */
snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyHogeFront );
MyDrawImage( imagepath, ( MyWidth / 2 ) - 199, ( MyHeight / 1.75 ), 99, 150 );
XFlush( display );
usleep( 300 );

 /* キャラ2正面絵描画 */
snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyChipoFront );
MyDrawImage( imagepath, ( MyWidth / 2 ) - 99, ( MyHeight / 1.75 ), 99, 150 );
XFlush( display );
usleep( 300 );

 /* キャラ3正面絵描画 */
snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyPiyoFront );
MyDrawImage( imagepath, ( MyWidth / 2 ) + 1, ( MyHeight / 1.75 ), 99, 150 );
XFlush( display );
usleep( 300 );

/* 画面左部文字表示領域 */
for ( i = 0; (i < MyHeight / 3); i++ ){
 XDrawPoint( display, window, gc, (MyWidth / 1.25), (MyHeight / 3) + i);
 XDrawPoint( display, window, gc, (MyWidth / 1.05), (MyHeight / 3) + i);
 XDrawPoint( display, window, gc1, (MyWidth / 1.05) - (((MyWidth / 1.05) - (MyWidth / 1.25)) / 2) + 8,
                (MyHeight / 3) + i);
 XFlush( display );
 usleep(300);
}

for ( i = 0; i < (MyWidth / 1.05) - (MyWidth / 1.25); i++ ){
 XDrawPoint( display, window, gc, (MyWidth / 1.05) - i, (MyHeight / 3) );
 XDrawPoint( display, window, gc, (MyWidth / 1.05) - i, (MyHeight / 3) + (MyHeight / 3) );
 XFlush( display );
 usleep(300);
}

/* 画面上部文字表示領域 */
for ( i = 0; (i < MyHeight / 3.5); i++ ){
 XDrawPoint( display, window, gc, (MyWidth / 3), (MyHeight / 14) + i);
 XDrawPoint( display, window, gc, (MyWidth / 1.5), (MyHeight / 14) + i);               
 XFlush( display );
 usleep(300);
}

for ( i = 0; i <= (MyWidth / 3); i++ ) {
 XDrawPoint( display, window, gc, (MyWidth / 3) + i, ((MyHeight / 14)));
 XDrawPoint( display, window, gc, (MyWidth / 3) + i, (MyHeight / 2.75) - 3);
 XDrawPoint( display, window, gc1, (MyWidth / 3) + i,
                ( MyHeight / 5 ));
 XFlush( display );
 usleep(300);
}

XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, 70, 125 );
                 XFlush( display );
 usleep(500);
XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, 60, 25 );
 XFlush( display );
 usleep(500);
XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, 35, 85 );
 XFlush( display );
 usleep(500);
XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, ( MyWidth - 70 ), 150 );
 XFlush( display );
 usleep(500);

XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, ( MyWidth - 60 ), 30 );
 XFlush( display );
 usleep(500);

XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, ( MyWidth - 35 ), 80 );
 XFlush( display );
 usleep(500);
XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, ( MyWidth - 90 ), 100 );
 XFlush( display );
 usleep(500);
 
 getchar();

 XDestroyWindow( display, window);
 XCloseDisplay( display );

 return 0;
}
