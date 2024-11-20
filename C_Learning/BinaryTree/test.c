#include "BinaryTree.h"
#include "queue.h"

int main()
{
    BTNode *root = BinaryTreeCreate();
    printf("%d\n", BinaryTreeComplete(root));
    BinaryTreeDestory(root);
    return 0;
}