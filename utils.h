/*************************************************************************
                       Collection  -  description
                             -------------------
    début                : 02/10/2025
    copyright            : (C) 2025 par PICQUART Samuel, FISCHEROVA Ema  
    e-mail               : samuel.picquart@insa-lyon.fr
    			   ema.fischerova@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <Xxx> (fichier Xxx.h) -------------------
#if ! defined (UTILS_H )
#define UTILS_H

//------------------------------------------------------------------------
// Rôle du module <Xxx>
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void saisieInt(int* adresse, int limitInf,int limitSup);
// Mode d'emploi :
// Function qui permet une saisie controlee d'un int, compris
// entre `limitInf` et `limitSup`, a stocker dans `adresse`.
//
// Contrat : Aucun.

void saisieString(char* adresse);
// Mode d'emploi :
// Function qui permet une saisie controlee d'un string, d'un
// longueur au max 99 chars.
//
// Contrat : Aucun.

#endif // UTILS_H
