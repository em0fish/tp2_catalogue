/*************************************************************************
                       Collection  -  description
                             -------------------
    début                : 02/10/2025
    copyright            : (C) 2025 par PICQUART Samuel, FISCHEROVA Ema  
    e-mail               : samuel.picquart@insa-lyon.fr
    			   ema.fischerova@insa-lyon.fr

*************************************************************************/

//---------- Réalisation de la classe <Collection> (fichier collection.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>

//------------------------------------------------------ Include personnel
#include "collection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Collection::Ajouter(const Trajet* pt)
// Algorithme :
{
	Cellule *nouvelleCellule = new Cellule;
	nouvelleCellule->pt = pt;
	nouvelleCellule->suivant = nullptr;

	dernier->suivant = nouvelleCellule;
	dernier = nouvelleCellule;
} //----- Fin de Ajouter

void Collection::Afficher() const
{
	Cellule *courant = premier;
	while (courant)
	{
		if (premier!=courant) 
			cout << "--------------" << endl;
		courant->pt->Afficher();
		courant = courant->suivant;
	}
} //------ Fin de Afficher()

const Trajet *Collection::Rechercher(
		const char *depart, const char *arrivee) const
{
	for (Cellule *c = premier; c; c = c->suivant)
	{	if (!strcmp(c->pt->GetVilleDepart(), depart)
		&& !strcmp(c->pt->GetVilleArrivee(), arrivee))
		{	return c->pt;
		}
	}
	return NULL;
}

const Trajet *Collection::GetPremier() const
// Algorithme :
{	
	return premier->pt;
} //----- Fin de GetPremier

const Trajet *Collection::GetDernier() const
// Algorithme :
{	
	return dernier->pt;
} //----- Fin de GetDernier

//------------------------------------------------- Surcharge d'opérateurs
Collection & Collection::operator = ( const Collection & uneCollection )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Collection::Collection ( const Collection & uneCollection )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Collection>" << endl;
#endif
} //----- Fin de Collection (constructeur de copie)


Collection::Collection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif
	premier = nullptr;
	dernier = nullptr;
} //----- Fin de Collection


Collection::~Collection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif
    supprimer(premier);    	
} //----- Fin de ~Collection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Collection::supprimer(Cellule *premier)
{
	if (premier)
	{
		supprimer(premier->suivant);
		delete premier;
	}
}
