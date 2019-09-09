#include "header/code_method.h"

int main(){
  cout<<"\nFibonacci"<<endl;
  for(int i=1; i<=10; i++){ 
    cout<< getFibonacci(i)<<" "; 
    if(i%5==0){ cout<<endl; }
  }

  cout<<"\nFactorial"<<endl;
  for(int i=1; i<=10; i++){ 
    cout<< getFactorial(i)<<" "; 
    if(i%5==0){ cout<<endl; }
  }
  cout<<"\nPrime"<<endl;
  
  int count = 0;
  for(int i=1; i<=100; i++){ 
    if(is_prime(i)){
      cout<< i <<" "; 
      count = count + 1;
    if(count%5 == 0){ cout<<endl; }
    }
  }

  return 0;
}