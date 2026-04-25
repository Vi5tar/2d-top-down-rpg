compile:
	g++ -std=c++11 src/main.cpp $(shell pkg-config --cflags --libs sfml-window sfml-graphics sfml-system) -o output/main

run:
	./output/main

freshrun:
	make compile
	make run

clean:
	rm -rf output/*