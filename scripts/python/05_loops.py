#!/usr/bin/python

#  while loop
#  Repeats a statement or group of statements while/until a given condition is TRUE.
#  It tests the condition before executing the loop body. 
#
#  for loop
#  Executes a sequence of statements multiple times and abbreviates the code
#  that manages the loop variable.
#
#  nested loops
#  You can use one or more loop inside any another while, for or do..while loop.

# while loop
#
# syntax
#    while expression:
#      statement(s)

# find sum of first N natural no's

num = int(raw_input("\n Enter value for N : "));

iter = 1; 
sum = 0;

while(iter<=num):
   sum = sum + iter;
   iter = iter + 1;

print "\n Sum of first ", num, " Natural numbers is ", sum


# python supports else statement with loops

# If the else statement is used with a for loop, the else statement is
# executed when the loop has exhausted iterating the list.

# If the else statement is used with a while loop, the else statement is
# executed when the condition becomes false.


# find factorial of number

iter = 1; 
fact = 1;
num = int(raw_input("\n Enter value for N : "));

while(iter<=num):
   fact = fact * iter;
   iter = iter + 1;
else:
   print "\n Factorial value of ",  num, "is ", fact

# Infinite Loop - Be cautious

# A loop becomes infinite loop if a condition never becomes FALSE.
# An infinite loop might be useful in client/server programming where the server
# needs to run continuously so that client programs can communicate with it as 
# and when required.

# for Loop

# used to iterate over the items of any sequence (list,tuple,dictionary)
# used to iterate characters on a string
# used to iterate over range of values

# to iterate over list
fruits = ['Apple', 'Orange', 'Mango', 'Banana']
for fruit in fruits:
   print fruit

# to iterate over string characters
for fruit in fruits:
    print "\n"
    for letter in fruit:
        print letter 

# to iterate over tuples
print "\n"
weekdays = ('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday')
for days in weekdays:
    print days

print "\n"
for index in range(len(weekdays)):
    print weekdays[index]

# find sum of first N natural nos
num = int(raw_input("\n Enter value for N : "));
sum = 0;
for index in range(1,num+1):
    sum = sum + index;
else:
    print "Sum of first ", num ," natural no's is ", sum


# Nested Loop
# Allows to use one loop inside another loop

# find all prime numbers present in first N natural nos
isPrime = 1
num = int(raw_input("\n Enter value for N : "));
# 1,2,3 are prime nos
print 1
print 2

for no in range(3,num+1):
    isPrime = 1
    for index in range(2, no):
        if((no % index) == 0):
            isPrime = 0
            break; 
    if(isPrime == 1):
        print no   

# Loop Control Statements

# Loop control statements change execution from its normal sequence. 
# When execution leaves a scope, all automatic objects that were created 
# in that scope are destroyed.

# break statement
# Terminates the loop statement and transfers execution to the statement
# immediately following the loop.

# continue statement
# Causes the loop to skip the remainder of its body and immediately retest its
# condition prior to reiterating.
 
