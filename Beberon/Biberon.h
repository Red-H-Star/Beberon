#pragma once

class Biberon {
protected:
	int _quantite_max;
	int _quantite_mini;
	int _quantite_restante;
	int _quantite_donnee;
	int _premiere_prise;
	int* _heure_prise;
	bool _vomi;
public:
	Biberon();
	Biberon(int, int, int, int, int);
	Biberon(int, int, int, int, int, int, bool);
	~Biberon();
	void creationPlanning(int, int);
	int getQuantite_max();
	int getQuantite_mini();
	int getQuantite_restante();
	int getQuantite_donnee();
	int getPremierePrise();
	int* getHeure_Prise();
	bool getVomi();
	void setQuantite_restante(int);
	void setQuantite_donnee(int);
	void setPremierePrise(int);
	void afficherHoraire();
};