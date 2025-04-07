.PHONY:all
all:hello

hello:hello.cc
	g++ -std=c++17 -o $@ $^ /usr/local/lib/libredis++.a /usr/lib/x86_64-linux-gnu/libhiredis.a -pthread

clean:
	rm -rf hello