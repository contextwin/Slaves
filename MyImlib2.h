#ifndef MY_IMAGE_H
#define MY_IMAGE_H

#include <Imlib2.h>

/* image.c内の関数 */
/* 画像を描画する */
extern void MyDrawImage( char *imagepath, int x, int y, int width, int height );
/* 画像をバッファにブレンドする */
extern void MyBlendImage( char *imagepath, int x, int y, int width, int height );

/* font.c内の関数 */
/* メニュー画面にフォントをブレンドする、領域1 */
extern void MyBlendMenueStrings1 (char positionnum );
/* メニュー画面にフォントをブレンドする、領域2 */
extern void MyBlendMenueStrings2( void );
/* メニュー画面にフォントをブレンドする、領域3 */
extern void MyBlendMenueStrings3( void );
#endif