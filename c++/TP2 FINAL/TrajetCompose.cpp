/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $21-11-2022$
    copyright            : (C) $2022$ par $Binôme3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// GETTERS,SETTERS
const char *TrajetCompose::getvillea() const
// Algorithme : Méthode simple
{
    Cell *parcours = compo.getracine();
    while (parcours->getNext() != nullptr)
    {
        parcours = parcours->getNext();
    }

    return parcours->getData()->getvillea();
}

const char *TrajetCompose::getvilled() const
// Algorithme : Méthode simple
{
    Cell *parcours = compo.getracine();
    return parcours->getData()->getvilled();
}

//--Fin GETTERS,SETTERS

int TrajetCompose::AjouterTrajet(const Trajet *t)
// Algorithme : Méthode simple
{

    if (compo.getracine()->getData() == nullptr || strcmp(getvillea(), t->getvilled()) == 0)
    {
        if (compo.getracine()->getData() == nullptr)
            depart = (char *)t->getvilled();
        compo.Ajouter(t); // on utilise la méthode d'ajout de la Linkedlist
        arrivee = (char *)t->getvillea();
        return 1;
    }
    else
    {
        cout << "Erreur: impossible de rajouter";
        t->Afficher();
        cout << "la ville d'arrivée ne correspond pas à la ville de depart\n";
        return 0;
    }

} //----- Fin de AjouterTrajet

void TrajetCompose::Afficher() const
// Algorithme : Méthode simple
//
{
    cout << "TC de " << depart << " à " << arrivee << ":" << endl;
    cout << "[\n";
    compo.Afficher();
    cout << "]\n";

} //----- Fin Afficher

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetComposee>" << endl;
#endif

} //----- Fin de TrajeCompose

TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComposee>" << endl;
#endif

} //----- Fin de ~TrajetComposee

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées