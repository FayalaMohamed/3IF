#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
int main(void)
{
    vector<int> v{1, 2, 3, 4, 5};
    // reverse_iterator < vector < int >::iterator > ri;
    vector<int>::reverse_iterator ri;
    for (ri = v.rbegin(); ri != v.rend(); ++ri)
    {
        cout << " " << *ri;
    }
    cout << endl;
    return 0;
}