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
using namespace std;
#include <iostream>

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
    cout << "TrajetCompose : " << endl;
    sousTrajets.Afficher();
} //----- Fin de Afficher

bool TrajetCompose::Ajouter (Trajet * unTrajet)
{
    if (strcmp(unTrajet->GetVilleDepart(), this->GetVilleArrivee()) == 0)
    {
        return sousTrajets.Ajouter(unTrajet);
    }
    return false;
} //----- Fin de Ajouter


const char *TrajetCompose::GetVilleDepart() const
{
    return sousTrajets.GetPremier()->GetVilleDepart();
} //----- Fin de GetVilleDepart

const char *TrajetCompose::GetVilleArrivee() const
{
    return sousTrajets.GetDernier()->GetVilleArrivee();
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
