#include "CreatureClass.h"
#include "RaceClass.h"
#include "ProfessionClass.h"


RaceClass::RaceClass()
{
	this->choice = 0;
	this->baseStrength = 0;
	this->baseDexterity = 0;
	this->baseHealth = 0;
	this->cooldown = 1;

}

RaceClass::~RaceClass()
{
}

void RaceClass::RacialAttack(CreatureClass* target)
{

	if (this->getRace() == "OGRE" && cooldown == 0)
	{
		//Ogre attack

		//Deals 2* strength damage, increases the opponent’s cooldown timers by 1
		std::cout << "SLAM!! " << std::endl;

		target->setHealth(-2 * getStrength());
		target->race->setCooldowns(1);
		target->profession->setCooldowns(3);
		this->setCooldowns(3);

		std::cout << "Opponent Cooldown +1" << std::endl;
		std::cout << std::endl;

		std::cout << "Opponent HP: " << target->getHealth()<<std::endl;
	}
	else if (this->getRace() == "VAMPIRE" && cooldown == 0)
	{
		//Vampire attack
		
		//Deals 2* dexterity damage, restores health equal to half the damage dealt

		std::cout << "DRAIN!! " << std::endl;

		target->setHealth(-2 * getDexterity());
		this->setHealth(getDexterity());
		this->setCooldowns(4);

		std::cout << getDexterity() << "Health Restored" << std::endl;
		std::cout << std::endl;

		std::cout << "Opponent HP: " << target->getHealth() << std::endl;
	}
	else if (this->getRace() == "SERPENT" && cooldown == 0)
	{
		//Serpent attack

		//Deals strength + dexterity  damage, reduces  opponent’s  strength  and dexterity by 1 each (to a minimum of 1).
		std::cout << "WEAKEN!! " << std::endl;

		target->setHealth(-getStrength());
		target->setHealth(-getDexterity());

		if (target->getDexterity() > 1 && target->getStrength() > 1)
		{
			target->setStrength(0, -1);
			target->setDexterity(0, -1);

			std::cout << "Opponent Dexterity and Strength -1" << std::endl;
		}

		this->setCooldowns(3);
		std::cout << std::endl;


		std::cout << "Opponent HP: " << target->getHealth() << std::endl;
	}
}

void RaceClass::RaceClassChoice(int choice)
{
	//Select race and create class based on player choice
	if (choice == 1)
	{
		race = "OGRE";
		OgreClass* ogre = new OgreClass();
	}
	else if (choice == 2)
	{
		race = "VAMPIRE";
		VampireClass* vampire = new VampireClass();
	}
	else if (choice == 3)
	{
		race = "SERPENT";
		SerpentClass* serpent = new SerpentClass();
	}

	else {
		race = "NULL";
		this->setBaseStrength(0);
		this->setBaseDexterity(0);
		this->setBaseHealth(0);
	}
}

std::string RaceClass::getRace()
{
	return this->race;
}



void RaceClass::setBaseStrength(int baseStrength)
{

	this->baseStrength += baseStrength;
}

int RaceClass::getBaseStrength()
{
	return this->baseStrength;
}



void RaceClass::setBaseDexterity(int baseDexterity)
{

	this->baseDexterity += baseDexterity;
}

int RaceClass::getBaseDexterity()
{
	return this->baseDexterity;
}


void RaceClass::setBaseHealth(int baseHealth)
{

	this->baseHealth += baseHealth;
}


int RaceClass::getBaseHealth()
{
	return this->baseHealth;
}

void RaceClass::setCooldowns(int cooldown)
{
	this->cooldown += cooldown;
}

int RaceClass::getCooldowns()
{
	return this->cooldown;
}


OgreClass::OgreClass()
{
	strengthOgre = 10;
	dexterityOgre = 2;
	healthOgre = 200;

	setBaseStrength(strengthOgre);
	setBaseDexterity(dexterityOgre);
	setBaseHealth(healthOgre);
}

OgreClass::~OgreClass()
{
}

VampireClass::VampireClass()
{
	strengthVamp = 2;
	dexterityVamp = 10;
	healthVamp = 150;

	setBaseStrength(strengthVamp);
	setBaseDexterity(dexterityVamp);
	setBaseHealth(healthVamp);
}

VampireClass::~VampireClass()
{
}

SerpentClass::SerpentClass()
{
	strengthSerpent = 5;
	dexteritySerpent = 5;
	healthSerpent = 150;

	setBaseStrength(strengthSerpent);
	setBaseDexterity(dexteritySerpent);
	setBaseHealth(healthSerpent);
}

SerpentClass::~SerpentClass()
{
}
