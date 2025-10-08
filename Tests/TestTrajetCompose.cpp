/*************************************************************************
TestTrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TestTrajetCompose> (fichier TestTrajetCompose.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "TestTrajetCompose.h"

#include <iostream>
#include <ostream>

#include "../TrajetCompose.h"
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
    TrajetCompose tc;
    tc.Afficher();
}

static void TestAfficher ()
{
    cout << "TestAjouter" << endl;
    Trajet * t1 = new TrajetSimple("Lyon","Paris","Train");
    Trajet * t2 = new TrajetSimple("Paris","Marseille","Auto");
    Trajet * t3 = new TrajetSimple("Biarritz","Paris","Avion");
    TrajetCompose tc;
    tc.Ajouter(t1);
    tc.Ajouter(t2);
    tc.Ajouter(t3);
    tc.Afficher();
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ()

{
    TestConstructeur();
    TestAfficher();
} //----- fin de main
