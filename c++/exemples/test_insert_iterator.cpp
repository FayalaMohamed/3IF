#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
int main(void)
{
    vector<int> v{1, 2, 3, 4, 5};
    list<int> l{-1, -2, -3};
    copy(v.begin(), v.end(), // peut être simplifié avec std::inserter
         insert_iterator<list<int>>(l, l.end()));
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << " " << *it;
    }
    cout << endl;
    insert_iterator<list<int>> ii(l, l.begin());
    copy(v.begin(), v.end(), inserter(l, l.end()));
    *ii = 99; // ++ est inutile
    *ii = 88; // ++ est inutile
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << " " << *it;
    }
    cout << endl;
    return 0;
}