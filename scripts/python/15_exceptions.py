#!/usr/bin/python

print " Simple program to demonstrate exception handling in python "

# Exception
# 1) An exception is an event, which occurs during the execution of a program 
#    that disrupts the normal flow of the program's instructions. 
# 2) When Python script encounters a situation that it cannot cope with, it 
#    raises an exception. 
# 3) An exception is a Python object that represents an error.
# 4) When a Python script raises an exception, it must either handle the 
#    exception immediately otherwise it terminates and quits

# syntax
# try:
#   You do your operations here;
#   ......................
# except ExceptionI:
#   If there is ExceptionI, then execute this block.
# except ExceptionII:
#   If there is ExceptionII, then execute this block.
#   ......................
# else:
#   If there is no exception then execute this block. 

# use try and except clause to handle exception
# if we use open without try it will lead to an IOError and program stops
# immediately and not proceeding further
 
try:
   fh = open("testfile", "r")
   fh.write("This is my test file for exception handling!!")
except IOError:
   print "Error: can\'t find file or read data"

# except clause with no exception
# 1) can handle all types of exception in except clause with no exception  
# 2) ideally it can be default clause after all except clause
def div1(a, b):
   try:
      if(a >= b):
         c = a/b;
      print "Resut is : ", c;
   except:
      print "Exception arrised"

div(100,10)  
div(100,0)     # Exception raised for divide by zero error 
div(100,1000)  # Exception raised for UnboundLocalError, c referred before
               # assignment

# except clause with multiple exception
# single except clause can handle multiple exception also
def div2(a, b):
   try:
      if(a >= b):
         c = a/b;
      print "Resut is : ", c;
   except(ZeroDivisionError, UnboundLocalError):
      print "Exception arrised"

div(100,10)  
div(100,0) 

# use else clause in exception handling 

# use finally clause in exception handling

# use argument of an exception

# raising an exception

# user defined exception
