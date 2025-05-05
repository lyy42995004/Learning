#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;
int turn = 0; // 0: a, 1: b, 2: c

void printChar(char ch, int myTurn, int n) {
    while (n--) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&] { return turn == myTurn; });
        cout << ch;
        turn = (turn + 1) % 3;
        cv.notify_all();
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