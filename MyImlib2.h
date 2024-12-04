#ifndef MY_IMAGE_H
#define MY_IMAGE_H

#include <Imlib2.h>

/* image.c内の関数 */
/* 画像を描画する */
extern void MyDrawImage( char *imagepath, int x, int y, int width, int height );
/* 画像をバッファにブレンドする */
extern void MyBlendImage( Imlib_Image buffer, char *imagepath, int x, int y, int width, int height );

/* font.c内の関数 */
/* メニュー画面にフォントをブレンドする */
extern void MyBlendMenueStrings1(char positionnum);

#endif