#include "../header/code_medium.h"
 
class Solution {
public:
  string intToRoman(int num) {
    string result = "";
    int temp, iterator;
    string single, plural, target;
    
    for(int i = 3; i > -1; i--){
      iterator = (int)pow(10, i);
      switch (iterator){
      case 1:
        single = 'I'; plural = 'V'; target = 'X'; break;
      case 10:
        single = 'X'; plural = 'L'; target = 'C'; break;
      case 100:
        single = 'C'; plural = 'D'; target = 'M'; break;
      case 1000:
        single = 'M'; plural = '_'; target = '_'; break;
      default:
        cout << "error" << endl;
      }

      temp = num / iterator;
      num = num % iterator;

      if(temp > 0 && temp < 4){
        for(int j = 0; j < temp; j++){ result += single; }
      }
      else if(temp == 4){
        result += single + plural;
      }
      else if(temp > 4 && temp < 9){
        result += plural;
        for(int j = 0; j < temp - 5; j++){ result += single; }
      }
      else if(temp == 9){
        result += single + target;
      }
      else{ }
    }
    
    return result;
  }
};

bool show_12(int setwidth){
  const string title = "12.Integer to Roman";
  vector<int> input = {3, 4, 9, 58, 1994};
  vector<string> output = {"III", "IV", "IX", "LVIII", "MCMXCIV"};
  Solution Program;

  bool result = true;
  for(int i=0; i<input.size(); i++){
    result = Program.intToRoman(input[i]) == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}