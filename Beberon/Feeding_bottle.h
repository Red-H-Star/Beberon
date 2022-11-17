#pragma once
#include <string>;
#include <ctime>;

class Feeding_bottle {
protected:
	int _max_quantity;
	int _meal_quantity;
	int _quantity_left;
	int _first_meal;
	int _waiting_time;
	bool _vomit;
public:
	Feeding_bottle();
	Feeding_bottle(int, int, int, int);
	Feeding_bottle(int, int, int, int, bool);
	~Feeding_bottle();
	int getMax_quantity();
	int getMeal_quantity();
	int getQuantity_left();
	int getFirst_meal();
	int getWaiting_time();
	bool getVomit();
	void setMeal_Quantity(int);
	void setQuantity_left(int);
	void setFirst_meal(int);
	void setWaiting_time(int);
	//string showTime(time_t);					// Doesn't work, most probably because of the string type, needs fixing
};