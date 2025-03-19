.PHONY:all
all:hello

hello:hello.cc
	gcc -std=c++17 -o $@ $^ /usr/local/lib/libredis++.a /usr/local/lib/libhiredis.a -pthread

clean:
	rm -rf hello