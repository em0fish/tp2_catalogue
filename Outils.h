/*************************************************************************
                         Outils  -  description
                             -------------------
    début                : 02/10/2025
    copyright            : (C) 2025 par PICQUART Samuel, FISCHEROVA Ema  
    e-mail               : samuel.picquart@insa-lyon.fr
    			   ema.fischerova@insa-lyon.fr
*************************************************************************/

//-------- Interface du module <Outils> (fichier outils.h) ---------------
#if ! defined ( OUTILS_H )
#define OUTILS_H

//------------------------------------------------------------------------
// Rôle du module <Outils>
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

bool saisieInt(int* adresse, int limitInf,int limitSup);
// Mode d'emploi :
// Function qui permet une saisie controlee d'un int, compris
// entre `limitInf` et `limitSup`, a stocker dans `adresse`.
//
// Contrat : Aucun.

bool saisieString(char** adresse, const char* message);
// Mode d'emploi :
// Function qui permet une saisie controlee d'un string, d'un
// longueur au max 99 chars.
//
// Contrat : Aucun.

#endif // OUTILS_H
