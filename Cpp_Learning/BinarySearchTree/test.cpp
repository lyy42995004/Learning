#include "BinarySearchTree.h"

int main()
{
    BSTree<int> bt;
    int arr[10] = {5, 7, 2, 3, 1, 10, 9, 4, 8, 6};
    for (auto x : arr)
        bt.insertR(x);
    bt.inorder();
    auto n = bt.findR(6);
    cout << n->_key << endl;
    for (auto x : arr)
    {
        bt.eraseR(x);
        bt.inorder();
    }
    return 0;
}