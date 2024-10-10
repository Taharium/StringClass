#include "header/String.h"
#include <cassert>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "header/doctest.h"
#include <vector>
#include <algorithm>



//doctest
TEST_CASE("main"){

    //Arrange append
    String a("Hello");
    String te("Hello");
    String b = "YOYO";
    String g = "BLABLA";
    const char* test_a = "HelloYOYOBLABLABLABLA";

    //act append
    a.appendNew(b).appendNew(g);
    a.appendNew(g);

    //test append with null
    a.appendNew(nullptr); //Error in getting length

    //CHECK_EQ append
    CHECK_EQ(a, test_a);
    //std::cout << "Append(HelloYOYOBLABLA): " << a << '\n'; 
    
    //Arrange & Act CopyConstructor
    const char* test_f = "YOYO";
    String f = b;

    //test with nullptr
    String h = nullptr; // Error in getting length
    
    //Assert copyconstructor
    CHECK_EQ(f, test_f);
    //std::cout << "CopyConstructor(YOYO): " << f << '\n'; 
    
    //Arrange CopyAssignment
    String c = "Yuyu";
    const char* test_c = "YOYO";

    //Act 
    c = b;

    //test with null
    b = nullptr; // Error in getting length
    
    //CHECK_EQ
    CHECK_EQ(c , test_c);
    //std::cout << "CopyAssignment(YOYO): " << c << '\n'; 

    //Arrange MoveConstructor
    String d = (String&&)c;
    const char* test_d = "YOYO";

    //test with null
    String t = std::move(nullptr); // Error in getting length
    
    //CHECK_EQ
    CHECK_EQ(d , test_d);
    //std::cout << "MoveConstructor(YOYO): " << d << '\n'; 

    //Arrange MoveAssignment
    String z = (String&&)f;
    const char* test_d2 = "HelloYOYOBLABLABLABLA";
    
    //test with null
    z = std::move(nullptr); //Error in getting length
    
    //Act
    d = std::move(a);

    //Assert
    CHECK_EQ(d , test_d2);
    //std::cout << "MoveAssignment(HelloYOYOBLABLA): " << d << '\n';

    //Test all remaining function

    //Arrange
    String test_d3 = "HelloYOYOBLABLABLABLA";
    size_t size = test_d3.size();
    size_t capacity = 30;

    //Assert
    CHECK_EQ(d , test_d3);
    CHECK_EQ(d , test_d3);
    //std::cout << "C_str()(HelloYOYOBLABLA): " << d.c_str() << '\n';
    CHECK_EQ( d.size() , size);

    //Act
    d.reserve(30);

    //CHECK_EQ
    CHECK_EQ(d.size() , size);
    CHECK_EQ(d.getCapacity() , capacity);
    //std::cout << "size()(15): " << d.size() << '\n';
    //std::cout << "reserve(20)" << '\n';
    //std::cout << "size()(15): " << d.size() << '\n';
    //std::cout << "getCapacity()(20): " << d.getCapacity() << '\n';
    //std::cout << "C_str()(HelloYOYOBLABLA): " << d.c_str() << '\n';

    //Act
    d.reserve(10);

    //CHECK_EQ
    CHECK_EQ(d.getCapacity() , capacity);
    //std::cout << "reserve(10)" << '\n';
    //std::cout << "getCapacity()(20): " << d.getCapacity() << '\n';

    String test_conc = "ToConcatenateto";
    String test_conc2 = "TobeConcatenated";
    String test_conc4;
    const char* test_con = "ToConcatenatetoTobeConcatenated";
    test_conc += test_conc2;
    CHECK_EQ(test_conc , "ToConcatenatetoTobeConcatenated");

    test_conc += nullptr;
    CHECK_EQ(test_conc , "ToConcatenatetoTobeConcatenated"); 
    test_conc += "";
    CHECK_EQ(test_conc , "ToConcatenatetoTobeConcatenated"); 

    String test_conc3 = "ToConcatenateto";
    test_conc3 += "TobeConcatenated";
    CHECK_EQ(test_conc3 , "ToConcatenatetoTobeConcatenated");
    test_conc3 += nullptr;
    CHECK_EQ(test_conc3 , "ToConcatenatetoTobeConcatenated"); 
    test_conc3 += "";
    CHECK_EQ(test_conc3 , "ToConcatenatetoTobeConcatenated");

    test_conc3 += test_conc4;
    CHECK_EQ(test_conc3, "ToConcatenatetoTobeConcatenated");

    String concat = test_conc2 + test_conc;
    CHECK_EQ(concat, "TobeConcatenatedToConcatenatetoTobeConcatenated");

    String concat2 = d + "hehe";
    CHECK_EQ(concat2, "HelloYOYOBLABLABLABLAhehe");

    String concat3 =  "hehe" + d;
    CHECK_EQ(concat3, "heheHelloYOYOBLABLABLABLA");

    String concat4 =  "" + d;
    CHECK_EQ(concat4, "HelloYOYOBLABLABLABLA");
    
    String null;
    String null2;
    String concat5 = null + null2;
    //std::cout << concat5 << '\n';

    assert(nullptr == concat5);
    
    String hello = "HELLO";
    const char* test_bye = "BYE"; 
    CHECK(hello != test_bye);

    int res = puts(d);
    CHECK(res >= 0);


}

/* int main(){
    String a = "HELLO";

    auto b = a.rend();
    std::cout << *b << '\n';

    for(auto it = a.rend(); it != a.rbegin(); --it) {
        std::cout << *it << '\n';
    }

    std::string test2 = "HELLO";
    std::cout << "DHDH\n";
    for(auto it = test2.rend(); it != test2.rbegin(); --it){
        std::cout << *it << '\n';
    }
    
    for(auto it = a.end(); it != a.begin(); --it) {
        std::cout << *it << '\n';
    }

    std::string test2 = "HELLO";
    std::cout << "DHDH\n";
    for(auto it = test2.end(); it != test2.begin(); --it){
        std::cout << *it << '\n';
    }
}
 */



TEST_CASE("TEST"){

    String test("Hello World");
    for (auto it = test.begin(); it != test.end(); ++it){
        std::cout << *it << '\n';
    }
    
    std::cout << "\n\n";
    String test2 = "HELLO";
    for(auto it = test2.rbegin(); it != test2.rend(); ++it){
        std::cout << *it << '\n';
    }

    std::cout << "\n\n";
    String test3 = "HELLO";
    for(auto it = test3.rend(); it != test3.rbegin(); --it){
        std::cout << *it << '\n';
    }

    std::cout << "\n\n";
    String test4("Hello World");
    for (auto it = test4.end(); it != test4.begin(); --it){
        std::cout << *it << '\n';
    }

    std::cout << "\n\n";
    std::string test5 = "HELLO";
    for(auto it = test5.rend(); it != test5.rbegin(); --it){
        std::cout << *it << '\n';
    }

    std::cout << "\n\n";
    std::string test6("HelloWorld");
    for (auto it = test6.end(); it != test6.begin(); --it){
        std::cout << *it << '\n';
    }
    

    std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << '\n';
    std::cout << (std::find(test.rbegin(), test.rend(), 'W') != test.rend()) << '\n';
}