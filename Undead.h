#pragma once
#include "Character.h"

class Undead : public Character
{
public:
	Undead(std::string _firstName, std::string _lastName, unsigned int _health, Gender _gen)
		:Character(_firstName, _lastName, _health, _gen)
	{
		mRace = Race::UNDEAD;
		//std::cout << "Undead CTor\n";
	}
	~Undead()
	{ 
		if (mWeapon)
		{
			delete mWeapon;
			mWeapon = nullptr;
		}
		//std::cout << "Undead DTor\n"; 
	}
	void Display() const
	{
		std::cout << "Undead Choose\n";
	}

	void SetClass(const CharacterClass _class);
	void SetWeapon(const CharacterClass _class);

	CharacterClass GetClass() const { return mClass; }
	Race GetRace()const { return mRace; }
	Gender GetGender() const { return mGender; }
	Weapon* GetWeapon() const { return mWeapon; }
	std::string GetFirstName() const { return mFirstName; }
	std::string GetLastName() const { return mLastName; }
};

