#pragma once

// Standard library functions for testing
 int std_lower_bound(const int* arr, int n, int target);
 int std_upper_bound(const int* arr, int n, int target);
 int std_frequency(const int *arr, int n, int target);
 
 // Recursive versions
 int lower_bound(const int* arr, int n, int target);
 int upper_bound(const int* arr, int n, int target);
 int frequency(const int *arr, int n, int target);
 // Recursive helper versions
 int lower_bound_recursive(const int* arr, int low, int high, int target);
 int upper_bound_recursive(const int* arr, int low, int high, int target);

 // Iterative versions
 
 int lower_bound_iterative(const int* arr, int n, int target);
 int upper_bound_iterative(const int* arr, int n, int target);
 int frequency_iterative(const int *arr, int n, int target);
 