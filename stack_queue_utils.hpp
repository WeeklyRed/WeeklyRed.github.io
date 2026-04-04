//stackqueue/stack_queue_utils.hpp

#pragma once

#include "array/vector.hpp"
#include "list/doubly_linked.hpp"

#include "stackqueue/stack.hpp"
#include "stackqueue/queue.hpp"

#include <string>
#include <stdexcept>

std::string remove_duplicates(std::string input){
    dsac::stackqueue::stack<char> c;
    //std::stack<char> c;

    for(int i = 0; i < input.size(); i++){
        if(!(c.empty())){
            if(input[i] == c.top()){
                c.pop();
            }
            else{
                c.push(input[i]);
            }
        }
        else{
            c.push(input[i]);
        }
        
    }
    input.clear();
    input = "";
    int size = c.size();
    for(int i = 0; i < size; i++){
        input = c.top() + input;
        c.pop();
    }
    return input;
}

std::string clean_backspace_string(std::string input){
    dsac::stackqueue::stack<char> c;
        //std::stack<char> c;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '<'){
            if(!(c.empty())){
                c.pop();
            }
        }
        else{
            c.push(input[i]);
        }
    }
    input.clear();
    input = "";
    int size = c.size();
    for(int i = 0; i < size; i++){
        input = c.top() + input;
        c.pop();
    }
    return input;
}

template <
    typename T, 
    typename StackContainer=dsac::array::Vector<T>,
    typename QueueContainer=dsac::array::Vector<T>
    >
bool stack_contains(
    dsac::stackqueue::stack<T, StackContainer>& st, 
    dsac::stackqueue::queue<T, QueueContainer>& qu, 
    const T& elt){
        if(!(qu.empty())){
        throw std::invalid_argument("qu must be initially empty.");
    }

    bool f = false;
    int size = st.size();

    for(int i = 0; i < size; i++){
        if(st.top() == elt){
            f = true;
        }
        qu.push(st.top());
        st.pop();
    }
    
    for(int i = 0; i < size; i++){
        st.push(qu.front());
        qu.pop();
    }
    for(int i = 0; i < size; i++){
        qu.push(st.top());
        st.pop();
    }
    for(int i = 0; i < size; i++){
        st.push(qu.front());
        qu.pop();
    }
    return f;
    }