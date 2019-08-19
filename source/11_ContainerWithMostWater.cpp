#include "../header/code_medium.h"
 
class Solution {
public:
  int maxArea(vector<int>& height){
    int result = 0, cache = 0;
    int first = 0;
    int last = height.size() - 1;

    result = height[first] * height[last];
    if(height[first] < height[last]){
      result = height[first] * (last - first);
    }else{
      result = height[last] * (last - first);
    }

    while (first < last){
      if(height[first] < height[last]){ first++; }
      else{ last--; }

      if(height[first] < height[last]){ cache = height[first] * (last - first); }
      else{ cache = height[last] * (last - first); }

      if(cache > result){ result = cache; }
    }

    return result;
  }
};

bool show_11(int setwidth){
  const string title = "11.Container With Most Water";
  vector<int> input = {1,8,6,2,5,4,8,3,7};
  int output = 49;
  Solution Program;

  bool result = Program.maxArea(input) == output;
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}