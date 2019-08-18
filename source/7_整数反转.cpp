#include "../header/code_easy.h"

class Solution {
public:
  int reverse(int x) {
    int result = 0;
    while(x != 0){
      if(result <= -214748364){
        if(result == -214748364){ if( x % 10 < -8){ result=0; break; } }
        else{ result = 0; break; }
      }
      if(result >= 214748364){
        if(result == 214748364){ if(x % 10 > 7){ result=0;  break; } }
        else{ result = 0; break; }
      } 
      result = result * 10 + x % 10;
      x = x / 10;
    }
    return result;
  }
};

bool show_7(int setwidth){
  const string title = "7.Reverse Integer";
  vector<int> input = {123, -123, 120};
  vector<int> output = {321, -321, 21};
  Solution Program;

  bool result = true;
  for(int i=0; i<input.size(); i++){
    result = Program.reverse(input[i]) == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}