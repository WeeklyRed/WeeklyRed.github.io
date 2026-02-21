//include/reverse.hpp
 
 //declare generic versions
 
#include "reverse.ipp"
#pragma once

template <typename T1>
void reverse_array(T1 a[], int n);

template <typename T1>
void print_array(T1 a[], int n);

template <typename T1, typename T2>
bool checkReverse(T1 a[], T2 b[]);