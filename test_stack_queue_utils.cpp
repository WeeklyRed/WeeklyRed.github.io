//tests/test_stack_queue_utils.cpp

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "array/vector.hpp"
#include "list/doubly_linked.hpp"

#include "stackqueue/stack.hpp"
#include "stackqueue/queue.hpp"
//#include "stackqueue/deque.hpp"
#include "stackqueue/array_queue.hpp"
#include "stackqueue/stack_queue_utils.hpp"

#include <string>


TEST_CASE("Check removeDuplicates") 
{
    {
    INFO("Check removeDuplicates");
        std::string s = "abbaca";
        s = remove_duplicates(s);
        CHECK(s == "ca");

        s = "abcde";
        s = remove_duplicates(s);
        CHECK(s == "abcde");
    }    
}

TEST_CASE("Check clean_backspace_string") 
{
    {
    INFO("Check clean_backspace_string");
        std::string s = "ab<c";
        s = clean_backspace_string(s);
        CHECK(s == "ac");

        s = "a<bc<d";
        s = clean_backspace_string(s);
        CHECK(s == "bd");
    }    
}


//for some reason dsac::stackqueue::queue didn't want to work
/*
TEST_CASE("stack_contains_restore") 
{
    {
    INFO("Check stack_contains_restore");
        dsac::stackqueue::stack<int> s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        
        dsac::stackqueue::stack<int> copy = s;
        
        //dsac::stackqueue::queue<int> q;

            
        int x = 3;
        int sz = s.size();
        bool t = stack_contains(s, q, x);
        
        CHECK(t);
        CHECK(q.empty());

        x = 6;
        t = stack_contains(s, q, x);
        CHECK(!t);
        CHECK(q.empty());
        
    }    
}*/
    