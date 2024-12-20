#pragma once
#include <iostream>
#include "Iterator.h"
#include "Reverse_iterator.h"

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
    
    public:
        using iterator = Iterator<char>;
        using reverse_iterator = Reverse_iterator<iterator>;
        iterator begin() const;
        iterator end() const;
        reverse_iterator rbegin() const;
        reverse_iterator rend() const;

    public:
		friend String operator+(const char* str1, const String& str2);
        friend std::ostream& operator<<(std::ostream& stream, const String& other);
        
    private:
        static size_t getLength(const char* str);
        static void memcpy(char* des, const char* src, size_t size);

    private:
        char * m_string;
        size_t m_length;
        size_t m_capacity;
};



