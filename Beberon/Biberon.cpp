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
	// Getters
	int getQuantite_mini() {
		return this->quantite_mini;
	}
	int getQuantite_restante() {
		return this->quantite_restante;
	}
	int getQuantite_donnee() {
		return this->quantite_donnee;
	}
	bool getVomi() {
		return this->vomi;
	}
};
