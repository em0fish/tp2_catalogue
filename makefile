OBJECTS=Outils.o TrajetSimple.o TrajetCompose.o Collection.o Catalogue.o main.o
FLAGS=-ansi -pedantic -Wall -std=c++11

.PHONY: clean

all: main

main: $(OBJECTS)
	g++ $(OBJECTS) -o main $(FLAGS)

main-map: $(OBJECTS)
	g++ $(OBJECTS) -o main -DMAP $(FLAGS)

%.o: %.cpp
	g++ $< -c -g $(FLAGS) 

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
testSaisieTrajets: test.o Collection.o TrajetSimple.o TrajetCompose.o
	g++ test.o -o test Collection.o TrajetSimple.o TrajetCompose.o $(FLAGS)
