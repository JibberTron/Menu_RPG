#pragma once
#include "Character.h"

class GameMode
{
	bool mHit = false;
	bool mCrit = false;
	Character* InChar = nullptr;

	std::mt19937& RNG();
	bool RollChance(double _chance);
public:
	GameMode()
	{

	}
	void Attack(Character* _char);
};

