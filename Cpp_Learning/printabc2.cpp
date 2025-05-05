#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

atomic<int> turn(0); // 0: a, 1: b, 2: c

void printChar(char ch, int myTurn, int n) {
    while(n--) {
        while (turn.load() != myTurn) {
            // 自旋等待
            this_thread::yield();
        }
        cout << ch;
        turn = (turn + 1) % 3;
    }
}

int main() {
    int n = 10;
    thread t1(printChar,'a', 0, n);
    thread t2(printChar,'b', 1, n);
    thread t3(printChar,'c', 2, n);
    t1.join();
    t2.join();
    t3.join();
    cout << endl;

    return 0;
}