#pragma once
#include <string>
#include <iostream>
#include "Weapon.h"
#include "Melee.h"
#include "Ranged.h"

enum class Gender
{
	MALE = 1,
	FEMALE = 2,
	DEFAULT_GENDER = 3
};

enum class Race
{
	HUMAN = 1,
	UNDEAD = 2,
	DEFAULT_RACE = 3
};

enum class CharacterClass
{
	WARRIOR = 1,
	ARCHER = 2,
	MAGE = 3,
	PRIEST = 4,
	DEATH_KNIGHT = 5,
	DEFAULT_CLASS = 6
};

class Character
{
protected:
	Gender mGender = Gender::DEFAULT_GENDER;
	CharacterClass mClass = CharacterClass::DEFAULT_CLASS;
	Weapon* mWeapon = nullptr;
	Race mRace = Race::DEFAULT_RACE;
	std::string mFirstName;
	std::string mLastName;
	unsigned int mHealth = 0;

public:
	Character(std::string _firstName, std::string _lastName, unsigned int _health, Gender _gen) 
		: mFirstName(_firstName), mLastName(_lastName), mHealth(_health), mGender(_gen)
	{

	}

	virtual ~Character() = default;

	virtual void Display() const = 0;
	virtual void DisplayStats();

	virtual void SetClass(const CharacterClass _class) = 0;
	virtual void SetWeapon(const CharacterClass _class) = 0;
	virtual void SetHealth(const unsigned int _health) = 0;

	virtual CharacterClass GetClass() const = 0;
	virtual Weapon* GetWeapon() const = 0;
	virtual Gender GetGender() const = 0;
	virtual Race GetRace() const = 0;
	virtual std::string GetFirstName() const = 0;
	virtual std::string GetLastName() const = 0;
	virtual unsigned int GetHealth() const = 0;
};