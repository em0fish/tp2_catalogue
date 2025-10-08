/*************************************************************************
                         Catalogue  -  description
                             -------------------
    début                : 02/10/2025
    copyright            : (C) 2025 par PICQUART Samuel, FISCHEROVA Ema  
    e-mail               : samuel.picquart@insa-lyon.fr
    			   ema.fischerova@insa-lyon.fr

**************************************************************************/

//----- Interface de la classe <Catalogue> (fichier catalogue.h) ------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "collection.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue : private Collection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques   
	bool AjouterTrajet();
	// Mode d'emploi :
	// Permet de saisir un trajet (simple ou compose) et l'ajouter
	// dans le catalogue.	
	//
	// Contrat : Aucun.
 
	void Menu() const;
	// Mode d'emploi :
	// La methode qui gere toutes les interactions de l'utilisateur
	// avec le catalogue.
	//
	// Contrat : Aucun.
 
	void Afficher() const;
	// Mode d'emploi :
	//
	// Contrat : Aucun.
 
//------------------------------------------------- Surcharge d'opérateurs
    Catalogue & operator = ( const Catalogue & unCatalogue );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue ( );
    // Mode d'emploi :
    // Constructeur par defaut. Initialise
    // un catalogue vide.
    //
    // Contrat : Aucun.

    virtual ~Catalogue ( );
    // Mode d'emploi :
    // Destructeur de la classe Catalogue,
    // appeler automatiquement par le compilateur.
    //
    // Contrat : Aucun.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // CATALOGUE_H

