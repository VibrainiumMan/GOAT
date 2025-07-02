main: main.c
	gcc main.c terminal.c -o main

clean:
	rm -f main
