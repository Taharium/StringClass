#include "header/String.h"
#include <cassert>


//doctest
int main(){

    //Arrange append
    String a("Hello");
    String b = "YOYO";
    String g = "BLABLA";
    const char* test_a = "HelloYOYOBLABLABLABLA";

    //act append
    a.appendNew(b).appendNew(g);
    a.appendNew(g);
    std::cout << a.c_str() << '\n';

    //test append with null
    a.appendNew(nullptr); //Error in getting length

    //assert append
    assert("Expected: HelloYOYOBLABLABLABLA" && a == test_a);
    //std::cout << "Append(HelloYOYOBLABLA): " << a << '\n'; 
    
    //Arrange & Act CopyConstructor
    const char* test_f = "YOYO";
    String f = b;

    //test with nullptr
    String h = nullptr; // Error in getting length
    
    //Assert copyconstructor
    assert("Expected: YOYO" && f == test_f);
    //std::cout << "CopyConstructor(YOYO): " << f << '\n'; 
    
    //Arrange CopyAssignment
    String c = "Yuyu";
    const char* test_c = "YOYO";

    //Act 
    c = b;

    //test with null
    b = nullptr; // Error in getting length
    
    //assert
    assert("Expected: YOYO" && c == test_c);
    //std::cout << "CopyAssignment(YOYO): " << c << '\n'; 

    //Arrange MoveConstructor
    String d = (String&&)c;
    const char* test_d = "YOYO";

    //test with null
    String t = std::move(nullptr); // Error in getting length
    
    //assert
    assert("Expected: YOYO" && d == test_d);
    //std::cout << "MoveConstructor(YOYO): " << d << '\n'; 

    //Arrange MoveAssignment
    String z = (String&&)f;
    const char* test_d2 = "HelloYOYOBLABLABLABLA";
    
    //test with null
    z = std::move(nullptr); //Error in getting length
    
    //Act
    d = std::move(a);

    //Assert
    assert("Expected: HelloYOYOBLABLABLABLA" && d == test_d2);
    //std::cout << "MoveAssignment(HelloYOYOBLABLA): " << d << '\n';

    //Test all remaining function

    //Arrange
    String test_d3 = "HelloYOYOBLABLABLABLA";
    size_t size = test_d3.size();
    size_t capacity = 30;

    //Assert
    assert("Expected: HelloYOYOBLABLABLABLA" && d == test_d3);
    assert("Expected: HelloYOYOBLABLABLABLA" && d == test_d3);
    //std::cout << "C_str()(HelloYOYOBLABLA): " << d.c_str() << '\n';
    assert("Expected: 21" && d.size() == size);

    //Act
    d.reserve(30);

    //assert
    assert("Expected: 21" && d.size() == size);
    assert("Expected: 30" && d.getCapacity() == capacity);
    //std::cout << "size()(15): " << d.size() << '\n';
    //std::cout << "reserve(20)" << '\n';
    //std::cout << "size()(15): " << d.size() << '\n';
    //std::cout << "getCapacity()(20): " << d.getCapacity() << '\n';
    //std::cout << "C_str()(HelloYOYOBLABLA): " << d.c_str() << '\n';

    //Act
    d.reserve(10);

    //assert
    assert("Expected: 30" && d.getCapacity() == capacity);
    //std::cout << "reserve(10)" << '\n';
    //std::cout << "getCapacity()(20): " << d.getCapacity() << '\n';

    String test_conc = "ToConcatenateto";
    String test_conc2 = "TobeConcatenated";
    test_conc += test_conc2;
    assert("Expected: ToConcatenatetoTobeConcatenated" && test_conc == "ToConcatenatetoTobeConcatenated");

    test_conc += nullptr;
    assert("Expected: ToConcatenatetoTobeConcatenated" && test_conc == "ToConcatenatetoTobeConcatenated"); 
    test_conc += "";
    assert("Expected: ToConcatenatetoTobeConcatenated" && test_conc == "ToConcatenatetoTobeConcatenated"); 

    String test_conc3 = "ToConcatenateto";
    test_conc3 += "TobeConcatenated";
    assert("Expected: ToConcatenatetoTobeConcatenated" && test_conc3 == "ToConcatenatetoTobeConcatenated");
    test_conc3 += nullptr;
    assert("Expected: ToConcatenatetoTobeConcatenated" && test_conc3 == "ToConcatenatetoTobeConcatenated"); 
    test_conc3 += "";
    assert("Expected: ToConcatenatetoTobeConcatenated" && test_conc3 == "ToConcatenatetoTobeConcatenated"); 

}