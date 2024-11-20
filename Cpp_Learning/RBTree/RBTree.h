#pragma once

enum Colour
{
    RED,
    BLACK
};

template <class T>
struct RBTreeNode
{
    RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
    T _data;
    Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
        ,_col(RED)
	{}
};

template <class T, class Ref, class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> self;
	Node* _node;

	__RBTreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	self& operator--();
	
	self& operator++()
	{
		if (_node->_right)
		{
			Node* cur = _node->_right;
			while (cur->_left)
				cur = cur->_left;
			_node = cur;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	bool operator==(const self& s)
	{
		return _node == s._node;	
	}

	bool operator!=(const self& s)
	{
		return _node != s._node;	
	}
};


template <class k, class T, class KeyofT>
class RBTree
{
    typedef RBTreeNode<T> Node;
public:
	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T, const T&, const T*> const_iterator;
	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
			cur = cur->_left;
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	const_iterator begin() const
	{
		Node* cur = _root;
		while (cur && cur->_left)
			cur = cur->_left;
		return const_iterator(cur);
	}

	const_iterator end() const
	{
		return const_iterator(nullptr);
	}

    pair<Node*, bool> Insert(const T& data)
    {
        if (_root == nullptr)
		{
			_root = new Node(data);
            _root->_col = BLACK;
			return make_pair(_root, true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		KeyofT kot;

		while (cur)
		{
            parent = cur;
			if (kot(cur->_data) < kot(data))
				cur = cur->_right;
			else if (kot(cur->_data) > kot(data))
				cur = cur->_left;
			else
				return make_pair(cur, false);
		}

		cur = new Node(data);
		Node* newnode = cur;
        cur->_col = RED;

		if (kot(parent->_data) < kot(data))
			parent->_right = cur;
		else
			parent->_left = cur;
        cur->_parent = parent;

        while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上更新处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else  // parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}

		_root->_col = BLACK;

		return make_pair(newnode, true);
    }

    void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		subR->_left = parent;

		Node* parentParent = parent->_parent;

		parent->_parent = subR;
		if (subRL)
			subRL->_parent = parent;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;

			subR->_parent = parentParent;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}
	}

    bool IsBalance()
    {
        if (_root == nullptr)
            return true;
        
        if (_root->_col == RED)
            return false;

        int refVal = 0;
        Node* cur = _root;
        while (cur)
        {
            if (cur->_col == BLACK)
                refVal++;
            cur = cur->_left;
        }

        int BlackNum = 0;
        return Check(_root, BlackNum, refVal);
    }

    bool Check(Node* root, int BlackNum, const int refVal)
    {
        if (root == nullptr)
        {
            if (BlackNum != refVal)
            {
                cout << "存在黑色节点数量不相等的路径" << endl;
                return false;
            }
            return true;
        }

        if (root->_col == RED && root->_parent->_col == RED)
        {
            cout << "有连续的红色节点" << endl;
            return false;
        }

        if (root->_col == BLACK)
            BlackNum++;
        return Check(root->_left, BlackNum, refVal) && Check(root->_right, BlackNum, refVal);
    }

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

    int Height()
	{
		return _Height(_root);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	size_t Size()
	{
		return _Size(_root);
	}

	size_t _Size(Node* root)
	{
		if (root == NULL)
			return 0;

		return _Size(root->_left)
			+ _Size(root->_right) + 1;
	}

	Node* Find(const T& data)
	{
		Node* cur = _root;
		KeyofT kot;
		while (cur)
		{
			if (kot(cur->_data) < kof(data))
				cur = cur->_right;
			else if (kot(cur->_data) > kof(data))
				cur = cur->_left;
			else
				return cur;
		}

		return nullptr;
	}
private:
    Node* _root = nullptr;
};