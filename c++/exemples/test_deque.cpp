#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;
ostream &operator<<(ostream &os, const deque<int> &d)
{
    for (deque<int>::const_iterator id = d.cbegin(); id != d.cend(); id++)
    {
        os << " " << *id;
    }
    return os;
}
int main(void)
{
    deque<int> d1;
    d1.push_back(3);
    d1.push_front(1);
    d1.push_front(1);
    d1.insert(d1.begin() + 2, 2);
    d1[0] = 0;
    cout << "deque = " << d1 << endl;
    
    d1.pop_front();
    cout << "deque (après pop) = " << d1 << endl;
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}