#include "../header/code_medium.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> result;
        int length = nums.size();
        int val;
        
        for(int i = 0; i<length; i++){
          if(i>0 && nums[i-1] == nums[i]){ continue; }
          for(int j = i + 1; j<length; j++){
            if(j> i + 1 && nums[j-1] == nums[j]){ continue; }
            for(int k = j + 1; k<length; k++){
              if(k> j + 1 && nums[k-1] == nums[k]){ continue; }
              for(int l = k+1; l<length; l++){
                if(l> k + 1 && nums[l-1] == nums[l]){  continue; }
                val = nums[i]+nums[j]+nums[k]+nums[l];
                if(val == target){
                  vector<int> cache = {nums[i],nums[j],nums[k],nums[l]};
                  result.push_back(cache);
                }
                if(val > target){
                  break;
                }
              }
            }
          }
        }

        return result;
    }
};

bool show_18(int setwidth){
  const string title = "18.4 Sum";
  vector<int> input = {1, 0, -1, 0, -2, 2};
  int target = 0;
  vector<vector<int>> output = {vector<int>{-1, 0, 0, 1}, vector<int>{-2, -1, 1, 2}, vector<int>{-2,  0, 0, 2}};
  Solution Program;

  bool result = true;
  vector<vector<int>> compareCache =  Program.fourSum(input,target);
  for(int i=0; i<compareCache.size(); i++){
    for(int j=0; j<compareCache[i].size(); j++){
      if(output[i][j] != compareCache[i][j]){result = false; break; }
    }
    if(result == false){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}