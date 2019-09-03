#include "../header/code_hard.h"
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        
        auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        
        if (p.length() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        } else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

bool show_10(int setwidth){
  const string title = "10.Regular Expression Matching";
  vector<string> input1 = {"aa","aa","ab","aab","mississippi"};
  vector<string> input2 = {"a","a*",".*","c*a*b","mis*is*p*."};
  vector<bool> output = {false,true,true,true,false};
  Solution Program;

  bool result = true;
  for(int i=0; i<input1.size(); i++){
    bool temp = Program.isMatch(input1[i], input2[i]);
    result = temp == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}