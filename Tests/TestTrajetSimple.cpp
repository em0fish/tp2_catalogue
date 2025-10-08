/*************************************************************************
TestTrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TestTrajetSimple> (fichier TestTrajetSimple.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "TestTrajetSimple.h"

#include <iostream>
#include <ostream>

#include "../TrajetSimple.h"
using namespace std;

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

static void TestConstructeur()
{
    cout << "TestConstructeur" << endl;
    TrajetSimple t("Lyon","Paris","Train");
    t.Afficher();
    Trajet * pt;
    pt = new TrajetSimple("","","");
    pt->Afficher();
}

static void TestAfficher ()
{
    cout << "TestAfficher" << endl;
    TrajetSimple t("Lyon","Paris","Train");
    t.Afficher();
    Trajet * pt;
    pt = new TrajetSimple("Paris","Marseille","Auto");
    pt->Afficher();
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ()

{
    TestConstructeur();
    TestAfficher();
} //----- fin de main
