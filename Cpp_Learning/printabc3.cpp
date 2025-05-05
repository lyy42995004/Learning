#include <iostream>
#include <thread>
#include <semaphore>
#include <functional>
using namespace std;

// 定义三个信号量，初始值：a信号量为1（先打印a），b/c为0
counting_semaphore<1> semA(1);
counting_semaphore<1> semB(0);
counting_semaphore<1> semC(0);

void printChar(char c, counting_semaphore<1>& mySem, counting_semaphore<1>& nextSem, int n) {
    for (int i = 0; i < n; ++i) {
        mySem.acquire();         // 等待自己的 turn
        cout << c;
        nextSem.release();       // 释放下一个线程的信号
    }
}

int main() {
    int n = 10;
    thread tA(printChar, 'a', ref(semA), ref(semB), n);
    thread tB(printChar, 'b', ref(semB), ref(semC), n);
    thread tC(printChar, 'c', ref(semC), ref(semA), n);
    tA.join();
    tB.join();
    tC.join();

    cout << endl;
    return 0;
}