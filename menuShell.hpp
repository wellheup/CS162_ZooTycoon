/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Prototypes several functions useful for displaying
** menus with choice selection to users and utilizes input validation
** to make sure that the user's choices are valid selections for 
** the context of the menu.
*********************************************************************/
#ifndef MENUSHELL_HPP
#define MENUSHELL_HPP


/*********************************************************************
** Description: initMenu() takes in a string for the name of a program
** and asks the player if they'd like to run that program. Y will
** return a 1 and N will return an 2
*********************************************************************/
int initMenu(std::string programName);

/*********************************************************************
** Description: initMenuSOrQ() uses the first parameter to prompt the
** user then the second to define the first selection as opposed to
** a "Quit" option and returns a 1 or a 2
*********************************************************************/
int initMenuSOrQ(std::string startPrompt, std::string text1);

/*********************************************************************
** Description: choiceMenu1() uses the first parameter to prompt the
** user and the rest to present options to them in a numbered format, 
** the final being intended as a Quit/Exit. Returns 1-2
*********************************************************************/
int choiceMenu1(std::string startPrompt, std::string text1, std::string quitText);

/*********************************************************************
** Description: choiceMenu2() uses the first parameter to prompt the
** user and the rest to present options to them in a numbered format, 
** the final being intended as a Quit/Exit. Returns 1-3
*********************************************************************/
int choiceMenu2(std::string startPrompt, std::string text1, std::string text2, std::string quitText);

/*********************************************************************
** Description: choiceMenu3() uses the first parameter to prompt the
** user and the rest to present options to them in a numbered format, 
** the final being intended as a Quit/Exit. Returns 1-4
*********************************************************************/
int choiceMenu3(std::string startPrompt, std::string text1, std::string text2, std::string text3, std::string quitText);

/*********************************************************************
** Description: choiceMenu4() uses the first parameter to prompt the
** user and the rest to present options to them in a numbered format, 
** the final being intended as a Quit/Exit. Returns 1-5
*********************************************************************/
int choiceMenu4(std::string startPrompt, std::string text1, std::string text2, std::string text3, std::string text4, std::string quitText);

/*********************************************************************
** Description: chooseIntInRange() prompts the user with the first
** parameter then compares user input to make sure it is an int
** between the low and high values provided
*********************************************************************/
int chooseIntInRange(std::string startPrompt, int low, int high);

/*********************************************************************
** Description: chooseIntInRange() prompts the user with the first
** parameter then compares user input to make sure it is an int
** between the low and high values provided
*********************************************************************/
double chooseDoubleInRange(std::string startPrompt, int low, int high);

/*********************************************************************
** Description: chooseIntInRange() prompts the user with the first
** parameter then compares user input to make sure it is an int
** between the low and high values provided
*********************************************************************/
std::string enterStringWithinRange(std::string startPrompt, int low, int high);

//std::string chooseTextFileName();

#endif