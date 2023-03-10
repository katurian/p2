all: minions

minions: minions .c Makefile
	gcc -pthread -o minions minions.c

clean:
	rm -f minions
