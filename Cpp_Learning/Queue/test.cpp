#include "queue.h"

int main()
{
    chan::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    return 0;
}