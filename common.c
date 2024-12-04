#include "common.h"

/* ウィンドウサイズを計算する関数 */
int MyWindowsize( int n ) {
 return MyROOT_NUM + ((n - 1) * (MyROOT_NUM + MyPADDING));
}