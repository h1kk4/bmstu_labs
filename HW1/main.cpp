#include <forward_list>
#include <iostream>


#define CHECK

#ifdef CHECK
#include "TList.h"

template<class T>
using forward_list = TForwardList<T>;

#else

template<class T>
using forward_list = std::forward_list<T>;

#endif // CHECK

#define assert(X) { \
	if(!(X)) {\
		std::cout << "see function:'" << __FUNCTION__ << "' line: " << __LINE__;\
		throw std::logic_error(#X); \
	}\
}

int main()
{
    {
        forward_list<std::string> m(0);
        assert(m.empty());

        m.push_front("e");
        m.push_front("d");
        m.push_front("a");
        m.push_front("c");
        m.push_front("d");

        int cnt = 0;
        for (auto & i : m)
        {
            ++cnt;
        }
        assert(cnt == 5);

        auto m1 = m;
        assert(m.front() == "d");

        m1.clear();
        assert(m1.empty());

        m1.swap(m);
        assert(m.empty());

        cnt = 0;
        for (auto & i : m1)
        {
            ++cnt;
        }
        assert(cnt == 5);

        auto it = m1.begin();
        ++it;
        it++;
        m1.erase_after(it);
        cnt = 0;
        for (auto & i : m1)
        {
            ++cnt;
        }
        assert(cnt == 4);

        m1.remove("d");
        cnt = 0;
        for (auto & i : m1)
        {
            ++cnt;
        }
        assert(cnt == 3);
    }

}