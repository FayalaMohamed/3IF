#include <iostream>
#include <list>
using namespace std;

ostream &operator<<(ostream &os, const list<int> &l)
{
    for (list<int>::const_iterator il = l.cbegin(); il != l.cend(); il++)
    {
        os << " " << *il;
    }
    return os;
}

int is_impaire(int a) {
    //pour remove_if
    return a % 2;
}

int main()
{
    list<int> list1;
    list1.push_back(5);
    list1.push_back(9);
    list1.insert(++list1.begin(), 3);
    cout << "liste 1 = " << list1 << endl;

    // comment faire un remove_if :
    //list1.remove_if(is_impaire);
    
    list1.sort();
    cout << "liste 1 triée = " << list1 << endl;

    list<int> list2 = {8, 2, 7, 3, 7, 9};
    list2.unique();
    cout << "liste 2 (sans doublons ?) = " << list2 << endl;

    list2.sort();
    cout << "liste 2 triée = " << list2 << endl;

    list1.merge(list2);
    cout << "Fusion = " << list1 << endl;

    list1.unique();
    cout << "Fusion (sans doublon) = " << list1 << endl;

    cout << list1 << endl; 
    return 0;
}