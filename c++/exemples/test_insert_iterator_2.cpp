#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
int main(void)
{
    list<int> l{-1, -2, -3};
    front_insert_iterator<list<int>> fii(l);
    *fii = -99;
    fii = -77;
    *fii = -88; // insertion toujours en tête
    cout << "l (après front_...) =";
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << " " << *it;
    }
    cout << endl;
    back_insert_iterator<list<int>> bii(l);
    *bii = 7;
    bii = 9;
    *bii = 8; // insertion toujours en queue
    cout << "l (après back_...) =";
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << " " << *it;
    }
    cout << endl;
    return 0;
}