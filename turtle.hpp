/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies Turtle subclass 
*********************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP

class Turtle :public Animal {
private: 
	 
public:
	
	Turtle(int age, int numberOfBabies, double buyCost, double baseFoodCost, double payOff)
		: Animal(age, numberOfBabies, buyCost, baseFoodCost, payOff) {}
		
	~Turtle() {}
	/*********************************************************************
	** Description: 
	*********************************************************************/


};



#endif