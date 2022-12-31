#include <iostream>
#include <map>
using namespace std;
int main(void)
{
    map<char, int> m1;
    map<char, int>::iterator ilow;
    map<char, int>::iterator iup;
    m1['a'] = 11;
    m1['b'] = 22;
    m1['c'] = 33;
    m1['d'] = 44;
    m1['e'] = 55;
    m1['a'] = 99;
    ilow = m1.lower_bound('b'); // ilow pointe l'élément de clé 'b'
    iup = m1.upper_bound('d');  // iup pointe l'élément de clé 'e' (et non 'd')
    m1.erase(ilow, iup);        // on efface les éléments dans la plage [ ilow, iup ]
    // Affichage du conteneur map m1
    for (map<char, int>::iterator it = m1.begin(); it != m1.end(); ++it)
    {
        cout << "( " << it->first << " -> " << it->second << " )" << endl;
    }
    cout << "Taille maximale de la map 'm1' = " << m1.max_size() << endl;
    return 0;
}