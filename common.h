#ifndef MY_COMMON_H
#define MY_COMMON_H

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdio.h>

/* ウィンドウ描画に関する宣言 */
#define MyROOT_NUM 59
#define MyPADDING 1

extern Display *display;
extern Window window;
extern XEvent event;
extern KeySym keysym;

/* common.c */
/* ウィンドウサイズを計算する関数 */
extern int MyWindowsize( int n );

/* 画面サイズを保持する変数 */
extern int MyWidth;
extern int MyHeight;

#endif