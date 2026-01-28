#include "Character.h"
#include <iomanip>

void Character::DisplayStats()
{
	std::string charClass;
	std::string gender = (mGender == Gender::MALE) ? "Male" : "Female";
	std::string race;

	switch (mClass)
	{
	case CharacterClass::WARRIOR:
		charClass = "Warrior";
		break;

	case CharacterClass::ARCHER:
		charClass = "Archer";
		break;

	case CharacterClass::MAGE:
		charClass = "Mage";
		break;

	case CharacterClass::PRIEST:
		charClass = "Priest";
		break;

	case CharacterClass::DEATH_KNIGHT:
		charClass = "Death Knight";
		break;

	default:
		break;
	}

	switch (mRace)
	{
	case Race::HUMAN:
		race = "Human";
		break;

	case Race::UNDEAD:
		race = "Undead";
		break;

	default:
		break;
	}
	std::string c = "|";

	//std::cout << "----------Character Stats----------\n";
	std::cout << "==========Character Stats==========\n";
	std::cout << "\t Name: " << mFirstName + " " + mLastName << "\n\t Gender: " << gender << "\n\t Race: " << race
		<< "\n\t Class: " << charClass << "\n\t Health: " << mHealth << '\n';
	//std::cout << "-----------------------------------\n";
	std::cout << "===================================\n";
}
