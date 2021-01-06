/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies Tiger subclass 
*********************************************************************/
#ifndef TIGER_HPP
#define TIGER_HPP

class Tiger : public Animal {	
private: 
	 
public:
	Tiger(int age, int numberOfBabies, double buyCost, double baseFoodCost, double payOff)
		: Animal(age, numberOfBabies, buyCost, baseFoodCost, payOff) {}

	~Tiger() {}


};



#endif