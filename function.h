//機能層のヘッダ

//数値算出
#define CHECK_ODD_NUM(num) (num % 2) //奇数ならばTrue,偶数ならばFalseを返す
#define CAL_CENTER_NUM(num) ((num / 2) + 1) //奇数の中央値を求める


//実引数が奇数ならばその中央値を返す
int cal_center_num(int num){
 if(CHECK_ODD_NUM(num))
 { return CAL_CENTER_NUM(num);
 } else {return False;} // 実引数が偶数であれば0を返す
}
