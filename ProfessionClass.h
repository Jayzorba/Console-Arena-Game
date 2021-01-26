#pragma once
#ifndef PROFESSIONCLASS_H
#define PROFESSIONCLASS_H


class ProfessionClass : public CreatureClass
{
private:
	int strengthBonus;
	int dexterityBonus;
	int healthBonus;
	int cooldown;

	int choice;

	std::string profession;

public:
	//Constructor Destructors
	ProfessionClass();
	~ProfessionClass();


	//Attack method based on profession
	void professionalAttack(CreatureClass* target);


	//Accessors and modifiers
	void ProfessisonClassChoice(int choice);
	std::string getProfession();

	void setBonusStrength(int bonusStrength);
	int getBonusStrength(); 

	void setBonusDexterity(int bonusDexterity);
	int getBonusDexterity(); 

	void setBonusHealth(int bonusHealth);
	int getBonusHealth(); 

	void setCooldowns(int cooldown);
	int getCooldowns();
};

//SUB CLASSES FOR EACH PROFESSION WITH ACCESSORS, MODIFIERS AND SUITABLE CONSTRUCTORS

class WarriorClass : public ProfessionClass
{
private:

	int warriorStrength;
	int warriorDexterity;
	int warriorHealth;

public:

	WarriorClass();
	~WarriorClass();
};

class ShadeClass : public ProfessionClass
{
private:

	int shadeStrength;
	int shadeDexterity;
	int shadeHealth;

public:

	ShadeClass();
	~ShadeClass();
};

class ClericClass : public ProfessionClass
{
private:

	int clericStrength;
	int clericDexterity;
	int clericHealth;

public:

	ClericClass();
	~ClericClass();
};
#endif