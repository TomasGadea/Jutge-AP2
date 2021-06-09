# Exemple de makefile per a 3 problemes.
# Dissenyat per a optimitzar el temps d'examen

p1: p1.cc
	g++ -Wall -std=c++17 -O2 p1.cc
	./a.out
	make clean

p2: p2.cc
	g++ -Wall -std=c++17 -O2 p2.cc
	./a.out
	make clean

p3: p3.cc
	g++ -Wall -std=c++17 -O2 p3.cc
	./a.out
	make clean

clean:
	rm -f a.out
