/*

Friend Function
Used to grant a non-member function access to the private members of a class 
by using a friend.
friend function has access to all private and protected members of the class 
for which the class, preceding it with the keyword friend

*/

#include<iostream.h>
using namespace std;
 
class student
{
   private:
      int a,b;
   public:
      void getab()
      {
         cout<<endl<<"Ent val for a and b: ";
         cin>>a>>b;
      }
      void putab()
      {
         cout<<endl<<" Values are: "<<a<<"  "<<b<<endl;
      }
      friend int add(student);  // function declaration
};
 
 
int add(student f)     // function definition
{
   return f.a+f.b;
}
 
void main()
{
   student ff;  // object creation
   ff.getab();
   ff.putab();
   cout<<endl<<"Added value is:"<<add(ff);
}


