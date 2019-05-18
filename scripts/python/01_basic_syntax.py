#!/usr/bin/python

# Program on Python Basic Syntax

print "Welcome to Python World"

# First comment
print "Hello, Python!" # second comment

# accepts single ('), double (") and triple (''' or """) quotes to denote string
# literals, as long as the same type of quote starts and ends the string.
word = 'Hello'
sentence1 = 'Welcome to Python'
sentence2 = "Python Sentence 2"

# triple quotes are used to span the string across multiple lines
paragraph1 = """Hope things are
             fine for you 1"""
paragraph2 = '''Hope things are
             fine for you 2'''

print word
print sentence1
print sentence2
print paragraph1
print paragraph2

raw_input("\n\n Press enter key to proceed..");

no = 11;
# multistatement on a single line
item1 = 20; item2 =30; item3 =50;
item4 = 20; item5 =30; item6 =50;

# A group of individual statements, which make a single code block are called
# suites in Python. Compound or complex statements, such as if, while, def, and
# class require a header line and a suite.

if ((no % 2) == 0):
   print no
   print "is Even \n"
else:
   print no
   print "is Odd \n"

print "Sum of all Items set 1" , item1 + item2 + item3

print "Sum of all Items set 2" , item4 + \
                                 item5 + \
                                 item6

days = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri',
        'Sat', 'Sun']

print days

for elem in days:
   print elem    
