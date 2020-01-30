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

//ユーザー定義ヘッダリンク
#include "function.h"
#include "view.h"
#include "specific.h"

int main(void)
{
 //変数宣言
 BITMAPDATA_t bitmap;

  if(pngFileReadDecode(&bitmap, PNG_FILE) == EXIT_FAILURE){
    printf("pngFileReadDecode error\n");
    exit(EXIT_FAILURE);
  }

  freeBitmapData(&bitmap);

  exit(EXIT_SUCCESS);
}

