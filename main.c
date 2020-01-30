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

int main(int argc, char *argv[])
{
 //変数宣言
 BITMAPDATA_t bitmap;
 int i, j, c;
 int ave, sum;
 char outname[FILENAME_MAX];

   if(argc != 2){
    printf("ファイル名が指定されていません\n");
    return -1;
  }

  if(pngFileReadDecode(&bitmap, argv[1]) == -1){
    printf("pngFileReadDecode error\n");
    return -1;
  }

  printf("bitmap->data = %p\n", bitmap.data);
  printf("bitmap->width = %d\n", bitmap.width);
  printf("bitmap->height = %d\n", bitmap.height);
  printf("bitmap->ch = %d\n", bitmap.ch);

  /* グレースケールに変換 */
  for(j = 0; j < bitmap.height; j++){
    for(i = 0; i < bitmap.width; i++){
      sum = 0;
      for(c = 0; c < bitmap.ch; c++){
        sum += bitmap.data[bitmap.ch * (i + j * bitmap.width) + c];
      }
      ave = sum / bitmap.ch;
      for(c = 0; c < bitmap.ch; c++){
        bitmap.data[bitmap.ch * (i + j * bitmap.width) + c] = ave;
      }
    }
  }

  sprintf(outname, "%s", "output.PNG");

  if(pngFileEncodeWrite(&bitmap, outname) == -1){
    printf("pngFileEncodeWrite error\n");
    freeBitmapData(&bitmap);
    return -1;
  }

  freeBitmapData(&bitmap);

  return 0;
}

