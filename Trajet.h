/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 2 Oct 2025
    copyright            : (C) 2025 par PICQUART Samuel
    e-mail               : samuel.picquart@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( Trajet_H )
#define Trajet_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Afficher () const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    // Permet d'afficher les caractéristique d'un trajet

    virtual const char * GetVilleDepart() const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    // Permet de récupérer un pointer vers la chaine de caractère de la ville de départ d'un trajet

    virtual const char * GetVilleArrivee() const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    // Permet de récupérer un pointer vers la chaine de caractère de la ville d'arrivée d'un trajet

//------------------------------------------------- Surcharge d'opérateurs
    // Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    virtual ~Trajet() {};

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

