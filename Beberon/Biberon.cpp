#include <iostream>;
#include "Biberon.h";
#include <string>;
#include <ctime>;
using namespace std;

// ============= Initialisation =============
void Biberon::creationPlanning(int heurePremierRepas, int delaiPrise) {
	int nmbrRepas = getQuantite_max() - getQuantite_mini();
	for (int i = 0; i < nmbrRepas; i++) {
		_heure_prise[i] = (heurePremierRepas + delaiPrise)% 86400000;
	}
}

// ============= Getters =============
int Biberon::getQuantite_max() {
	return _quantite_max;
}
int Biberon::getQuantite_mini() {
	return _quantite_mini;
}
int Biberon::getQuantite_restante() {
	return _quantite_restante;
}
int Biberon::getQuantite_donnee() {
	return _quantite_donnee;
}
int Biberon::getPremierePrise() {
	return _premiere_prise;
}
int* Biberon::getHeure_Prise() {
	return _heure_prise;
}
bool Biberon::getVomi() {
	return _vomi;
}

// ============= Setters =============
void Biberon::setQuantite_restante(int newQuantite) {
	_quantite_restante = newQuantite;
}
void Biberon::setQuantite_donnee(int newQuantite) {
	_quantite_donnee = newQuantite;
}
void Biberon::setPremierePrise(int premierePrise) {
	_premiere_prise = premierePrise;
}

// ============= Constructeur =============

Biberon::Biberon() {																					// Constructeur par d�faut de Biberon
	_quantite_max = 0;
	_quantite_mini = 0;
	_quantite_restante = 0;
	_quantite_donnee = 0;
	_premiere_prise = 0;
	_heure_prise [0] = {};
	_vomi = false;
}

Biberon::Biberon(int quantMax, int quantMini, int quantInitial											// Constructeur d'un nouveau biberon plein pas encore donn�.
				, int premierePrise, int intervallePrises) {
	_quantite_max = quantMax;
	_quantite_mini = quantMini;											
	_quantite_restante = quantInitial;																	// Le biberon �tant plein, la quantit� restant = quantit� initiale
	_quantite_donnee = 0;																				// Vu que le biberon n'a pas encore �tait donn�, quantit�_donn�e = 0
	_premiere_prise = premierePrise;
	creationPlanning(_premiere_prise, intervallePrises);
	_vomi = false;																						// Vu que le biberon n'a pas encore �tait donn�, impossible qu'il ai �t� vomi
}

Biberon::Biberon(int quantiMax, int quantiMini, int quantiInital,										// Constructeur d'un biberon d�j� donn�
				int quantiDonnee, int heureDonnee, int intervallePrises, bool vomito) {	
	_quantite_max = quantiMax;
	_quantite_mini = quantiMini;
	_quantite_restante = quantiInital - quantiDonnee;													// Comme on a d�j� donn� le biberon au moins une fois, quantit� restante = quantit� intiale - quantit� donn�e
	_quantite_donnee = quantiDonnee;
	_premiere_prise = heureDonnee;																		// Heure � laquelle on a donn�e le biberon
	creationPlanning(heureDonnee, intervallePrises);
	_vomi = vomito;																						// On declare si le biberon a �t� vomi ou non
}

// ============= Destructeur =============

Biberon::~Biberon() {
	
}

// ============= M�thodes =============

void Biberon::afficherHoraire() {
	string heureTraduite = "";

}

// ============= Choses � utiliser (prise de notes pour m'y retrouver) =============

/*
* -- Usage de la librairie ctime
*	- // date / heure actuelle bas�e sur le syst�me actuel
		time_t tmm = time(0);
	- double difftime (time_t time2, time_t time1);
		Cette fonction calcule la diff�rence en secondes entre time1 et time2.
	
	-- A faire
		- afficherHoraire() qui affiche la prochaine prise de biberon
		(trouv� comment faire la diff�rence entre les heures dans le tableau et l'heure syst�me et prendre la premi�re occurence de temps sup�rieur � l'heure syst�me)
		- 
*/