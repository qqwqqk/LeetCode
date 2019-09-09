#include "../header/code_method.h"

void iomaniptest(string str, double num){
  //左则20字符宽度空格填充
  cout << setiosflags(ios::left) << setw(20) <<setfill(' ') << str << endl;
  //固定小数点后五位
  cout << setiosflags(ios::fixed) << setprecision(5) << num << endl;
}
