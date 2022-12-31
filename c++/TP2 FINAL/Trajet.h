/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $21-11-2022$
    copyright            : (C) $2022$ par $Binôme3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined(TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Une classe abstraite parent de TrajetSimple et TrajetComposé
//
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const = 0;
    // Mode d'emploi :
    // Affichage des détails d'un trajet
    // Contrat :
    // PAS DE CONTRAT

    virtual const char *getvilled() const = 0;
    // Mode d'emploi :
    // retourne la ville de départ d'un trajet
    // Contrat :
    // PAS DE CONTRAT

    virtual const char *getvillea() const = 0;
    // Mode d'emploi :
    // retourne la ville d'arrivée d'un trajet
    // Contrat :
    // PAS DE CONTRAT

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    virtual ~Trajet();
    // Mode d'emploi :
    // Destructeur d'un trajet
    // Contrat :
    // PAS DE CONTRAT

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    char *depart;
    char *arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H