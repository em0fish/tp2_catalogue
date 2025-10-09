/*************************************************************************
                         Outils  -  description
                             -------------------
    début                : 02/10/2025
    copyright            : (C) 2025 par PICQUART Samuel, FISCHEROVA Ema  
    e-mail               : samuel.picquart@insa-lyon.fr
    			   ema.fischerova@insa-lyon.fr
*************************************************************************/

//-------- Interface du module <Outils> (fichier outils.h) ---------------
#if ! defined (OUTILS_H )
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

void saisieInt(int* adresse, int limitInf,int limitSup);
// Mode d'emploi :
// Function qui permet une saisie controlee d'un int, compris
// entre `limitInf` et `limitSup`, a stocker dans `adresse`.
//
// Contrat : Aucun.

void saisieString(char* adresse, const size_t longueur = 50, const char* message = "Veuillez saisir un string");
// Mode d'emploi :
// Fonction qui permet une saisie contrôlée d'une chaîne C (char*), de
// longueur au plus 99 caractères (sans compter le terminator '\0').
// Le prompt affiche le message fourni (ou le message par défaut) suivi de
// "(longueur max 99)". La chaîne lue est stockée dans `adresse` avec
// terminaison NUL garantie.
//
// Contrat : `adresse` doit pointer vers un buffer d'au moins 100 octets.

#endif // OUTILS_H
