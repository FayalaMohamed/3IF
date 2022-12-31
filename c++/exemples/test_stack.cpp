#include <iostream>
#include <deque>
using namespace std;
// Exemple d’implémentation de l’adaptateur de conteneur stack (existe dans la STL)
template <typename T, typename Conteneur = deque<T>>
class maStack
{
public:
    bool empty() const
    {
        return unePile.empty();
    }
    typename Conteneur::size_type size() const
    {
        return unePile.size();
    }
    T &top()
    {
        return unePile.back();
    }
    void push(const T &x)
    {
        unePile.push_back(x);
    }
    void pop()
    {
        unePile.pop_back();
    }

protected:
    Conteneur unePile;
};

// Utilisation de l’adaptateur de conteneur maStack
int main(void)
{
    maStack<double> p;
    p.push(1.5);
    p.push(3.14);
    p.push(0.123);
    cout << p.size() << " éléments dans la pile" << endl;
    cout << "Elément de tête : " << p.top() << endl;
    // p.top() laisse l'élément sur le sommet de la pile
    cout << p.size() << " éléments dans la pile" << endl;
    p.pop();
    // p.pop() supprime l'élément sur le sommet de la pile
    cout << p.size() << " éléments dans la pile" << endl;
    cout << "Elément de tête : " << p.top() << endl;
    return 0;
}