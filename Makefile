CC=gcc
CFLAGS=-Wall -Wextra -g
LIB=-lmraa -lstdc++

default: 
	gcc -lmraa -o lsm6ds33_test lsm6ds33_test.cpp -lstdc++
	
