/*************************************************************************
                       Collection  -  description
                             -------------------
    début                : 02/10/2025
    copyright            : (C) 2025 par PICQUART Samuel, FISCHEROVA Ema  
    e-mail               : samuel.picquart@insa-lyon.fr
    			   ema.fischerova@insa-lyon.fr

*************************************************************************/

//---------- Réalisation du module <Utils> (fichier utils.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <limits>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "utils.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


void saisieInt (int* adresse, int limitInf, int limitSup)
// Algorithme : saisie contrôlée via cin/cout, validation bornes et nettoyage du flux.
{
    if (adresse == nullptr)
    {
        return;
    }

    int tmp;
    while (true)
    {
        cout << "Veuillez saisir une valeur entre " << limitInf << " et " << limitSup << " : " << endl;

        if (!(cin >> tmp))
        {
            if (cin.eof())
            {
                return; // fin de fichier: on abandonne sans modifier *adresse
            }
            // entrée invalide: effacer l'état d'erreur et vider la ligne
            cout << "Entrée invalide: veuillez saisir un entier." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Consommer le reste de la ligne pour repartir proprement au prochain input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (tmp < limitInf || tmp > limitSup)
        {
            cout << "Valeur hors bornes. Attendu dans [" << limitInf << ", " << limitSup << "]. Réessayez." << endl;
            continue; // hors bornes, redemander
        }

        *adresse = tmp;
        return;
    }
} //----- fin de saisieInt
 
void saisieString(char* adresse)
// Algorithme : lecture d'une ligne via cin.getline dans un buffer C, gestion dépassement et copie sécurisée.
{
    if (adresse == nullptr)
    {
        return;
    }

    char tmp[100]; // capacité 100 -> on autorise jusqu'à 99 caractères + '\0'
    while (true)
    {
        cout << "Veuillez saisir un string de longueur au plus 99" << endl;

        cin.getline(tmp, sizeof(tmp));
        if (!cin)
        {
            if (cin.eof())
            {
                // EOF: abandon sans modifier le buffer cible
                return;
            }
            // Dépassement (failbit) ou autre erreur: vider le reste de la ligne et réessayer
            cerr << "Entrée trop longue (maximum 99 caractères). Veuillez réessayer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Longueur lue (sans le '\n')
        size_t len = strlen(tmp);
        if (len > 99)
        {
            cerr << "Entrée trop longue (maximum 99 caractères). Veuillez réessayer." << endl;
            continue;
        }

        // Copier et garantir la terminaison NUL
        strncpy(adresse, tmp, 99);
        adresse[len] = '\0';
        return;
    }
}
