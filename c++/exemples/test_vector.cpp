#include <iostream>
#include <vector>
using namespace std;

static void afficher(const vector<int> &v)
{
    cout << "Taille = " << v.size() << endl;
    cout << "Capacité = " << v.capacity() << endl;
    vector<int>::const_iterator iv;
    cout << "Contenu =";
    for (iv = v.cbegin(); iv != v.cend(); ++iv)
    {
        cout << " " << *iv;
    }
    cout << endl;
    cout << endl;
}

int main(void)
{
    vector<int> v1;
    v1.push_back(99);
    v1.push_back(-55);
    v1.insert(v1.begin(), 22);
    afficher(v1);

    vector<int> v2(5, 3);
    afficher(v2);

    vector<int>::iterator iv = v2.end();
    vector<int> v3(v2.begin(), iv - 2);
    afficher(v3);

    return 0;
}