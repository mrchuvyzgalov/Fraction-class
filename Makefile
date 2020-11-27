Warnings = -Wall -Wextra -Werror

all: fraction

fraction: obj/main.o obj/Fraction.o
	g++ -std=c++17 $(Warnings) obj/main.o obj/Fraction.o -o fraction

obj/main.o: src/main.cpp include/Fraction.h include/Unit_test_framework.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/main.cpp -o obj/main.o

obj/Fraction.o: src/Fraction.cpp include/Fraction.h | obj
	g++ -std=c++17 -c $(Warnings) -Iinclude src/Fraction.cpp -o obj/Fraction.o

obj:
	mkdir obj

clean:
	rm -rf obj
	rm -rf fraction