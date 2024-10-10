#pragma once
#include <iterator>
#include <cstddef>

template<class T>
class Iterator {
    public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::bidirectional_iterator_tag;

        Iterator();
        Iterator(pointer ptr);

        pointer operator-> () const;
        reference operator* () const;
        //reference operator[] (difference_type n) const;

        Iterator& operator++ ();
        Iterator& operator-- ();
        Iterator operator++ (int);
        Iterator operator-- (int);
        //reference operator+= (difference_type n);
        bool operator== (const Iterator& iter) const;
        bool operator!= (const Iterator& iter) const;

        //friend bool operator!= (const Iterator& lIter, const Iterator& rIter);
        //friend bool operator== (const Iterator& lIter, const Iterator& rIter);

    private:
        pointer m_ptr;
};

template <typename T>
Iterator<T>::Iterator() : m_ptr(nullptr) {}

template <typename T>
Iterator<T>::Iterator(pointer ptr) : m_ptr(ptr) {}

template<typename T>
typename Iterator<T>::pointer Iterator<T>::operator-> () const {
    return m_ptr;
}

template<typename T>
typename Iterator<T>::reference Iterator<T>::operator* () const {
    return *m_ptr;
}

/* template <typename T>
typename Iterator<T>::reference Iterator<T>::operator[](difference_type n) const {
    return *(m_ptr + n);
} */

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    ++m_ptr;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--() {
    --m_ptr;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int) {
    Iterator<T> temp(m_ptr);
    --m_ptr;
    return temp;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator<T> temp(m_ptr);
    ++m_ptr;
    return temp;
}

template <typename T>
bool Iterator<T>::operator== (const Iterator<T>& iter) const {
    return m_ptr == iter.m_ptr;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& iter) const {
    return !(*this == iter);
}

/* template <typename T>
bool operator!=(const Iterator<T>& lIter, const Iterator<T>& rIter) {
    return !(lIter == rIter);
} */

/* template <typename T>
bool operator==(const Iterator<T>& lIter, const Iterator<T>& rIter) {
    return lIter.m_ptr == rIter.m_ptr;
} */
