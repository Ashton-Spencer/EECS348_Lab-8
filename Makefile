CC := gcc

main.exe: matrix.cpp matrix.h main.cpp
	&(CC) -o main.exe main.cpp matrix.cpp

clean:
	rm -f main.exe