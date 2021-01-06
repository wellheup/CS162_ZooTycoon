
/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Runs the Zoo class game until the user elects to quit
*********************************************************************/
#include<string>
#include<iostream>
#include "menuShell.hpp"
#include "isValidInput.hpp"
#include "zoo.hpp"
#include "animal.hpp"
#include "tiger.hpp"

int main() {

	
	do {
		Zoo myZoo;
		myZoo.runGame();
	} while (choiceMenu1("Would you like to play again?", "1. Yes", "2. No")==1);

	return 0;
}
