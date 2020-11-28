Warnings = -Wall -Wextra -Werror

all: fraction

fraction: obj/main.o 
	g++ -std=c++17 $(Warnings) obj/main.o -o fraction

obj/main.o: src/main.cpp include/Fraction.h include/Unit_test_framework.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/main.cpp -o obj/main.o

obj:
	mkdir obj

clean:
	rm -rf obj
	rm -rf fraction