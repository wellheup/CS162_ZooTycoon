/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Implements Zoo class which will run the Zoo game and 
** use the Animal classes and subclasses to populate it
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono> //used for alternate random generator
#include <random> 
#include "menuShell.hpp" 
#include "animal.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"
#include "bonusAnimal.hpp"
#include "zoo.hpp" 

/*********************************************************************
** Description: Zoo::runGame() executes all of the methods necessary
** for running the full game ntil the user loses or chooses to stop
*********************************************************************/
void Zoo::runGame() {
	while (loseCondition == false && choiceMenu1(askToPlay, yes, no) == 1) {
		if (day == 0) {
			wantBonusAnimal();
			zooStartup();
			askToPlay = askToPlay_2;
		}
		ageAnimals();
		if (day != 0) {
			feedAnimals();
			randomEvent();
			collectIncome();
			runAnimalStore();
			loseCondition = checkLoseCondition();
		}
		day++;
	}
	std::cout << loseMessage << std::endl;
	printStats();
}
/*********************************************************************
** Description:Zoo::wantBonusAnimal() asks the user whether or not 
** they would like to use bonus animals in this session of the game, 
** defines all of the attributes of the BonusAnimal subclass,
** and resets all dynamic strings pertaining to the bonus animal to 
** update them
*********************************************************************/
void Zoo::wantBonusAnimal() {
	if (choiceMenu1(askUseBonusAnimal, yes, no) == 1) {
		useBonusAnimal = true;
		numberOfBonusAnimalTypes++;
		
		bonusAnimalName = enterStringWithinRange(askBonusAnimalName, 1, 25);
		//define string to request price
		askBonusAnimalPrice = "How much will a/an " + bonusAnimalName + " cost? ($100-25000)";
		
		priceOfBonusAnimals = chooseIntInRange(askBonusAnimalPrice, 100, 25000);
		//define the rest of strings now that price is defined too
		askBonusAnimalFoodModifier = "How much of base food cost does " + bonusAnimalName + " food cost? (1%-2000%)";
		askBonusAnimalPayoffRate = "How much of their initial cost does a/an " + bonusAnimalName + " make per day? (1%-25%)";
		askBonusAnimalLitterSize = "How many babies does a/an " + bonusAnimalName + " have when giving birth? (1-100)";
		askStartingBonusAnimals = "How many " + bonusAnimalName + "(s) would you like to buy? (Enter 1 or 2)";
		sickBonusAnimal = "Unfortunately, a/an " + bonusAnimalName + " has died due to illness.";
		babyBonusAnimal = "The " + bonusAnimalName + "(s) had a litter, hooray!";
		buyBonusAnimal = "4. " + bonusAnimalName + " - $" + std::to_string(priceOfBonusAnimals) + " each";
		howManyBonusAnimals = "How many " + bonusAnimalName + "(s) would you like to buy? (0-10)";
		
		bonusAnimalPayoffModifier = chooseIntInRange(askBonusAnimalPayoffRate, 1, 25)*.01;
		bonusAnimalFoodModifier = chooseIntInRange(askBonusAnimalFoodModifier, 1, 2000)*.01;
		bonusAnimalBabyNumber = chooseIntInRange(askBonusAnimalLitterSize, 1, 100);
	}
	else {
		std::cout << noBonusAnimal << std::endl;
	}
}
/*********************************************************************
** Description: Zoo::zooStartup() Gives the user initial purchasing 
** options for their zoo to have starting animals
*********************************************************************/
void Zoo::zooStartup(){
	std::cout << intro_1 << intro_2<<  std::endl;
	buyAnimals(TIGER, chooseIntInRange(askStartingTigers, 1, 2));
	buyAnimals(PENGUIN, chooseIntInRange(askStartingPenguins, 1, 2));
	buyAnimals(TURTLE, chooseIntInRange(askStartingTurtles, 1, 2));
	if (useBonusAnimal == true) {
		buyAnimals(BONUSANIMAL, chooseIntInRange(askStartingBonusAnimals, 1, 2));
	}
	printStats();
}
/*********************************************************************
** Description: Zoo::ageAnimals() Increments animal ages by 1 day
*********************************************************************/
void Zoo::ageAnimals() {
	for (int i = 0; i < numberOfTigers; i++) {
		tigerArray[i]->incrementAge();
	}
	for (int i = 0; i < numberOfPenguins; i++) {
		penguinArray[i]->incrementAge();
	}
	for (int i = 0; i < numberOfTurtles; i++) {
		turtleArray[i]->incrementAge();
	}
	for (int i = 0; i < numberOfBonusAnimals; i++) {
		bonusAnimalArray[i]->incrementAge();
	}
}
/*********************************************************************
** Description: Zoo::printStats() Prints out the user's current day, 
** funds, and number of animals
*********************************************************************/
void Zoo::printStats() {
  std::cout << std::string(50, '*') << std::endl;
	std::cout << "\nDay: " << day << std::endl;
	std::cout << bankReport << std::fixed << std::setprecision(2) << std::setfill('0')<<bank << std::endl;
	std::cout << "Tigers: " << numberOfTigers << std::endl;
	std::cout << "Penguins: " << numberOfPenguins << std::endl;
	std::cout << "Turtles: " << numberOfTurtles << std::endl;
	if (useBonusAnimal == true) {
		std::cout << bonusAnimalName << ": " << numberOfBonusAnimals << "\n" << std::endl;
	}
}
/*********************************************************************
** Description: Zoo::feedAnimals() Offers 3 different feeding options
** for the zoo and feeds the animals for the day, deducting costs
** as appropriate
*********************************************************************/
void Zoo::feedAnimals() {
	int foodType = choiceMenu2(promptFeedAnimals, askCheapFeed, askNormalFeed, askPremiumFeed);

	if (foodType == 1) {
		bank -= baseFoodCost * cheapFoodPriceModifier * tigerFoodModifier * numberOfTigers;
		bank -= baseFoodCost * cheapFoodPriceModifier * penguinFoodModifier * numberOfPenguins;
		bank -= baseFoodCost * cheapFoodPriceModifier * turtleFoodModifier * numberOfTurtles;
		bank -= baseFoodCost * cheapFoodPriceModifier * bonusAnimalFoodModifier * numberOfBonusAnimals;
		currentHealthModifier = cheapFoodHealthModifier;
	}
	else if (foodType == 2) {
		bank -= baseFoodCost * normalFoodHealthModifier * tigerFoodModifier * numberOfTigers;
		bank -= baseFoodCost * normalFoodHealthModifier * penguinFoodModifier * numberOfPenguins;
		bank -= baseFoodCost * normalFoodHealthModifier * turtleFoodModifier * numberOfTurtles;
		bank -= baseFoodCost * normalFoodHealthModifier * bonusAnimalFoodModifier * numberOfBonusAnimals;
		currentHealthModifier = normalFoodHealthModifier;
	}
	else if (foodType == 3) {
		bank -= baseFoodCost * premiumFoodPriceModifier * tigerFoodModifier * numberOfTigers;
		bank -= baseFoodCost * premiumFoodPriceModifier * penguinFoodModifier * numberOfPenguins;
		bank -= baseFoodCost * premiumFoodPriceModifier * turtleFoodModifier * numberOfTurtles;
		bank -= baseFoodCost * premiumFoodPriceModifier * bonusAnimalFoodModifier * numberOfBonusAnimals;
		currentHealthModifier = premiumFoodHealthModifier;
	}
}
/*********************************************************************
** Description: Zoo::randomEvent() Chooses a single random event to 
** occur during the day at the zoo and executes that event 
*********************************************************************/
void Zoo::randomEvent() {
	double numberOfEventsMinusSickness = 3, sicknessChance = 1 * currentHealthModifier,
		 roll = randomDouble(1, (numberOfEventsMinusSickness + sicknessChance));

	if (roll > 0 && roll <= 1) {
		businessBoom();
	}
	else if (roll > 1 && roll<= 2) {
		babyAnimal();
	}
	else if (roll > 2 && roll <= 3) {
		nothingHappens();
	}
	else if (roll > 3) {
		sickAnimal();
	}
	else {
		std::cout << "something wrong with randomEvent()" << std::endl;
	}
}
/*********************************************************************
** Description: Zoo::sickAnimal() Chooses a random animal to die of 
** sickness. If there are no animals to choose from, reports that all
** animals survived
*********************************************************************/
void Zoo::sickAnimal() {
	bool sickChosen = false;
	int sickAttempts = 0;
	while (sickChosen == false) {
		int	roll = randomInt(1, (baseNumberOfAnimalTypes + numberOfBonusAnimalTypes));
		
		if (roll == TIGER) {
			if (numberOfTigers > 0) {
				removeTigers(1);
				sickChosen = true;
				std::cout << sickTiger << std::endl;
			}
		}
		else if (roll == PENGUIN) {
			if (numberOfPenguins > 0) {
				removePenguins(1);
				sickChosen = true;
				std::cout << sickPenguin << std::endl;
			}
		}
		else if (roll == TURTLE) {
			if (numberOfTurtles > 0) {
				removeTurtles(1);
				sickChosen = true;
				std::cout << sickTurtle << std::endl;
			}
		}
		else if (roll == BONUSANIMAL) {
			if (numberOfBonusAnimals > 0) {
				removeBonusAnimals(1);
				sickChosen = true;
				std::cout << sickBonusAnimal << std::endl;
			}
		}
		if(sickAttempts>=10){
			std::cout << noSickAnimals << std::endl;
			sickChosen = true;
		}
		sickAttempts++;
	}
}
/*********************************************************************
** Description: Zoo::businessBoom() Saves an amount of extra money
** made from a business boom based on the number of tigers at the
** zoo, reports this value, and sets a boolean variable to flag that
** this value should be added to the profit at the end of the day
*********************************************************************/
void Zoo::businessBoom() {
	std::cout << businessBoomText_1 << std::endl;
	businessBoomProfit = numberOfTigers * randomInt(250, 500);
	businessBoomText_2 = "As a result of a business boom, you made an extra $" 
			+ std::to_string(businessBoomProfit) + " today.";
	addBusinessBoom = true;
}
/*********************************************************************
** Description: Zoo::babyAnimal() chooses a random animal from the zoo
** to have a baby and adds a new animal of that type to the zoo with 
** an age of 0
*********************************************************************/
void Zoo::babyAnimal() {
	bool motherChosen = false;
	int birthAttempts = 0;
	while (motherChosen == false) {
		int	roll = randomInt(1, (baseNumberOfAnimalTypes + numberOfBonusAnimalTypes));

		if (roll == TIGER) {
			if (numberOfTigers > 0) {
				for (int i = 0; i < numberOfTigers; i++) {
					if (tigerArray[i]->getAge() >= 3 && motherChosen == false) {
						addTigers(tigerBabyNumber, true);
						motherChosen = true;
						std::cout << babyTiger << std::endl;
					}
				}

			}
		}
		else if (roll == PENGUIN) {
			if (numberOfPenguins > 0) {
				for (int i = 0; i < numberOfTigers; i++) {
					if (penguinArray[i]->getAge() >= 3 && motherChosen == false) {
						addPenguins(penguinBabyNumber, true);
						motherChosen = true;
						std::cout << babyPenguin << std::endl;
					}
				}
			}
		}
		else if (roll == TURTLE) {
			if (numberOfTurtles > 0) {
				for (int i = 0; i < numberOfTurtles; i++) {
					if (turtleArray[i]->getAge() >= 3 && motherChosen == false) {
						addTurtles(turtleBabyNumber, true);
						motherChosen = true;
						std::cout << babyTurtle << std::endl;
					}
				}
			}
		}
		else if (roll == BONUSANIMAL) {
			if (numberOfBonusAnimals > 0) {
				for (int i = 0; i < numberOfBonusAnimals; i++) {
					if (bonusAnimalArray[i]->getAge() >= 3 && motherChosen == false) {
						addBonusAnimals(bonusAnimalBabyNumber, true);
						motherChosen = true;
						std::cout << babyBonusAnimal << std::endl;
					}
				}
			}
		}
		if (birthAttempts >= 10) {
			std::cout << noBornAnimals << std::endl;
			motherChosen = true;
		}
		birthAttempts++;
	}
}
/*********************************************************************
** Description: Zoo::nothingHappens() Reports that nothing happened
*********************************************************************/
void Zoo::nothingHappens() {
	std::cout << nothingHappensText << std::endl;
}
/*********************************************************************
** Description: Zoo::collectIncome() Totals the profits for the day 
** and gives the user a status update on the zoo
*********************************************************************/
void Zoo::collectIncome() {
	int tigerProfit = numberOfTigers * priceOfTigers* tigerPayoffModifier,
		penguinProfit = numberOfPenguins * priceOfPenguins*penguinPayoffModifier,
		turtleProfit = numberOfTurtles * priceOfTurtles*turtlePayoffModifier,
		bonusAnimalProfit = numberOfBonusAnimals * priceOfBonusAnimals*bonusAnimalPayoffModifier;
		dailyProfit = tigerProfit + penguinProfit + turtleProfit + bonusAnimalProfit;
		std::cout << "Today Tigers made: $" << tigerProfit
			<< "\nToday Penguins made: $" << penguinProfit
			<< "\nToday Turtles made: $" << turtleProfit << std::endl;
		if (useBonusAnimal == true) {
			std::cout << "\nToday " + bonusAnimalName + " made: $" << bonusAnimalProfit << std::endl;
		}
	if (addBusinessBoom == true) {
		std::cout << businessBoomText_2 << std::endl;
		dailyProfit += businessBoomProfit;
		addBusinessBoom = false;
		std::cout << "A boom in business added an extra: $" << businessBoomProfit << std::endl;
	}
	std::cout << "The total profit today is: $" << dailyProfit << "\n" << std::endl;
	bank += dailyProfit;
	printStats();
}
/*********************************************************************
** Description: Zoo::runAnimalStore() Asks the user if they'd like to
** buy more animals, facilitates selection and then adds animals to 
** the zoo using the buyAnimals() method if they're purchased
*********************************************************************/
void Zoo::runAnimalStore(){
	//update animal buy strings
	buyTigers = "1. Tigers - $" + std::to_string(priceOfTigers) + " each";
	buyPenguins = "2. Penguins - $" + std::to_string(priceOfPenguins) + " each";
	buyTurtles = "3. Turtles - $" + std::to_string(priceOfTurtles) + " each";
	buyBonusAnimal = "4. " + bonusAnimalName + " - $" + std::to_string(priceOfBonusAnimals) + " each";
	while (choiceMenu1(promptBuyAnimals, yes, no) == 1) {
		int animalToBuy = -1;
		printStats();
		std::cout << "Reminder: if you purchase more than you can afford you will go into debt."
			<< "\nNegative funds at the end of the day will result in losing the game." << std::endl;
		if (useBonusAnimal == true) {
			animalToBuy = choiceMenu4(promptBuyAnimals, buyTigers, buyPenguins, buyTurtles, buyBonusAnimal, "5. Nevermind");
		}
		else {
			animalToBuy = choiceMenu3(promptBuyAnimals, buyTigers, buyPenguins, buyTurtles, "4. Nevermind");
		}

		if (animalToBuy == TIGER) {
			buyAnimals(TIGER, chooseIntInRange(howManyTigers, 0, 10));
		}
		else if (animalToBuy == PENGUIN) {
			buyAnimals(PENGUIN, chooseIntInRange(howManyPenguins, 0, 10));
		}
		else if (animalToBuy == TURTLE) {
			buyAnimals(TURTLE, chooseIntInRange(howManyTurtles, 0, 10));
		}
		else if (animalToBuy == BONUSANIMAL) {
			buyAnimals(BONUSANIMAL, chooseIntInRange(howManyBonusAnimals, 0, 10));
		}
		else if (animalToBuy == 5) {
			//do nothing, move on
		}
		else {
			std::cout << "animalToBuy is not being correctly set";
		}
	} 
	printStats();
}
/*********************************************************************
** Description: Zoo::buyAnimals() Receives a type of animal and how 
** many of that type to purchase and subtracts the appropriate amount
** of money from the user's bank. Then uses the add method for the
** appropriate animal to add it to the zoo
*********************************************************************/
void Zoo::buyAnimals(int animalType, int howMany) {

	if (animalType == TIGER) {
		bank -= (priceOfTigers * howMany);
		addTigers(howMany, false);
	}
	else if (animalType == PENGUIN) {
		bank -= (priceOfPenguins*howMany);
		addPenguins(howMany, false);
	}
	else if (animalType == TURTLE) {
		bank -= (priceOfTurtles*howMany);
		addTurtles(howMany, false);
	}
	else if (animalType == BONUSANIMAL) {
		bank -= (priceOfBonusAnimals*howMany);
		addBonusAnimals(howMany, false);
	}
	std::cout << bankReport << bank << std::endl;//print remaining cash
}
/*********************************************************************
** Description: Zoo::checkLoseCondition() checks to see if the user's 
** zoo is currently meeting any of the lose conditions for the game
*********************************************************************/
bool Zoo::checkLoseCondition(){
	if (bank <= 0) {
		std::cout << loseToDebt << std::endl;
		return true;
	}
	if (numberOfTigers <= 0 && numberOfPenguins <= 0 && numberOfTurtles <= 0 && numberOfBonusAnimals <= 0) {
		std::cout << loseToDeath << std::endl;
		return true;
	}
	return false;
}
/*********************************************************************
** Description: remove---() these methods remove animals from the zoo
*********************************************************************/
void Zoo::removeTigers(int numberToRemove) {
	numberOfTigers--;
}

void Zoo::removePenguins(int numberToRemove){
	numberOfPenguins--;
}

void Zoo::removeTurtles(int numberToRemove){
	numberOfTurtles--;
}

void Zoo::removeBonusAnimals(int numberToRemove){
	numberOfBonusAnimals--;
}
/*********************************************************************
** Description: add----() these methods take a parameter of how many 
** animals to add to their appropriate arrays and sets their ages
** depending on the second parameter
*********************************************************************/
void Zoo::addTigers(int numberToAdd, bool addBabies){
	for (int i = 0; i < numberToAdd; i++) {
		if (numberOfTigers == maxTigers) {
			Tiger **tempArray = new Tiger*[maxTigers*2];
			for (int i = 0; i < maxTigers; i++) {
				tempArray[i] = tigerArray[i];
			}
			delete[] tigerArray;
			tigerArray = tempArray;
			maxTigers *= 2;
			delete tigerArray[numberOfTigers];
			tigerArray[numberOfTigers] = nullptr;
		}
		
		tigerArray[numberOfTigers] = new Tiger(3, tigerBabyNumber, priceOfTigers, tigerFoodModifier, tigerPayoffModifier);
		if (addBabies == true || day==0) {
			tigerArray[numberOfTigers]->setAge(0);
		}
		numberOfTigers++;
	}
}

void Zoo::addPenguins(int numberToAdd, bool addBabies){
	for (int i = 0; i < numberToAdd; i++) {
		if (numberOfPenguins == maxPenguins) {
			Penguin **tempArray = new Penguin*[maxTurtles * 2];
			for (int i = 0; i < maxPenguins; i++) {
				tempArray[i] = penguinArray[i];
			}
			delete[] penguinArray;
			penguinArray = tempArray;
			maxPenguins *= 2;
			delete penguinArray[numberOfPenguins];
			penguinArray[numberOfPenguins] = nullptr;
		}
		
		penguinArray[numberOfPenguins] = new Penguin(3, penguinBabyNumber, priceOfPenguins, penguinFoodModifier, penguinPayoffModifier);
		if (addBabies == true||day==0) {
			penguinArray[numberOfPenguins]->setAge(0);
		}
		numberOfPenguins++;
	}
}

void Zoo::addTurtles(int numberToAdd, bool addBabies){
	for (int i = 0; i < numberToAdd; i++) {
		if (numberOfTurtles == maxTurtles) {
			Turtle **tempArray = new Turtle*[maxTurtles * 2];
			for (int i = 0; i < maxTurtles; i++) {
				tempArray[i] = turtleArray[i];
			}
			delete[] turtleArray;
			turtleArray = tempArray;
			maxTurtles *= 2;
			delete turtleArray[numberOfTurtles];
			turtleArray[numberOfTurtles] = nullptr;
		}
		
		turtleArray[numberOfTurtles] = new Turtle(3, turtleBabyNumber, priceOfTurtles, turtleFoodModifier, turtlePayoffModifier);
		if (addBabies == true||day==0) {
			turtleArray[numberOfTurtles]->setAge(0);
		}
		numberOfTurtles++;
	}
}

void Zoo::addBonusAnimals(int numberToAdd, bool addBabies){
	for (int i = 0; i < numberToAdd; i++) {
		if (numberOfBonusAnimals == maxBonusAnimals) {
			BonusAnimal **tempArray = new BonusAnimal*[maxBonusAnimals * 2];
			for (int i = 0; i < maxBonusAnimals; i++) {
				tempArray[i] = bonusAnimalArray[i];
			}
			delete[] bonusAnimalArray;
			bonusAnimalArray = tempArray;
			maxBonusAnimals *= 2;
			delete bonusAnimalArray[numberOfBonusAnimals];
			bonusAnimalArray[numberOfBonusAnimals] = nullptr;
		}
		
		bonusAnimalArray[numberOfBonusAnimals] = new BonusAnimal(3, bonusAnimalBabyNumber, priceOfBonusAnimals, bonusAnimalFoodModifier, bonusAnimalPayoffModifier);
		if (addBabies == true||day==0) {
			bonusAnimalArray[numberOfBonusAnimals]->setAge(0);
		}
		numberOfBonusAnimals++;
	}
}
/*********************************************************************
** Description: Zoo::randomInt() returns a random integer within the 
** range parameters provided
*********************************************************************/
int Zoo::randomInt(int lowerLimit, int upperLimit){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(lowerLimit, upperLimit);
	int roll = distribution(generator);
	return roll;
}
/*********************************************************************
** Description: Zoo::randomDouble() returns a random double within the 
** range parameters provided
*********************************************************************/
double Zoo::randomDouble(double lowerLimit, double upperLimit){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distribution(lowerLimit, upperLimit);
	double roll = distribution(generator);
	return roll;
}

void Zoo::initText(){
	//generic yes/no
	yes = "1. Yes", no = "2. No";

	//text for bank reports
	bankReport = "Remaining funds: $";

	//animal names
	tigerString = "Tigers", penguinString = "Penguins", turtleString = "Turtles", bonusAnimalName = "Unnamed";

	//bonus animal addon
	askUseBonusAnimal = "Would like to use the extra credit bonus animal for this play through?",
	askBonusAnimalName = "What will the bonus animal be named?",
	askBonusAnimalPrice = "How much will a " + bonusAnimalName + " cost? ($100-25000)",
	askBonusAnimalFoodModifier = "What is the food cost multiplier for " + bonusAnimalName + " food? (0.1-15)",
	askBonusAnimalPayoffRate = "How much of their initial cost does a/an " + bonusAnimalName + " make per day? (1%-25%)",
	askBonusAnimalLitterSize = "How many babies does a " + bonusAnimalName + " have when giving birth? (1-100)",
	noBonusAnimal = "The bonus animal will not be used in this playthrough.";

	//introductory strings
	askToPlay_1 = "Would you like to play the Zoo Tycoon game?";
	askToPlay_2 = "Would you like to CONTINUE the Zoo Tycoon game for another day?";
	askToPlay = askToPlay_1;
	intro_1 = "\nGreetings and welcome to Phillip Wellheuser's Project 2, Zoo Tycoon.\n";
	intro_2 = "To start your new zoo, you have $100,000 to buy animals for your day 1 attractions.\nIf at any point you end the day with no animals at your zoo, it will end the game.\n";
	askStartingTigers = "How many Tigers would you like to buy? (Enter 1 or 2)";
	askStartingPenguins = "How many Penguins would you like to buy? (Enter 1 or 2)";
	askStartingTurtles = "How many Turtles would you like to buy? (Enter 1 or 2)";
	askStartingBonusAnimals = "How many " + bonusAnimalName + "(s) would you like to buy? (Enter 1 or 2)";

	//animal buy strings
	promptBuyAnimals = "Would you like to buy animals?";
	howManyTigers = "How many Tigers would you like to buy? (0-10)";
	howManyPenguins = "How many Penguins would you like to buy? (0-10)";
	howManyTurtles = "How many Turtles would you like to buy? (0-10)";
	howManyBonusAnimals = "How many " + bonusAnimalName + "(s) would you like to buy? (0-10)";

	//animal feed strings
	promptFeedAnimals = "What type of feed would you like to give the animals today? ";
	askCheapFeed = "1. Cheap feed - 0.5 times the normal price but 2 times the health risk";
	askNormalFeed = "2. Normal feed - standard price ($10), standard health risk";
	askPremiumFeed = "3. Premium feed - 2 times the normal price but 0.5 times the health risk";

	//random event strings
	sickTiger = "Unfortunately, one of your Tigers has died due to illness.";
	sickPenguin = "Unfortunately, one of your Penguins has died due to illness.";
	sickTurtle = "Unfortunately, one of your Turtles has died due to illness.";
	sickBonusAnimal = "Unfortunately, a/an " + bonusAnimalName + " has died due to illness.";
	noSickAnimals = "Despite rampant disease at the zoo, all of your animals survived!";
	nothingHappensText = "Today was just another normal day at the zoo, nothing really happened.";
	businessBoomText_1 = "Business Boomed today, the extra profit will be added to the totals at the end of the day";
	businessBoomText_2 = "Business boomed today!";
	noBornAnimals = "The zoo keepers thought one of your animals was pregnant, but they were wrong...";
	babyTiger = "A Tigers had a baby, hooray!";
	babyPenguin = "The Penguins had 5 babies, hooray!";
	babyTurtle = "The Turtles had 10 babies, hooray!";
	babyBonusAnimal = "The " + bonusAnimalName + "(s) had a litter, hooray!";

	//lose message
	loseMessage = "It seems your zoo has failed in the end. Your days as a zoo entrepreneur are over.";
	loseToDebt = "You're all out of money. Can't run a zoo without money...";
	loseToDeath = "All of your animals died... maybe invest in better feed next time...";
}