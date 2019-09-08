#include "../header/code_other.h"

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

//斐波那契数列通项公式
double getFibonacci(int n){
  const double sqrt5 = sqrt(5);
  const double x1 = 0.5 * (1 + sqrt5);
  const double x2 = 0.5 * (1 - sqrt5);
  double result = (pow(x1,n) - pow(x2,n)) / sqrt5;
  return result;
}

//阶乘公式
int getFactorial(int n){
  int result = 1;
  if(n==0 || n==1){ return result;}
  for(int i=1; i<=n; i++){ result *= i; }
  return result;
}

//排序函数
bool sortFun(int x, int y){
  return x > y;
}

//质数判断
bool is_prime(int n){
  int iter = n / 6 + 1;
  int stop = sqrt(n) + 5;

	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11) { return true; }
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n == 1) { return false; }

	for (int i = 1; i <= iter; i++) {
		if (i * 6 >= stop) { break; }
		if ((n % (i * 6 + 1) == 0) || (n % (i * 6 + 5) == 0)) { return false; }
	}

	return true;
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
