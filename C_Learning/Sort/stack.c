#include "stack.h"

void StackInit(Stack* ps) 
{
    assert(ps);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}

void StackPush(Stack* ps, STDataType data) 
{
    assert(ps);
    if(ps->top == ps->capacity)//只有入栈时需要扩容，所以不用再单独写一个函数
    {
        int newcapacity = (ps->capacity == 0 ? 4 : 2 * ps->capacity);
        STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
        if(tmp == NULL)
        {
            perror("StackPush realloc fail");
            return;
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }
    ps->a[ps->top] = data;
    ps->top++;
}

void StackPop(Stack* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}

STDataType StackTop(Stack* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}

int StackSize(Stack* ps)
{
    assert(ps);
    return ps->top;
}

int StackEmpty(Stack* ps)
{
    assert(ps);
    return (ps->top == 0);
}

void StackDestroy(Stack* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}