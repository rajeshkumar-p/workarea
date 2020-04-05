#!/usr/bin/python

print "Program to find average of n numbers using list"

int_list = []
elem = 0
total = 0
avg = 0

# construct list

no = (int)(input("Enter number of elements in the list : "))

for i in range(0,no):
   elem = (int)(input("Enter element : "))    
   int_list.append(elem) 

# find total and average of list 

for elem in int_list:
   total = total + elem
avg = total / len(int_list)

print "List : ", int_list
print "Total value of list : ", total
print "Average of list     : ", avg 
