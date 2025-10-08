/*************************************************************************
                         Catalogue  -  description
                             -------------------
    début                : 02/10/2025
    copyright            : (C) 2025 par PICQUART Samuel, FISCHEROVA Ema  
    e-mail               : samuel.picquart@insa-lyon.fr
    			   ema.fischerova@insa-lyon.fr

 *************************************************************************/

//---- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <stdlib.h>

//------------------------------------------------------ Include personnel
#include "catalogue.h"
//#include "trajet.h"
#include "outils.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Menu() const 
// Algorithme :
{	int input = -1;
	int valeurRetour;
	bool succes;
	char villeDepart[100];
	char villeArrivee[100];
	Trajet* resultat;

	printf("Bienvenu dans l'interface de notre catalogue des \
trajets !\n");
	while (1)
	{
		printf("Qu'est ce que vous souhaitez faire ?\n\
\t 1 - Afficher les trajets proposes\n\
\t 2 - Trouver un trajet\n\
\t 3 - Ajouter un trajet dans le catalogue\n\n\
\t 0 - Sortir de l'interface");
		saisieInt(&input, 0, 3);

		switch (input) 
		{
			case 0:
				printf("Merci pour l'utilisation de \
nos services !\n");
				exit(0);
			case 1:
				Afficher();
				break;
			case 2:
				saisieString(&villeDepart);
				saisieString(villeArrivee);
				resultat = Rechercher(villeDepart, villeArrivee);
				if (resultat)
				{	printf("Trajet trouve !\n");
					resultat->Afficher();
				} else
				{	printf("Aucun trajet convient a\
ce recherche.\n");
				}

			case 3:
				succes = AjouterTrajet();
				if (succes)
				{	printf("Trajet ajouter avec succes !\n");
				} else 
				{	printf("Impossible d'ajouter le trajet.\n");
				}
				break;

		}
	}	
} //---- Fin de Menu

bool AjouterTrajet()
// Algorithme :
//
{
} //---- Fin de AjouterTrajet


//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
// Algorithme :
//
:Collection()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif 
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE
Trajet *saisieTS(int niveau)
// Algorithme:
//
{	char *depart = (char*)malloc(100*sizeof(char));
	char *arrivee = (char*)malloc(100*sizeof(char));
	char *moyenTransport = (char*)malloc(100*sizeof(char));
	char* messageDep = new char[101];
	char* messageArr = new char[101];
	char* messageTrans = new char[101];
	
	for (int i = 0; i < niveau; i++) {
		messageDep[i] = '-';
		messageArr[i] = '-';
		messageTrans[i] = '-';
	}
	messageDep[niveau] = '\0';
	messageArr[niveau] = '\0';
	messageTrans[niveau] = '\0'; 

	printf("%sTS: \n", messageArr);

	if (!saisieString(&depart, strcat(messageDep, "Ville de depart: "))
	|| !saisieString(&arrivee, strcat(messageArr, "Ville d'arrivee: "))
	|| !saisieString(&moyenTransport, strcat(messageTrans, "Moyen de transport: ")))
	{	fprintf(stderr,"saisie d'un trajet simple a echoue.\n");
		exit(1);
	}
	//printf("depart: %s, arrivee: %s, trans: %s\n", depart, arrivee, moyenTransport);
	return new Trajet(depart, arrivee, moyenTransport);
}




//----------------------------------------------------- Méthodes protégées
