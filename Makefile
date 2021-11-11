test_tout: test_tout1 test_tout2
	./test_tout1 && ./test_tout2
test_tout1: exo1.o 
	gcc exo1.o -o test_tout1
test_tout2: exo2.o
	gcc exo2.o -o test_tout2
exo1.o: exo1.c
	gcc -c exo1.c
exo2.o: exo2.c
	gcc -c exo2.c
clean:
	rm -rf *.o test_tout
