#include "../header/code_method.h"

//解析行数据
vector<int> analyzeLine(string str){
  int strSub = 0, strPos = 0;
  string cache = "";
  char split = ' ';
  vector<int> result;

  for(int i = 0 ; i < str.size(); i++){
    if(str[i] == split){
      strSub = i - strPos;
      cache = str.substr(strPos, strSub);
      result.push_back(stoi(cache));
      strPos = i+1;
    }
  }
  cache = str.substr(strPos, str.size() - strPos);
  if(cache.size()>0){ result.push_back(stoi(cache)); }

  return result;
}