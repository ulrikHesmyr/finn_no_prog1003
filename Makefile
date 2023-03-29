output: main.o func.o LesData3.o
	g++  -I ./src main.o func.o LesData3.o -o output

main.o: src/main.cpp
	g++ -I ./src -c src/main.cpp

func.o: src/func.cpp src/func.h
	g++ -I ./src -c src/func.cpp

LesData3.o: src/LesData3.cpp src/LesData3.h
	g++ -I ./src -c src/LesData3.cpp

brukttring.o: src/bruktting.cpp src/bruktting.h
	g++ -I ./src -c src/bruktting.cpp

const.o: src/const.h
	g++ -I ./src -c src/const.cpp

enum.o: src/enum.h
	g++ -I ./src -c src/enum.h

kategori.o: src/kategorier.cpp src/kategorier.h
	g++ -I ./src -c src/kategorier.cpp

kategori.o: src/kategori.cpp src/kategori.h
	g++ -I ./src -c src/kategori.cpp

kunde.o: src/kunde.cpp src/kunde.h
	g++ -I ./src -c src/kunde.cpp

nyting.o: src/nyting.cpp src/nyting.h
	g++ -I ./src -c src/nyting.cpp

clean:
	rm *.o output
