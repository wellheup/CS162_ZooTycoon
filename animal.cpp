/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Implements Animal class 
*********************************************************************/
#include <iostream>
#include <string>
#include "menuShell.hpp" 
#include "animal.hpp"

void Animal::incrementAge(){
	this->age += 1;
}

double Animal::getAge(){
	return this->age;
}

void Animal::setAge(double age){
	this->age = age;
}

double Animal::getbuyCost(){
	return this->buyCost;
}

void Animal::setbuyCost(double cost){
	this->buyCost = cost;
}

double Animal::getNumberOfBabies(){
	return this->numberOfBabies;
}

void Animal::setNumberOfBabies(double numBabies){
	this->numberOfBabies = numBabies;
}

double Animal::getFoodModifier(){
	return this->foodModifier;
}

void Animal::setFoodModifier(double foodModifier){
	this->foodModifier = foodModifier;
}

double Animal::getPayoff(){
	return this->payOff;
}

void Animal::setPayoff(double payOff){
	this->payOff = payOff;
}
