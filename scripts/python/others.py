#!/usr/bin/python                                                              i


# two ways to read input from user keyboard in python using
#
# 1) raw_input() - reads one line from standard input and return it as a string 
# 2) input() - reads one line from standard input and it assumes that given 
#              input is a valid python expression and returns the evaluated
#              result to user

a = int(raw_input("Enter value for a : "))
b = int(raw_input("Enter value for b : "))
sum = a + b

print "Sum of a and b is ", sum
 
first_name = raw_input("Enter first name : ");
last_name  = raw_input("Enter sur name  : ");

print "Name of the student ", first_name + " " + last_name
