#include "image.h"

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