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
        const char* c_str() const;
        size_t size() const;
        void reserve(size_t size);
        size_t getCapacity() const;
        bool operator== (const String& str) const;
        bool operator== (const char* str) const;
        operator const char*() const{
            return this->c_str();
        }
        class Iterator {
		    public:
			    Iterator(char* ptr);
			    Iterator& operator++();
			    Iterator operator++(int);
                Iterator& operator--();
			    Iterator operator--(int);
			    char& operator*();
				char& operator->();
			    bool operator!=(const Iterator& other) const;
			    bool operator==(const Iterator& other) const;

            private:
				char* m_ptr;
        };

		Iterator begin() const;
		Iterator end() const;

        friend std::ostream& operator<<(std::ostream& stream, const String& other);
		String& operator+=(const String& other);
		String& operator+=(const char* stringtoAppend);
		String operator+(const String& string);
		String operator+(const char* string);
		friend String operator+(const char* str1, const String& str2);

        static size_t getLength(const char* str);

    private:
        static void memcpy(char* des, const char* src, size_t size);

    private:
        char * m_string;
        size_t m_length;
        size_t m_capacity;

};