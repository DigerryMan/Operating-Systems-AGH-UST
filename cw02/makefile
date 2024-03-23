flag = -Wall

all:
#bibl.a - STATYCZNIE
	gcc ${flag} -c collatz.c
	ar rcs libcollatz.a collatz.o

#bibl.so - DYNAMICZNA/WSPOL
	gcc ${flag} -fPIC -c collatz.c
	gcc ${flag} -shared collatz.o -o libcollatz.so

#programy
	gcc ${flag} main.c libcollatz.a -o main_stat
	gcc ${flag} main.c -L ./ -lcollatz -Wl,-rpath,. -o main_wspoldz
	gcc ${flag} main.c -o main_dynam -ldl -D DYNAMIC

stat:
	./main_stat

wspoldz:
	./main_wspoldz

dynam:
	./main_dynam

clean:
	rm -f *.o *.a *.so main_*