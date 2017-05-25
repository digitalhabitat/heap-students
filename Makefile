# makefile for heap of students

# standard g++ compiler
CC = g++

# for debuging
CFLAGS = -g -Wall

heap: main.o student.o address.o date.o
	$(CC) $(CFLAGS) main.o student.o address.o date.o -o heap
# compile heap executable (target)
# if changes made to main.o student.o address.o date.o (dependencies)

main.o: main.cpp student.h
	$(CC) $(CFLAGS) -c main.cpp
# complie main object file (target)
# if change made to main.cpp student.h (dependencies)

student.o: student.cpp student.h address.h date.h
	$(CC) $(CFLAGS) -c student.cpp
# compile student object file (taget)
# if changes made to student.cpp student.h address.h date.h (dependencies)

address.o: address.cpp address.h
	$(CC) $(CFLAGS) -c address.cpp
# compile address object file (target)
# if changes made to address.cpp address.h (dependencies)

date.o: date.cpp date.h
	$(CC) $(CFLAGS) -c date.cpp
# comple address object file (target)
# if changes made to date.cpp date.h (dependencies)

clean:
	rm *.o heap fullReport.txt shortReport.txt alphaReport.txt
# remove all object files and heap executable

valgrind: heap
	valgrind --leak-check=full --show-leak-kinds=all ./heap
debug: heap
	gdb heap

run: heap
	./heap

# <target>: <dependencies>
# [tab]<system command>
