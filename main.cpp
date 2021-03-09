//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include "catch.hpp"
using Catch::Matchers::Equals;
//------------------------------

// Fix the following class
class Complex {
private: 
  int re;
  int im;
public:
  Complex(int = 0, int = 0);
  int getRe();
  int getIm();

  void operator>>(std::string&) const;
  void operator<<(const std::string&);
};

Complex(int re = 0, int im = 0){
  this->re = re;
  this->im = im;
}
int getRe(){return this->re;}
int getIm(){return this->im;} 

void Complex::&operator>>(std::string& a) const{
  a.append(std::to_string(this->re))
  if (this->im > 0){
    s.append('+'); 
  }
}

void Complex::&operator<<(const std::string&){}
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
}
//------------------------------
