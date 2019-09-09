#include "../header/code_method.h"

//输出全排列
vector<vector<int>> analyzePermutation(vector<int> array){
  const int n = array.size();
  int lists[n];
  copy(array.begin(), array.end(), lists);
  vector<vector<int>> result;

  sort (lists,lists + n);
  reverse (lists,lists + n);

  do {
    vector<int> caches(lists,lists + n);
    // for(int i=0; i<n; i++){ cout<< caches[i]<<' '; } cout<<endl;
    result.push_back(caches);
  } while ( prev_permutation(lists,lists+n) );

  return result;
}

//n进制数进位
vector<int> decimalcarry(vector<int> nums, int n){
  const int length = nums.size();
  if(length == 0){ return nums;}
  int i=0;
  while(1){
    nums[i] = nums[i] + 1;
    if(nums[i] < n){break;}
    else{
      nums[i] = 0;
      i++;
      if(i == length){nums.clear(); break;}
    }
  }
  return nums;
}