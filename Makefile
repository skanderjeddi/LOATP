CC = g++ -Wall -std=c++11
CCO = $(CC) -c $<
OBJECTS = graphe.o main.o ramassemiettes.o
all : $(OBJECTS)
	$(CC) -o exe $(OBJECTS)
	./exe
ramassemiettes.o : ramassemiettes.cpp ramassemiettes.hpp
	$(CCO)
graphe.o : graphe.cpp graphe.hpp
	$(CCO)
main.o : main.cpp
	$(CCO)
clean :
	rm -f *.o exe