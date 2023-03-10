all: minions

colsort: minions .c Makefile
	gcc -Wall -Wextra -O2 -g minions.c -o minions

clean:
	rm -f minions
