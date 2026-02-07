//prime.cpp
#include "prime.hpp"
#include "iostream"


// TODO: Implement isPrimeHalf
bool isPrimeHalf(int n, long long* modOps) {
    // Your implementation 
    // Checks for divisibility up to n/2
    // return true if n is prime else return false
    // count modulo operations when modOps is not nullptr

    //long long count = 0;
    //modOps = &count;
    if(n <= 1){
        return false;
    }
    if(n == 2){
        return true;
    }
    if(modOps){
        (*modOps)++;
    }
    
    if(n%2 == 0){
        return false;
    }

    //std::cout<<*modOps;
    for(int i = 3; i <= n/2; i+=2){
        if(modOps){
            (*modOps)++;
        }
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
// TODO: Implement isPrimeSqrt
bool isPrimeSqrt(int n, long long* modOps) {
    // Your implementation here
    //Checks for divisibility up to square root of n
    // return true if n is prime else return false
    // Remember to count modulo operations when modOps is not nullptr

    //long long count = 0;
    //modOps = &count;
    
    if(n <= 1){
        return false;
    }
    if(n == 2){
        return true;
    }
    if(modOps){
        (*modOps)++;
    }
    if(n%2 == 0){
        return false;
    }

    for(int i = 3; i <= sqrt(n); i+=2){
        if(modOps){
            (*modOps)++;
        }
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

// TODO: Implement countModOps
long long countModOpsHalf(int lo, int hi) {
    // Your implementation here
    // This should call the provided isPrime function for each number in range [lo, hi]
    // and return the total number of modulo operations performed

    long long total = 0;

    for(int i = lo; i <= hi; i++){
        //long long* modops = nullptr;
        isPrimeHalf(i, &total);
        //total += *modops;
    }
    return total;
}

long long countModOpsSqrt(int lo, int hi) {
        // Your implementation here
    // This should call the provided isPrime function for each number in range [lo, hi]
    // and return the total number of modulo operations performed

    long long total = 0;

    for(int i = lo; i <= hi; i++){
        //long long* modops = nullptr;
        isPrimeSqrt(i, &total);
        //total += *modops;
    }
    return total;

}