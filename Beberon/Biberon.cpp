#include <iostream>;
#include "Biberon.h";
using namespace std;

// ============= Initialisation =============
void Biberon::fu(int delaiPrise, int heurePremierRepas) {
	int nmbrRepas = getQuantite_max() - getQuantite_mini();
	for (int i = 0; i < nmbrRepas; i++) {

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

// ============= Constructeur =============

Biberon::Biberon() {																					// Constructeur par d�faut de Biberon
	_quantite_max = 0;
	_quantite_mini = 0;
	_quantite_restante = 0;
	_quantite_donnee = 0;
	_heure_prise [0] = {};
	_vomi = false;
}

Biberon::Biberon(int quantMax, int quantMini, int quantInitial, int intervallePrise) {								// Constructeur d'un nouveau biberon plein pas encore donn�.
	_quantite_max = quantMax;
	_quantite_mini = quantMini;											
	_quantite_restante = quantInitial;																	// Le biberon �tant plein, la quantit� restant = quantit� initiale
	_quantite_donnee = 0;																				// Vu que le biberon n'a pas encore �tait donn�, quantit�_donn�e = 0
	_heure_prise, intervallePrise;
	_vomi = false;																						// Vu que le biberon n'a pas encore �tait donn�, impossible qu'il ai �t� vomi
}

Biberon::Biberon(int quantiMax, int quantiMini, int quantiInital,										// Constructeur d'un biberon d�j� donn�
				int quantiDonnee, int heureDonnee, bool vomito) {	
	_quantite_max = quantiMax;
	_quantite_mini = quantiMini;
	_quantite_restante = quantiInital - quantiDonnee;													// Comme on a d�j� donn� le biberon au moins une fois, quantit� restante = quantit� intiale - quantit� donn�e
	_quantite_donnee = quantiDonnee;
	_heure_prise, heureDonnee;																			// Heure � laquelle on a donn�e le biberon
	_vomi = vomito;																						// On declare si le biberon a �t� vomi ou non
}

// ============= Destructeur =============

Biberon::~Biberon() {
	
}