#!/usr/bin/python                                                              
# https://www.tutorialspoint.com/python/python_date_time.htm 
# https://pythonspeed.com/articles/blocking-cpu-or-io/

import time;
import calendar;
import datetime;

def welcome_banner():
   print "\n"
   for i in range(1,3):
      print "Welcome Buddy !!!"
      time.sleep(1)

ticks = time.time()
print "\n Number of ticks since epoch (12:00am, January 1, 1970) : ", ticks

time_tuple = time.localtime(time.time())
print "\n Time tuple : \n" , time_tuple

local_time = time.asctime(time.localtime(time.time()))
print "\n Local time in Ascii format : ", local_time

print "\n wait for 2 second ... \n"
time.sleep(2)

# wall time calculation
t0 = time.time()
welcome_banner()
t1 = time.time()
print "welcome_banner task start time      : ", time.asctime(time.localtime(t0))
print "welcome_banner task end time        : ", time.asctime(time.localtime(t1))
print "welcome_banner task completion time : ", t1-t0

# cpu time calculation
cpu_t0 = time.clock()
welcome_banner()
cpu_t1 = time.clock()
print "welcome_banner task cpu  time       : ", cpu_t1-cpu_t0

print "\n calendar : \n"
cal = calendar.month(2008, 1);
print cal

print "\n current date using datetime module : ", datetime.datetime.now()
print "datetime attributes are : ", datetime.datetime

# timer implementation in python ?
# https://www.geeksforgeeks.org/python-how-to-time-the-program/
