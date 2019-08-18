#include "../header/code_medium.h"
 
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int result = 0, i = 0, j = 0;
    bool tag = true;
    for (; j<s.length(); j++){
      tag = true;
      while (tag){
        tag = false;
        for (int t = i; t<j; t++){
          if (s[t] == s[j]){ tag = true; i++; }
        }
      }
      if (result<j - i + 1){ result = j - i + 1; }
    }
    return result;
  }
};

bool show_3(int setwidth){
  const string title = "3.Longest Substring Without Repeating Characters";
  vector<string> input = {"abcabcbb", "bbbbb", "pwwkew"};
  vector<int> output = {3, 1, 3};
  Solution Program;

  bool result = true;
  for(int i=0; i<input.size(); i++){
    result = Program.lengthOfLongestSubstring(input[i]) == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}