#include "priority_queue.h"

int main()
{
    chan::priority_queue<int> q;
    q.push(2);
    q.push(5);
    q.push(1);
    q.push(9);
    q.push(4);
    while (!q.empty())
    {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;
    return 0; 
}