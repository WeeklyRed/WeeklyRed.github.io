#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_DISABLE_BREAK_INTO_DEBUGGER
#include "catch2/catch.hpp"
#include "array_bounds.hpp"





TEST_CASE("Testing code") 
{

    int a[] = {2, 5, 5, 5, 10};
    int n = sizeof(a) / sizeof(a[0]);
     
    // Test cases with various target values
    for (int t : {-1, 0, 2, 3, 5, 6, 10, 11}) {
        // Test iterative implementations
        CHECK(lower_bound_iterative(a, n, t) == std_lower_bound(a, n, t));
        CHECK(upper_bound_iterative(a, n, t) == std_upper_bound(a, n, t));

        // Test recursive implementations
        CHECK(lower_bound(a, n, t) == std_lower_bound(a, n, t));
 
        CHECK(upper_bound(a, n, t) == std_upper_bound(a, n, t));
         
        // Test frequency calculation
        CHECK(frequency_iterative(a, n, t) == std_frequency(a, n, t));
         
        std::cout << "Target " << t << ": ";
        std::cout << "LB=" << lower_bound(a, n, t) << ", ";
        std::cout << "UB=" << upper_bound(a, n, t) << ", ";
        std::cout << "Freq=" << frequency(a, n, t) << std::endl;
    }
    {
    INFO("Check for even length arrays");
     
    }    
}