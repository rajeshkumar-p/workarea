CC=gcc

#CFLAGS=-c -Wall -fPIC -fno-stack-protector -fno-stack-protector-all
CFLAGS=-c -Wall -fPIC -fno-stack-protector
LDFLAGS=

SOURCES= errfunc.c \
		myprint.c \
		clrfl.c \
		setfl.c \
		test_app.c exitStatus.c processSync.c

DEPS= apue.h \
	  myprint.h \
	mydefs.h
			
OBJECTS=$(SOURCES:.c=.o)
EXEC=test_app		

LIBSO= libmylib.so
LIBA= libmylib.a

all: $(SOURCES) $(EXEC) $(LIBSO) $(LIBA)

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

# to create shared library
$(LIBSO): $(OBJECTS)
	ld -shared -soname $(LIBSO) -o $(LIBSO) -lc $(OBJECTS)	

# to create static library
$(LIBA): $(OBJECTS)
	ar -cvq $(LIBA) $(OBJECTS)

clean:
	rm -rf *.o $(EXEC) $(LIBSO)	$(LIBA)
