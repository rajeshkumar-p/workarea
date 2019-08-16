#!/usr/bin/python

# Types of Operator

# 1. Arithmetic Operators
# 2. Comparison (Relational) Operators
# 3. Assignment Operators
# 4. Logical Operators
# 5. Bitwise Operators
# 6. Membership Operators
# 7. Identity Operators

# arithmetic operators 

print "Pythons arithmetic operators usage \n"

a = 20; 
b = 10;

c = 5;
d = 2;


print "addition   of 20 and 10 ", a+b
print "subraction of 20 and 10 ", a-b
print "multiply   of 20 and 10 ", a*b
print "divide     of 20 and 10 ", a/b

# Divides left hand operand by right hand operand and returns remainder
print "modulus    of 5 and 2 ", c%d 

# Performs exponential (power) calculation on operators
print "exponent   of 5 and 2 ", c**d

# Floor Division - The division of operands where the result is the quotient in
# which the digits after the decimal point are removed. But if one of the
# operands is negative, the result is floored, i.e., rounded away from zero
# (towards negative infinity)

# python comparison operators

#  ==   (a==b) is true
#  !=   (a!=b) is not true
#  <>   (a<>b)
#  >    (a<b)
#  <    (a>b)
#  >=   (a>=b)
#  <=   (a<=b)


# python membership operators

# in      Evaluates to true if it finds a variable in the specified sequence 
#         and false otherwise.
# not in  Evaluates to true if it does not finds a variable in the specified
#         sequence and false otherwise.

print "Pythons membership operators usage \n"

no1 = 10
no2 = 5 
list = [1,2,3,4,5]

if (no1 in list):
   print no1, "is in list", list
else:
   print no1, "is not in list", list
   
if (no2 in list):
   print no2, "is in list", list
else:
   print no2, "is not in list", list

# python identity operators

# Identity operators compare the memory locations of two objects. 
# is      Evaluates to true if the variables on either side of the operator
#         point to the same object and false otherwise.
# is not  Evaluates to false if the variables on either side of the operator 
#         point to the same object and true otherwise.

# What is the difference between comparison and Identity operators ?

a1 = 10
b1 = 10

if (a1 is b1):
   print "a1 and b1 have same identity"
else:
   print "a1 and b1 don't have same identity"

if (id(a1) == id(b1)):
   print "a1 and b1 have same identity"
else:
   print "a1 and b1 don't have same identity"

b1 = 20

if (a1 is b1):
   print "a1 and b1 have same identity"
else:
   print "a1 and b1 don't have same identity"

if (id(a1) == id(b1)):
   print "a1 and b1 have same identity"
else:
   print "a1 and b1 don't have same identity"


# python operator precedence
