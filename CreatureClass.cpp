#include "CreatureClass.h"
#include "RaceClass.h"
#include "ProfessionClass.h"

CreatureClass::CreatureClass()
{
	//INIT
	this->strength = 0;
	this->dexterity = 0;
	this->health = 0;
	this->maxHealth = 0;
	this->damage = 0;
	this->minDamage = 0;
	this->maxDamage = 0;
	race = nullptr;
	profession = nullptr;
}

CreatureClass::~CreatureClass()
{
}

void CreatureClass::CharacterInitialiser(int raceChoice, int professionChoice)
{

	this->race = new RaceClass();
	this->profession = new ProfessionClass();

	//decide Race using the user choice in the game class
	if (raceChoice == 1)
	{
		if(race != NULL){
		
			race->RaceClassChoice(1);
			race->setBaseStrength(10);
			race->setBaseDexterity(2);
			race->setBaseHealth(200);
			
		}



	}
	else if (raceChoice == 2)
	{
		if (race != NULL) {

			race->RaceClassChoice(2);
			race->setBaseStrength(2);
			race->setBaseDexterity(10);
			race->setBaseHealth(150);
		}


	}
	else if (raceChoice == 3)
	{
		if (race != NULL) {

			race->RaceClassChoice(3);
			race->setBaseStrength(5);
			race->setBaseDexterity(5);
			race->setBaseHealth(150);
		}


	}


	//Decide Class/Profession
	if (professionChoice == 1)
	{
		if (race != NULL) {

			profession->ProfessisonClassChoice(1);
			this->profession->setBonusStrength(10);
			this->profession->setBonusDexterity(2);
			this->profession->setBonusHealth(100);
		}


	}
	else if (professionChoice == 2)
	{
		if (race != NULL) {

			profession->ProfessisonClassChoice(2);
			this->profession->setBonusStrength(2);
			this->profession->setBonusDexterity(10);
			this->profession->setBonusHealth(80);
		}


	}
	else if (professionChoice == 3)
	{
		if (race != NULL) {
			
			profession->ProfessisonClassChoice(3);
			this->profession->setBonusStrength(5);
			this->profession->setBonusDexterity(5);
			this->profession->setBonusHealth(120);
		}


	}

	//Take stats from race and creature classes and combine them in creature class
	this->setStrength(this->race->getBaseStrength(), this->profession->getBonusStrength());
	this->setDexterity(this->race->getBaseDexterity(), this->profession->getBonusDexterity());
	this->setMaxHealth(this->race->getBaseHealth(), this->profession->getBonusHealth());
	this->setDamage(this->dexterity, this->strength);
		
}

void CreatureClass::PrintCharacter()
{

	//prints character sheet
	std::cout << race->getRace() << " " << profession->getProfession() << std::endl;
	std::cout << "Strength: " << this->getStrength()<< std::endl;
	std::cout << "Dexterity: " << this->getDexterity() << std::endl;
	std::cout << "Max Health: " << this->getMaxHealth() << std::endl;
	std::cout << "Current Health: " << this->getHealth() << std::endl;
	std::cout << std::endl;
}

void CreatureClass::Attack(CreatureClass* target)
{
	//checks if dexterity is more than or equal to strength and sets damage based on which is highest
	if (this->dexterity >= this->strength)
	{
		this->damage = dexterity;
}
	else {
		this->damage = strength;
	}
	target->setHealth(-this->damage);
	std::cout << target->health << std::endl;

	if (this->race->getCooldowns() > 0) {
		this->race->setCooldowns(-1);
	}

	if(this->profession->getCooldowns()>0)
	{ 
		this->profession->setCooldowns(-1);
	}
}

//GETTER AND SETTERS


void CreatureClass::setStrength(int baseStrength, int bonusStrength)
{
	this->strength += baseStrength;
	this->strength += bonusStrength;
}

int CreatureClass::getStrength() const
{
	
	return this->strength;
}

void CreatureClass::setDexterity(int baseDexterity, int bonusDexterity)
{
	this->dexterity += baseDexterity;
	this->dexterity += bonusDexterity;
}

int CreatureClass::getDexterity() const
{
	return this->dexterity;
}

void CreatureClass::setHealth(int health)
{ 
	this->health += health;
}

int CreatureClass::getHealth() const
{
	return this->health;
}

void CreatureClass::setMaxHealth(int baseMaxHealth, int bonusMaxHealth)
{
	this->maxHealth += baseMaxHealth;
	this->maxHealth += bonusMaxHealth;
	setHealth(maxHealth);
}

int CreatureClass::getMaxHealth() const
{
	return this->maxHealth;
}

void CreatureClass::setRace(std::string raceChoice)
{
	this->raceChoice = raceChoice;
}

std::string CreatureClass::getRace()
{
	return this->raceChoice;
}

void CreatureClass::setProfession(std::string professionChoice)
{
	this->professionChoice = professionChoice;
}

std::string CreatureClass::getProfession()
{
	return this->professionChoice;
}

void CreatureClass::setDamage(int dex, int strength)
{
	if (dex >= strength)
	{
		this->damage = dex;
	}
	else {
		this->damage = strength;
	}
}

 int CreatureClass::getDamage()
{
	return this->damage;
}
