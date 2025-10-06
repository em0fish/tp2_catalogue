/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 06/10/2025
    copyright            : (C) 2025 par PICQUART Samuel & FISCHEROVA Ema
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "collection.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool Ajouter (Trajet * unTrajet);
    // Mode d'emploi :
    // permet d'ajouter un trajet dans un trajet composé si la ville d'arrivee courante est égale à la ville de départ de unTrajet
    // Contrat :
    // retourne true si l'ajout est réalisé, false sinon


    virtual const char * GetVilleDepart() const;


    virtual const char * GetVilleArrivee() const;


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privées
//
    Collection sousTrajets;

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H

