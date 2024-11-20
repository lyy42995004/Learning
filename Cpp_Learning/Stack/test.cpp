#include "stack.h"

int main()
{
    chan::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    while (!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }
    return 0;
}