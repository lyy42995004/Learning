#include "RBTree.h"

namespace chan
{
    template<class K, class V>
    class map
    {
    public:
        struct MapKeyofT
        {
            const K& operator()(const pair<K, V>& kv)
            {
                return kv.first;
            }
        };
        typedef typename RBTree<K, pair<const K, V>, MapKeyofT>::iterator iterator;
        typedef typename RBTree<K, pair<const K, V>, MapKeyofT>::const_iterator const_iterator;

        iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

        V& operator[](const K& k)
        {
            pair<iterator, bool> p = _t.Insert(make_pair(k, V()));
            return p.first->second;
        }

        pair<iterator, bool> insert(const pair<K, V>& kv)
        {
            return _t.Insert(kv);
        }

    private:
        RBTree<K, pair<const K, V>, MapKeyofT> _t;
    };
}