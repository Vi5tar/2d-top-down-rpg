compile:
	g++ -std=c++11 src/main.cpp -I/usr/local/Cellar/sfml/2.6.0/include/ -L/usr/local/Cellar/sfml/2.6.0/lib -lsfml-window -lsfml-graphics -lsfml-system -o output/main

run:
	./output/main

freshrun:
	make compile
	make run

clean:
	rm -rf output/*