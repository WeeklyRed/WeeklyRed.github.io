#define CATCH_CONFIG_MAIN
#include <vector>
#include <algorithm>
#include "catch2/catch.hpp"

#include "list/singly_linked.hpp"
#include "list/circularly_linked.hpp"
#include "list/doubly_linked.hpp"



using namespace dsac::list;

void test_singly_linked() {
    std::cout << "Testing SinglyLinkedList...\n";

    // Test 1: empty list
    SinglyLinkedList<int> SL;
    assert(SL.empty() && SL.size() == 0);

    // Test 2: push_back and front/back
    SL.push_back(10);
    SL.push_back(20);
    SL.push_back(30);
    assert(SL.front() == 10 && SL.back() == 30 && SL.size() == 3);

    // Test 3: reverse
    SL.reverse();
    int expected_rev[] = {30, 20, 10};
    int i = 0;
    for (int x : SL) {
        assert(x == expected_rev[i++]);
    }

    // Test 4: concatenate
    SinglyLinkedList<int> SM;
    SM.push_back(40);
    SM.push_back(50);
    SL.concatenate(SM);
    int expected_concat[] = {30, 20, 10, 40, 50};
    i = 0;
    for (int x : SL) assert(x == expected_concat[i++]);
    assert(SM.empty());

    std::cout << "SinglyLinkedList tests passed.\n";
}

void test_doubly_linked() {
    std::cout << "Testing DoublyLinkedList...\n";

    DoublyLinkedList<int> DL, DM;

    // Test 1: push_back
    DL.push_back(1);
    DL.push_back(2);
    DL.push_back(3);
    assert(DL.front() == 1 && DL.back() == 3 && DL.size() == 3);

    // Test 2: push_front
    DL.push_front(0);
    assert(DL.front() == 0 && DL.size() == 4);

    // Test 3: concatenate
    DM.push_back(4);
    DM.push_back(5);
    DL.concatenate(DM);
    int expected_concat[] = {0, 1, 2, 3, 4, 5};
    int i = 0;
    for (int x : DL) assert(x == expected_concat[i++]);
    assert(DM.empty());

    std::cout << "DoublyLinkedList tests passed.\n";
}

void test_circularly_linked() {
    std::cout << "Testing CircularlyLinkedList...\n";

    CircularlyLinkedList<int> L, A, B;

    // Test 1: push_back
    for (int i = 1; i <= 6; i++) L.push_back(i);
    assert(L.size() == 6 && L.front() == 1 && L.back() == 6);

    // Test 2: splitEven
    L.splitEven(A, B);
    assert(L.empty() && A.size() == 3 && B.size() == 3);

    int expected_A[] = {1, 2, 3};
    int expected_B[] = {4, 5, 6};

    for (int i = 0; i < A.size(); i++) {
        assert(A.front() == expected_A[i]);
        A.rotate();
    }
    for (int i = 0; i < B.size(); i++) {
        assert(B.front() == expected_B[i]);
        B.rotate();
    }

    std::cout << "CircularlyLinkedList tests passed.\n";
}

int main() {
    test_singly_linked();
    test_doubly_linked();
    test_circularly_linked();
    std::cout << "All linked list tests passed!\n";
    return 0;
}