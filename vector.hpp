#pragma once
#include <algorithm>     // provides max
#include <stdexcept>     // provides out_of_range exception

using std::max;

namespace dsac::array {

    template <typename T>
class Vector {
    private:
        int cap{0};
        int sz{0};
        T* data{nullptr};
    public:
        Vector(){
            cap = 0;
            sz = 0;
            data = nullptr;
            }

        int capacity() const{
            return cap;
        }

        int size() const{
            return sz;
        }

        bool empty() const{
            return (sz == 0);
        }
        
        const T& operator[](int i) const{
            if(i < 0 || i >= sz){
                throw std::out_of_range("Invalid Index");
            }
            return data[i];
        }

        T& operator[](int i){
            if(i < 0 || i >= sz){
                throw std::out_of_range("Invalid Index");
            }
            return data[i];
        }
        
        const T& at(int i) const{
            if(i < 0 || i >= sz){
                throw std::out_of_range("Invalid Index");
            }
            return data[i];
        }

        T& at(int i){
            if(i < 0 || i >= sz){
                throw std::out_of_range("Invalid Index");
            }
            return data[i];
        }

        const T& front() const{
            return data[0];
        }

        T& front(){
            return data[0];
        }

        const T& back() const{
            return data[sz-1];
        }

        T& back(){
            return data[sz-1];
        }

        void push_back(const T& elem){
            if(sz == cap){
                reserve(max(1, 2*cap));
            }
            data[sz] = elem;
            sz++;
        }

        void pop_back(){
            sz--;
            shrink();
        }

        void insert(int i, const T& elem){
            if(sz == cap){
                reserve(max(1, 2*cap));
            }
            for(int k = sz-1; k >= i; k--){
                data[k+1] = data[k];
            }
            data[i] = elem;
            sz++;
        }

        void erase(int i){
            for(int k = i+1; k <= sz-1; k++){
                data[k-1] = data[k];
            }
            pop_back();
        }

        void reserve(int minimum){
            if(cap < minimum){
                T* temp = new T[minimum];

                for(int i = 0; i < sz; i++){
                    temp[i] = data[i];
                }
                delete[] data;
                data = temp;
                cap = minimum;
            }
        }

        Vector(const Vector& other){
            clone(other);
        }

        Vector& operator=(const Vector& other){
            if(this != &other){
                delete[] data;
                clone(other);
            }
            return *this;
        }

        Vector(Vector&& other){
            transfer(other);
        }
        Vector& operator=(Vector&& other){
            if(this != &other){
                delete[] data;
                transfer(other);
            }
            return *this;
        }

        ~Vector() { delete[] data; }
    
    private:
        void clone(const Vector& other){
            cap = other.cap;
            sz = other.sz;
            data = new T[cap];
            for(int k = 0; k < sz; k++){
                data[k] = other.data[k];
            }
        }

        void transfer(Vector& other){
            cap = other.cap;
            sz = other.sz;
            data = other.data;
            other.cap = other.sz = 0;
            other.data = nullptr;
        }

    public:
        class iterator {
            friend class Vector;
            private:
                Vector* vec;
                int ind;        // index within the vector
            
            public:
                iterator(Vector* v = nullptr, int i = -1){
                    vec = v;
                    ind = i;
                }
                T& operator*() const{
                    return (*vec)[ind];
                }
                T* operator->() const{
                    return &(*vec)[ind];
                }
                iterator& operator++(){
                    ind++;
                    return *this;
                }
                iterator operator++(int){
                    iterator old(*this);
                    ind++;
                    return old;
                }
                iterator& operator--(){
                    ind--;
                    return *this;
                }
                iterator operator--(int){
                    iterator old(*this);
                    ind--;
                    return old;
                }
                bool operator==(iterator rhs) const{
                    return (vec == rhs.vec) && (ind == rhs.ind);
                }
                bool operator!=(iterator rhs) const{
                    return !(*this == rhs);
                }
        };

        class const_iterator {
            private:
                const Vector* vec;
                int ind;                   // index within the vector
            
            public:
                const_iterator(const Vector* v = nullptr, int i = -1){
                    vec = v;
                    ind = i;
                }
                const T& operator*() const{
                    return *vec[ind];
                }
                const T* operator->() const{
                    return &*vec[ind];
                }
                const_iterator& operator++(){
                    ind++;
                    return *this;
                }
                const_iterator operator++(int){
                    iterator old(*this);
                    ind++;
                    return old;
                }
                const_iterator& operator--(){
                    ind--;
                    return *this;
                }
                const_iterator operator--(int){
                    iterator old(*this);
                    ind--;
                    return old;
                }
                bool operator==(const_iterator rhs) const{
                    return (vec == rhs.vec) && (ind == rhs.ind);
                }
                bool operator!=(const_iterator rhs) const{
                    return !(*this == rhs);
                }
        };

        iterator begin(){
            return iterator(this, 0);
        }
        iterator end(){
            return iterator(this, sz);
        }
        const_iterator cbegin() const{
            return const_iterator(this, 0);
        }
        const_iterator cend() const{
            return const_iterator(this, sz);
        }

        iterator insert(iterator it, const T& elem){
            insert(it.ind, elem);
            return it;
        }

        iterator erase(iterator it){
            erase(it.ind);
            return it;
        }

        void shrink(){
            if(cap > 0 && sz <= cap/4){
                int new_cap = max(1, cap/2);
                reallocate(new_cap);
            }
        }
        
        void shrink_to_fit(){
            if(cap > sz){
                int new_cap = max(1, sz);
                reallocate(new_cap);
            }
        }

        void reallocate(int new_cap){
            if(new_cap == cap){
                return;
            }
            T* temp = new T[new_cap];
            for(int i = 0; i < sz; i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            cap = new_cap;
        }
    
}; // Vector class

}  // namespace dsac::array
