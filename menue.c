#include <X11/Xlib.h>
#include <string.h>
#include <unistd.h>

#include "common.h"
#include "MyImlib2.h"
#include "menue.h"

/* xbmデータのインクルード */
#include "./image/current/menue/test.xbm"
#include "./image/current/menue/triangle.xbm"

/* 画像格納ディレクトリへのパス */
#define MyImagePath "./image/current/menue"

/* menue1画像変数 */
#define MyMenueImage "/menue.png"

/* キャラクター正面画像変数 */
#define MyHogeFront "/test3.jpg"
#define MyChipoFront "/test2.png"
#define MyPiyoFront "/test1.png"

#define TEST_TEXT "test"

void MyDrawMenue(void) {
 
int i;

/* 画像描画関連の変数 */
char imagepath[100];
//memset(imagepath, 0, sizeof(imagepath)); ;

 /* xbmび関連の変数 */
 Pixmap pat;
 XColor xcolor;

gc = XCreateGC( display, window, 0, 0 );
gc1 = XCreateGC( display, window, 0, 0 );
XSetForeground( display, gc1, WhitePixel( display, 0 ) );

XSelectInput( display, window, ExposureMask | KeyPressMask );
XMapWindow( display, window );

/* xbm 設定 */
 pat = XCreatePixmapFromBitmapData( display, window, test_bits, test_width, test_height,
                                        BlackPixel( display, 0 ), WhitePixel( display, 0 ),
                                        DefaultDepth( display, 0 ) );


/* XサーバからExposeイベントが送られてくるまで待つ */
do{
        XNextEvent( display, &event);
}while( event.type != Expose );

for ( i = 0; i < ( MyWidth / 3 ); i++ ) {
 XDrawPoint( display, window, gc, ( ( MyWidth / 2 ) - i ), ( ( MyHeight / 5 ) ) );
 XDrawPoint( display, window, gc, ( ( MyWidth / 2 ) - i ), ( ( MyHeight / 1.25 ) ) );
 XDrawPoint( display, window, gc, ( ( MyWidth / 2 ) + i ), ( ( MyHeight / 5 ) ) );
 XDrawPoint( display, window, gc, ( ( MyWidth / 2 ) + i ), ( ( MyHeight / 1.25 ) ) );

 XFlush( display );
 usleep(200);
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
 usleep(200);
}
/* 側面の線を描画 */
for( i = 0 ; i < ( ( MyHeight / 2 ) + 21 ); i++ ) {
 XDrawPoint( display, window, gc, centrex1 * 2, ( ( ( MyHeight / 4 ) + 13 ) + i ) );
 XDrawPoint( display, window, gc, centrex2, ( ( ( MyHeight / 4 ) + 13 ) + i ) );
 XFlush( display );
 usleep(200);
}

for ( i = 0; i < 15; i++ ) {
 XDrawPoint( display, window, gc, centrex1 + 47 + i, (MyHeight / 1.25));
 XDrawPoint( display, window, gc, centrex2 - i, (MyHeight / 1.25));
 XFlush( display );
 usleep(200); 
}
/* キャラグラ表示領域 */
for( i = 0; i < 200; i++ ) {
 XDrawPoint( display, window, gc, ( MyWidth / 2 ) , ( ( MyHeight / 1.25 ) - i  ));
 XDrawPoint( display, window, gc, ( MyWidth / 2 ) + 100 , ( ( MyHeight / 1.25 ) - i  ));
 XDrawPoint( display, window, gc, ( MyWidth / 2 ) - 100 , ( ( MyHeight / 1.25 ) - i  ));
 XDrawPoint( display, window, gc, ( MyWidth / 2 ) + 200 , ( ( MyHeight / 1.25 ) - i  ));
 XDrawPoint( display, window, gc, ( MyWidth / 2 ) - 200 , ( ( MyHeight / 1.25 ) - i  ));

 XFlush( display );
 usleep(200);
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
 usleep(200);
}

/* 画面左部文字表示領域 */
for ( i = 0; (i < MyHeight / 3); i++ ){
 XDrawPoint( display, window, gc, (MyWidth / 1.25), (MyHeight / 3) + i);
 XDrawPoint( display, window, gc, (MyWidth / 1.05), (MyHeight / 3) + i);
 XDrawPoint( display, window, gc, (MyWidth / 1.05) - (((MyWidth / 1.05) - (MyWidth / 1.25)) / 2) + 8,
                (MyHeight / 3) + i);
 XFlush( display );
 usleep(200);
}

for ( i = 0; i < (MyWidth / 1.05) - (MyWidth / 1.25); i++ ){
 XDrawPoint( display, window, gc, (MyWidth / 1.05) - i, (MyHeight / 3) );
 XDrawPoint( display, window, gc, (MyWidth / 1.05) - i, (MyHeight / 3) + (MyHeight / 3) );
 XFlush( display );
 usleep(200);
}

/* 画面上部文字表示領域 */
for ( i = 0; (i < MyHeight / 3.5); i++ ){
 XDrawPoint( display, window, gc, (MyWidth / 3), (MyHeight / 14) + i);
 XDrawPoint( display, window, gc, (MyWidth / 1.5), (MyHeight / 14) + i);               
 XFlush( display );
 usleep(200);
}

for ( i = 0; i <= (MyWidth / 3); i++ ) {
 XDrawPoint( display, window, gc, (MyWidth / 3) + i, ((MyHeight / 14)));
 XDrawPoint( display, window, gc, (MyWidth / 3) + i, (MyHeight / 2.75) - 3);
 XDrawPoint( display, window, gc, (MyWidth / 3) + i,
                ( MyHeight / 5 ));
 XFlush( display );
 usleep(200);
}

for ( i = 0; i < MyWidth; i++ ) {
 XDrawPoint( display, window, gc, i, ( MyHeight - 81 ) );
 XFlush( display );
 usleep(150);
}

 /* クロス描画 */
 XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, 70, 125 );
                 XFlush( display );
 usleep(200);
 XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, 60, 25 );
 XFlush( display );
 usleep(200);
 XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, 35, 85 );
 XFlush( display );
 usleep(200);
 XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, ( MyWidth - 70 ), 150 );
 XFlush( display );
 usleep(200);

 XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, ( MyWidth - 60 ), 30 );
 XFlush( display );
 usleep(200);

 XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, ( MyWidth - 35 ), 80 );
 XFlush( display );
 usleep(200);
 XCopyArea( display, pat, window, gc, 0, 0,
                test_width, test_height, ( MyWidth - 90 ), 100 );
 XFlush( display );
 usleep(200);
 
 /* メニュー画面画像表示 */
 snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyMenueImage );
 MyBlendImage( imagepath, 0, 0, MyWidth, MyHeight);
 
 /* メニュー画面画像バッファ合成 */
 char positionnum1 = 1;

 /* 領域1フォント合成 */
 MyBlendMenueStrings1( positionnum1 );
 /* 領域2フォント合成 */
 MyBlendMenueStrings2();

 /* キャラクター正面画像バッファ合成 */
 snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyHogeFront );
 MyBlendImage( imagepath, ( MyWidth / 2 ) - 199, ( MyHeight / 1.75 ), 99, 150);
 usleep(200);

 snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyChipoFront );
 MyBlendImage( imagepath, ( MyWidth / 2 ) - 99, ( MyHeight / 1.75 ), 99, 150);
 usleep(200);
 
 snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyPiyoFront );
 MyBlendImage( imagepath, ( MyWidth / 2 ) + 1, ( MyHeight / 1.75 ), 99, 150);
 usleep(200);

 /* ウィンドウへの描画 */
 imlib_context_set_drawable(window);
 imlib_render_image_on_drawable( 0, 0 );

 /* ループ中のtriangle.xbmカラー設定 */
 unsigned long red = BlackPixel(display, screen);
 if (XAllocNamedColor(display, cm, "red", &xcolor, &xcolor)) {
  red = xcolor.pixel; // 赤色をピクセル値として取得
 } else {
  fprintf(stderr, "Cannot allocate red color\n");
 }
 pat = XCreatePixmapFromBitmapData( display, window, triangle_bits, triangle_width, triangle_height,
                                        red, WhitePixel( display, 0 ),
                                        DefaultDepth( display, 0 ) );

 /* ユーザーイベント待受 */
 for (;;) {
  XNextEvent( display, &event );
  if ( event.type == KeyPress ) {
   keysym = XLookupKeysym( &event.xkey, 0 );

   if ( keysym == XK_Right ) {
    keysym = NoSymbol;
    if ( positionnum1 == 1 || positionnum1 == 3 || positionnum1 == 5 )  { 
     positionnum1 += 1;
    } else {
     positionnum1 -= 1;
    }
   }

   if ( keysym == XK_Down ) {
    keysym = NoSymbol;
    if ( positionnum1 == 5 || positionnum1 == 6 ) { 
     positionnum1 -= 4;
    } else if ( positionnum1 == 4 && positionnum1 == 6 ) {
     positionnum1 = 2;
    } else {
     positionnum1 += 2;
    }
   }

   if ( keysym == XK_Left ) {
    keysym = NoSymbol;
    if (positionnum1 == 1 ) { 
     positionnum1 = 2;
    } else if ( positionnum1 == 3 ) {
     positionnum1 = 4;
    } else if ( positionnum1 == 5 ) {
     positionnum1 += 0;
    } else {
     positionnum1 -= 1;
    }
   }

   if ( keysym == XK_Up ) {
    keysym = NoSymbol;
    if (positionnum1 == 1 || positionnum1 == 2 ) { 
     positionnum1 += 4;
    } else {
     positionnum1 -= 2;
    }
   }
   
   if ( keysym == XK_Escape ) {
    keysym = NoSymbol;
    break;
   }

   /* 文字列描画バッファ合成 */
   MyBlendMenueStrings1( positionnum1 );
   /* 描画 */
   imlib_render_image_on_drawable( 0, 0 );

   if ( keysym == XK_Return ) {
    keysym = NoSymbol;
    if ( positionnum1 == 2 ) { // つよさ押下時
     char positionnum2 = 1;
     
     // 黒の透明マスクの設定
     imlib_context_set_color(0, 0, 0, 220);
     // 四角形を塗りつぶす
     imlib_image_fill_rectangle( (MyWidth / 3) + 1, (MyHeight / 14) + 1, 279, 188 );
     // 描画
     imlib_render_image_on_drawable( 0, 0 );

     /* triangle.xbm描画 */
     XCopyArea( display, pat, window, gc, 0, 0,
                triangle_width, triangle_height, ( ( MyWidth / 2 ) - 199 ) + 45, ( MyHeight / 1.75 ) + 165 );
     XFlush( display );

     /* 強さ選択中イベントループ(キャラクター選択)*/
     for (;;) {
      XNextEvent( display, &event );
      if ( event.type == KeyPress ) {
       keysym = XLookupKeysym( &event.xkey, 0 );
       
       if ( keysym == XK_Right ) {
        keysym = NoSymbol;
        if ( positionnum2 == 3 ) {
         positionnum2 = 1;
        } else {
         positionnum2 += 1;
        }

        if ( positionnum2 == 1 ) {
         XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 243, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
         XCopyArea( display, pat, window, gc, 0, 0,
                triangle_width, triangle_height, ( ( MyWidth / 2 ) - 199 ) + 45, ( MyHeight / 1.75 ) + 165 );
         XFlush( display );
        } else if ( positionnum2 == 2 ) {
         XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 45, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
         XCopyArea( display, pat, window, gc, 0, 0,
                triangle_width, triangle_height, ( ( MyWidth / 2 ) - 199 ) + 144, ( MyHeight / 1.75 ) + 165 );
         XFlush( display );
        } else if ( positionnum2 == 3 ) {
         XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 144, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
         XCopyArea( display, pat, window, gc, 0, 0,
                triangle_width, triangle_height, ( ( MyWidth / 2 ) - 199 ) + 243, ( MyHeight / 1.75 ) + 165 );
         XFlush( display );
        }
       }
       if ( keysym == XK_Left ) {
        keysym = NoSymbol;
        if ( positionnum2 == 1 ) {
         positionnum2 = 3;
        } else {
         positionnum2 -= 1;
        }

        if ( positionnum2 == 1 ) {
         XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 144, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
         XCopyArea( display, pat, window, gc, 0, 0,
                triangle_width, triangle_height, ( ( MyWidth / 2 ) - 199 ) + 45, ( MyHeight / 1.75 ) + 165 );
         XFlush( display );
        } else if ( positionnum2 == 2 ) {
         XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 243, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
         XCopyArea( display, pat, window, gc, 0, 0,
                triangle_width, triangle_height, ( ( MyWidth / 2 ) - 199 ) + 144, ( MyHeight / 1.75 ) + 165 );
         XFlush( display );
        } else if ( positionnum2 == 3 ) {
         XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 45, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
         XCopyArea( display, pat, window, gc, 0, 0,
                triangle_width, triangle_height, ( ( MyWidth / 2 ) - 199 ) + 243, ( MyHeight / 1.75 ) + 165 );
         XFlush( display );
        }

       }

       if ( keysym == XK_space ) {
        keysym = NoSymbol;
        XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 144, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
        XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 243, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
        XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 45, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
        /* メニュー画面画像合成 */
        snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyMenueImage );
        MyBlendImage( imagepath, 0, 0, MyWidth, MyHeight);
        MyBlendMenueStrings1(positionnum1);
        snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyHogeFront );
        MyBlendImage( imagepath, ( MyWidth / 2 ) - 199, ( MyHeight / 1.75 ), 99, 150);
        snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyChipoFront );
        MyBlendImage( imagepath, ( MyWidth / 2 ) - 99, ( MyHeight / 1.75 ), 99, 150);
        snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyPiyoFront );
        MyBlendImage( imagepath, ( MyWidth / 2 ) + 1, ( MyHeight / 1.75 ), 99, 150);
        MyBlendMenueStrings2();
        imlib_render_image_on_drawable( 0, 0 );
        break;
       }
      }
      
      if ( keysym == XK_Return ) {
       keysym = NoSymbol;
       XFillRectangle(display, window, gc1, 0, 0, MyWidth, MyHeight );
       MyDrawStatus( positionnum2 );
       /* メニュー画面画像合成 */
       snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyMenueImage );
       MyBlendImage( imagepath, 0, 0, MyWidth, MyHeight );
       MyBlendMenueStrings1(positionnum1);
       // 黒の透明マスクの設定
       imlib_context_set_color(0, 0, 0, 220);
       // 四角形を塗りつぶす
       imlib_image_fill_rectangle( (MyWidth / 3) + 1, (MyHeight / 14) + 1, 279, 188 );
       snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyHogeFront );
       MyBlendImage( imagepath, ( MyWidth / 2 ) - 199, ( MyHeight / 1.75 ), 99, 150);
       snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyChipoFront );
       MyBlendImage( imagepath, ( MyWidth / 2 ) - 99, ( MyHeight / 1.75 ), 99, 150);
       snprintf( imagepath, sizeof( imagepath ), "%s%s", MyImagePath, MyPiyoFront );
       MyBlendImage( imagepath, ( MyWidth / 2 ) + 1, ( MyHeight / 1.75 ), 99, 150);
       MyBlendMenueStrings2();
       imlib_render_image_on_drawable( 0, 0 );
       if ( positionnum2 == 1 ) {
       XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 243, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
        XCopyArea( display, pat, window, gc, 0, 0,
               triangle_width, triangle_height, ( ( MyWidth / 2 ) - 199 ) + 45, ( MyHeight / 1.75 ) + 165 );
        XFlush( display );
       } else if ( positionnum2 == 2 ) {
        XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 45, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
        XCopyArea( display, pat, window, gc, 0, 0,
               triangle_width, triangle_height, ( ( MyWidth / 2 ) - 199 ) + 144, ( MyHeight / 1.75 ) + 165 );
        XFlush( display );
       } else if ( positionnum2 == 3 ) {
        XFillRectangle(display, window, gc1, ( ( MyWidth / 2 ) - 199 ) + 144, ( MyHeight / 1.75 ) + 165, triangle_width, triangle_height );
        XCopyArea( display, pat, window, gc, 0, 0,
               triangle_width, triangle_height, ( ( MyWidth / 2 ) - 199 ) + 243, ( MyHeight / 1.75 ) + 165 );
        XFlush( display );
       }
      } 
     }
    }
   }
  }
 }
}