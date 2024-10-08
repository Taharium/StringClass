#pragma once
#include <iterator>
#include <cstddef>

template<typename T>
class Iterator {
    public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::random_access_iterator_tag;

        Iterator();
        Iterator(pointer ptr);

        pointer operator-> () const;
        reference operator* () const;
        reference operator[] (difference_type n) const;

        reference operator++ ();

        friend bool operator != (const Iterator& lIter, const Iterator& rIter);
        friend bool operator == (const Iterator& lIter, const Iterator& rIter);

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

template <typename T>
typename Iterator<T>::reference Iterator<T>::operator[](difference_type n) const {
    return *(m_ptr + n);
}

template <typename T>
typename Iterator<T>::reference Iterator<T>::operator++() {
    ++m_ptr;
    return *m_ptr;
}

template <typename T>
bool operator==(const Iterator<T>& lIter, const Iterator<T>& rIter) {
    return lIter.m_ptr == rIter.m_ptr;
}

template <typename T>
bool operator!=(const Iterator<T>& lIter, const Iterator<T>& rIter) {
    return !(lIter == rIter);
}