#include "queue.h"

void QueueInit(Queue *pq)
{
    assert(pq);
    pq->front = pq->rear = NULL;
    pq->size = 0;
}

void QueuePush(Queue *pq, QDataType data)
{
    assert(pq);
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        perror("newnode malloc fail");
        return;
    }
    newnode->next = NULL;
    newnode->data = data;
    if (pq->front == NULL)
    {
        pq->front = pq->rear = newnode;
    }
    else
    {
        pq->rear->next = newnode;
        pq->rear = newnode;
    }
    pq->size++;
}

void QueuePop(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    QNode *del = pq->front;
    pq->front = del->next;
    free(del);
    pq->size--;
}

QDataType QueueFront(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->front->data;
}

QDataType QueueBack(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->rear->data;
}

int QueueSize(Queue *pq)
{
    assert(pq);
    return pq->size;
}

int QueueEmpty(Queue *pq)
{
    assert(pq);
    return (pq->size == 0);
}

void QueueDestroy(Queue *pq)
{
    assert(pq);
    QNode *cur = pq->front;
    while (cur)
    {
        QNode *del = cur;
        cur = cur->next;
        free(del);
    }
    pq->front = pq->rear = NULL;
    pq->size = 0;
}