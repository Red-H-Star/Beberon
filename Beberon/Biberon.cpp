#include <iostream>;
#include "Biberon.h";
#include <sstream>;
using namespace std;

// ============= Getters =============
int Biberon::getQuantite_max() {
	return _quantite_max;
}
int Biberon::getQuantite_repas() {
	return _quantite_repas;
}
int Biberon::getQuantite_restante() {
	return _quantite_restante;
}
int Biberon::getPremierePrise() {
	return _premiere_prise;
}
int Biberon::getDelai_Prise() {
	return _delai_prise;
}
bool Biberon::getVomi() {
	return _vomi;
}

// ============= Setters =============
void Biberon::setQuantite_repas(int newQuantite) {
	_quantite_repas = newQuantite;
}
void Biberon::setQuantite_restante(int newQuantite) {
	_quantite_restante = newQuantite;
}
void Biberon::setPremierePrise(int premierePrise) {
	_premiere_prise = premierePrise;
}
void Biberon::setDelai_Prise(int intervallePrise) {
	_delai_prise = intervallePrise;
}

// ============= Constructeur =============

Biberon::Biberon() {																					// Constructeur par défaut de Biberon
	_quantite_max = 0;
	_quantite_repas = 0;
	_quantite_restante = 0;
	_premiere_prise = 0;
	_delai_prise = 0;
	_vomi = false;
}

Biberon::Biberon(int quantMax, int quantRepas, int premierePrise										// Constructeur d'un nouveau biberon plein pas encore donné.
				, int intervallePrises) {
	_quantite_max = quantMax;
	_quantite_repas = quantRepas;											
	_quantite_restante = _quantite_max;																	// Le biberon étant plein, la quantité restant = quantité max
	_premiere_prise = premierePrise;
	_delai_prise = intervallePrises;
	_vomi = false;																						// Vu que le biberon n'a pas encore était donné, impossible qu'il ai été vomi
}

Biberon::Biberon(int quantiMax, int quantiRepas, int heureDonnee,										// Constructeur d'un biberon déjà donné
				  int intervallePrises, bool vomito) {	
	_quantite_max = quantiMax;
	_quantite_repas = quantiRepas;
	_quantite_restante = quantiMax - quantiRepas;														// Comme on a déjà donné le biberon une fois, quantité restante = quantité max - quantité repas
	_premiere_prise = heureDonnee;																		// Heure à laquelle on a donnée le biberon
	_delai_prise = intervallePrises;
	_vomi = vomito;																						// On declare si le biberon a été vomi ou non
}

// ============= Destructeur =============

Biberon::~Biberon() {
	
}

// ============= Méthodes =============
string Biberon::afficherHoraire(time_t tempsSecondes) {													// Renvoie un string afin de pouvoir l'afficher dans l'application
	tm* tempsLis = localtime(&tempsSecondes);
	return "Le prochain biberon est prévu pour : " + to_string(1 + tempsLis->tm_hour) + ":" + to_string(1 + tempsLis->tm_min);
}