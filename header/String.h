#pragma once
#include <iostream>
#include <iterator>
#include <cstddef>

class String {
    public:
        String();
        String(const String& other);
        String(const char* str);
        String(String&& other);
        String& operator=(const String& str);
        String& operator=(String&& str);
        ~String();
    
    public:
        String& appendNew(const String& stringToAppend);
        const char* c_str() const;
        size_t size() const;
        void reserve(size_t size);
        size_t getCapacity() const;        

    public:
        bool operator== (const String& str) const;
        bool operator!= (const String& str) const;
        bool operator== (const char* str) const;
        bool operator!= (const char* str) const;
        operator const char*() const;
		String& operator+=(const String& other);
		String& operator+=(const char* stringtoAppend);
		String operator+(const String& string);
		String operator+(const char* string);
		friend String operator+(const char* str1, const String& str2);
        
        friend std::ostream& operator<<(std::ostream& stream, const String& other);


        struct Iterator {
            using value_type = char;
            using difference_type = std::ptrdiff_t;
            using pointer = char*;
            using reference = char&;
            using iterator_category = std::random_access_iterator_tag;

            Iterator() : m_ptr(nullptr) {}
            Iterator(pointer ptr) : m_ptr(ptr) {}

            pointer operator-> () const { return ;}
            reference operator* () const { return *m_ptr; }



            private:
                pointer m_ptr;
        };

        Iterator begin() { return  Iterator(m_string); }
        Iterator end() { return Iterator(m_string + m_length); }
        Iterator rbegin() { return Iterator(m_string + m_length); }
        Iterator rend() { return Iterator(m_string); }


    private:
        static size_t getLength(const char* str);
        static void memcpy(char* des, const char* src, size_t size);

    private:
        char * m_string;
        size_t m_length;
        size_t m_capacity;
};