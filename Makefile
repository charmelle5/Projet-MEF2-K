all : exec

Creation_chenil.o : Creation_chenil.c Creation_chenil.h
	gcc -c Creation_chenil.c -o Creation_chenil.o

Option_menu.o : Option_menu.c Option_menu.h
	gcc -c Option_menu.c -o  Option_menu.o

Variante.o : Variante.c Variante.h
	gcc -c Variante.c -o  Variante.o

main.o : main.c Creation_chenil.h Option_menu.h Variante.h
	gcc -c main.c -o  main.o

exec : main.o Creation_chenil.o Option_menu.o Variante.o
	gcc main.o Creation_chenil.o Option_menu.o Variante.o -o exec
