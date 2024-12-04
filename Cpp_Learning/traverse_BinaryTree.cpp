#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char c) : val(c),left(nullptr),right(nullptr)
    {}
};

// 根据前序（根，左，右）初始化二叉树
TreeNode* BuildTree(const string& str, int& index)
{
    if (index > str.size())
        return nullptr;
    if (str[index] == '*')
    {
        index++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(str[index++]);
    root->left = BuildTree(str, index);
    root->right = BuildTree(str, index);
    return root;
}

// 递归前序遍历
void PreorderTraversalRecursive(TreeNode* root)
{
    if (root == nullptr)
        return;
    cout << root->val;
    PreorderTraversalRecursive(root->left);
    PreorderTraversalRecursive(root->right);
}

// 递归中序遍历
void InorderTraversalRecursive(TreeNode* root)
{
    if (root == nullptr)
        return;
    InorderTraversalRecursive(root->left);
    cout << root->val;
    InorderTraversalRecursive(root->right);
}


// 递归后续遍历
void PostorderTraversalRecursive(TreeNode* root)
{
    if (root == nullptr)
        return;
    PostorderTraversalRecursive(root->left);
    PostorderTraversalRecursive(root->right);
    cout << root->val;
}

// 迭代前序遍历
void PreorderTraversalIterative(TreeNode* root)
{
    if (root == nullptr)
        return;
    stack<TreeNode*> st; 
    st.push(root);
    while (!st.empty())
    {
        TreeNode* cur = st.top();
        cout << cur->val;
        st.pop();
        if (cur->right)
            st.push(cur->right);
        if (cur->left)
            st.push(cur->left);
    }
}

// 迭代中序遍历
void InorderTraversalIterative(TreeNode* root)
{
    if (root == nullptr)
        return;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty())
    {
        // cur的左子树全部入栈
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        cout << cur->val;
        st.pop();
        cur = cur->right;
    }
    
}

// 迭代后序遍历
void PostorderTraversalIterative(TreeNode* root)
{
    if (root == nullptr)
        return;
    stack<TreeNode*> st; 
    TreeNode* cur = root;
    TreeNode* prev = nullptr;
    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        // 如果右子树为空or右子树已经访问过了，访问当前节点，并出栈
        if (cur->right == nullptr || cur->right == prev)
        {
            cout << cur->val;
            st.pop();
            prev = cur;
            cur = nullptr;
        }
        // 右子树未访问过
        else
            cur = cur->right;
    }
}

int main()
{
    string str;
    cin >> str;
    int index = 0;
    TreeNode* root = BuildTree(str, index);

    // 递归
    cout << "先序序列";
    PreorderTraversalRecursive(root);
    cout << endl;

    cout << "中序序列";
    InorderTraversalRecursive(root);
    cout << endl;

    cout << "后序序列";
    PostorderTraversalRecursive(root);
    cout << endl;

    // 迭代
    cout << "先序序列";
    PreorderTraversalIterative(root);
    cout << endl;

    cout << "中序序列";
    InorderTraversalIterative(root);
    cout << endl;

    cout << "后序序列";
    PostorderTraversalIterative(root);
    cout << endl;

    return 0;
}