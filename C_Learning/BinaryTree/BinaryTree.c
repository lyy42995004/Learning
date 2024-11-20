#include "BinaryTree.h"
#include "queue.h"

BTNode* BuyNode(BTDataType x)
{
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    if(!newnode)
    {
        perror("BuyNode:malloc");
        return NULL;
    }
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

BTNode* BinaryTreeCreate()
{
    BTNode* newnode1 = BuyNode(1);
    BTNode* newnode2 = BuyNode(2);
    BTNode* newnode3 = BuyNode(3);
    BTNode* newnode4 = BuyNode(4);
    BTNode* newnode5 = BuyNode(5);
    BTNode* newnode6 = BuyNode(6);
    BTNode* newnode7 = BuyNode(7);

    newnode1->left = newnode2;
    newnode1->right = newnode3;
    newnode2->left = newnode4;
    newnode3->left = newnode5;
    newnode3->right = newnode6;
    newnode2->right = newnode7;

    return newnode1;
}

void BinaryTreeDestory(BTNode* root)
{
    if(root == NULL)
        return;
    BinaryTreeDestory(root->left);
    BinaryTreeDestory(root->right);
    free(root);
}

int BinaryTreeSize(BTNode* root)
{
    if(root == NULL)
        return 0;

    return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
    if(root == NULL)
        return 0;
    if(k == 1 && root != NULL)
        return 1;
    return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    if(root == NULL)
        return NULL;
    if(root->data == x)
        return root;
    BTNode* retleft =  BinaryTreeFind(root->left, x);
    BTNode* retright = BinaryTreeFind(root->right, x);
    return (retleft != NULL ? retleft : retright);
}

void BinaryTreePrevOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("# ");
        return;
    }
    printf("%d ", root->data);
    BinaryTreePrevOrder(root->left);
    BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("# ");
        return;
    }
    BinaryTreeInOrder(root->left);
    printf("%d ", root->data);
    BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("# ");
        return;
    }
    BinaryTreePostOrder(root->left);
    BinaryTreePostOrder(root->right);
    printf("%d ", root->data);
}

void BinaryTreeLevelOrder(BTNode* root)
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q, root);  
    while(!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
        if(front)
        {
            printf("%d ", front->data);
            QueuePush(&q, front->left);
            QueuePush(&q, front->right);
        }
        else
            printf("# ");
    }
    QueueDestroy(&q);
}

int BinaryTreeComplete(BTNode* root)
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q, root);  
    while(!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
        if(front)
        {
            QueuePush(&q, front->left);
            QueuePush(&q, front->right);
        }
        else
            break;
    }
    while(!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
        if(front)
        {
            QueueDestroy(&q);
            return 0;
        }
    }
    QueueDestroy(&q);
    return 1;
}