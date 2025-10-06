/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H


//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const;

    virtual const char * GetVilleDepart() const;

    virtual const char * GetVilleArrivee() const;

    const char * GetMoyenDeTransport() const;
    // Mode d'emploi :
    //
    // Contrat :
    // Retourne le pointeur de char vers le mode de transport


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple (const char unDepart[], const char uneArrivee[], const char unMoyenDeTransport[]);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetSimple ();
        // Mode d'emploi :
        //
        // Contrat :
        //


//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privee

//----------------------------------------------------- Attributs privee
    char* villeDepart;
    char* villeArrivee;
    char* moyenDeTransport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H

