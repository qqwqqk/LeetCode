#include "../header/code_other.h"

bool is_prime(int n){
  int iter = n / 6 + 1;
  int stop = sqrt(n) + 5;

	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11) { return true; }
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n == 1) { return false; }

	for (unsigned long long i = 1; i <= iter; i++) {
		if (i * 6 >= stop) { break; }
		if ((n % (i * 6 + 1) == 0) || (n % (i * 6 + 5) == 0)) { return false; }
	}

	return true;
}