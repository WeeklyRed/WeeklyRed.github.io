#include "array_bounds.hpp"
 #include <cassert>
 #include <iostream>

 void test_binary_search() {
    std::cout << "test";
     int a[] = {2, 5, 5, 5, 10};
     int n = sizeof(a) / sizeof(a[0]);
     
     // Test cases with various target values
     for (int t : {-1, 0, 2, 3, 5, 6, 10, 11}) {
         // Test iterative implementations
         assert(lower_bound_iterative(a, n, t) == std_lower_bound(a, n, t));
         assert(upper_bound_iterative(a, n, t) == std_upper_bound(a, n, t));

         // Test recursive implementations
         assert(lower_bound(a, n, t) == std_lower_bound(a, n, t));

         assert(upper_bound(a, n, t) == std_upper_bound(a, n, t));

         // Test frequency calculation
         assert(frequency(a, n, t) == std_frequency(a, n, t));
         assert(frequency_iterative(a, n, t) == std_frequency(a, n, t));
         
         std::cout << "Target " << t << ": ";
         std::cout << "LB=" << lower_bound(a, n, t) << ", ";
         std::cout << "UB=" << upper_bound(a, n, t) << ", ";
         std::cout << "Freq=" << frequency(a, n, t) << std::endl;
     }

     std::cout << "All tests passed!" << std::endl;
 }
 
 int main() {

     test_binary_search();
     return 0;
 }
 
 //for array {2, 5, 5, 5, 10};
 /*
 Target -1: LB=0, UB=0, Freq=0
 Target 0: LB=0, UB=0, Freq=0
 Target 2: LB=0, UB=1, Freq=1
 Target 3: LB=1, UB=1, Freq=0
 Target 5: LB=1, UB=4, Freq=3
 Target 6: LB=4, UB=4, Freq=0
 Target 10: LB=4, UB=5, Freq=1
 Target 11: LB=5, UB=5, Freq=0
 All tests passed!
 */