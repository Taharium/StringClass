#include "../header/String.h"
#include "String.h"

//default constructor
String::String() : m_string(nullptr), m_length(0), m_capacity(0) {}

//Constructor with const char*
String::String(const char* str){
    m_length = getLength(str);
    if(m_length == -1){
        std::cout << "Error in getting length\n";
        m_string = nullptr;
        m_capacity = 0;
        return;
    }
    m_capacity = m_length + 1;
    m_string = new char[m_capacity];
    memcpy(m_string, str, m_capacity);
    m_string[m_capacity - 1] = '\0';
}

String& String::appendNew(const String& stringToAppend) {
    if(m_string && stringToAppend.m_string){        //check if string is nullptr
        size_t lengthOfOtherString = stringToAppend.m_length;
        size_t lengthOfNewString = m_length + lengthOfOtherString + 1;
        if(m_capacity < lengthOfNewString){
            char* newString = new char[lengthOfNewString];
            memcpy(newString, m_string, m_length);
            memcpy(newString + m_length, stringToAppend.m_string, lengthOfOtherString);
            newString[lengthOfNewString - 1] = '\0';
            delete[] m_string;
            m_string = newString;
            m_capacity = lengthOfNewString;
            m_length = getLength(m_string); 
            newString = nullptr;
        }
        else {
            memcpy(m_string, stringToAppend.m_string, lengthOfOtherString);
            m_string[lengthOfOtherString - 1] = '\0';
            m_capacity = lengthOfNewString;
            m_length = getLength(m_string); 
        }
    }
    return *this;
}

/* //Append String& and return *this instead of void
void String::appendRealloc(const String& stringToAppend){
    
    if(m_string && stringToAppend.m_string){
        size_t lengthOfOtherString = stringToAppend.m_length;
        size_t lengthOfNewString = m_length + lengthOfOtherString + 1;
        m_string = (char*)std::realloc(m_string, lengthOfNewString);
        memcpy(m_string + m_length, stringToAppend.m_string, lengthOfOtherString);
        m_string[lengthOfNewString - 1] = '\0';

        m_capacity = lengthOfNewString;
        m_length = getLength(m_string); 
    }
} */

//copy assignment
String& String::operator=(const String& other){
    if(&other != this || !other.m_string){
        m_length = other.m_length;
        m_capacity = other.m_capacity;
        delete[] m_string;
        m_string = new char[m_capacity];
        memcpy(m_string, other.m_string, m_capacity);
    }
    return *this;
}

//Copy constructor
String::String(const String& other){
    if(!other.m_string){
        return;
    }
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_string = new char[m_capacity];
    memcpy(m_string, other.m_string, m_capacity);
}

//Move constructor
String::String(String&& other){
    if(!other.m_string){
        return;
    }
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_string = other.m_string;
    other.m_string = nullptr;
    other.m_length = 0;
    other.m_capacity = 0;
}

//Move assignment
String& String::operator=(String&& other) {
    if(&other != this || !other.m_string){
        m_length = other.m_length;
        m_capacity = other.m_capacity;
        delete[] m_string;
        m_string = other.m_string;
        other.m_string = nullptr;
        other.m_length = 0;
        other.m_capacity = 0;
    }
    return *this;
}

size_t String::size() const {
    return m_length;
}

size_t String::getCapacity() const {
    return m_capacity;
}

char* String::c_str() const {
    return m_string;
}

bool String::operator== (const String& str) const {
    if(str.m_length != m_length){
        return false;
    }

    for(int i = 0; str.m_string[i] != '\0'; i++){
        if(m_string[i] != str.m_string[i] ){
            return false;
        }
    }
    return true;
}

String& String::operator+=(const String& other) {
    if(other.m_string == nullptr || getLength(other.m_string) <= 0){
        return *this;
    }
    size_t newLength = m_length + other.m_length;
	char* str = new char[newLength + 1];

	for (int i = 0; i < m_length; i++) {
		str[i] = m_string[i];
	}

    for (int i = 0; i < other.m_length; i++) {
        str[m_length + i] = other.m_string[i];
    }

	delete m_string;
	m_string = str;
	m_length = newLength;
	m_capacity = newLength + 1;
	m_string[m_length] = '\0';
    return *this;
}

String& String::operator+=(const char* stringtoAppend) {
    if(stringtoAppend == nullptr || getLength(stringtoAppend) <= 0){
        return *this;
    }

	size_t lengthOfOtherString = getLength(stringtoAppend);
	size_t newLength = m_length + lengthOfOtherString;
	char* str = new char[newLength + 1];
	
    for (int i = 0; i < m_length; i++) {
		str[i] = m_string[i];
	}

	for (int i = 0; i < lengthOfOtherString; i++) {
		str[m_length + i] = stringtoAppend[i];
	}

	delete m_string;
	m_string = str;
	m_length = newLength;
	m_capacity = newLength + 1;
	m_string[m_length] = '\0';
	return *this;

}

//destructor
String::~String(){
    delete[] m_string;
}

//reserve size
void String::reserve(size_t size) {
    if(m_capacity >= size){
        return;
    }

    if(m_capacity < size){
        m_string = (char*)realloc(m_string, size);
        m_capacity = size;
        m_string[m_capacity - 1] = '\0';
    }
}

std::ostream& operator<<(std::ostream& stream, const String& other){
    stream << other.m_string;
    return stream;
}

size_t String::getLength(const char* str) {
    if(!str){
        return -1;
    }

    size_t len = 0;
    for (char i = *str; i != '\0'; ) {
        ++len;
        i = *(str + len);
    }
    return len;
}

//https://stackoverflow.com/questions/11876361/implementing-own-memcpy-size-in-bytes
void String::memcpy(char* des, const char* src, size_t size) {

    char* pdes = des;
    char* psrc = (char*)src;
    int loops = (size / sizeof(uint64_t));

    for(int i = 0; i < loops; ++i){ // pdes[0] -> *(pdes + 0) -> below the m_length is added
        *((uint64_t*)pdes) = *((uint64_t*)psrc);    //points to the first char -> cast first char to 8bytes
        pdes += sizeof(uint64_t);                   // now you have 8 chars in a variable
        psrc += sizeof(uint64_t);
    }

    loops = size % sizeof(src);         //rest is taken
    for(int i = 0; i < loops; i++){     
        *pdes = *psrc;                  //byte by byte
        ++pdes;
        ++psrc;
    }

}
