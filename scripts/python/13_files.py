#!/usr/bin/python

# program to demonstrate file handling in python

# to open the file
fobj = open("welcome.txt", "w+", 0)

# to print the file name
print "file name : " + fobj.name

# to write content to file
fobj.write("Welcome to python tutorial !!! \n");
fobj.write("!!! Have fun in learning !!! \n");

# close the file after completion
fobj.close()



