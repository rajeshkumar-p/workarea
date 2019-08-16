#!/usr/bin/python

print "Program to demonstrate different variable types in Python"

# Variables are nothing but reserved memory locations to store values.

# Based on the data type of a variable, the interpreter allocates memory and
# decides what can be stored in the reserved memory.

# Python variables do not need explicit declaration to reserve memory space. 
# The declaration happens automatically when you assign a value to a variable. 

#standard data types in python
# 1. numbers
# 2. string
# 3. list
# 4. tuple
# 5. dictionary

# numbers

# Four different numerical Types
# 1. int     (signed integers)
# 2. long    (long integers, can also be represented in octal and hexadecimal)
# 3. float   (floating point real values)
# 4. complex (complex numbers)

counter  = 100
miles = 1000.0

print counter
print miles

# multiple assignment 1 - allows to assign a single value to several
# variables simultaneously 
no1 = no2 = no3 = 10

print no1
print no2
print no3

# multiple assignment 2 - allows to assign multiple objects to multiple
# variables 
counter, miles = 200, 2000.0

print counter
print miles

# del allows to delete the reference to a object
print no1, no2, no3
del no1
del no2, no3

#print no1, no2, no3
# Above statement will lead to Error
# NameError: name 'no1' is not defined

# Strings

# Identified as a contiguous set of characters represented in quotation marks
name1 = "Rajesh"
name2 = 'Theeksh'
name3 = """Anbu"""

print name1, name2, name3

# Subsets of strings can be taken using the slice operator ([ ] and [:] ) 
# With indexes starting at 0 in the beginning of the string and working their 
# way from -1 at the end.
# plus (+) sign is the list concatenation operator, and the asterisk (*) is the
# repetition operator. 

str = "Welcome Neo"
print str       # prints string
print str[0]    # prints first character of the string
print str[0:4]  # prints first four characters from the string
print str[8:]   # prints string from 9th character
print str * 2   # print string 2 times

print str + " to Matrix" # concatenates two string

# LIST

# list contains items separated by commas and enclosed within square brackets
# ([])

# To some extent, lists are similar to arrays in C
# Difference between them is that all the items belonging to a list can be of
# different data type.

# Values stored in a list can be accessed using the slice operator ([ ] and [:])
# Indexes starting at 0 in the beginning of the list and working their way to
# end -1.
# plus (+) sign is the list concatenation operator, and the asterisk (*) is the
# repetition operator.

familylist  = ['Rajesh', 'Theeksh', 'Anbu', 'Selvi']
friendslist = ['Jeeva', 'Naveen']

print familylist          # Prints complete list
print familylist[0]       # Prints first element of the list
print familylist[1:3]     # Prints elements starting from 2nd till 3rd 
print familylist[2:]      # Prints elements starting from 3rd element

print friendslist * 2           # Prints list two times
print familylist + friendslist  # Prints concatenated lists

familylist[2] = 'Anbuselvan'
print familylist          # Prints complete list

# Tuples

# Tuple is another sequence data type that is similar to the list.
# Main differences between lists and tuples are: 
# Lists are enclosed in brackets ([]) and their elements and size can be changed, 
# Tuples are enclosed in parentheses ( ( ) ) and cannot be updated. 
# Tuples can be thought of as read-only lists.  

weekdays = ('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday')
weekend = ('Saturday', 'Sunday')                                                           

print "Weekdays : ", weekdays                      
print "Weekend  : ", weekend     

# Attempt to update a tuple is not allowed
# TypeError: 'tuple' object does not support item assignment
#weekend[0] = 'Monday'

# All operations other than update applicable for lists is applicable for tuples
# also

# Dictionary

# Dictionaries are kind of hash table type. They work like associative arrays or
# hashes found in Perl and consist of key-value pairs.
 
# A dictionary key can be almost any Python type, but are usually numbers or 
# strings. Values, on the # other hand, can be any arbitrary Python object.

# Dictionaries are enclosed by curly braces ({ }) and values can be assigned and
# accessed using square braces ([]). 

binary_numbers = {}
binary_numbers[0] = "zero"
binary_numbers[1] = "one"
print binary_numbers

decimal_numbers = {0:'zero', 1:'one', 2:'two', 3:'three', 4:'four', 5:'five',
                   6:'six', 7:'seven', 8:'eight', 9:'nine'}
print decimal_numbers
 
print binary_numbers[0]  # Prints value for 0 key
print decimal_numbers[9] # Prints value for 9 key

print binary_numbers.keys()     # Prints all the keys
print decimal_numbers.keys()    # Prints all the keys
print binary_numbers.values()   # Prints all the values 
print decimal_numbers.values()  # Prints all the values

# Note : Dictionaries have no concept of order among elements. It is incorrect
# to say that the elements are "out of order"; they are simply unordered.

