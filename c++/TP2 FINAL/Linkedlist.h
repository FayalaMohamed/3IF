/*************************************************************************
                           Linkedlist  -  description
                             -------------------
    début                : $21-11-2022$
    copyright            : (C) $2022$ par $Binôme3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Linkedlist> (fichier Linkedlist.h) ----------------
#if ! defined ( LINKEDLIST_H )
#define LINKEDLIST_H

//--------------------------------------------------- Interfaces utilisées
#include "Cell.h"

//------------------------------------------------------------- Constantes
const int INIT=2;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Linkedlist>
//Linkedlist est une liste chainee qui pointe vers la première racine
// celle-ci peut contenir des trajets
//
//------------------------------------------------------------------------

class Linkedlist
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    //GETTERS,SETTERS
    Cell* getracine()const;
    // Mode d'emploi :
    // retourne la première racine de la liste
    // Contrat :
    //PAS DE CONTRAT
    //
    const char* getVillea() const;
    // Mode d'emploi :
    // retourne la ville d'arrivée du dernier trajet de la liste
    // on l'utilise dans la recherche combinée dans Catalogue
    // Contrat :
    //PAS DE CONTRAT
    //
    const char* getVilled() const;
    // Mode d'emploi :
    // retourne la ville de de départ du premier trajet de la liste
    // on l'utilise dans la recherche combinée dans Catalogue
    // Contrat :
    //PAS DE CONTRAT
    //
    void setracine(Cell* cell);
    // Mode d'emploi :
    // change la valeur de la première racine de la liste
    // Contrat :
    //PAS DE CONTRAT
    //

    //----Fin GETERS,SETTERS

    void Ajouter(const Trajet* t);
    // Mode d'emploi :
    // cette methode va ajouter un trajet à la liste
    // Contrat :
    //PAS DE CONTRAT
    //

    void tri();
    // Mode d'emploi :
    // cette methode va trier les cellules selon un ordre alphabétique croissant
    // des villes de départ afin de simplifier la lecture de l'affichage
    // pour l'utilisateur.
    // Contrat :
    //PAS DE CONTRAT
    //

    void Afficher()const;
    // Mode d'emploi :
    // cette méthode va afficher les différents trajets qui composent la liste
    // pour chaque racine elle va faire appel à la méthode Afficher liée à chaque type de trajet (simple ou composé).
    // Contrat :
    //PAS DE CONTRAT
    //

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur


    Linkedlist ();
    // Mode d'emploi :
    // Constructeur de Linkedlist
    // Contrat :
    //

    virtual ~Linkedlist ( );
    // Mode d'emploi :
    // Desructeur de Linkedlist
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Cell *racine;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // Linkedlist_H