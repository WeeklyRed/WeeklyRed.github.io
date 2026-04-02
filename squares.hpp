#pragma once

 #include <cstdlib>  // if you want to compute std::abs

 //smallest on front
 // must be O(n) // TODO
 void sorted_squares(int *nums, int n);
 
 //Complexity O(nlogn) // Given to compare
 void square_then_sort(int* nums, int n);
 
 // to compare both arrays //TODO
 bool equal_arr(const int* a, const int* b, int n);