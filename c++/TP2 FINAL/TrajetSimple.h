/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $21-11-2022$
    copyright            : (C) $2022$ par $Binôme3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Créer et gérer un trajet simple d'une ville A vers une ville B en utilisant un moyen de transport déterminé
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const ;
    // Mode d'emploi :
    //  Affiche un texte qui résume le voyage
    // Contrat :
    //
    
    const char* getvilled() const ;
    // Mode d'emploi :
    //  retourne  la ville de départ du trajet simple
    // Contrat :
    //

    const char* getvillea() const ;
    // Mode d'emploi :
    // retourne  la ville d'arrivée du trajet simple
    // Contrat :
    //

    const char* getTransport() const ;
    // Mode d'emploi :
    //  retourne  le moyen de transport du trajet simple
    // Contrat :
    //




//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple (const char * vDepart ,const char * vArrivee ,const char * mTransport );
    // Mode d'emploi :
    //  Constructeur d'un trajet simple à partir d'une ville de départ, une ville d'arrivée et un moyen de transport
    // Contrat :
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    // Destructeur
    // Contrat :
    //



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char* transport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H