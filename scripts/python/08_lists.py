#!/usr/bin/python

print "Program to demonstrate list in Python"

# Sequence 
# 1) Basic data structure in Python is the sequence
# 2) Each element of a sequence is assigned a number - its position or index.
# 3) The first index is zero, the second index is one, and so forth.
# 4) Python has six built-in types of sequences, but the most common ones are 
#    lists and tuples,

# Lists
# 1) list contains items separated by commas and enclosed within square 
#    brackets ([])
# 2) To some extent, lists are similar to arrays in C
# 3) Difference between them is that all the items belonging to a list can be of
#    different data type.

familylist  = ['Rajesh', 'Theeksh', 'Anbu', 'Selvi']
friendslist = ['Jeeva', 'Naveen']

print "Family members : ", familylist          # Prints complete list
print "Friends list   : ", friendslist         # Prints complete list

# Basic list operation
# 1) length of the list
# 2) membership of the list
# 3) iterating over the list element

print "Length of the familylist : ", len(familylist)
print "Rajesh is in familylist : ", 'Rajesh' in familylist
print "Prem   is in familylist : ", 'Prem' in familylist

for name in familylist:
    print name

# Accessing List
# 1) Values stored in a list can be accessed using the slice operator 
#     ([ ] and [:])
# 2) Indexes starting at 0 in the beginning of the list and working their way to
#    end -1.
# 3) plus (+) sign is the list concatenation operator, and the asterisk (*) is 
#    the repetition operator.
# 4) use index method to find index of the particular object

print familylist[0]       # Prints first element of the list
print familylist[1:3]     # Prints elements starting from 2nd till 3rd 
print familylist[2:]      # Prints elements starting from 3rd element
print familylist[-2]      # Prints second element from last of the list

print friendslist * 2           # Prints list two times
print familylist + friendslist  # Prints concatenated lists

familylist[2] = 'Anbuselvan'
print familylist          # Prints complete list

# Updating list
# 1) can use slice operator to update the list element
# 2) can use append method to update the list element
# 3) can use extend method to extend the list with sequence(list/tuple)
# 4) can use insert method to insert element in the list at specific index

familylist[3] = 'Anbuselvi';
print familylist

familylist.append('Aathira');
print familylist

familylist2 = ['Ramesh','Deepa','Naren','Jeyan']
familylist.extend(familylist2);
print familylist

familylist.insert(0,'Kani')
print familylist
familylist.insert(1,'Vijaya')
print familylist

# Delete list elements
# 1) can use del statement to remove the list element by index
# 2) can use remove method to remove the list element
# 3) can use pop method to remove the last element in the list or index specific
#    element in the list 

del familylist[3]
print familylist

familylist.remove('Aathira');
print familylist

# Other list functions and Methods

# cmp(list1, list2) - to compare two lists
familylist3 = familylist2
print cmp(familylist2, familylist3)
print cmp(familylist, familylist2)

# max(list) - to return item with max value
# min(list) - to return item with min value
print max(familylist)
print min(familylist)

# list.insert(index, obj) - to insert object in the specified position
# list.count(obj) - to count no of objects in the list
# list.index(obj) - to find position of object in the list
# list.reverse()  - to reverse te list
# list.sort(func) - to sort the list, using given func if given
# list.pop(obj=list[-1])

print familylist3
print familylist3.count('Rajesh')
print familylist3.count('Ramesh')

familylist3.append('Ramesh')
print familylist3
print familylist3.count('Ramesh')

print familylist3
familylist3.pop()

print familylist3
familylist3.pop(1)

print familylist3
familylist3.sort()

print familylist3
familylist3.reverse()
print familylist3

# Lists and Tuples
# 1) Tuples can be thought of as read-only lists.  
# 2) All operations other than update applicable for lists is applicable for 
#    tuples also
# 3) list(seq) used to convert(tuples) sequence into list
