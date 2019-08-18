#include "../header/code_easy.h"

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string result = "";
    bool tag = true;
    int length = 0;

    while (1){
      try{
        if (strs.at(length).length() != 0){ length++; }
        else{ return result; break; }
      }
      catch (...){ break; }
    }
    
    if(length == 0){ return result; }

    for (int i = 0; i < strs[0].size(); i++){
      try{
        for (int j = 1; j < length; j++){
          if (strs[0][i] != strs[j][i]){ return result; }
        }
        if (tag){ result += strs[0][i]; }
        else{ break; }
      }
      catch(...){ break; }
    }

    return result;
  }
};

bool show_14(int setwidth){
  const string title = "14.Longest Common Prefix";
  vector<vector<string>> input = {vector<string>{"flower","flow","flight"}, vector<string>{"dog","racecar","car"}};
  vector<string> output = {"fl",""};
  Solution Program;

  bool result = true;
  for(int i=0; i<input.size(); i++){
    result = Program.longestCommonPrefix(input[i]) == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}