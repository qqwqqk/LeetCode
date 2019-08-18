#include "../header/code_easy.h"

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++){
      for(int j=i+1;j<nums.size();j++){
        if(nums[i]+nums[j]==target){
          nums.clear();
          nums.push_back(i);
          nums.push_back(j);
          return nums;
        }
      }
    }
    return nums;
  };
};

bool show_1(int setwidth){
  const string title = "1.Two Sum";
  vector<int> nums = {2,7,11,15};
  const int target = 9;
  vector<int> output = {0,1};
  Solution Program;

  bool result = output == Program.twoSum(nums,target);

  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}
