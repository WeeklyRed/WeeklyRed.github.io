#include "array_bounds.hpp"
#include <algorithm>//std::lower_bound std::upper_bound



int lower_bound_recursive(const int* arr, int low, int high, int target){

    if(low > high){
        return high;
    }

    if(arr[low] >= target){
        return low;
    }
    else{
        return lower_bound_recursive(arr, low+1, high, target);
    }

}

int upper_bound_recursive(const int* arr, int low, int high, int target){

    if(high < 0){
        return low;
    }

    if(arr[high] > target){
        if(high == 0){
            return high;
        }
        if(arr[high-1] <= target){
            return high;
        }
    }
    
    return upper_bound_recursive(arr, low, high-1, target);

}




 int lower_bound(const int* arr, int n, int target){
    return lower_bound_recursive(arr, 0, n, target);
 }

 int upper_bound(const int* arr, int n, int target){
    return upper_bound_recursive(arr, n, n, target);
 }

 int frequency(const int *arr, int n, int target){

    return upper_bound(arr, n, target)-lower_bound(arr, n, target);

 }




int lower_bound_iterative(const int* arr, int n, int target){

    for(int i = 0; i < n; i++){
        if(arr[i] >= target){
            return i;
        }
    }
    return n;
}
int upper_bound_iterative(const int* arr, int n, int target){

    for(int i = n-1; i > 0; i--){
        if(arr[i] > target){
            if(arr[i-1] <= target){
                return i;
            }
        }
    }
    if(arr[0] > target){
        return 0;
    }
    return n;
}
int frequency_iterative(const int *arr, int n, int target){
    return (upper_bound_iterative(arr, n, target)-lower_bound_iterative(arr, n, target));
}



 // Standard library function for testing
 int std_lower_bound(const int* arr, int n, int target){
     auto it = std::lower_bound(arr, arr+n, target);
     int idx = it - arr; // convert iterator to index
     return idx;
 }

 // Standard library function for testing
 int std_upper_bound(const int* arr, int n, int target){
     auto it = std::upper_bound(arr, arr+n, target);
     int idx = it - arr; // convert iterator to index
     return idx;
 }

 // Standard library function for testing
 int std_frequency(const int *arr, int n, int target) {
     int lb = std_lower_bound(arr, n, target);
     int ub = std_upper_bound(arr, n, target);
     return ub - lb;
 }