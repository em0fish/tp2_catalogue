/*************************************************************************
TrajetCompose  -  description
                             -------------------
    début                : 06/10/2025
    copyright            : (C) 2025 par PICQUART Samuel & FISCHEROVA Ema
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetCompose::Afficher() const
{
    cout << "########### TrajetCompose ###########" << endl;
    sousTrajets.Afficher();
    cout << "######### Fin TrajetCompose #########" << endl;
} //----- Fin de Afficher

bool TrajetCompose::Ajouter (const Trajet * unTrajet)
{
    if (unTrajet == nullptr)
    {
        return false;
    }

    // Si aucun sous-trajet ajouter
    const Trajet* dernierSousTrajet = sousTrajets.GetDernier();
    if (dernierSousTrajet == nullptr)
    {
        return sousTrajets.Ajouter(unTrajet);
    }

    // Sinon, vérifier la continuité: arrivée courante == départ du nouveau puis ajouter
    const char* arriveeCourante = dernierSousTrajet->GetVilleArrivee();
    const char* departNouveau = unTrajet->GetVilleDepart();

    if (arriveeCourante != nullptr && departNouveau != nullptr && strcmp(departNouveau, arriveeCourante) == 0)
    {
        return sousTrajets.Ajouter(unTrajet);
    }
    return false;
} //----- Fin de Ajouter


const char *TrajetCompose::GetVilleDepart() const
{
    const Trajet* premierSousTrajet = sousTrajets.GetPremier();
    return premierSousTrajet ? premierSousTrajet->GetVilleDepart() : nullptr;
} //----- Fin de GetVilleDepart

const char *TrajetCompose::GetVilleArrivee() const
{
    const Trajet* dernierSousTrajet = sousTrajets.GetDernier();
    return dernierSousTrajet ? dernierSousTrajet->GetVilleArrivee() : nullptr;
} //----- Fin de GetVilleArrivee



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
