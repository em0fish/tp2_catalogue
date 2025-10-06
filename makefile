OBJECTS=main.o trajetSimple.o trajetCompose.o catalogue.o collection.o
FLAGS=-ansi -pedantic -Wall -std=c++11

.PHONY: clean

all: main

main: $(OBJECTS)
	g++ $(OBJECTS) -o main $(FLAGS)

main-map: $(OBJECTS)
	g++ $(OBJECTS) -o main -DMAP $(FLAGS)

%.o: %.cpp
	g++ $< -c $(FLAGS) 

valgrind: main
	valgrind ./main
	# possible de recouperer automatiquement la valeur de ret
	
clean:
	rm *.o
