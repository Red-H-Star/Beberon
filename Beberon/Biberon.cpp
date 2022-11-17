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

Biberon::Biberon() {																					// Constructeur par défaut de Biberon
	_quantite_max = 0;
	_quantite_mini = 0;
	_quantite_restante = 0;
	_quantite_donnee = 0;
	_premiere_prise = 0;
	_heure_prise [0] = {};
	_vomi = false;
}

Biberon::Biberon(int quantMax, int quantMini, int quantInitial											// Constructeur d'un nouveau biberon plein pas encore donné.
				, int premierePrise, int intervallePrises) {
	_quantite_max = quantMax;
	_quantite_mini = quantMini;											
	_quantite_restante = quantInitial;																	// Le biberon étant plein, la quantité restant = quantité initiale
	_quantite_donnee = 0;																				// Vu que le biberon n'a pas encore était donné, quantité_donnée = 0
	_premiere_prise = premierePrise;
	creationPlanning(_premiere_prise, intervallePrises);
	_vomi = false;																						// Vu que le biberon n'a pas encore était donné, impossible qu'il ai été vomi
}

Biberon::Biberon(int quantiMax, int quantiMini, int quantiInital,										// Constructeur d'un biberon déjà donné
				int quantiDonnee, int heureDonnee, int intervallePrises, bool vomito) {	
	_quantite_max = quantiMax;
	_quantite_mini = quantiMini;
	_quantite_restante = quantiInital - quantiDonnee;													// Comme on a déjà donné le biberon au moins une fois, quantité restante = quantité intiale - quantité donnée
	_quantite_donnee = quantiDonnee;
	_premiere_prise = heureDonnee;																		// Heure à laquelle on a donnée le biberon
	creationPlanning(heureDonnee, intervallePrises);
	_vomi = vomito;																						// On declare si le biberon a été vomi ou non
}

// ============= Destructeur =============

Biberon::~Biberon() {
	
}

// ============= Méthodes =============

void Biberon::afficherHoraire() {
	string heureTraduite = "";

}

// ============= Choses à utiliser (prise de notes pour m'y retrouver) =============

/*
* -- Usage de la librairie ctime
*	- // date / heure actuelle basée sur le système actuel
		time_t tmm = time(0);
	- double difftime (time_t time2, time_t time1);
		Cette fonction calcule la différence en secondes entre time1 et time2.
	
	-- A faire
		- afficherHoraire() qui affiche la prochaine prise de biberon
		(trouvé comment faire la différence entre les heures dans le tableau et l'heure système et prendre la première occurence de temps supérieur à l'heure système)
		- 
*/