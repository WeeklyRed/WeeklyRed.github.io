#include "squares.hpp"
 
 #include <algorithm> //you may use std::copy(a1, a1+n, a1_copy); to copy array elements from a1 a1_copy (optional)
 
 #include <cstdlib>  // if you want to compute std::abs (optional) ​

 // must be of O(n)
 void sorted_squares(int *nums, int n){
 // ToDo


    for(int i = 0; i < n; i++){
        nums[i] = nums[i]*nums[i];
    }

    for(int i = 1; i < n; i++){

        
        if(nums[i] < nums[i-1]){
            bool temp = true;
            int count = 0;
            int copy = std::move(nums[i]);
            while(temp){
                if(copy < nums[(i-count)-1]){
                    nums[i-count] = std::move(nums[(i-count)-1]);
                    nums[(i-count)-1] = std::move(copy);
                    count++;
                }
                else{
                    temp = false;
                }
                if((i-count)-1 == -1){
                    temp = false;
                }
            }
        }

    }


 }
 
//compares two array if both have same elements
bool equal_arr(const int* a, const int* b, int n) {
 // ToDo
    for(int i = 0; i < n; i++){
        if(!(a[i] == b[i])){
            return false;
        }
    }
    return true;
}

 //Complexity O(n log n)
 void square_then_sort(int* nums, int n) {
     for (int i{0}; i<n; i++) 
         nums[i] = nums[i] * nums[i];
     std::sort(nums, nums + n);
 }