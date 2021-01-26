#pragma once
#include <iomanip>
#include "Include.h"


class Game
{

public:
	//Constructor and Destructor
	Game();

	virtual ~Game();

	//Main Methods
	void mainMenu();

	bool getPlaying();
	
	void battle();


private:
	int choice;
	int battleChoice;
	int raceChoice;
	int professionChoice;
	bool playing;


	CreatureClass* player;
	CreatureClass* enemy;
};

