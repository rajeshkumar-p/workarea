#!/usr/bin/python

# https://www.tutorialspoint.com/python/python_functions.htm

# All parameters (arguments) in the Python language are passed by reference. It
# Function definition is here
# means if you change what a parameter refers to within a function, the change
# also reflects back in the calling function.

def print_list(mylist1, mylist2):

    print "inside func start mylist1 ", mylist1
    print "inside func start mylist2 ", mylist2
    for var in mylist1:
        print var
    mylist1.append(100)

    mylist2 = ["Anbu", "Tamil", "Selvan"]

    print "inside func end mylist1 ", mylist1
    print "inside func end mylist2 ", mylist2
 

# required arguments
def odd_or_even(no):

    if ( no%2 == 0 ):
       print no ," is even"
    else: 
       print no ," is odd"

# keyword arguments
# Keyword arguments are related to the function calls. When you use keyword
# arguments in a function call, the caller identifies the arguments by the
# parameter name.
# non-keyword arg after keyword arg is not allowed in python
def student_details(name, no, mark1, mark2, mark3):

    print "\nName   : ", name
    print "No     : ", no
    print "Mark 1 : ", mark1
    print "Mark 2 : ", mark2
    print "Mark 3 : ", mark3
    print "Total  : ", mark1+mark2+mark3
 
# default arguments
# A default argument is an argument that assumes a default value if a value is
# not provided in the function call for that argument. 

def welcome_banner(str = "Buddy"):

    print "Welcome ", str," !!"

# variable length arguments
def total(*var):
  
   sum = 0;
   for no in var:
      sum = sum + no;
   print "total is : ", sum 

# anonymous funtions - lambda
# These functions are called anonymous because they are not declared in the
# standard manner by using the def keyword. You can use the lambda keyword to
# create small anonymous functions.

# Lambda forms can take any number of arguments but return just one value in
# the form of an expression. They cannot contain commands or multiple expressions.

# An anonymous function cannot be a direct call to print because lambda
# requires an expression

#  Lambda functions have their own local namespace and cannot access variables
# other than those in their parameter list and those in the global namespace.

#  Although it appears that lambda's are a one-line version of a function, they
# are not equivalent to inline statements in C or C++, whose purpose is by passing
# function stack allocation during invocation for performance reasons.

sum = lambda arg1, arg2, arg3: arg1 + arg2 + arg3;

print "Hello World"
odd_or_even(10)
odd_or_even(11)

welcome_banner("Rajesh")
welcome_banner()

total()
total(10,20)
total(100,200,200,500)

student_details(no=1, name="Rajesh", mark3=60, mark2=60, mark1=75)
student_details("Theekshna", 2, mark2=80, mark1=60, mark3=75)
student_details("Naren", 2, 85, 90, 95)

list1 = [10,20,30]
list2 = [100,200,300]
print list1
print list2

print_list(list1, list2)
print list1
print list2

print "Value of total : ", sum( 10, 20, 30 )
print "Value of total : ", sum( 200, 400, 600 )
