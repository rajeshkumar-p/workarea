#!/usr/bin/python

print "Program to demonstrate tuples usage in Python"

# Tuples

# Tuple is another sequence data type that is similar to the list.
# Main differences between lists and tuples are: 
# Lists are enclosed in brackets ([]) and their elements and size can be changed, 
# Tuples are enclosed in parentheses ( ( ) ) and cannot be updated. 
# Tuples can be thought of as read-only lists (immutable).  

weekdays = ('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday')
weekend = ('Saturday', 'Sunday')                                                           

print "Weekdays : ", weekdays                      
print "Weekend  : ", weekend     

# Tuple updation 
# 1) Attempt to update a tuple is not allowed
#    TypeError: 'tuple' object does not support item assignment
#    weekend[0] = 'Monday'
# 2) All operations other than update applicable for lists is applicable for 
#     tuples also, means accessing tuple will be same as list
# 3) New tuple creation from exiting tuple allowed

days = weekdays + weekend
print "Days : ", days

# Tuple deletion
# 1) Deleting single element from tuple is not allowed
# 2) Deleting entire tuple can be done using del statement

print days
del days


# tuple methods
# 1) cmp(tuple1, tuple2)
# 2) len(tuple) - returns length of the tuple 
# 3) max(tuple) - returns maximum element of the list
# 4) min(tuple) - returns minimum element of the list
# 5) tuple(seq) - converts a list into tuple
