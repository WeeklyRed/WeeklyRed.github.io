#pragma once

#include <utility>     // provides std::swap

namespace dsac::list {
//akin to std::list
template <typename T>
class DoublyLinkedList {
    private:
        class Node {
            public:
                T elem;
                Node* prev{nullptr};
                Node* next{nullptr};
                
                // ToDo
                Node();
                Node(const T& element, Node* prv, Node* nxt) : elem(element), prev(prv), next(nxt) {}
        };
        int sz{0};
        Node* header; // sentinel node
        Node* trailer;// sentinel node
        void create_sentinels();
    public:
        // ToDo
        DoublyLinkedList() { init(); }
        int size() const { return sz; }
        bool empty() const { return sz == 0; }
        T& front() { return header->next->elem; }
        const T& front() const { return header->next->elem;}
        T& back() { return trailer->prev->elem; }
        const T& back() const { return trailer->prev->elem; }
    private:
        Node* insert_before(T elem, Node* successor) {
            Node* newNode = new Node(elem, successor->prev, successor);
            successor->prev->next = newNode;
            successor->prev = newNode;
            sz++;
            return newNode;
        }
        void erase(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            sz--;
        }
    public:
        void push_front(const T& e) {
            Node* n = new Node(e, header, header->next);
            header->next->prev = n;
            header->next = n;
            sz++;
        }

        void push_back(const T& e) {
            Node* n = new Node(e, trailer->prev, trailer);
            trailer->prev->next = n;
            trailer->prev = n;
            sz++;
        }

        void pop_front() {
            if (empty()) return;
            Node* n = header->next;
            header->next = n->next;
            n->next->prev = header;
            delete n;
            sz--;
        }

        void pop_back() {
            if (empty()) return;
            Node* n = trailer->prev;
            trailer->prev = n->prev;
            n->prev->next = trailer;
            delete n;
            sz--;
        }

        void concatenate(DoublyLinkedList& M) {
            if (this == &M || M.empty()) return;

            if (empty()) {
                header->next = M.header->next;
                trailer->prev = M.trailer->prev;
                header->next->prev = header;
                trailer->prev->next = trailer;
                sz = M.sz;
            } else {
                Node* a = trailer->prev;
                Node* b = M.header->next;
                Node* c = M.trailer->prev;

                a->next = b;
                b->prev = a;
                c->next = trailer;
                trailer->prev = c;

                sz += M.sz;
            }

            M.header->next = M.trailer;
            M.trailer->prev = M.header;
            M.sz = 0;
        }
    public:
        class iterator {
            friend class DoublyLinkedList;
            private:
                Node* node_ptr;
            public:
                iterator(Node* ptr = nullptr) : node_ptr(ptr) {}

            T& operator*() const { return node_ptr->elem; }

            T* operator->() const { return &(node_ptr->elem); }

            iterator& operator++() {
                node_ptr = node_ptr->next;
                return *this;
            }

            iterator operator++(int) {
                iterator temp = *this;
                node_ptr = node_ptr->next;
                return temp;
            }

            iterator& operator--() {
                node_ptr = node_ptr->prev;
                return *this;
            }

            iterator operator--(int) {
                iterator temp = *this;
                node_ptr = node_ptr->prev;
                return temp;
            }

            bool operator==(const iterator& other) const {
                return node_ptr == other.node_ptr;
            }

            bool operator!=(const iterator& other) const {
                return node_ptr != other.node_ptr;
            }
        };
        class const_iterator {
            private:
                const Node* node_ptr;
            public:
                const_iterator(const Node* ptr = nullptr) : node_ptr(ptr) {}

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

            const_iterator& operator--() {
                node_ptr = node_ptr->prev;
                return *this;
            }

            const_iterator operator--(int) {
                const_iterator temp = *this;
                node_ptr = node_ptr->prev;
                return temp;
            }

            bool operator==(const const_iterator& other) const {
                return node_ptr == other.node_ptr;
            }

            bool operator!=(const const_iterator& other) const {
                return node_ptr != other.node_ptr;
            }
        };

    public:
        iterator begin() { return iterator(header->next); }
        const_iterator begin() const { return const_iterator(header->next); }
        iterator end() { return iterator(trailer); }
        const_iterator end() const { return const_iterator(trailer); }
        iterator insert(iterator it, const T& elem) {
            Node* newNode = insert_before(elem, it.node_ptr);
            return iterator(newNode);
        }

        iterator erase(iterator it) {
            Node* nextNode = it.node_ptr->next;
            erase(it.node_ptr);
            return iterator(nextNode);
        }
    private:
        void clone(const DoublyLinkedList& other) {
            clear();  // remove all nodes first
            for (Node* curr = other.header->next; curr != other.trailer; curr = curr->next)
                push_back(curr->elem);  // reuse push_back to maintain order
        }
    public:
        friend void swap(DoublyLinkedList& a, DoublyLinkedList& b) {
            std::swap(a.header, b.header);
            std::swap(a.trailer, b.trailer);
            std::swap(a.sz, b.sz);
        }
        void clear() {
            while (!empty()) pop_front();
        }
        DoublyLinkedList(const DoublyLinkedList& other) {
            init();
            for (Node* curr = other.header->next; curr != other.trailer; curr = curr->next)
                push_back(curr->elem);
        }
        DoublyLinkedList& operator=(const DoublyLinkedList& other) {
            if (this == &other) return *this;
            clear();
            for (Node* curr = other.header->next; curr != other.trailer; curr = curr->next)
                push_back(curr->elem);
            return *this;
        }
        DoublyLinkedList(DoublyLinkedList&& other) noexcept
            : header(other.header), trailer(other.trailer), sz(other.sz) {
            other.header = other.trailer = nullptr;
            other.sz = 0;
        }
        DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept {
            if (this == &other) return *this;
            clear();
            delete header;
            delete trailer;
            header = other.header;
            trailer = other.trailer;
            sz = other.sz;
            other.header = other.trailer = nullptr;
            other.sz = 0;
            return *this;
        }
        ~DoublyLinkedList() {
            clear();
            delete header;
            delete trailer;
        }
        void print() const {
            for (Node* curr = header->next; curr != trailer; curr = curr->next)
                std::cout << curr->elem << " ";
            std::cout << "\n";
        }
};
}  // namespace dsac::list
