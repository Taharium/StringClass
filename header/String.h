#pragma once
#include <iostream>

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
        //void appendRealloc(const String& stringToAppend);
        char* c_str() const;
        size_t size() const;
        void reserve(size_t size);
        size_t getCapacity() const;
        bool operator== (const String& str) const;

        friend std::ostream& operator<<(std::ostream& stream, const String& other);
        static size_t getLength(const char* str);

    private:
        void memcpy(char* des, const char* src, size_t size);

    private:
        char * m_string;
        size_t m_length;
        size_t m_capacity;
};