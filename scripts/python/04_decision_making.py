#!/usr/bin/python

# if statements
# if... else statements
# elif statement
# nested if statements

# if statements

print "\nif statement usage"

mark1 = 100

if (mark1 == 100):
   print "Congrats !!! Full Marks .."

# if.. else statements

print "\nif else statement usage"
no1=10
no2=3

if (no1%2 == 0):
   print no1, "is even no"
else:
   print no1, "is odd no"

if (no2%2 == 0):
   print no2, "is even no"
else:
   print no2, "is odd no"


# elif statement
print "\nelif statement usage"
mark2 = 80

if (mark2 < 35):
   print "Failed"
elif (mark2 < 60):
   print "Second Class"
elif (mark2 < 80):
   print "First Class"
else:
   print "Topper"

# nested if statement
print "\nnested if statement usage"
mark3 = 80

if (mark3 < 35):
   print "Failed"
else:
   print "Passed"
   if (mark3 < 60):
      print "Second Class"
   elif (mark3 < 80):
      print "First Class"
   else:
      print "Topper"
