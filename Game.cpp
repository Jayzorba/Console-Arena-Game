#include "Game.h"



Game::Game()
{
	
	choice = 0;
	battleChoice = 0;
	raceChoice = 0;
	professionChoice = 0;
	playing = true;
	 player = nullptr;
	 enemy = nullptr;
	 CreatureClass p;
	 CreatureClass e;
	 player = &p;
	 enemy = &e;

	player = new CreatureClass();
	enemy = new CreatureClass();


}

Game::~Game()
{
}

void Game::mainMenu()
{
	//Main menu, based on players options

	std::cout << "Main Menu" << std::endl;
	std::cout << "0: Quit" << std::endl;
	std::cout << "1: Choose Race and Class" << std::endl;
	std::cout << "2: Choose Opponent Race and Class" << std::endl;
	std::cout << "3: START!" << std::endl;
	std::cout << std::endl << "Choice: ";

	std::cin >> choice;

	switch (choice)
	{
	case 0:
		//quit game
		playing = false;
		break;
	case 1:

		//Create the player character using their choice
		std::cout << "Pick your Race : 1 OGRE, 2 VAMPIRE, 3 SERPENT" << std::endl;
		std::cin >> raceChoice;
		std::cout << std::endl << "Pick your Class: 1 WARRIOR, 2 SHADE, 3 CLERIC" << std::endl;
		std::cin >> professionChoice;
		std::cout << std::endl;
		player->CharacterInitialiser(raceChoice, professionChoice);
		player->PrintCharacter();
		break;
	case 2:
		//Create Opposing Character based on player choice
		std::cout << "Pick your Race : 1 OGRE, 2 VAMPIRE, 3 SERPENT" << std::endl;
		std::cin >> raceChoice;
		std::cout << std::endl << "Pick your Class: 1 WARRIOR, 2 SHADE, 3 CLERIC" << std::endl;
		std::cin >> professionChoice;
		std::cout<<std::endl;
		enemy->CharacterInitialiser(raceChoice, professionChoice);
		std::cout << "YOU PICKED A: " << std::endl;
		enemy->PrintCharacter();
		break;
	case 3:
		//Start Battle
		while (player->getHealth() > 0 || enemy->getHealth() > 0)
		{
			battle();
		}
		break;

	default: break;
	}
}

bool Game::getPlaying()
{
	return this->playing;
}

void Game::battle()
{

	//Check to see if player or enemy health is over 0 to find the winner
	if (player->getHealth() <= 0)
	{
		std::cout << "YOU LOSE" << std::endl;
		mainMenu();
	}

	else if (enemy->getHealth() <= 0)
	{
		std::cout << "YOU WIN!!! " << std::endl;
		mainMenu();

	}

	//Player must press 1 to continue the turns, creatures prioritise professional attack, then racial attack and lastly if all cooldowns are up their basic attack.
	else {
		std::cout << "GET READY FOR BATTLE!!" << std::endl;
		std::cout << std::endl;
		std::cout << "PRESS 1 TO GO TO THE NEXT TURN" << std::endl;

		std::cin >> battleChoice;

		if (player->race->getCooldowns() == 0 && battleChoice == 1)
		{
			player->race->RacialAttack(enemy);
		}
		else if (player->profession->getCooldowns() == 0 && battleChoice == 1)
		{
			player->profession->professionalAttack(enemy);
		}
		else {
			player->Attack(enemy);
		}

		if (enemy->race->getCooldowns() == 0 && battleChoice == 1)
		{
			enemy->race->RacialAttack(player);
		}
		else if (enemy->profession->getCooldowns() == 0)
		{
			enemy->profession->professionalAttack(player);
		}
		else {
			enemy->Attack(player);
		}
	}

	//Shows you current character stats at end of each turn.
	std::cout << std::endl;
	player->PrintCharacter();
	std::cout << std::endl;
	enemy->PrintCharacter();
	std::cout << std::endl;
}
