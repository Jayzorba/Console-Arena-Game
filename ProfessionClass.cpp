#include "CreatureClass.h"
#include "ProfessionClass.h"



ProfessionClass::ProfessionClass()
{
	this->strengthBonus = 0;
	this->dexterityBonus = 0;
	this->healthBonus = 0;
	this->cooldown = 0;
	this->choice = 0;
}

ProfessionClass::~ProfessionClass()
{
}

void ProfessionClass::professionalAttack(CreatureClass* target)
{

	if (this->getProfession() == "WARRIOR" && cooldown == 0)
	{
		//Warrior attack

		//Deals 2* Strength damage and increases strength by 1
		std::cout << "Warrior attack" << std::endl;

		target->setHealth(-2 * getStrength());
		this->setStrength(1, 0);
		this->setCooldowns(3);

		std::cout <<"Strength +1" << std::endl;
		std::cout << std::endl;

		std::cout << "Opponent HP: " << target->getHealth() << std::endl;
	}
	else if (this->getProfession() == "SHADE" && cooldown == 0)
	{
		//Shade attack

		//Deals 2* Dexterity damage and increases dexterity by 1.
		target->setHealth(-2 * getDexterity());
		this->setDexterity(1, 0);
		this->setCooldowns(3);


		std::cout << "Dexterity +1" << std::endl;
		std::cout << std::endl;

		std::cout << target << " HP: " << target->getHealth() << std::endl;
	}
	else if (this->getProfession() == "CLERIC" && cooldown == 0)
	{
		//Cleric attack

		//Does no damage, restores 80 health
		std::cout << "Cleric attack" << std::endl;

		if(getHealth() < getMaxHealth()){
		
			this->setHealth(80);
			this->setCooldowns(4);
		}

		std::cout << std::endl;
		std::cout << "You healed for 80 hit points " << std::endl;
	}


}

void ProfessionClass::ProfessisonClassChoice(int choice)
{

	//Creates a subclass based on player choice

	if (choice == 1)
	{
		profession = "WARRIOR";
		WarriorClass* warrior = new WarriorClass();
	}
	else if (choice == 2)
	{
		profession = "SHADE";
		ShadeClass* shade = new ShadeClass();
	}
	else if (choice == 3)
	{
		profession = "CLERIC";
		ClericClass* cleric = new ClericClass();
	}

	else {
		profession = "NULL";
		this->setBonusStrength(0);
		this->setBonusDexterity(0);
		this->setBonusHealth(0);
	}
}

std::string ProfessionClass::getProfession()
{
	return this->profession;
}

void ProfessionClass::setBonusStrength(int bonusStrength)
{
	this->strengthBonus += bonusStrength;
}

int ProfessionClass::getBonusStrength() 
{
	return this->strengthBonus;
}

void ProfessionClass::setBonusDexterity(int bonusDexterity)
{
	this->dexterityBonus += bonusDexterity;
}

int ProfessionClass::getBonusDexterity()
{
	return this->dexterityBonus;
}

void ProfessionClass::setBonusHealth(int bonusHealth)
{
	this->healthBonus += bonusHealth;
}

int ProfessionClass::getBonusHealth()
{
	return this->healthBonus;
}

void ProfessionClass::setCooldowns(int cooldown)
{
	this->cooldown += cooldown;
}

int ProfessionClass::getCooldowns()
{
	return this->cooldown;
}

WarriorClass::WarriorClass()
{
	warriorStrength = 10;
	warriorDexterity = 2;
	warriorHealth = 200;

	setBonusStrength(warriorStrength);
	setBonusDexterity(warriorDexterity);
	setBonusHealth(warriorHealth);
}

WarriorClass::~WarriorClass()
{
}

ShadeClass::ShadeClass()
{
	shadeStrength = 2;
	shadeDexterity = 10;
	shadeHealth = 150;

	setBonusStrength(shadeStrength);
	setBonusDexterity(shadeDexterity);
	setBonusHealth(shadeHealth);
}

ShadeClass::~ShadeClass()
{
}

ClericClass::ClericClass()
{
	clericStrength = 5;
	clericDexterity = 5;
	clericHealth = 150;

	setBonusStrength(clericStrength);
	setBonusDexterity(clericDexterity);
	setBonusHealth(clericHealth);

}

ClericClass::~ClericClass()
{
}
