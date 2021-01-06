/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 4/28/19
** Description: Specifies Zoo class which will run the Zoo game and 
** use the Animal classes and subclasses to populate it
*********************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
//www.learncpp.com/cpp-tutorial/forward-declarations/
class Tiger;
class Penguin;
class Turtle;
class BonusAnimal;
class Animal; 

class Zoo{
private: 
	int day = 0, baseNumberOfAnimalTypes = 3, numberOfBonusAnimalTypes = 0,
		maxTigers = 10, maxPenguins = 10, maxTurtles = 10, maxBonusAnimals = 10,
		numberOfTigers = 0, numberOfPenguins = 0, numberOfTurtles = 0, numberOfBonusAnimals = 0,
		tigerBabyNumber = 1, penguinBabyNumber = 5, turtleBabyNumber = 10, bonusAnimalBabyNumber = 0,
		priceOfTigers = 10000, priceOfPenguins = 1000, priceOfTurtles = 100, priceOfBonusAnimals = 9999;

	double bank = 100000, currentHealthModifier = 1, dailyProfit = 0, businessBoomProfit = 0,
		cheapFoodPriceModifier = 0.5, cheapFoodHealthModifier = 2,
		normalFoodPriceModifier = 1, normalFoodHealthModifier = 1,
		premiumFoodPriceModifier = 2, premiumFoodHealthModifier = 0.5,
		baseFoodCost = 10, tigerFoodModifier = 5, penguinFoodModifier = 1, turtleFoodModifier = .5,
		bonusAnimalFoodModifier,
		tigerPayoffModifier = .2, penguinPayoffModifier = .1, turtlePayoffModifier = .05,
		bonusAnimalPayoffModifier;

	//array pointers for each animal type
	Tiger **tigerArray;
	Penguin **penguinArray;
	Turtle **turtleArray;
	BonusAnimal **bonusAnimalArray;
	bool useBonusAnimal = false, addBusinessBoom = false, loseCondition = false;

	//generic yes/no
	std::string yes, no;

	//text for bank reports
	std::string bankReport;

	//bonus animal addon
	std::string askUseBonusAnimal,
		askBonusAnimalName,
		askBonusAnimalPrice,
		askBonusAnimalFoodModifier,
		askBonusAnimalPayoffRate,
		askBonusAnimalLitterSize,
		noBonusAnimal;

	//animal names
	std::string tigerString, penguinString, turtleString, bonusAnimalName;
	enum WhichAnimal { TIGER = 1, PENGUIN, TURTLE, BONUSANIMAL };

	//introductory strings
	std::string askToPlay_1,
		askToPlay_2,
		askToPlay = askToPlay_1,
		intro_1,
		intro_2,
		askStartingTigers,
		askStartingPenguins,
		askStartingTurtles,
		askStartingBonusAnimals;

	//animal buy strings
	std::string promptBuyAnimals,
		buyTigers, buyPenguins, buyTurtles, buyBonusAnimal,
		howManyTigers,
		howManyPenguins,
		howManyTurtles,
		howManyBonusAnimals;

	//animal feed strings
	std::string promptFeedAnimals,
		askCheapFeed,
		askNormalFeed,
		askPremiumFeed;

	//random event strings
	std::string sickTiger,
		sickPenguin,
		sickTurtle,
		sickBonusAnimal,
		noSickAnimals,
		nothingHappensText,
		businessBoomText_1,
		businessBoomText_2,
		noBornAnimals,
		babyTiger,
		babyPenguin,
		babyTurtle,
		babyBonusAnimal;

	//lose message
	std::string loseMessage,
		loseToDebt,
		loseToDeath;

	void wantBonusAnimal();
	void zooStartup();
	void ageAnimals();
	void printStats();
	void feedAnimals();
	void randomEvent();
	void sickAnimal();
	void businessBoom();
	void babyAnimal();
	void nothingHappens();
	void collectIncome();
	void runAnimalStore();
	void buyAnimals(int animalType, int howMany);
	bool checkLoseCondition();
	void removeTigers(int numberToRemove);
	void removePenguins(int numberToRemove);
	void removeTurtles(int numberToRemove);
	void removeBonusAnimals(int numberToRemove);
	void addTigers(int numberToAdd, bool addBabies);
	void addPenguins(int numberToAdd, bool addBabies);
	void addTurtles(int numberToAdd, bool addBabies);
	void addBonusAnimals(int numberToAdd, bool addBabies);
	int randomInt(int lowerLimit, int upperLimit);
	double randomDouble(double lowerLimit, double upperLimit);
	void initText();

public:
	
	Zoo() {
		initText();
		tigerArray = new Tiger*[maxTigers];
		penguinArray = new Penguin*[maxPenguins];
		turtleArray = new Turtle*[maxTurtles];
		bonusAnimalArray = new BonusAnimal*[maxBonusAnimals];
	}

	~Zoo() {
		/*for (int i = 0; i < maxTigers; i++) {
			delete tigerArray[i];
			tigerArray[i] = nullptr;
		}*/
		delete tigerArray;
		tigerArray = nullptr;

		/*for (int i = 0; i < maxPenguins; i++) {
			delete penguinArray[i];
			penguinArray[i] = nullptr;
		}*/
		delete[] penguinArray;
		penguinArray = nullptr;

		/*for (int i = 0; i < maxTurtles; i++) {
			delete turtleArray[i];
			turtleArray[i] = nullptr;
		}*/
		delete[] turtleArray;
		turtleArray = nullptr;

		/*for (int i = 0; i < maxBonusAnimals; i++) {
			delete bonusAnimalArray[i];
			bonusAnimalArray[i] = nullptr;
		}*/
		delete[] bonusAnimalArray;
		bonusAnimalArray = nullptr;
	}

	void runGame();
	
};



#endif