#include "../header/code_method.h"

//斐波那契数列通项公式
double getFibonacci(int n){
  const double sqrt5 = sqrt(5);
  const double x1 = 0.5 * (1 + sqrt5);
  const double x2 = 0.5 * (1 - sqrt5);
  double result = (pow(x1,n) - pow(x2,n)) / sqrt5;
  return result;
}

//杨辉三角
vector<int> getRow(int rowIndex) {
    vector<int>result;
    for(int i=0;i<=rowIndex;++i)
    {
        result.push_back(1);
        for(int j=i-1;j>0;--j)
            result[j]+=result[j-1];
    }
    return result;
}