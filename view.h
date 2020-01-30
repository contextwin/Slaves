//抽象層のヘッダ

#include <png.h>

#define HEADER_NUM 8
#define PNG_COLOR 3
#define PNG_COLOR_ALPHA 4

typedef struct{
 /* pngデコード後のBITMAPデータの先頭ポインタを指すアドレス */
 unsigned char *data;
 unsigned int width; //画像の横幅
 unsigned int height; //画像の高さ
 unsigned int ch; //カラーの時は3,カラー&アルファチャネルの時は4
} BITMAPDATA_t;

//関数プロトタイプ宣言
/* 引数に指定されたfilenameの読み込みとデコードし画像データをbitmapDataにセット */
int pngFileReadDecode(BITMAPDATA_t *, const char*);
/* 引数に指定されfilenameの読み込みとエンコードし出力 */
int pngFileEncodeWrite(BITMAPDATA_t *, const char*);
/* 引数に指定された構造体の開放 */
int freeBitmapData(BITMAPDATA_t *);

//関数宣言
int pngFileReadDecode(BITMAPDATA_t *bitmapData, const char* filename){

 FILE *fi;
 int j;
 unsigned int width, height;
 unsigned int readSize;

 png_structp png;
 png_infop info;
 png_bytepp datap;
 png_byte type;
 png_byte header[HEADER_NUM];

 fi = fopen(filename, "rb");

 if(fi == NULL){
    printf("%sは開けません\n", filename);
    return ERROR;
 }

 readSize = fread(header, 1, HEADER_NUM, fi);

 /* ファイルがPNGかどうかのチェック */
 if(png_sig_cmp(header, 0, HEADER_NUM)){
  printf("png_sig_cmp error!\n");
  return ERROR;
 }

 /* read構造体の生成 */
 png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

 if(png == NULL){
  printf("png_create_read_struct error!\n");
  return ERROR;
 }

 /* info構造体の生成 */
 info = png_create_info_struct(png);

 if(info == NULL){
  printf("png_crete_info_struct error!\n");
  return ERROR;
 }

 png_init_io(png, fi); /* 読み込み先のファイルポインタの設定 */
 png_set_sig_bytes(png, readSize);

 /* 画像の読み込みの開始 */
 png_read_png(png, info, PNG_TRANSFORM_PACKING | PNG_TRANSFORM_STRIP_16, NULL);

 /* 画像情報取得 */
 width = png_get_image_width(png, info);
 height = png_get_image_height(png, info);
 datap = png_get_rows(png, info);
 type = png_get_color_type(png, info);

 /* とりあえずRGBだけ対応 */
 if(type != PNG_COLOR_TYPE_RGB && type != PNG_COLOR_TYPE_RGB_ALPHA){
  printf("color type is not RGB or RGBA\n");
  return ERROR;
 }

 bitmapData->width = width;
 bitmapData->height = height;

 if(type == PNG_COLOR_TYPE_RGB) {
  bitmapData->ch = PNG_COLOR;
 } else if(type == PNG_COLOR_TYPE_RGBA) {
  bitmapData->ch = PNG_COLOR_ALPHA;
 }

 printf("width = %d, height = %d, ch = %d\n", bitmapData->width, bitmapData->height, bitmapData->ch);

 bitmapData->data =
  (unsigned char*)malloc(sizeof(unsigned char) * bitmapData->width * bitmapData->height * bitmapData->ch);
 if(bitmapData->data == NULL){
   printf("data malloc error\n");
   return ERROR;
 }

 /* デコード結果のメモリ領域へのコピー */
 for(j = 0; j < bitmapData->height; j++){
  memcpy(bitmapData->data + j * bitmapData->width * bitmapData->ch, datap[j], bitmapData->width * bitmapData->ch);
 }

 /* 生成した構造体の削除 */
 png_destroy_read_struct(&png, &info, NULL);
 fclose(fi);

 return SUCCESS;
}

int pngFileEncodeWrite(BITMAPDATA_t *bitmapData, const char *filename){
 FILE *fo;
 int j;

 png_structp png;
 png_infop info;
 png_bytepp datap;
 png_byte type;

 fo = fopen(filename, "wb");
 if(fo == NULL){
  printf("%sは開けません\n", filename);
  return ERROR;
 }

 png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
 info = png_create_info_struct(png);

 if(bitmapData->ch == PNG_COLOR) {
  type = PNG_COLOR_TYPE_RGB;
 } else if(bitmapData->ch == PNG_COLOR_ALPHA) {
  type = PNG_COLOR_TYPE_RGB_ALPHA;
 } else {
  printf("ch num is invalid!\n");
  return ERROR;
 }

 png_init_io(png, fo);

 png_set_IHDR(png, info, bitmapData->width, bitmapData->height, 8, type, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

 datap = png_malloc(png, sizeof(png_bytep) * bitmapData->height);

 png_set_rows(png, info, datap);

 for(j = 0; j < bitmapData->height; j++){
  datap[j] = png_malloc(png, bitmapData->width * bitmapData->ch);
  memcpy(datap[j], bitmapData->data + j * bitmapData->width * bitmapData->ch, bitmapData->width * bitmapData->ch);
 }

 png_write_png(png, info, PNG_TRANSFORM_IDENTITY, NULL);

 for(j = 0; j < bitmapData->height; j++){
  png_free(png, datap[j]);
 }

 png_free(png, datap);

 png_destroy_write_struct(&png, &info);
 fclose(fo);

 return SUCCESS;
}

int freeBitmapData(BITMAPDATA_t *bitmap){

 if(bitmap->data != NULL){
  free(bitmap->data);
  bitmap->data = NULL;
 }

 return SUCCESS;
}
