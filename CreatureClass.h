#pragma once
#include <iostream>
#ifndef CREATURECLASS_H
#define CREATURECLASS_H

class RaceClass;
class ProfessionClass;

class CreatureClass
{
public:

	RaceClass* race;
	ProfessionClass* profession;

	//Constructor and Deconstructor
	CreatureClass();
	virtual ~CreatureClass();

	void CharacterInitialiser(int race, int profession);
	
	void PrintCharacter();

	void Attack(CreatureClass* target);

	//Accessors and Modifiers
	void setStrength(int baseStrength, int bonusStrength);
	int getStrength() const;

	void setDexterity(int baseDexterity, int bonusDexterity);
	int getDexterity() const;

	void setHealth(int health);
	int getHealth()const;
	 
	void setMaxHealth(int baseMaxHealth, int bonusMaxHealth);
	int getMaxHealth()const;

	void setRace(std::string raceChoice);
	std::string getRace();

	void setProfession(std::string professionChoice);
	std::string getProfession();

	void setDamage(int dex, int strength);
	int getDamage();


private:

	int strength;
	int dexterity;
	int health;
	int maxHealth;
	int minDamage;
	int maxDamage;
	int damage;
	std::string raceChoice;
	std::string professionChoice;

	
	

};

#endif