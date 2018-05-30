#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>
using namespace std;

int main(){

	int init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	vector<int> height(begin(init), end(init));

	int result = 0;

	int Max_num = -1, Min_num = 0;
	int Number, Length;
	int rank = 0, temp = 0;
	int index = 0, first = 0, last = 0;

	Number = height.size();

	while (Max_num != 0){

		Max_num = Min_num = 0;
		for (index = 0; index < Number; index++){
			if (height[index]>0){
				Min_num = height[index];
				first = index;
				break;
			}
		}

		for (; index < Number; index++){
			Max_num = height[index] > Max_num ? height[index] : Max_num;
			if (height[index] > 0){
				last = index;
				Min_num = height[index] < Min_num ? height[index] : Min_num;
			}
		}

		Length = last - first;
		if (rank >= Max_num && Length * 2 < Number){
			break;
		}
		rank += Min_num;
		
		for (index = 0; index < Number; index++){
			if (height[index] > 0){
				height[index] = height[index] - Min_num;
			}
		}

		temp = rank*Length;
		result = result>temp ? result : temp;
	}

	cout << result << endl;
	system("pause");

}