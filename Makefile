CC := g++

all: matrix.exe

matrix.exe: main.cpp matrix.cpp matrix.hpp
	$(CC) -o matrix.exe main.cpp matrix.cpp

clean:
	rm -f matrix.exe