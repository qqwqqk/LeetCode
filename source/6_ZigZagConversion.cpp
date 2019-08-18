#include "../header/code_medium.h"
 
class Solution {
public:
  string convert(string s, int numRows) {
    string result;
    int length = s.length();
    int distance = 2 * (numRows - 1);
    int row = 0, temp = 0;

    if(numRows == 1 || numRows == length){ result = s; }
    else{
      for(int i = row; i < length; i += distance) { 
        result += s[i];
      }

      while (++row < numRows - 1){
        temp = 2 * (numRows - 1 - row);
        int i = row;
        while (1){
          result += s[i];
          i += temp;
          if(i >= length) break;

          result += s[i];
          i += distance - temp;
          if(i >= length) break;
        }
      }

      for(int i = row; i < length; i += distance) {
        result += s[i];
      }
    }
    return result;
  }
};

bool show_6(int setwidth){
  const string title = "6.ZigZag Conversion";
  vector<string> input = {"PAYPALISHIRING", "PAYPALISHIRING"};
  vector<int> numrows = {3, 4}; 
  vector<string> output = {"PAHNAPLSIIGYIR", "PINALSIGYAHRPI"};
  Solution Program;

  bool result = true;
  for(int i=0; i<input.size(); i++){
    result = Program.convert(input[i], numrows[i]) == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}