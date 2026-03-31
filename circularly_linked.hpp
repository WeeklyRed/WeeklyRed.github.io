#pragma once

#include <utility>     // provides std::swap

namespace dsac::list {

/// circularly linked list
template <typename T>
class CircularlyLinkedList {
    private:
        class Node {
            public:
                T elem;
                Node* next;
                // ToDo
                Node(const T& element, Node* nxt = nullptr) : elem(element), next(nxt) {}
        };
    private:
        int sz{0};
        Node* tail{nullptr};
    public:
        // ToDo
        CircularlyLinkedList() = default;

        int size() const { return sz; }
        bool empty() const { return sz == 0; }
        T& front() { return tail->next->elem; }
        const T& front() const { return tail->next->elem; }
        T& back() { return tail->elem; }
        const T& back() const { return tail->elem; }
        void push_back(const T& e) {
            Node* n = new Node(e);
            if (empty()) {
                n->next = n;
                tail = n;
            } else {
                n->next = tail->next;
                tail->next = n;
                tail = n;
            }
            sz++;
        }

        void push_front(const T& e) {
            Node* n = new Node(e);
            if (empty()) {
                n->next = n;
                tail = n;
            } else {
                n->next = tail->next;
                tail->next = n;
            }
            sz++;
        }

        void pop_front() {
            if (empty()) return;

            Node* head = tail->next;

            if (sz == 1) {
                delete head;
                tail = nullptr;
            } else {
                tail->next = head->next;
                delete head;
            }
            sz--;
        }

        void rotate() {
            if (tail) tail = tail->next;
        }

        void splitEven(CircularlyLinkedList& A, CircularlyLinkedList& B) {
            if (empty()) return;
            if (sz % 2 != 0)
                throw std::logic_error("Size must be even");

            int half = sz / 2;

            Node* head = tail->next;
            Node* curr = head;

            for (int i = 1; i < half; i++)
                curr = curr->next;

            Node* firstTail = curr;
            Node* secondHead = curr->next;
            Node* secondTail = tail;

            // A
            A.tail = firstTail;
            A.tail->next = head;
            A.sz = half;

            // B
            B.tail = secondTail;
            B.tail->next = secondHead;
            B.sz = half;

            // clear original
            tail = nullptr;
            sz = 0;
        }
    private:
        void clear() {
            while (!empty()) pop_front();
        }
    public:
        friend void swap(CircularlyLinkedList& a, CircularlyLinkedList& b) {
            std::swap(a.tail, b.tail);
            std::swap(a.sz, b.sz);
        }
        void clear();
        CircularlyLinkedList(const CircularlyLinkedList& other) : tail(nullptr), sz(0) {
            if (other.empty()) return;
            Node* curr = other.tail->next;
            for (int i = 0; i < other.sz; i++) {
                push_back(curr->elem);
                curr = curr->next;
            }
        }

        CircularlyLinkedList& operator=(const CircularlyLinkedList& other) {
            if (this == &other) return *this;
            clear();
            Node* curr = other.tail ? other.tail->next : nullptr;
            for (int i = 0; i < other.sz; i++) {
                push_back(curr->elem);
                curr = curr->next;
            }
            return *this;
        }

        CircularlyLinkedList(CircularlyLinkedList&& other) noexcept
            : tail(other.tail), sz(other.sz) {
            other.tail = nullptr;
            other.sz = 0;
        }

        CircularlyLinkedList& operator=(CircularlyLinkedList&& other) noexcept {
            if (this == &other) return *this;
            clear();
            tail = other.tail;
            sz = other.sz;
            other.tail = nullptr;
            other.sz = 0;
            return *this;
        }

        ~CircularlyLinkedList() { clear(); }
        void print() {
            if (empty()) return;
            Node* curr = tail->next;
            for (int i = 0; i < sz; i++) {
                std::cout << curr->elem << " ";
                curr = curr->next;
            }
            std::cout << "\n";
        }
};

}  // namespace dsac::list

