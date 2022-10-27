CC = g++ -Wall -std=c++11
CCO = $(CC) -c $<
OBJECTS = graph.o main.o
all : $(OBJECTS)
	$(CC) -o exe $(OBJECTS)
	./exe
graph.o : graph.cpp graph.hpp
	$(CCO)
gc.o : gc.cpp gc.hpp
	$(CCO)
main.o : main.cpp
	$(CCO)
clean :
	rm -f *.o exe