#!/usr/bin/python
# https://www.tutorialspoint.com/python/python_strings.htm

str1 = 'Hello World '
str2 = "String Program"

# concatenation
print str1 + str2

# repetition
print str1 * 3

# slice operators
print str2[1]
print str2[7:]
print str2[:7]
print str2[7:11]

# membership operator
print 'H' in str1
print 'S' in str1


print 'H' not in str1
print 'S' not in str1

# string formatting operator

print "My name is %s and age is %d " % ("Rajesh", 34)
