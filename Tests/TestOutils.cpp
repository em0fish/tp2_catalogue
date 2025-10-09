/*************************************************************************
TestUtils  -  description
                            -------------------
    début                : $DATE$
*************************************************************************/

//---------- Réalisation du module <TestUtils> (fichier TestUtils.cpp) ---------------

///////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TestOutils.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes
#define LEN_BUFFER 130

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void TestSaisieInt()
// Mode d'emploi :
//  - L'utilisateur doit d'abord taper une entrée non entière (ex: abc),
//    puis un entier hors des bornes, puis un entier valide.
// Contrat :
//  - Utilise saisieInt(adresse, 1, 3).
{
    cout << "==== Test saisieInt ====" << endl;
    cout << "Tapez d'abord une valeur non numérique (ex: abc), puis 99, puis 2." << endl;
    int val = -1;
    saisieInt(&val, 1, 3);
    cout << "Valeur retenue: " << val << endl;
}

static void TestSaisieString()
// Mode d'emploi :
//  - L'utilisateur doit d'abord saisir une chaîne de plus de 99 caractères
//    (pour déclencher le message d'erreur), puis une chaîne courte valide.
// Contrat :
//  - Utilise saisieString(buffer).
{
    cout << "==== Test saisieString ====" << endl;
    cout << "Tapez d'abord une chaîne de plus de "<< LEN_BUFFER << " caractères (puis Entrée)," << endl;
    cout << "puis une chaîne courte" << endl;
    char buffer[LEN_BUFFER];
    buffer[0] = '\0';
    saisieString(buffer, LEN_BUFFER, "test saisie string");
    cout << "Chaîne lue: [" << buffer << "]" << endl;
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ()
{
    cout << "===== Début des tests interactifs de Utils =====" << endl;
    TestSaisieInt();
    TestSaisieString();
    cout << "===== Fin des tests Utils =====" << endl;
    return 0;
}