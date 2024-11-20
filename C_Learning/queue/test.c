#include "queue.h"

int main()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    printf("%d\n", QueueFront(&q));
    QueuePop(&q);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    while(!QueueEmpty(&q))
    {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");
    QueueDestroy(&q);
    return 0;
}