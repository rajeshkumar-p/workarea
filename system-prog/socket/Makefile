CC=gcc

#CFLAGS=-c -Wall
#CFLAGS= -pcap
LDFLAGS=

C_INCLUDES=-I$(SOFTWARE_ROOT)/mylib/
SO_PATH=-L$(SOFTWARE_ROOT)/mylib/;/usr/lib/i386-linux-gnu/

#SOLIST= -lmylib -lpcap
SOLIST= -lmylib

SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
EXEC = $(patsubst %.c,%,$(SOURCES))

all: $(EXEC)

% : %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(C_INCLUDES) $(SO_PATH) $(SOLIST) -o $@ $<

clean:
	rm -rf *.o $(EXEC)	
