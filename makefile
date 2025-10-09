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

# Build & run test
allTests: testTrajetSimple testTrajetCompose testOutils

testTrajetSimple:
	g++ Tests/TestTrajetSimple.cpp TrajetSimple.cpp TrajetCompose.cpp collection.cpp -o Tests/TestTrajetSimple $(FLAGS)
	./Tests/TestTrajetSimple
	rm Tests/TestTrajetSimple

testTrajetCompose:
	g++ Tests/TestTrajetCompose.cpp TrajetSimple.cpp TrajetCompose.cpp collection.cpp -o Tests/TestTrajetCompose $(FLAGS)
	./Tests/TestTrajetCompose
	rm Tests/TestTrajetCompose

testOutils:
	g++ Tests/TestOutils.cpp outils.cpp -o Tests/TestOutils $(FLAGS)
	./Tests/TestOutils
	rm Tests/TestOutils
