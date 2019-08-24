#include <algorithm>
#include <vector>
#include <map>

#include<iostream>
#include<cmath>
#include<iomanip>

#include "header/code_other.h"
using namespace std;


int main()
{
  for(int i=0; i<100; i++){
    if(is_prime(i)){cout<< i <<'\t';}
  }
  return 0;
}