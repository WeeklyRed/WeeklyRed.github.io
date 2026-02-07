//main.cpp
#include <iomanip>
#include <iostream>
#include <vector>
#include "prime.hpp"

int main() {
    const int LO = 2, HI = 10'000;

    long long halfOps = countModOpsHalf(LO, HI);
    long long sqrtOps = countModOpsSqrt(LO, HI);

    std::cout << halfOps << "\n"; // 1461014
    std::cout << sqrtOps << "\n"; // 65956
    return 0;
}