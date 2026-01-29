#pragma once
#include "Character.h"

class Human : public Character
{
public:
	Human(std::string _firstName, std::string _lastName, unsigned int _health, Gender _gen)
		:Character(_firstName, _lastName, _health, _gen)
	{
		mRace = Race::HUMAN;
		//std::cout << "Human CTor\n";
	}

	~Human() 
	{ 
		//std::cout << "Human DTor\n"; 
		if (mWeapon)
		{
			delete mWeapon;
			mWeapon = nullptr;
		}
	}
	void Display() const
	{
		std::cout << "Human Choose\n";
	}

	void SetClass(const CharacterClass _class);
	void SetWeapon(const CharacterClass _class);
	void SetHealth(const unsigned int _health);

	CharacterClass GetClass() const { return mClass; }
	Race GetRace()const { return mRace; }
	Gender GetGender() const { return mGender; }
	Weapon* GetWeapon() const { return mWeapon; }
	std::string GetFirstName() const { return mFirstName; }
	std::string GetLastName() const { return mLastName; }
	unsigned int GetHealth() const { return mHealth; }
};

