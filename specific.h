//Slaves固有の振る舞いのヘッダ

//描画マクロ
#define MyWIDTH (521 * 2) + 1
#define MyHEIGHT 351 * 3

// limt
#define FILE_NAME_MAX 256
#define STRINGS_MAX 256

//フォントデータ関連マクロ
#define FONT_DIR "./fonts/"
#define TTF_FONT1 "PixelMplus-20130602/PixelMplus12-Regular.ttf"
#define TTF_FONT2 "PixelMplus-20130602/PixelMplus10-Regular.ttf"

//画像データ関連マクロ
#define IMAGE_DIR "./image/"
#define PNG_FILE01 "chipo_center01.png"
#define PNG_FILE02 "chipo_side01.png"

//メニュー画面2 レンダリングデータ保持用 構造体
struct MyMenue2Struct {
char img_path_name[FILE_NAME_MAX] = IMAGE_DIR,
 font_path_name[FILE_NAME_MAX] = FONT_DIR,
 select_square2_strings[4][STRINGS_MAX] = {"つよさ", "そうび", "とくぎ", "アビリティUP"};

}

int MyInitMenue2() {
	return EXIT_SUCCESS;
}
