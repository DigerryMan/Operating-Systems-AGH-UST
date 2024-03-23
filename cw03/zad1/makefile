flag = -Wall

all:
	make clean
	gcc ${flag} zad1.c -o zad1_char.o -D CHAR
	gcc ${flag} zad1.c -o zad1_block.o
	chmod 777 zad1_char.o zad1_block.o

char:
	./zad1_char.o

block:
	./zad1_block.o

clean:
	rm -f *.o pomiar_zad_1.txt reversedFile.txt
