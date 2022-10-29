CC = g++ -Wall -std=c++11
CCO = $(CC) -c $<
OBJECTS = graph.o main.o gc.o
all : $(OBJECTS)
	$(CC) -o exe $(OBJECTS)
	./exe
gc.o : gc.cpp gc.hpp
	$(CCO)
graph.o : graph.cpp graph.hpp
	$(CCO)
main.o : main.cpp
	$(CCO)
clean :
	rm -f *.o exe