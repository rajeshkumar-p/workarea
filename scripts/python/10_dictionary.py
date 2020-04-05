#!/usr/bin/python

print "Program to demonstrate dictionary usage in Python"

#Quiz:
#https://www.geeksforgeeks.org/output-python-programs-set-9-dictionary/

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

