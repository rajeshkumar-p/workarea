/*
Inheritence 

* Capability of a class to derive properties and characteristics from another
  class is called Inheritance. 
* Inheritance is one of the most important feature of Object Oriented Programming.
  (Code reusability)

Sub Class: The class that inherits properties from another class is called Sub
class or Derived Class.
Super Class:The class whose properties are inherited by sub class is called Base
Class or Super class.

*/

#include <iostream>
 
using namespace std;

// Base class or Super class
class Shape {
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
      
   protected:
      int width;
      int height;
};

// Derived class or Sub class
class Rectangle: public Shape {
   public:
      int getArea() { 
         return (width * height); 
      }
};

int main(void) {
   Rectangle Rect;
 
   Rect.setWidth(5);
   Rect.setHeight(7);

   // Print the area of the object.
   cout << "Area of Rectangle : " << Rect.getArea() << endl;

   return 0;
}
