#pragma once

#include <utility>     // provides std::swap

namespace dsac::list {

// similar to std::forward_list
template <typename T>
class SinglyLinkedList {
    private:
        class Node {
            public:
                T elem;
                Node* next;
                // ToDo
                Node(const T& element, Node* nxt = nullptr) : elem(element), next(next) {}
        };
        int sz{0};
        Node* head{nullptr};
        Node* tail{nullptr};
    public:
        // ToDo
            SinglyLinkedList() = default;

        int size() const { return sz; }
        bool empty() const { return sz == 0; }

        T& front() { return head->elem; }
        const T& front() const { return head->elem; }

        T& back() { return tail->elem; }
        const T& back() const { return tail->elem; }

        void push_front(const T& e) {
            head = new Node(e, head);
            if (sz == 0) tail = head;
            sz++;
        }

        void pop_front() {
            if (empty()) return;
            Node* old = head;
            head = head->next;
            delete old;
            sz--;
            if (sz == 0) tail = nullptr;
        }

        void push_back(const T& e) {
            Node* n = new Node(e);
            if (empty()) head = tail = n;
            else {
                tail->next = n;
                tail = n;
            }
            sz++;
        }

        void concatenate(SinglyLinkedList& M) {
            if (this == &M || M.empty()) return;

            if (empty()) {
                head = M.head;
                tail = M.tail;
                sz = M.sz;
            } else {
                tail->next = M.head;
                tail = M.tail;
                sz += M.sz;
            }

            M.head = M.tail = nullptr;
            M.sz = 0;
        }

        void reverse() {
            if (!head || !head->next) return;

            Node* prev = nullptr;
            Node* curr = head;
            tail = head;

            while (curr) {
                Node* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
        }

    public:
        class iterator {
            friend class SinglyLinkedList;
            private:
                Node* node_ptr;  // pointer to a node
            public:
                // ToDo
                iterator(Node* ptr = nullptr) : node_ptr(ptr) {}

                T& operator*() const { return node_ptr->elem; }

                T* operator->() const { return &(node_ptr->elem); }

                iterator& operator++() { // pre-increment
                    node_ptr = node_ptr->next;
                    return *this;
                }

                iterator operator++(int) { // post-increment
                    iterator temp = *this;
                    node_ptr = node_ptr->next;
                    return temp;
                }

                bool operator==(iterator rhs) const {
                    return node_ptr == rhs.node_ptr;
                }

                bool operator!=(iterator rhs) const {
                    return node_ptr != rhs.node_ptr;
                }
        };
    public:
        class const_iterator {
            private:
                Node* node_ptr;
            public:
                const_iterator(Node* ptr = nullptr) : node_ptr(ptr) {}

                const T& operator*() const { return node_ptr->elem; }

                const T* operator->() const { return &(node_ptr->elem); }

                const_iterator& operator++() {
                    node_ptr = node_ptr->next;
                    return *this;
                }

                const_iterator operator++(int) {
                    const_iterator temp = *this;
                    node_ptr = node_ptr->next;
                    return temp;
                }

                bool operator==(const_iterator rhs) const {
                    return node_ptr == rhs.node_ptr;
                }

                bool operator!=(const_iterator rhs) const {
                    return node_ptr != rhs.node_ptr;
                }
        };
    public:
        iterator begin() { return iterator(head); }
        const_iterator begin() const { return const_iterator(head); }
        iterator end() { return iterator(nullptr); }
        const_iterator end() const { return const_iterator(nullptr); }
        iterator insert_after(iterator it, const T& elem) {
            if (!it.node_ptr) return end();
            Node* newNode = new Node(elem, it.node_ptr->next);
            it.node_ptr->next = newNode;
            if (it.node_ptr == tail) tail = newNode;
            sz++;
            return iterator(newNode);
        }

        iterator erase_after(iterator it) {
            if (!it.node_ptr || !it.node_ptr->next) return end();
            Node* toDelete = it.node_ptr->next;
            it.node_ptr->next = toDelete->next;
            if (toDelete == tail) tail = it.node_ptr;
            delete toDelete;
            sz--;
            return iterator(it.node_ptr->next);
        }

    private:
        void clone(const SinglyLinkedList& other) {
            clear();  // start empty
            Node* curr = other.head;
            while (curr) {
                push_back(curr->elem);  // reuse push_back to create nodes
                curr = curr->next;
            }
        }
    public:
        friend void swap(SinglyLinkedList& a, SinglyLinkedList& b) {
            std::swap(a.head, b.head);
            std::swap(a.tail, b.tail);
            std::swap(a.sz, b.sz);
        }
        void clear() {
            while (!empty()) pop_front();
        }
        SinglyLinkedList(const SinglyLinkedList& other) : head(nullptr), tail(nullptr), sz(0) {
            clone(other);
        }
        SinglyLinkedList& operator=(const SinglyLinkedList& other) {
            if (this != &other) clone(other);
            return *this;
        }
        SinglyLinkedList(SinglyLinkedList&& other) noexcept
            : head(other.head), tail(other.tail), sz(other.sz) {
            other.head = other.tail = nullptr;
            other.sz = 0;
        }
        SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept {
            if (this == &other) return *this;
            clear();
            head = other.head;
            tail = other.tail;
            sz = other.sz;
            other.head = other.tail = nullptr;
            other.sz = 0;
            return *this;
        }
        ~SinglyLinkedList() { clear(); }
};

} // namespace dsac::list
