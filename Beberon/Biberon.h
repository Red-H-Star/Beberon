#pragma once
#include <string>;
#include <ctime>;

class Biberon {
protected:
	int _quantite_max;
	int _quantite_repas;
	int _quantite_restante;
	int _premiere_prise;
	int _delai_prise;
	bool _vomi;
public:
	Biberon();
	Biberon(int, int, int, int);
	Biberon(int, int, int, int, bool);
	~Biberon();
	int getQuantite_max();
	int getQuantite_repas();
	int getQuantite_restante();
	int getPremierePrise();
	int getDelai_Prise();
	bool getVomi();
	void setQuantite_repas(int);
	void setQuantite_restante(int);
	void setPremierePrise(int);
	void setDelai_Prise(int);
	string afficherHoraire(time_t);
};