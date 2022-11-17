#include <iostream>;
#include "Feeding_bottle.h";
#include <sstream>;
#include <string>;
#include <ctime>;
using namespace std;

// ============= Getters =============
int Feeding_bottle::getMax_quantity() {
	return _max_quantity;
}
int Feeding_bottle::getMeal_quantity() {
	return _meal_quantity;
}
int Feeding_bottle::getQuantity_left() {
	return _quantity_left;
}
int Feeding_bottle::getFirst_meal() {
	return _first_meal;
}
int Feeding_bottle::getWaiting_time() {
	return _waiting_time;
}
bool Feeding_bottle::getVomit() {
	return _vomit;
}

// ============= Setters =============
void Feeding_bottle::setMeal_Quantity(int newQuantity) {
	_meal_quantity = newQuantity;
}
void Feeding_bottle::setQuantity_left(int newQuantity) {
	_quantity_left = newQuantity;
}
void Feeding_bottle::setFirst_meal(int firstMeal) {
	_first_meal = firstMeal;
}
void Feeding_bottle::setWaiting_time(int intervalMeal) {
	_waiting_time = intervalMeal;
}

// ============= Constructors =============

Feeding_bottle::Feeding_bottle() {																// Default constrructor for Feeding_bottle
	_max_quantity = 0;
	_meal_quantity = 0;
	_quantity_left = 0;
	_first_meal = 0;
	_waiting_time = 0;
	_vomit = false;
}

Feeding_bottle::Feeding_bottle(int maxQuant, int mealQuant, int firstMeal						// Constructor for a Feeding_bottle not given.
				, int intervalMeal) {
	_max_quantity = maxQuant;
	_meal_quantity = mealQuant;											
	_quantity_left = _max_quantity;																// As the Feeding_bottle is full, quantity_left = max_quantity 
	_first_meal = firstMeal;
	_waiting_time = intervalMeal;
	_vomit = false;																				// Because the Feeding_bottle has yet to be given, it is impossible for it to be vomitted
}

Feeding_bottle::Feeding_bottle(int maxQuant, int mealQuant, int mealTime,						// Constructor for a Feeding_bottle that has been given
				  int intervalMeal, bool barf) {	
	_max_quantity = maxQuant;
	_meal_quantity = mealQuant;
	_quantity_left = maxQuant - mealQuant;														// Since Feeding_bottle has already been given once, quantity_left = max_quantity - meal_quantity
	_first_meal = mealTime;																		// Time at which the Feeding_bottle has been given
	_waiting_time = intervalMeal;
	_vomit = barf;																				// Declaration of if the Feeding_bottle has been barf or not
}

/*
// ============= Methods =============
string Feeding_bottle::showTime(time_t timeSeconds) {											// Returns a string in order to be able to display it in the application
	tm* viewTime = localtime(&timeSeconds);
	return "The next feeding time is planned for : " + to_string(1 + viewTime->tm_hour) + ":" + to_string(1 + viewTime->tm_min);
}*/

// ============= Destructor =============

Feeding_bottle::~Feeding_bottle() {

}