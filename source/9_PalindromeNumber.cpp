#include "../header/code_easy.h"

class Solution {
public:
  bool isPalindrome(int x) {
    bool result;
    int length = 0;
    int temp = x;
    int i, x1, x2;
    result = true;

    if (x < 0){ result = false; }
    else{
      while (temp != 0){ temp = temp / 10; length++; }
      temp = x;
      for (i = 0; i<length / 2; i++){
        x1 = x % (int)pow(10, i + 1) / (int)pow(10, i);
        x2 = x % (int)pow(10, length - i) / (int)pow(10, length - 1 - i);
        if (x1 != x2){ result = false; }
      }
    }

    return result;
  }
};

bool show_9(int setwidth){
  const string title = "9.Palindrome Number";
  vector<int> input = {121, -121, 10};
  vector<bool> output = {true, false, false};
  Solution Program;

  bool result = true;
  for(int i=0; i<input.size(); i++){
    result = Program.isPalindrome(input[i]) == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}