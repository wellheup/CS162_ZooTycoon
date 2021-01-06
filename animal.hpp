/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies Animal class 
*********************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
private:

public: 
	int age = 1, numberOfBabies = 1;
	double buyCost = 5, foodModifier=1, payOff=.1; 
	
	Animal(int age, int numberOfBabies, double buyCost, double foodModifier, double payOff) {
		this->age = age;
		this->numberOfBabies = numberOfBabies;
		this->buyCost = buyCost;
		this->foodModifier = foodModifier;
		this->payOff = payOff;
	}
	/*********************************************************************
	** Description: 
	*********************************************************************/
	void incrementAge();
	double getAge();
	void setAge(double age);
	double getbuyCost();
	void setbuyCost(double cost);
	double getNumberOfBabies();
	void setNumberOfBabies(double numBabies);
	double getFoodModifier();
	void setFoodModifier(double foodCost);
	double getPayoff();
	void setPayoff(double payOff);
};
#endif