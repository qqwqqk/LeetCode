#include "../header/code_easy.h"

class Solution {
public:
  int romanToInt(string s) {
    map<char,int> val;
    val['I']=1;
    val['V']=5;
    val['X']=10;
    val['L']=50;
    val['C']=100;
    val['D']=500;
    val['M']=1000;
    int sum=0;
    for(int i=0;i<s.size()-1;i++)
    {
      if(val[s[i]] >= val[s[i+1]]){ sum = sum + val[s[i]]; }
      else{ sum = sum - val[s[i]]; }
    }
    sum=sum+val[s.back()];
    return sum;
  }
};

bool show_13(int setwidth){
  const string title = "13.Roman to Integer";
  vector<string> input = {"III", "IV", "IX", "LVIII", "MCMXCIV"};
  vector<int> output = {3, 4, 9, 58, 1994};
  Solution Program;

  bool result = true;
  for(int i=0; i<input.size(); i++){
    result = Program.romanToInt(input[i]) == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}