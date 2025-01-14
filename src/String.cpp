#include "../header/String.h"

//default constructor
String::String() : m_string(nullptr), m_length(0), m_capacity(0) {}

//Constructor with const char*
String::String(const char* str){
    m_length = getLength(str);
    if(m_length == -1){
        m_string = nullptr;
        m_capacity = 0;
        return;
    }
    m_capacity = m_length + 1;
    m_string = new char[m_capacity];
    memcpy(m_string, str, m_capacity);
    m_string[m_capacity - 1] = '\0';
}

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

//destructor
String::~String(){
    delete[] m_string;
}

String& String::appendNew(const String& stringToAppend) {
    if(m_string && stringToAppend.m_string && stringToAppend.m_length > 0){        //check if string is nullptr
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
            m_length = lengthOfNewString - 1; 
            newString = nullptr;
        }
        else {
            memcpy(m_string + m_length, stringToAppend.m_string, lengthOfOtherString);
            m_string[m_length + lengthOfOtherString] = '\0';
            //m_capacity = lengthOfNewString;
            m_length += lengthOfOtherString; 
        }
    }
    return *this;
}

const char* String::c_str() const {
    return m_string;
}

size_t String::size() const {
    return m_length;
}

//reserve size
void String::reserve(size_t size) {
    if(m_capacity >= size){
        return;
    }

    if(m_capacity < size){
        m_string = (char*)std::realloc(m_string, size);
        m_capacity = size;
        m_string[m_capacity - 1] = '\0';
    }
}

size_t String::getCapacity() const {
    return m_capacity;
}

String::operator const char* () const{
    return this->c_str();
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

bool String::operator!=(const String &str) const {
    return !(*this == str);
}

bool String::operator== (const char* str) const {
    if(getLength(str) != m_length){
        return false;
    }

    for(int i = 0; str[i] != '\0'; i++){
        if(m_string[i] != str[i] ){
            return false;
        }
    }
    return true;
}

bool String::operator!=(const char *str) const {
    return !(*this == str);
}

//String::operator const char *() const 

String& String::operator+=(const String& stringToAppend) {
    return appendNew(stringToAppend);
}

String& String::operator+=(const char* stringToAppend) {
    return appendNew(stringToAppend);
}

 
String String::operator+(const String& string) {
    String newString;

    if(!m_string && !string.m_string){
        return String();
    }

    if(!m_string){
        return string;
    }

    if(!string.m_string){
        return *this;
    }
    
    size_t newStringLength = m_length + string.m_length + 1;
    newString.reserve(newStringLength);
    //TODO: in one function beginning with me
    memcpy(newString.m_string, m_string, m_length);
    memcpy(newString.m_string + m_length, string.m_string, string.m_length);
    newString.m_string[newStringLength - 1] = '\0';
    newString.m_length = newStringLength - 1;
    newString.m_capacity = newStringLength;
    
    return newString;
}

String String::operator+(const char* string) {
    String newString;

    if(!m_string){
        return string;
    }

    size_t lengthOfOtherString = getLength(string);
    size_t newStringLength = m_length + lengthOfOtherString + 1;
    newString.reserve(newStringLength);
    memcpy(newString.m_string, m_string, m_length);
    memcpy(newString.m_string + m_length, string, lengthOfOtherString);
    newString.m_string[newStringLength - 1] = '\0';
    newString.m_length = newStringLength - 1;
    newString.m_capacity = newStringLength;
    
    return newString;
}

String::iterator String::begin() const {
    return iterator(m_string);
}

String::iterator String::end() const {
    return iterator(m_string + m_length);
}

String::reverse_iterator String::rbegin() const {
    return reverse_iterator(end());
}

String::reverse_iterator String::rend() const {
    return reverse_iterator(begin());
}

String operator+(const char* str1, const String& str2) {
    String newString;

    if(!str2.m_string){
        return str1;
    }

    size_t lengthOfString1 = String::getLength(str1);
    size_t newStringLength = str2.m_length + lengthOfString1 + 1;
    newString.reserve(newStringLength);
    String::memcpy(newString.m_string, str1, lengthOfString1);
    String::memcpy(newString.m_string + lengthOfString1, str2.m_string, str2.m_length);
    newString.m_string[newStringLength - 1] = '\0';
    newString.m_length = newStringLength - 1;
    newString.m_capacity = newStringLength;
    
    return newString;
}

std::ostream& operator<<(std::ostream& stream, const String& other){
    stream << other.m_string;
    return stream;
}

size_t String::getLength(const char *str)
{
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