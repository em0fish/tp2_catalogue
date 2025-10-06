/*************************************************************************
                         Collection   -  description
                             -------------------
    début                : 02/10/2025
    copyright            : (C) 2025 par PICQUART Samuel, FISCHEROVA Ema 
    e-mail               : samuel.picquart@insa-lyon.fr
    			   ema.fischerova@insa-lyon.fr
*************************************************************************/

//----- Interface de la classe <Collection> (fichier Collection.h) -----
#if ! defined COLLECTION_H
#define COLLECTION_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Cellule {
	const Trajet *pt;
	struct Cellule *suivant;
};
typedef struct Cellule Cellule;

//------------------------------------------------------------------------
// Rôle de la classe <Collection>
// Cette classe represente une collection des objets de type `Trajet`,
// implementee sous forme d'une liste chainee.
//
//------------------------------------------------------------------------

class Collection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	bool Ajouter(const Trajet *pt);
	// Mode d'emploi :
    	// Ajoute un trajet pointe par `pt` dans la collection.
    	//
	// Contrat : Aucun.
	
	const Trajet *GetPremier() const;
	// Mode d'emploi :
    	// Recoupere le premier element ajoute dans la collection.
    	//
	// Contrat : Aucun.
	
	const Trajet *GetDernier() const;
	// Mode d'emploi :
    	// Recoupere le dernier element ajoute dans la collection.
	//
    	// Contrat : Aucun.
	
	const Trajet* Rechercher(const char *depart, const char *arrivee) const;
	// Mode d'emploi :
	// Trouve un trajet dans le catalogue partant de `depart`
	// et arrivant dans `arrive` et le renvoie, s'il existe.
	// S'il n'y a pas de trajet, la methode renvoie NULL.
	//
	// Contrat. Aucun.
	
	virtual void Afficher() const;
	// Mode d'emploi :
	// Affiche la collection.
	//
	// Contrat: Aucun.

//------------------------------------------------- Surcharge d'opérateurs
    Collection & operator = ( const Collection & uneCollection );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Collection ( const Collection & uneCollection );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat : Aucun.

    Collection ( );
    // Mode d'emploi :
    // Constructeur par defaut, initialise une collection vide.
    //
    // Contrat : Aucun.

    virtual ~Collection ( );
    // Mode d'emploi :
    // Destructeur de la classe Collection, appele automatiquement
    // par le compilateur quand necessaire.
    // 
    // Contrat : Aucun.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Cellule *premier;
	Cellule *dernier;

private:
	void supprimer(Cellule *premier);
	// Mode d'emploi:
	// Supprime recursivement une liste chainee de type Cellule *
	// qui commence avec `premier`.
	//
	// Contrat: Aucun.
};

//-------------------------------- Autres définitions dépendantes de <Collection>

#endif // COLLECTION_H
