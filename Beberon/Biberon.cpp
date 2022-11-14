#include <iostream>;
using namespace std;

class Biberon {
protected:
	int quantite_mini;
	int quantite_restante;
	int quantite_donnee;
	int heure_prise;
	bool vomi;
public:
	Biberon();
	Biberon(int, int, int, int, bool);
	int getQuantite_mini();
	int getQuantite_restante();
	int getQuantite_donnee();
	bool getVomi();
	void setQuantite_restante(int);
	void setQuantite_donnee(int);
};

// ============= Getters =============
int Biberon::getQuantite_mini() {
	return quantite_mini;
}
int Biberon::getQuantite_restante() {
	return quantite_restante;
}
int Biberon::getQuantite_donnee() {
	return quantite_donnee;
}
bool Biberon::getVomi() {
	return vomi;
}

// ============= Setters =============
void Biberon::setQuantite_restante(int newQuantite) {
	quantite_restante = newQuantite;
}
void Biberon::setQuantite_donnee(int newQuantite) {
	quantite_donnee = newQuantite;
}

// ============= Constructeur =============

Biberon::Biberon() {
	quantite_mini = 0;
	quantite_restante = 0;
	quantite_donnee = 0;
	heure_prise = 0;
	vomi = false;
}

