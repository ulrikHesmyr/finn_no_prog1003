output: main.o func.o LesData3.o
	g++ main.o func.o LesData3.o -o output

main.o: Sources/main.cpp
	g++ -c Sources/main.cpp

func.o: Sources/func.cpp Headers/func.h
	g++ -c Sources/func.cpp

LesData3.o: Sources/LesData3.cpp
	g++ -c Sources/LesData3.cpp

clean:
	rm *.o output
