#include <iomanip>
#include <iostream>
//#include <vector>
#include <cstring>//std::strlen()
#include "reverse.hpp"

//main.cpp

int main() {
     // int[]
     int ai[]{1, 2, 3, 4};
     int ni = (sizeof(ai)/sizeof(ai[0]));
     std::cout<<"ai: "; 
     print_array<int>(ai, ni);
     reverse_array<int>(ai, ni);
     std::cout<<"ai: "; 
     print_array<int>(ai, ni);
 
     // double[]
     double ad[] = {1.5, 2.5, 3.5, 4.5};
     int nd = (sizeof(ad)/sizeof(ad[0]));// compute size of array
     std::cout<<"ad: "; 
     print_array<double>(ad, nd);
     reverse_array<double>(ad, nd); 
     std::cout<<"ad: "; 
     print_array<double>(ad, nd);
 
     // char[] (not a C-string)
     char letters[] = {'E','C','E','3','5', '1', '4'};
     int nc = (sizeof(letters)/sizeof(letters[0]));// compute size of array
     std::cout<<"letters: "; 
     print_array<char>(letters, nc);
     reverse_array<char>(letters, nc);
     std::cout<<"letters: "; 
     print_array<char>(letters, nc);
 
     // C-string: reverse only the characters, not the '\0'
     char word[] = "hello";
     std::cout << "cstr: " << word << "\n";
     int nw = std::strlen(word);// compute size of string  
     reverse_array<char>(word, nw);
     std::cout << "cstr: " << word << "\n";
 
     return 0;
}
 /*
 Expected Output
 ai: : [1, 2, 3, 4]
 ai: : [4, 3, 2, 1]
 ad: : [1.5, 2.5, 3.5, 4.5]
 ad: : [4.5, 3.5, 2.5, 1.5]
 letters: : [E, C, E, 3, 5, 1, 4]
 letters: : [4, 1, 5, 3, E, C, E]
 cstr: hello
 cstr: olleh
 */