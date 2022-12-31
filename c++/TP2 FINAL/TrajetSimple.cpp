/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $21-11-2022$
    copyright            : (C) $2022$ par $Binôme3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const
// Algorithme : Méthode simple
//
{
    cout << "TS de " << depart << " à " << arrivee << " en " << transport << endl ;
}

const char* TrajetSimple::getvilled() const
// Algorithme : Méthode simple
//
{
    return depart;
}

const char* TrajetSimple::getvillea() const
// Algorithme : Méthode simple
//
{
    return arrivee;
}

const char* TrajetSimple::getTransport() const
// Algorithme : Méthode simple
//
{
    return transport;
}



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char * vDepart ,const char * vArrivee ,const  char * mTransport )
// Algorithme : Méthode simple
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
    depart=new char[strlen(vDepart)+1];
    arrivee=new char[strlen(vArrivee)+1];
    transport=new char[strlen(mTransport)+1];
    strcpy(depart,vDepart);
    strcpy(arrivee,vArrivee);
    strcpy(transport,mTransport); 
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme : Méthode simple
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
    delete[] arrivee;
    delete[] depart;
    delete[] transport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées