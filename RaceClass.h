#pragma once
#ifndef RACECLASS_H
#define RACECLASS_H


class RaceClass : public CreatureClass
{

private:

	std::string race;

	int baseStrength;
	int baseDexterity;
	int baseHealth;
	int cooldown;
	int choice;

	
public:
	//Constructor Destructors

	RaceClass();
	virtual ~RaceClass();

	//Special attack based on race
	void RacialAttack(CreatureClass* target);


	//Accessors and modifiers
	void RaceClassChoice(int choice);
	std::string getRace();

	void setBaseStrength(int baseStrength);
	int getBaseStrength();

	void setBaseDexterity(int baseDexterity);
	int getBaseDexterity();

	void setBaseHealth(int baseHealth);
	int getBaseHealth();

	void setCooldowns(int cooldown);
	int getCooldowns();
};


//SUB CLASSES FOR EACH RACE WITH ACCESSORS, MODIFIERS AND SUITABLE CONSTRUCTORS

class OgreClass : public RaceClass
{
private:
	int strengthOgre;
	int dexterityOgre;
	int healthOgre;

public:
	OgreClass();
	~OgreClass();

};

class VampireClass : public RaceClass
{
private:
	int strengthVamp;
	int dexterityVamp;
	int healthVamp;

public:
	VampireClass();
	~VampireClass();

};

class SerpentClass : public RaceClass
{
private:
	int strengthSerpent;
	int dexteritySerpent;
	int healthSerpent;

public:
	SerpentClass();
	~SerpentClass();

};
#endif
