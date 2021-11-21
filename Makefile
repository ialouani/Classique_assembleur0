test_tout: test_tout1 test_tout2 test_tout3 top_conversion
	./test_tout1 && ./test_tout2 && ./test_tout3 && java top_conversion
test_tout1: exo1.o 
	gcc exo1.o -o test_tout1
test_tout2: exo2.o
	gcc exo2.o -o test_tout2
test_tout3: exo3.o
	gcc exo3.o -o test_tout3
top_conversion: top_conversion.java
	javac top_conversion.java
exo1.o: exo1.c
	gcc -c exo1.c
exo2.o: exo2.c
	gcc -c exo2.c
exo3.o: exo3.c
	gcc -c exo3.c 	
clean:
	rm -rf *.o test_tout test_tout1 test_tout2 test_tout3
