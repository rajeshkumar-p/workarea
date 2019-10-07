/*

Friend Function
Used to grant a non-member function access to the private members of a class 
by using a friend.
friend function has access to all private and protected members of the class 
for which the class, preceding it with the keyword friend

*/

#include <iostream.h>
using namespace std;

/* function definition */
void personal_details()
{
  cout<< "Name : " << name;
  cout<< "Age  : " << age;
}
 
class employee 
{
   private:
      char name[20];
      int  emp_no;
      int  age;
      int  salary;
   public:
      employee(char *name, int age, int salary, int emp_no)
      {
         this.emp_no = emp_no;
         this.age = age; 
         this.salary = salary;
         strcpy(this,name, name);
      }
      friend void personal_details();  // function declaration
};
 
class student 
{
   private:
      char name[20];
      int  reg_no;
      int  age;
      int  marks;
   public:
      employee(char *name, int age, int marks, int reg_no)
      {
         this.reg_no = reg_no;
         this.age = age; 
         this.marks = marks;
         strcpy(this,name, name);
      }
      friend void personal_details();  // function declaration
};
 
void main()
{
  employee emp1("Rajesh", 30);
  employee emp2("Kumar", 25);
  student stud1("Naren", 15);
  student stud2("Sanjiv", 10);

}


