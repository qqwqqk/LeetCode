#include "header/code_other.h"
 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int,string> dictionary;
        dictionary.insert(pair<int, string> (2,"abc"));
        dictionary.insert(pair<int, string> (3,"def"));
        dictionary.insert(pair<int, string> (4,"ghi"));
        dictionary.insert(pair<int, string> (5,"jkl"));
        dictionary.insert(pair<int, string> (6,"mno"));
        dictionary.insert(pair<int, string> (7,"pqrs"));
        dictionary.insert(pair<int, string> (8,"tuv"));
        dictionary.insert(pair<int, string> (9,"wxyz"));

        queue<string> queuelist;
        queuelist.push(digits);
        while(1){
          int nums = queuelist.size();
          string str = queuelist.front();
          for(int i=0; i < str.size(); i++){
            if(str[i] > '0' && str[i] <= '9'){
              int key = str[i] - '0';
              queuelist.pop();
              string temp = dictionary[key];
              for(int j=0; j<temp.size(); j++){
                str[i] = temp[j];
                queuelist.push(str);
              }
              break;
            }
          }

          if(queuelist.size() <= nums){ break; }
        }

        vector<string> result;
        while(!queuelist.empty()){
          string item = queuelist.front();
          if(item.size() > 0){ result.push_back(item); }
          queuelist.pop();
        }

        return result;
    }
};

int main(){
  const string title = "17.Letter Combinations of a Phone Number";
  string digits = "";
  vector<string> output = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
  Solution Program;

  vector<string> cache = Program.letterCombinations(digits);
  bool result = true;
  for(int i=0; i<output.size(); i++){
    result = output[i] == cache[i];
    if(!result) { break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(64) << title << prompt << endl;
  return 0;
}