#include "../header/code_medium.h"
 
class Solution {
public:
  int myAtoi(string str) {
    int result = 0;
    string temp;
    int begin = -1, end = 0, i = 0, c = 0;
    int tag = 0, length = str.length();

    for(int i = 0; i<length; i++){
      if(tag == 0){
        if(str[i] == '+'&&i + 1 != length){
          if(str[i + 1] >= '0'&&str[i + 1] <= '9'){
            begin = i + 1; tag = 1; continue;
          }
          else{ break; }
        }else if(str[i] == '-'&&i + 1 != length){
          if(str[i + 1] >= '0'&&str[i + 1] <= '9'){
            begin = i + 1; tag = -1; continue;
          }
          else{ break; }
        }else if(str[i] >= '0'&&str[i] <= '9'){
          begin = i; tag = 1; continue;
        }else if(str[i] == ' '){ continue; }
        else{ break; }
      }else{
        if(str[i] < '0' || str[i] > '9'){
          end = i; break;
        }
      }
    }

    length = end - begin>0 ? end - begin : length - begin;

    if(begin != -1){
      for(int i = begin; i < str.length(); i++){
        if(str[i] == '0'){ c++; }
        else{ break; }
      }
      temp = str.substr(begin + c, length - c);
      length = temp.length();
      if(length != 0){
        if(length > 10){
          if(tag == 1){ return INT_MAX; }
          else{ return INT_MIN; }
        }
        for(i = 0; i < length - 1; i++){
          c = temp[i] - '0';
          result = 10 * result + c;
        }
        if(length == 10){
          if(result > 214748364){
            if(tag == 1){ return INT_MAX; }
            else{ return INT_MIN; }
          }
          else{
            if(tag == 1  && result == 214748364 && temp[9] > '7'){
              return INT_MAX;
            }
            if(tag == -1  && result == 214748364 && temp[9] > '8'){
              return INT_MIN;
            }
          }
        }
        if(length <= 10){
          c = temp[i] - 48;
          result = 10 * result + c;
        }
      }
    }
    result = tag * result;
    return result;
  }
};

bool show_8(int setwidth){
  const string title = "8.String to Integer (atoi)";
  vector<string> input = {"42", "   -42", "4193 with words", "words and 987", "-91283472332"};
  vector<int> output = {42, -42, 4193, 0, -2147483648};
  Solution Program;

  bool result = true;
  for(int i=0; i<input.size(); i++){
    result = Program.myAtoi(input[i]) == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}