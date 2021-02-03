all: fork exec run

clean:
	rm -f fork exec run

fork: fork.c
	cc -g -Wall -Wextra -Werror -m32 -fno-pie -no-pie -O0 -m32 -pthread fork.c -o fork

exec: exec.c
	gcc -o exec exec.c -Wall

run: run.c
	gcc -o run run.c -Wall