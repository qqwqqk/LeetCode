#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findPosIndex(vector<int> nums, int target){
  for (int i = 0; i <= nums.size() - 1; i++){
    if (nums[i] == target){
      // cout << "pos: " << i << endl;
      return i;
    }
  }
  return -1;
}

vector<int> nums_ori;
int sortWithLeastExchange(vector<int> &nums){
  nums_ori = nums;
  int count = 0;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 1; i++){
    int posIndex = findPosIndex(nums_ori, nums[i]);
    if (posIndex == i) continue;
    // cout << "exhange: " << nums_ori[i] << ":" << nums_ori[posIndex] << endl;
    swap(nums_ori[i], nums_ori[posIndex]);
    
    count++;
  }
  return count;
}

int main()
{
  int n;
  int cache;
  int res;
  vector<int> nums;
  cin>>n;
  for(int i=0; i<n*n; i++){
    cin>>cache;
    nums.push_back(cache);
  }
  res = sortWithLeastExchange(nums);
  cout << res <<endl;
  return 0;
}