#include "RBTree.h"

namespace chan
{
    template <class K>
    class set
    {
    public:
        struct SetKeyofT
        {
            const K& operator()(const K& key)
            {
                return key;
            }
        };

        typedef typename RBTree<K, K, SetKeyofT>::const_iterator iterator;
        typedef typename RBTree<K, K, SetKeyofT>::const_iterator const_iterator;
        
        iterator begin() const
        {
            return _t.begin();
        }

        iterator end() const
        {
            return _t.end();
        }

        pair<iterator, bool> insert(const K& k)
        {
            return _t.Insert(k);
        }

    private:
        RBTree<K, K, SetKeyofT> _t;
    };
}
