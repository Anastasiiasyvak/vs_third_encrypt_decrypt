CC = g++
CFLAGS = -shared -o caesar.so -fPIC

all: caesar.so

caesar.so: caesar.cpp
	export LANG=en_US.UTF-8 
	$(CC) $(CFLAGS) $<
