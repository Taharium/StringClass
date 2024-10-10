#pragma once
#include<iterator>
#include <cstddef>
#include <type_traits>

template<typename It>
class Reverse_iterator {
    public:
        using value_type = It;
        using difference_type = std::ptrdiff_t;
        using pointer = It*;
        using reference = It&;
        using iterator_category = std::bidirectional_iterator_tag;

        //explicit Reverse_iterator(pointer ptr);
        explicit Reverse_iterator(value_type ptr);
        decltype(auto) operator*() const;
        pointer operator->() const;
        auto getPointer();
        //reference operator[] (difference_type n) const;
        Reverse_iterator& operator++();    
        Reverse_iterator& operator--();    
        Reverse_iterator operator++(int);  
        Reverse_iterator operator--(int); 

        bool operator== (const Reverse_iterator& iter) const;
        bool operator!= (const Reverse_iterator& iter) const;


    private:
        It m_ptr;
};

/* template <typename T>
Reverse_iterator<T>::Reverse_iterator(pointer ptr) : m_ptr(ptr){}
 */


/* template <typename T>
typename Reverse_iterator<T>::reference Reverse_iterator<T>::operator[](difference_type n) const {
    return *(m_ptr - n);
}
 */

template <typename T>
Reverse_iterator<T>::Reverse_iterator(value_type ptr) : m_ptr(ptr) {}

template <typename T>
decltype(auto) Reverse_iterator<T>::operator*() const {
    T _Tmp = m_ptr;
    return *--_Tmp;
}

template <typename T>
typename Reverse_iterator<T>::pointer Reverse_iterator<T>::operator->() const {
    T temp = m_ptr;
    --temp;
    if(std::is_pointer_v<T>){
        return temp;
    } else {
        return temp.operator->();
    }
}

template <typename T>
auto Reverse_iterator<T>::getPointer() {
    return m_ptr;
}

template <typename T>
Reverse_iterator<T>& Reverse_iterator<T>::operator++(){
    --m_ptr;
    return *this;
}

template <typename T>
Reverse_iterator<T>& Reverse_iterator<T>::operator--() {
    ++m_ptr;
    return *this;
}

template <typename T>
Reverse_iterator<T> Reverse_iterator<T>::operator++(int) {
    Reverse_iterator<T> temp = m_ptr;
    --m_ptr;
    return temp;
}

template <typename T>
Reverse_iterator<T> Reverse_iterator<T>::operator--(int) {
    Reverse_iterator<T> temp = m_ptr;
    ++m_ptr;
    return temp;
}

template <typename T>
bool Reverse_iterator<T>::operator== (const Reverse_iterator<T>& iter) const {
    return m_ptr == iter.m_ptr;
}

template <typename T>
bool Reverse_iterator<T>::operator!=(const Reverse_iterator<T>& iter) const {
    return !(*this == iter);
}

