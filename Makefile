all: minions

minions: minions.c 
	gcc -Wall -Wextra -g minions.c -o minions -pthread

clean:
	rm -f minions
