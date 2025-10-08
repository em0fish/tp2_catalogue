/*************************************************************************
                       Outils -  description
                             -------------------
    début                : 02/10/2025
    copyright            : (C) 2025 par PICQUART Samuel, FISCHEROVA Ema  
    e-mail               : samuel.picquart@insa-lyon.fr
    			   ema.fischerova@insa-lyon.fr

*************************************************************************/

//---------- Réalisation du module <Outils> (fichier outils.cpp) ---------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "outils.h"

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


bool saisieInt (int* adresse, int limitInf, int limitSup)
// Algorithme :
//
{	int tmp;
	int valRet;

	do 
	{	printf("Veuillez saisir une valeur entre %d et %d\n",
			limitInf, limitSup);
		valRet = scanf("%d", &tmp);
	
		if (feof(stdin)) 
		{	return false;
		}
		
		if (valRet == 0) // nettoyer le buffer stdin
		{	while (getchar()) {}
			continue;
		}
	} while (tmp > limitSup || tmp < limitInf);
	*adresse = tmp;
	return true
} //----- fin de saisieInt
 
bool saisieString(char **adresse, 
	const char *message = "Veuillez saisir un string de longueur au plus 99\n")
//Algorithme :
//
{	char tmp[100];

	printf("%s",message);
	scanf("%s", tmp);

	if (feof(stdin)) return false;

	strcpy(*adresse, tmp);
	return true;
}
