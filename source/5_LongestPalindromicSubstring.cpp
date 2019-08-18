#include "../header/code_medium.h"
 
class Solution {
public:
  string longestPalindrome(string s) {
    string result;
    int i, j, tend;
    int start = 0, l = 0;
    int length = s.length();
    bool tag;
    vector<int> temp;

    while (start + l<s.length()){
      temp.clear();
      for (j = start + l; j < length; j++){
        if(s[start] == s[j]){ temp.push_back(j); }
      }
      for (j = temp.size() - 1; j >= 0; j--){
        tag = false; tend = temp[j] - start + 1;
        if(tend>l){
          tag = true;
          for (i = 0; i < tend / 2; i++){
            if (s[start + i] != s[temp[j] - i]){ tag = false; }
          }
        }
        if(tag){ l = tend; result = s.substr(start, l); break; }
      }
      start++;
    }
    return result;
  }
};

bool show_5(int setwidth){
  const string title = "5.Longest Palindromic Substring";
  vector<string> input = {"babad", "cbbd"};
  vector<string> output = {"bab", "bb"};
  Solution Program;

  bool result = true;
  for(int i=0; i<input.size(); i++){
    result = Program.longestPalindrome(input[i]) == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}