sigsuspend: sigsuspend.c ../csapp.c
	gcc -o $@ $^ -lpthread

signal2: signal2.c ../csapp.c
	gcc -o $@ $^ -lpthread

sigint: sigint.c ../csapp.c
	gcc -o $@ $^ -lpthread

.PHONY:clean
clean:
	rm -f sigint
	rm -f signal2
	rm -f sigsuspend