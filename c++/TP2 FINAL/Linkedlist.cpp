/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Linkedlist> (fichier Linkedlist.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Linkedlist.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Linkedlist::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode



// GETTERS,SETTERS

Cell* Linkedlist::getracine() const
// Algorithme : Méthode simple
{
    return racine;
}

const char* Linkedlist::getVillea() const
// Algorithme : Méthode simple
{
    if(racine->getData() == nullptr) return ""; // si liste vide

    Cell* parcours=racine;
    while (parcours->getNext()!= nullptr){
        parcours=parcours->getNext();
    }
    return     parcours->getData()->getvillea();
}

const char* Linkedlist::getVilled() const
// Algorithme : Méthode simple
{
    return racine->getData()->getvilled();
}

void Linkedlist::setracine(Cell* cell)
// Algorithme : Méthode simple
{
    racine=cell;
}

//--Fin GETTERS,SETTERS

void Linkedlist::Ajouter(const Trajet *t)
// Algorithme : Méthode simple
{
    // cas où la liste est vide
    if(racine->getData() == nullptr){
        racine->setData(t);
        return;
    }

    // cas où la liste n'est pas vide : rajouter le nouveau trajet à la fin
    Cell* parcours=racine;
    while(parcours->getNext()!=nullptr){
        parcours=parcours->getNext();
    }

    Cell* aAjouter = new Cell(t);
    parcours->setNext(aAjouter);

}//--Fin Ajouter

void Linkedlist::tri()
// Algorithme : Tri par selection
{
    Cell* parcours=racine;
    Cell* parcours2=racine;
    while(parcours2!=nullptr){
        while (parcours!= nullptr){
            if(strcmp(parcours->getData()->getvilled(),parcours2->getData()->getvilled())<0){
                Trajet* tmp=parcours->getData();
                parcours->setData(parcours2->getData());
                parcours2->setData(tmp);
            }
            parcours=parcours->getNext();
        }
        parcours2=parcours2->getNext();
        parcours=parcours2;

    }

}//----Fin Tri

void Linkedlist::Afficher()const
// Algorithme : Méthode simple
//
{
    if(racine->getData() == nullptr){
        return;
    }

    if (racine->getNext() == nullptr) {
        racine->getData()->Afficher();// si notre Linekdlist n'a qu'une seule racine on va juste l'afficher
    } else { // sinon on doit afficher chaque racine de notre liste en parcourant les cellules.
        Cell *parcours = racine;
        while (parcours->getNext() != nullptr) {
            parcours->getData()->Afficher(); //selon le type du trajet (simple/composé) on aurait une methode afficher qui adaptée (virtual)
            parcours = parcours->getNext();
        }
        parcours->getData()->Afficher(); //on va afficher la dernière racine
    }
}//----- Fin Afficher


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


Linkedlist::Linkedlist()
// Algorithme :  Méthode simple
//
{
    #ifdef MAP
            cout << "Appel au destructeur de <Linkedlist>" << endl;
    #endif
    racine = new Cell();


} //----- Fin de ~Linkedlist


Linkedlist::~Linkedlist ( )
// Algorithme :  Méthode simple
//
{
    #ifdef MAP
    cout << "Appel au destructeur de <Linkedlist>" << endl;
    #endif
    delete racine;
} //----- Fin de ~Linkedlist


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
