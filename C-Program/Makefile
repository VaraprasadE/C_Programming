output : isprime.o isoddeven.o Main.o
	gcc isprime.c isoddeven.c Main.c -lm -o output

isprime.o:isprime.c
	gcc -c isprime.c

isoddeven.o:isoddeven.c
	gcc -c isoddeven.c

Main.o: Main.c
	gcc -c Main.c

clean:
	rm *.o output