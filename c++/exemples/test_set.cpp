#include <iostream>
#include <set>
using namespace std;

ostream &operator<<(ostream &os, const set<string> &s)
{
    os << "{ " << *s.begin();
    for (set<string>::iterator it = ++(s.begin()); it != s.end(); ++it)
    {
        os << ", " << *it;
    }
    os << " }" << endl;
    return os;
}
int main(void)
{
    set<string> e1; // (1) Construction par défaut
    e1.insert("table");
    e1.insert("chaise");
    e1.insert("tabouret");
    e1.insert("chaise");
    e1.insert("tabouret");
    cout << "e1 = " << e1 << endl;
    set<string> e2(e1.find("table"), e1.end()); // (2) Construction en itérant dans un autre set
    cout << "e2 = " << e2 << endl;
    set<string> e3(e1); // (3) Construction par copie d'un set existant
    e3.insert("buffet");
    cout << "e1 = " << e1;
    cout << "e3 = " << e3 << endl;
    set<string> e4(move(e1)); // (4) Construction par déplacement d'objets d'un autre set
    if (e1.empty())
    {
        cout << "e1 = vide" << endl;
    }
    cout << "e4 = " << e4 << endl;
    set<string> e5{"un", "deux", "trois", "quatre", "cinq"}; // (5) Initialisation à partir d'une liste
    cout << "e5 = " << e5 << endl;
    return 0;
}