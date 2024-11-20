#include <iostream>
using namespace std;

template <class K>
struct BSTreeNode
{
    BSTreeNode<K>* _left;
    BSTreeNode<K>* _right;
    K _key;

    BSTreeNode(const K& key)
    :_left(nullptr)
    ,_right(nullptr)
    ,_key(key)
    {}
};

template <class K>
class BSTree
{
    typedef BSTreeNode<K> Node;
public:
    bool insert(const K& key)
    {
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }
        else
        {
            Node* cur = _root;
            Node* prev = nullptr;
            while (cur != nullptr)
            {
                prev = cur;
                if (key > cur->_key)
                    cur = cur->_right;
                else if (key < cur->_key)
                    cur = cur->_left;
                else
                    return false;
            }
            cur = new Node(key);
            if (key > prev->_key)
                prev->_right = cur;
            else
                prev->_left = cur;
            return true;
        }
    }

    Node* find(const K& key)
    {
        Node* cur = _root;
        while (cur != nullptr)
        {
            if (key > cur->_key)
                cur = cur->_right;
            else if (key < cur->_key)
                cur = cur->_left;
            else
                return cur;
        }
        return nullptr;
    }

    bool erase(const K& key)
    {
        Node* cur = _root;
        Node *prev = nullptr;
        while (cur != nullptr)
        {
            if (key > cur->_key)
            {
                prev = cur;
                cur = cur->_right;
            }
            else if (key < cur->_key)
            {
                prev = cur;
                cur = cur->_left;
            }
            else
            {
                if (cur->_left == nullptr)
                {
                    if (cur == _root)
                        _root = cur->_right;
                    else
                    {
                        if (prev->_left == cur)
                            prev->_left = cur->_right;
                        else
                            prev->_right = cur->_right;
                    }
                    delete cur;
                }
                else if (cur->_right == nullptr)
                {
                    if (cur == _root)
                        _root = cur->_left;
                    else
                    {
                        if (prev->_left == cur)
                            prev->_left = cur->_left;
                        else
                            prev->_right = cur->_left;
                    }
                    delete cur;
                }
                else
                {
                    // 找到左数的最右节点和cur替换
                    Node* leftMaxParent = cur;
                    Node *leftMax = cur->_left;
                    while (leftMax->_right != nullptr)
                    {
                        leftMaxParent = leftMax;
                        leftMax = leftMax->_right;
                    }
                    swap(cur->_key, leftMax->_key);
                    if (leftMaxParent->_left == leftMax) // 删除节点就是cur的左节点
                        leftMaxParent->_left = leftMax->_left;
                    else
                        leftMaxParent->_right = leftMax->_left;
                    delete leftMax;
                }
                return true;    
            }
        }
        return false;
    }

    void inorder()
    {
        _inorder(_root);
        cout << endl;
    }

    bool insertR(const K& key)
    {
        return _insertR(_root, key);
    }

    Node* findR(const K& key)
    {
        return _findR(_root, key);
    }

    bool eraseR(const K& key)
    {
        return _eraseR(_root, key);
    }
private:
    void _inorder(const Node* root)
    {
        if (root == nullptr)
            return;
        _inorder(root->_left);
        cout << root->_key << " ";
        _inorder(root->_right);
    }

    bool _insertR(Node*& root, const K& key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return true;
        }
        if (key < root->_key)
            return _insertR(root->_left, key);
        else if (key > root->_key)
            return _insertR(root->_right, key);
        else
            return false;
    }

    Node* _findR(Node* root, const K& key)
    {
        if (root == nullptr)
            return nullptr;
        if (key < root->_key)
            return _findR(root->_left, key);
        else if (key > root->_key)
            return _findR(root->_right, key);
        else
            return root;
    }

    bool _eraseR(Node*& root, const K& key)
    {
        if (root == nullptr)
            return false;
        if (key < root->_key)
            return _eraseR(root->_left, key);
        else if (key > root->_key)
            return _eraseR(root->_right, key);
        else
        {
            if (root->_left == nullptr)
            {
                Node* del = root;
                root = root->_right;
                delete del;
                return true;
            }
            else if (root->_right == nullptr)
            {
                Node *del = root;
                root = root->_left;
                delete del;
                return true;
            }
            else
            {
                Node *leftMax = root->_left;
                while (leftMax->_right != nullptr)
                    leftMax = leftMax->_right;
                swap(root->_key, leftMax->_key);
                return _eraseR(root->_left, leftMax->_key);
            }   
        }
    }

    Node* _root = nullptr;
};