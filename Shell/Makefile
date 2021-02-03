all: fork

clean:
	rm -f fork

fork: fork.c
	cc -g -Wall -Wextra -Werror -m32 -fno-pie -no-pie -O0 -m32 -pthread fork.c -o fork