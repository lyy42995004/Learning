#include <iostream>
#include <sw/redis++/redis++.h>

int main() {
    sw::redis::Redis redis("tcp://127.0.0.1:6379");
    std::string result = redis.ping();
    std::cout << result << std::endl;
    return 0;
}