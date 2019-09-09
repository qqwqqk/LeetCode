#include "../header/code_method.h"

//斐波那契数列通项公式
double getFibonacci(int n){
  const double sqrt5 = sqrt(5);
  const double x1 = 0.5 * (1 + sqrt5);
  const double x2 = 0.5 * (1 - sqrt5);
  double result = (pow(x1,n) - pow(x2,n)) / sqrt5;
  return result;
}