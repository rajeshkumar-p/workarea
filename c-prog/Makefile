CC=gcc

CFLAGS=-c -Wall
LDFLAGS=

C_INCLUDES=-I$(SOFTWARE_ROOT)/mylib/
SO_PATH=-L$(SOFTWARE_ROOT)/mylib/

SOLIST= -lmylib

SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
EXEC = $(patsubst %.c,%,$(SOURCES))

all: $(EXEC)

% : %.c
	$(CC) $(LDFLAGS) $(C_INCLUDES) $(SO_PATH) $(SOLIST) -o $@ $<

clean:
	rm -rf *.o $(EXEC)	
