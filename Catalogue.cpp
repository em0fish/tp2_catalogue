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
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "Outils.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Menu() 
// Algorithme :
{	int input = -1;
	bool succes;
	char *villeDepart = (char*)malloc(sizeof(char)*101);
	char *villeArrivee = (char*)malloc(sizeof(char)*101);
	const Trajet* resultat;

	printf("Bienvenu dans l'interface de notre catalogue des \
trajets !\n");
	while (1)
	{
		printf("Qu'est ce que vous souhaitez faire ?\n\
\t 1 - Afficher les trajets proposes\n\
\t 2 - Trouver un trajet\n\
\t 3 - Ajouter un trajet dans le catalogue\n\n\
\t 0 - Sortir de l'interface\n");
		saisieInt(&input, 0, 3);

		switch (input) 
		{
			case 0:
				printf("Merci pour l'utilisation de \
nos services !\n");
				free(villeDepart); free(villeArrivee);
				return;
			case 1:
				Afficher();
				break;
			case 2:
				saisieString(&villeDepart, "Veuillez saisir la ville\
 de depart: \n");
				saisieString(&villeArrivee, "Veuillez saisir la ville\
 d'arrive: \n");
				resultat = Rechercher(villeDepart, villeArrivee);
				if (resultat)
				{	printf("Trajet trouve !\n");
					resultat->Afficher();
				} else
				{	printf("Aucun trajet convient a\
ce recherche.\n");
				}
				break;
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
	free(villeDepart); free(villeArrivee);	
} //---- Fin de Menu

bool Catalogue::AjouterTrajet()
// Algorithme :
//
{	Cellule *nouvelleCellule = saisieTrajet(0);
	if (!nouvelleCellule) return false;

	if (!Ajouter(nouvelleCellule->pt))
	{	// pour appeler implicitement le destructeur de collection
		Collection col(nouvelleCellule);
		free(nouvelleCellule);
		return false;
	}
	free(nouvelleCellule);
	return true;
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
Trajet *Catalogue::saisieTS(int niveau)
// Algorithme:
//
{	char *depart = (char*)malloc(100*sizeof(char));
	char *arrivee = (char*)malloc(100*sizeof(char));
	char *moyenTransport = (char*)malloc(100*sizeof(char));
	char *messageDep = (char*)malloc(sizeof(char)*100);
	char *messageArr = (char*)malloc(sizeof(char)*100);
	char *messageTrans = (char*)malloc(sizeof(char)*100);
	Trajet* retVal;


	for (int i = 0; i < niveau; i++) {
		messageDep[i] = '-';
		messageArr[i] = '-';
		messageTrans[i] = '-';
	}
	messageDep[niveau] = '\0';
	messageArr[niveau] = '\0';
	messageTrans[niveau] = '\0'; 

	printf("%sTS: \n", messageArr);

	strncat(messageDep, "Ville de depart: ", 18);
 	strncat(messageArr, "Ville d'arrivee: ", 18);
	strncat(messageTrans, "Moyen de transport: ", 21);
	
	if (!saisieString(&depart, messageDep)
	|| !saisieString(&arrivee, messageArr)
	|| !saisieString(&moyenTransport, messageTrans))
	{	fprintf(stderr,"saisie d'un trajet simple a echoue.\n");
		free(depart); free(arrivee); free(moyenTransport);
		free(messageDep); free(messageArr); free(messageTrans);
		exit(1);
	}
	// printf("depart: %s, arrivee: %s, trans: %s\n", depart, arrivee, moyenTransport);
	
	free(messageDep); free(messageArr); free(messageTrans);
	retVal = new TrajetSimple(depart, arrivee, moyenTransport);
	free(depart); free(arrivee); free(moyenTransport);
	return retVal;
} // ---- Fin de saisieTS

Cellule *Catalogue::saisieTrajet(int niveau)
// Algorithme :
{	char *type = (char*)malloc(sizeof(char)*100);
	char message[] = "Souhatez-vous ajouter un trajet simple (TS),\
 ajouter un trajet compose (TC) ou bien finir la saisie de TC en \
cours (FIN) ?\n";	
	Trajet* nouveauTrajet;
	Cellule* nouvelleCellule;
	Cellule* res;
	TrajetCompose* TC;

	char* traits = (char*)malloc(sizeof(char)*500);
	for (int i = 0; i < niveau; i++) traits[i] = '-';
	traits[niveau] = '\0';

//	printf("before saisieString\n");

	// saisie utilisateur TS/TC/FIN
	do 
	{ if (!saisieString(&type, strcat(traits, message))) 
		{	free(type); free(traits);
			fprintf(stderr, "Echec de lecture du choix\n");
			exit(1);
		}
	} while (strcmp(type, "TS") != 0 
		&& strcmp(type, "TC") != 0
		&& strcmp(type, "FIN") != 0);

	// creation d'un trajet
	if (!strcmp(type, "TS"))
	{	nouveauTrajet = saisieTS(++niveau);
		nouvelleCellule = (Cellule*)malloc(sizeof(Cellule));
		nouvelleCellule->pt = nouveauTrajet;
		nouvelleCellule->suivant = NULL;
		free(type); free(traits);
		return nouvelleCellule;
	} else if (!strcmp(type, "TC"))
	{	res = saisieTrajet(++niveau);
		if (!res) {
			free(type); free(traits);
			fprintf(stderr, "construction incorrecte d'un \
trajet compose. un TC doit avoir au moins un trajet\n");
			return NULL;
		}
		
		
		nouvelleCellule = (Cellule*)malloc(sizeof(Cellule));
		TC = new TrajetCompose();
		nouvelleCellule->pt = TC;
		nouvelleCellule->suivant = NULL;
		
		while (res) {
			if (TC->Ajouter(res->pt))
			{	free(res);
				res = saisieTrajet(niveau);
			} else 
			{	fprintf(stderr, "construction \
incorrecte d'un trajet compose. impossible d'ajouter le trajet cree dans un TC.\n");
				free(type); free(traits); free(nouvelleCellule);
				delete res->pt;
				free(res);
				delete TC;

				return NULL;
			}
		}

		free(type); free(traits);
		return nouvelleCellule;
	} else // type == "FIN" => fin de saisie d'un trajet compose 
	{	free(type); free(traits);
		return NULL;
	}
} //---- Fin de saisieTrajet


//----------------------------------------------------- Méthodes protégées
