/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies BonusAnimal subclass 
*********************************************************************/
#ifndef BONUSANIMAL_HPP
#define BONUSANIMAL_HPP

class BonusAnimal : public Animal {	
private: 
	 
public:
	BonusAnimal(int age, int numberOfBabies, double buyCost, double baseFoodCost, double payOff) 
		: Animal(age, numberOfBabies, buyCost, baseFoodCost, payOff){}

	~BonusAnimal() {}


};



#endif