#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


TreeNode* createNode(char data) {
    if (data == '*') {
        return NULL;
    } else {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
}


TreeNode* buildTree(char** str) {
    char data = **str;
    (*str)++;
    if (data == '\0')
        return NULL;
    if (data == '*') {
        return NULL;
    } else {
        TreeNode* root = createNode(data);
        root->left = buildTree(str);
        root->right = buildTree(str);
        return root;
    }
}

void preOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c", root->data);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char inputSequence[100];
    scanf("%s", inputSequence);
    
    char* str = inputSequence;
    TreeNode* root = buildTree(&str);
    
    printf("先序序列");
    preOrderTraversal(root);
    printf(" \n");
    
    printf("中序序列");
    inOrderTraversal(root);
    printf("\n");
    
    printf("后序序列");
    postOrderTraversal(root);
    printf("\n");
    
    
    
    return 0;
}