#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

void Usage() {
    std::cout << "usage: ./server [ip] [port]" << std::endl;
}

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        Usage();
        return 0;
    }

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        std::cerr << "socket" << std::endl;
        return 0;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    int ret = bind(fd, (sockaddr*)&addr, sizeof(addr));
    if (ret < 0) {
        std::cerr << "bind" << std::endl;
        return 0;
    }
    ret = listen(fd, 10);
    if (ret < 0) {
        std::cerr << "listen" << std::endl;
        return 0;
    }

    while (true) {
        sockaddr_in client_addr;
        socklen_t len;
        int client_fd = accept(fd, (sockaddr*)&client_addr, &len);
        if (client_fd < 0) {
            std::cerr << "accept" << std::endl;
            return 0;
        }
        char buf1[1024] = {0};
        ssize_t read_len = read(client_fd, buf1, sizeof(buf1));
        if (read_len < 0) {
            return 0;
        }
        std::cout << "[Request]" << buf1 << std::endl;
        char buf2[1024] = {0}; 
        const char* hello = "<h1>hello world</h1>";
        sprintf(buf2, "HTTP/1.0 200 OK \nContent-Length:%lu\n\n%s", strlen(hello), hello);
        write(client_fd, buf2, strlen(buf2));
    }
    
    return 0;
}