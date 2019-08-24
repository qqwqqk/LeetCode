#include "../header/code_medium.h"
 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if ((target = nums[i]) > 0) break;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] + target < 0) ++l;
                else if (nums[l] + nums[r] + target > 0) --r;
                else {
                    ans.push_back({target, nums[l], nums[r]});
                    ++l, --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
            }
        }
        return ans; 
    }
};

bool show_15(int setwidth){
  const string title = "15.3Sum";
  vector<int> input = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> output = {vector<int>{-1,-1,2}, vector<int>{-1,0,1}};
  Solution Program;

  bool result = true;
  vector<vector<int>> compareCache =  Program.threeSum(input);
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