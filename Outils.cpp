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
#include "Outils.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes
#define MAX_BUFFER_LEN 100

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


bool saisieInt (int* adresse, int limitInf, int limitSup)
// Algorithme : saisie contrôlée via cin/cout, validation bornes et nettoyage du flux.
{
    if (adresse == nullptr)
    {
        return false;
    }

    int tmp;
    while (true)
    {
        cout << "Veuillez saisir une valeur entre " << limitInf << " et " << limitSup << " : " << endl;

        if (!(cin >> tmp))
        {
            if (cin.eof())
            {
                return false; // fin de fichier: on abandonne sans modifier *adresse
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
        return true;
    }
} //----- fin de saisieInt

void saisieString(char* adresse, const char* message = "Veuillez saisir un string de longueur au plus 99\n")
// Algorithme : lecture d'une ligne via cin.getline dans un buffer C, gestion dépassement et copie sécurisée.
{
    if (adresse == nullptr)
    {
        return false;
    }
    size_t longueur =  MAX_BUFFER_LEN-1;

    char tmp[MAX_BUFFER_LEN]; // capacité maximale
    while (true)
    {
        cout << message << " (longueur entre 1 et " << longueur << ")" << endl;

        cin.getline(tmp, sizeof(tmp));
        if (!cin)
        {
            if (cin.eof())
            {
                // EOF: abandon sans modifier le buffer cible
                return false;
            }
            // Trop long ou autre erreur: vider le reste de la ligne et réessayer
            cerr << "Entrée trop longue (longueur entre 1 et " << longueur << "). Veuillez réessayer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        size_t len = strlen(tmp);
        if (len < 1)
        {
            cerr << "Entrée trop courte (longueur entre 1 et " << longueur << "). Veuillez réessayer." << endl;
            continue;
        }

        if (len > longueur)
        {
            cerr << "Entrée trop longue (longueur entre 1 et " << longueur << "). Veuillez réessayer." << endl;
            continue;
        }

        // Copier et garantir la terminaison NUL
        strncpy(adresse, tmp, len);
        adresse[len] = '\0';
        return true;
    }
}
