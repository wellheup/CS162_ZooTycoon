/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies Penguin subclass 
*********************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP

class Penguin :public Animal {
private: 
	
public:
	
	Penguin(int age, int numberOfBabies, double buyCost, double baseFoodCost, double payOff)
		: Animal(age, numberOfBabies, buyCost, baseFoodCost, payOff) {}
	
	~Penguin() {}
	/*********************************************************************
	** Description: 
	*********************************************************************/


};



#endif