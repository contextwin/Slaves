//標準ライブラリヘッダリンク
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

//Xlib関連ライブラリヘッダリンク
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/keysymdef.h>
#include <X11/Xlocale.h>

//bitmap描画関連ライブラリヘッダリンク
#include <png.h>

//ユーザー定義ヘッダリンク
#include "function.h"
#include "view.h"
#include "specific.h"

int main(void)
{
 printf("%d\n", cal_center_num(HEIGHT));
 return 0;
}
