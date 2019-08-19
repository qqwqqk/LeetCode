#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int> findMode(vector<int> nums){
  vector<int> res;
  map<int,int> caches;
  int count = 0;
  for(int i=0;i<nums.size();i++){
    map<int,int>::iterator iter = caches.find(nums[i]);
    if(iter == caches.end()){
      caches.insert(pair<int,int> (nums[i],1));
    } else {
      int tag = iter->second + 1;
      iter->second = tag;
      if(tag == count){ res.push_back(iter->first); }
      if(tag > count){
        count = tag;
        res.clear();
        res.push_back(iter->first);
      }
    }
  }
  return res;
}

int main()
{
  vector<int> cache={1,2,3,4,5,2,2,3,3,1,1,3,1};
  vector<int> res;

  res = findMode(cache);
  
  for(int i=0; i<res.size(); i++){
    cout<<res[i]<<endl;
  }
  return 0;
}