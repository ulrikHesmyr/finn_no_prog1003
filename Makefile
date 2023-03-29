output: main.o func.o LesData3.o
	g++ main.o func.o LesData3.o -o output

main.o: src/main.cpp
	g++ -c src/main.cpp

func.o: src/func.cpp src/func.h
	g++ -c src/func.cpp

LesData3.o: src/LesData3.cpp src/LesData3.h
	g++ -c src/LesData3.cpp

brukttring.o: src/bruktting.cpp src/bruktting.h
	g++ -c src/bruktting.cpp

const.o: src/const.h
	g++ -c src/const.cpp

enum.o: src/enum.h
	g++ -c src/enum.h

kategori.o: src/kategorier.cpp src/kategorier.h
	g++ -c src/kategorier.cpp

kategori.o: src/kategori.cpp src/kategori.h
	g++ -c src/kategori.cpp

kunde.o: src/kunde.cpp src/kunde.h
	g++ -c src/kunde.cpp

nyting.o: src/nyting.cpp src/nyting.h
	g++ -c src/nyting.cpp

clean:
	rm *.o output
