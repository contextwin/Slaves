#include "MyImlib2.h"
#include "common.h"

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

/* 画像をバッファにブレンドする */
void MyBlendImage(Imlib_Image buffer, char *imagepath, int x, int y, int width, int height) {
    Imlib_Image image;
    int w, h;

    // 入力画像をロード
    image = imlib_load_image(imagepath);
    if (!image) {
        fprintf(stderr, "Failed to load image: %s\n", imagepath);
        return;
    }

    // 入力画像のサイズを取得
    imlib_context_set_image(image);
    w = imlib_image_get_width();
    h = imlib_image_get_height();

    // 描画対象バッファを設定
    imlib_context_set_image(buffer);

    // アルファブレンドを有効化
    imlib_context_set_blend(1);

    // ブレンド処理
    imlib_blend_image_onto_image(image, 0, 0, 0, w, h, x, y, width, height);

    // ロードした画像を解放
    imlib_context_set_image(image);
    imlib_free_image();
}