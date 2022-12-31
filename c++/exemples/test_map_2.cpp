#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <utility> // make_pair ( )
using namespace std;
template <typename M>
void affiche(const string &msg, const M &m, bool rc = true)
{
    cout << msg;
    cout << m.size() << " élément(s) = ";
    // syntaxe C++11
    // for ( const auto & p : m )
    // {
    // cout << "( " << p.first << ", " << p.second << " ) ";
    // }
    for (typename M::const_iterator it = m.cbegin(); it != m.cend(); ++it)
    {
        cout << "( " << it->first << ", " << it->second << " ) ";
    }
    cout << endl;
    if (rc)
    {
        cout << endl;
    }
}

int main(void)
{
    map<int, int> m1;
    m1.insert({1, 10});          // appel de insert( const value_type & )
    m1.insert(make_pair(2, 20)); // appel de insert ( ValTy && )
    affiche("Contenu de 'm1' sous la forme ( clé, valeur )\n", m1);
    // tentative d’insertion d’un élément existant
    pair<map<int, int>::iterator, bool> crdu = m1.insert(make_pair(1, 99));
    if (!crdu.second)
    {
        pair<int, int> p = *crdu.first;
        cout << ">>> Echec à l'insertion : l'élément avec la clé = 1 existe déjà" << endl
             << " Voici l'élément = (" << p.first << ", " << p.second << ")" << endl;
        cout << endl;
    }
    else
    {
        affiche("Contenu de 'm1' sous la forme ( clé, valeur )\n", m1);
    }
    // insertion d’un élément (une paire), avec une suggestion de position (à la fin)
    m1.insert(m1.end(), make_pair(3, 30));
    affiche("Contenu de 'm1' sous la forme ( clé, valeur )\n", m1);

    // Insertion dans la map m2 à partir d’un vecteur v de paires sans ordre
    map<int, int> m2;
    vector<pair<int, int>> v;
    v.push_back(make_pair(44, 444));
    v.push_back(make_pair(33, 333));
    v.push_back(make_pair(55, 555));
    v.push_back({22, 222}); // syntaxe possible en C++11
    affiche("Insertion du vecteur 'v' dans la map 'm2'\n", v, false);
    m2.insert(v.begin(), v.end() - 1);
    affiche("Contenu de 'm2' sous la forme ( clé, valeur )\n", m2);
    map<int, string> m3;
    pair<int, string> e1(475, "Pierre");
    pair<int, string> e2(510, "Louis");
    m3.insert(move(e1)); // déplacement d’un élément e1 dans la map m3
    affiche("Contenu de 'm3' après l'insertion par déplacement de e1\n", m3, false);
    cout << ">>> e1.second = " << e1.second << endl;
    // insertion par déplacement de e2 avec une suggestion (fausse) de position dans m3
    m3.insert(m3.begin(), move(e2));
    affiche("Contenu de 'm3' après l'insertion par déplacement de e2\n", m3);
    map<int, int> m4;
    // insertion à partir d’une liste d’initialisation de paires
    m4.insert({{-1, 44}, {-2, 22}, {-3, 33}, {-1, 11}, {-5, 55}});
    affiche("Contenu de 'm4' après insertion à partir d'une liste d'initialisation\n", m4);
    return 0;
}