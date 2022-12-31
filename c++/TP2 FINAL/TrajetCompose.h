/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $21-11-2022$
    copyright            : (C) $2022$ par $Binôme3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées
#include "Linkedlist.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//cette Classe va créer/gérer/repertorier les trajets composés
//
//------------------------------------------------------------------------

class TrajetCompose: public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
      //GETTERS,SETTERS
    virtual const char* getvillea()const;
    // Mode d'emploi:
    // Retourne le ville d'arrivée du trajet composé
    //
    //Contrat:
    //PAS DE CONTRAT

    virtual const char* getvilled()const;
    // Mode d'emploi:
    // Retourne le ville de départ du trajet composé
    //
    //Contrat:
    //PAS DE CONTRAT

    //--Fin GETTERS,SETTERS

    
    int AjouterTrajet(const Trajet* t);
    // Mode d'emploi:
    // Ajouter un trajet à notre trajet composé tout en vérifiant de la faisabilité de cet ajout:
    // on vérifie s'il s'agit du premier trajet à rajouter, si c'est le cas on peut ajouter
    // sinon on doit vérifier la correspondence des villes.
    // cette méthode retourne 1 si l'ajout a été réaliser sinon 0
    //
    //Contrat:
    //PAS DE CONTRAT




    virtual void Afficher()const ;
    // Mode d'emploi :
    // Cette méthode va afficher la ville de départ de notre première étape ainsi
    // que la ville d'arrivée de la dernière étape. Etant donné que le trajet composé
    // peut avoir plusieurs moyens de transport on a décider de ne pas afficher les modes de
    // transport.
    // Contrat :
    //PAS DE CONTRAT




//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur


    TrajetCompose ();
    // Mode d'emploi : cette methode va demander à l'utilisateur:
    // cette méthode va créer un Trajet composé vide et après
    // on demandera à l'utilisateur de rajouter les étapes qui composent
    // ce trajet (avec la methode AjouterTrajet).
    // Contrat :
    //PAS DE CONTRAT


    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //PAS DE CONTRAT


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Linkedlist compo; // cette Linkedlist va indiquer les différents trajets qui compose notre trajet initial.

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H