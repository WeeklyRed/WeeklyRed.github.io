//include/reverse.hpp
 
 //declare generic versions
 
//#include "reverse.ipp"
#pragma once

template <typename T1>
void reverse_array(T1 a[], int n);

template <typename T1>
void print_array(T1 a[], int n);

template <typename T1, typename T2>
bool checkReverse(T1 a[], T2 b[]);



 
 //define generic version
#include <iostream>


template <typename T1>
void reverse_array(T1 a[], int n){

  int temp = n-1;
  T1 b[n] = {};
    for(int i = 0; i < n; i++){
    b[i] = a[temp];
    temp--;
  }

  for(int i = 0; i < n; i++){
    a[i] = b[i];
    temp--;
  }

}

template <typename T1>
void print_array(T1 a[], int n){

  std::cout << "[";
  for(int i = 0; i < n; i++){
    std::cout << a[i];
    if(i != n-1){
      std::cout << ", ";
    }
  }
  std::cout << "]\n";

}

template <typename T1, typename T2>
bool checkReverse(T1 a[], T2 b[]){

  int size = (sizeof(a)/sizeof(a[0]));

  for(int i = 0; i < size; i++){
    if(a[i] != b[i]){
      return false;
    }
  }
  return true;
}