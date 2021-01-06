/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Implements several functions useful for input 
** validation. Each function receives parameters and returns whether 
** or not they are valid input with a bool value. 
*********************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include "isValidInput.hpp"

/*********************************************************************
** Description: isInt() takes a string parameter and returns true if 
** the string contains only an integer. 
*********************************************************************/ 
bool isInt(std::string userIn) {
	bool isValid = false;
	for (char c : userIn) {
		if (isdigit(c)) {
			isValid = true;
		}
		else if (!isdigit(c)) {
			isValid = false;
			return isValid;
		}
		else {
			isValid = false;
		}
	}
	return isValid;
}

/*********************************************************************
** Description: isIntInRange() takes in a string parameter, and a low
** and high integer parameter then returns true only if the string 
** is an integer between the low and high values.
*********************************************************************/
bool isIntInRange(std::string userIn, int low, int high) {
	bool isValid = false;
	for (char c : userIn) {
		if (isdigit(c)) {
			isValid = true;
		}
		else if (!isdigit(c)) {
			isValid = false;
			return isValid;
		}
		else {
			isValid = false;
		}
	}
	if (isValid==true) {
		if (stoi(userIn) >= low && stoi(userIn) <= high) {
			isValid = true;
		}
		else
			isValid = false;
	}
	return isValid;
}

/*********************************************************************
** Description: isDouble() takes a string parameter and returns true if
** the string contains only a numbers and only one decimal point
** within the string.
*********************************************************************/ 
bool isDouble(std::string userIn) {
	bool isValid = false, deciUsed = false;
	for (char c : userIn) {
		if (isdigit(c)) {
			isValid = true;
		}
		else if (!isdigit(c)) {
			if (deciUsed == false && c == '.') {
				deciUsed = true;
			}
			else {
				isValid = false;
				return isValid;
			}
		}
		else
			isValid = false;
	}
	return isValid;
}

/*********************************************************************
** Description: isYesNo() takes a string parameter and returns true 
** only if the string is a stand-alone Y or N character. Reference:
** http://www.cplusplus.com/reference/string/string/compare/
*********************************************************************/
bool isYesNo(std::string userIn) {
	bool isValid = false;
	if (userIn.compare("Y") == 0 || userIn.compare("y") == 0) {
		isValid = true;
	}
	else if (userIn.compare("N") == 0 || userIn.compare("n") == 0) {
		isValid = true;
	}
	return isValid;
}

/*********************************************************************
** Description: istTxtFile() takes in a string parameter and returns
** true only if the string provided will work as a valid file name
*********************************************************************/
bool isTxtFile(std::string userIn) {
	bool isValid = false;
	std::ifstream test(userIn);
	if (!test) {
		if (userIn.length() < 4) {
			isValid = false; 
		}
		else if (userIn.compare(userIn.length() - 4, userIn.length(), ".txt")==0) {
			isValid = true;
		}
		else {
			//std::cout << "something is wrong with isTxtFile()" << std::endl;
		}
	}
	else {
		isValid = true;
	}
	return isValid;
}
/*********************************************************************
** Description: isString() takes in a string parameter and returns
** true only if the string provided is a string between the low and 
** high parameters
*********************************************************************/
bool isStringWithinRange(std::string userIn, int low, int high) {
	bool isValid = false;
	std::ifstream test(userIn);
	if (userIn.length() < low || userIn.length() > high) {
		isValid = false;
	}
	else {
		isValid = true;
	}
	return isValid;
}