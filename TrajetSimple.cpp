/*************************************************************************
TrajetSimple  -  description
                             -------------------
    début                : 06/10/2025
    copyright            : (C) 2025 par PICQUART Samuel & FISCHEROVA Ema
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetSimple::Afficher() const
{
    cout << villeDepart << " -> " << villeArrivee << " (" << moyenDeTransport << ")" << endl;
}


const char * TrajetSimple::GetVilleDepart() const
{
    return this->villeDepart;
} //----- Fin de getVilleDepart

const char * TrajetSimple::GetVilleArrivee() const
{
    return villeArrivee;
} //----- Fin de getVilleArrivee

const char * TrajetSimple::GetMoyenDeTransport() const
{
    return moyenDeTransport;
} //----- Fin de getMoyenDeTransport



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char unDepart[], const char uneArrivee[], const char unMoyenDeTransport[])
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    villeDepart = new char[strlen(unDepart)+1];
    strcpy(villeDepart, unDepart);

    villeArrivee = new char[strlen(uneArrivee)+1];
    strcpy(villeArrivee, uneArrivee);

    moyenDeTransport = new char[strlen(unMoyenDeTransport)+1];
    strcpy(moyenDeTransport, unMoyenDeTransport);
}//----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete [] villeDepart;
    delete [] villeArrivee;
    delete [] moyenDeTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
