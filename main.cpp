#include "header/code_other.h"
 
#include "../header/code_medium.h"
 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int length = nums.size(); 

        int val;
        int distance;
        int mindistance = -1;
        
        for(int i = 0; i<length; i++){
          if(i>0 && nums[i-1] == nums[i]){ continue; }
          for(int j = i + 1; j<length; j++){
            if(j> i+1 && nums[j-1] == nums[j]){ continue; }
            for(int k = j + 1; k<length; k++){
              if(k> j+1 && nums[k-1] == nums[k]){ continue; }
              int pos = nums[i]+nums[j]+nums[k] - target;
              distance = pos > 0 ? pos : -pos;

              if(mindistance == -1 || mindistance > distance){
                mindistance = distance;
                val = nums[i]+nums[j]+nums[k];
              }

              if(pos > 0){ continue; }
            }
          }
        }

        return val;
    }
};

int main(){
  const string title = "16.3Sum Closest";
  vector<int> nums = {0,0,0};
  int target = 1;
  int output = 0;
  Solution Program;

  bool result = output == Program.threeSumClosest(nums,target);
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return 0;
}