// prime.hpp
#include <cmath>
#include <memory>
#pragma once

using PrimeFn = bool(*)(int, std::shared_ptr<long long>);

//Checks for divisibility up to n/2
bool isPrimeHalf(int n, std::shared_ptr<long long> modOps);

//Checks for divisibility up to square root of n
bool isPrimeSqrt(int n, std::shared_ptr<long long> modOps);

//counts how many modulo operations a given prime function performs over a range of numbers.
long long countModOps(PrimeFn isPrime, int lo, int hi);