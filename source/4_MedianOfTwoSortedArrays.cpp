#include "../header/code_hard.h"
 
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double result; 
    int n1 = nums1.size(), n2 = nums2.size();
    int number = n1 + n2, tag = number % 2;

    if (n1*n2 == 0){
      if (n1 == 0){
        if (tag == 1) result = nums2[n2 / 2];
        else result = 0.5*(nums2[n2 / 2] + nums2[n2 / 2 - 1]);
      }
      else{
        if (tag == 1) result = nums1[n1 / 2];
        else result = 0.5*(nums1[n1 / 2] + nums1[n1 / 2 - 1]);
      }
    }
    else{
      int max = nums1[n1 - 1]>nums2[n2 - 1] ? nums1[n1 - 1] : nums2[n2 - 1];
      int min = nums1[0]<nums2[0] ? nums1[0] : nums2[0];

      if (max<min){
        if (tag == 1){
          if (nums1[0]>nums2[0]){
            if (n1>n2) result = nums1[(n1 - n2) / 2];
            else result = nums2[(n1 + n2) / 2 + 1];
          }
          else{
            if (n1>n2) result = nums1[(n1 + n2) / 2 + 1];
            else result = nums2[(n1 - n2) / 2];
          }
        }
        else{
          if (n1 == n2){ result = 0.5*(max + min); }
          else{
            if (nums1[0]>nums2[0]){
              if (n1>n2) result = 0.5*(nums1[(n1 - n2) / 2] + nums1[(n1 - n2) / 2 - 1]);
              else result = 0.5*(nums1[(n1 + n2) / 2] + nums1[(n1 + n2) / 2 - 1]);
            }
            else{
              if (n1>n2) result = 0.5*(nums1[(n1 + n2) / 2] + nums1[(n1 + n2) / 2 - 1]);
              else result = 0.5*(nums1[(n1 - n2) / 2] + nums1[(n1 - n2) / 2 - 1]);
            }
          }
        }
      }
      else{
        int xi = 0, yi = 0, xj = n1 - 1, yj = n2 - 1;
        bool flag = true;
        while (min<max&&(xi+yi)<(xj+yj+2)){
          if (flag){
            if (xi == n1){ min = nums2[yi++]; }
            else{
              if (yi == n2){ min = nums1[xi++]; }
              else{
                if (nums1[xi]<nums2[yi]){ min = nums1[xi++]; }
                else{ min = nums2[yi++]; }
              }
            }
            flag = !flag;
          }
          else{
            if (xj < 0){ max = nums2[yj--]; }
            else{
              if (yj < 0){ max = nums1[xj--]; }
              else{
                if (nums1[xj]>nums2[yj]){ max = nums1[xj--]; }
                else{ max = nums2[yj--]; }
              }
            }
            flag = !flag;
          }
        }
        if (tag == 1){ result = min; }
        else{ result = 0.5*(max + min); }
      }
    }

    return result;
  }
};

bool show_4(int setwidth){
  const string title = "4.Median of Two Sorted Arrays";
  vector<vector<int>> input1 = {vector<int>{1, 3}, vector<int>{1, 2}};
  vector<vector<int>> input2 = {vector<int>{2},    vector<int>{3, 4}};
  vector<double> output = {2.0, 2.5};
  Solution Program;

  bool result = true;
  for(int i=0; i<input1.size(); i++){
    double cache = Program.findMedianSortedArrays(input1[i], input2[i]);
    result =  cache == output[i];
    if(!result){ break; }
  }
  
  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}