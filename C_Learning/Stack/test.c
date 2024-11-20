#include "stack.h"

int main()
{
    Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 4);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StackDestroy(&st);
    return 0;
}