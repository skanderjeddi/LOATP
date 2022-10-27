CC = g++ -Wall -std=c++11
CCO = $(CC) -c $<
OBJECTS = graphe.o collecte.o main.o
all : $(OBJECTS)
	$(CC) -o exe $(OBJECTS)
	./exe
graphe.o : graphe.cpp graphe.hpp
	$(CCO)
collecte.o : collecte.cpp collecte.hpp
	$(CCO)
main.o : main.cpp
	$(CCO)
clean :
	rm -f *.o exe