#pragma once
#include <iostream>
#include <vector>
#include "Character.h"
#include "Human.h"
#include "Undead.h"
#include "GameMode.h"

struct GameClass
{
	int classID;
	CharacterClass charClass;
	Race classSpecific;
	std::string className;
};

class Main_Menu
{
	Character* mUserCharacter = nullptr;
	Character* mSecondCharacter = nullptr;
	GameMode* mGameMode = nullptr;
	Race mUserRace = Race::DEFAULT_RACE;
	Gender mGender = Gender::DEFAULT_GENDER;
	std::string mUserFirstName = " ";
	std::string mUserLastName = " ";
	bool bCharacter1Complete = false;
	bool bCharacter2Complete = false;
	bool bCharacter1RdyCreate = false;
	bool bCharacter2RdyCreate = false;
	bool bPlayer1First = false;
	bool bPlayer2First = false;
	bool bPlayer1Turn = false;
	bool bPlayer2Turn = false;
	bool bRaceSelected = false;
	bool bWeaponSelected = false;
	bool bSecondWeaponSelected = false;

public:
	Main_Menu() 
	{
		//std::cout << "Menu CTor\n";
	}
	~Main_Menu();
	CharacterClass UserClasses(int _offset);
	void RaceMenu();
	void ClassMenu();
	void GenderMenu();
	void BeginMenu();
	void DisplayCharacter(Character* _char);

	void PlayGame();
	GameMode* SetGameMode();

	Character* CreateCharacter(Race _race, std::string _firstName, std::string _lastName, Gender _gen);
};

