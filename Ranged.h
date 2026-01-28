#pragma once
#include "Weapon.h"
class Ranged : public Weapon
{
public:
	Ranged(double _wepDmg = 0, double _critChance = 0, double _critDmg = 0, double _hitChance = 0) :
		Weapon(_wepDmg, _critChance, _critDmg, _hitChance)
	{
		mCharWeapon = WeaponType::RANGED;
		mWeaponDmg = 50.0;
		mCritStrikeChance = 0.45;
		mCritStrikeDmg = mWeaponDmg * 2;
		mHitChance = 0.75;
	}

	void SetWeaponDmg(const double _dmg);
	void SetCritChance(const double _critChance);
	void SetHitChance(const double _hitChance);

	double GetWeaponDmg() const { return mWeaponDmg; }
	double GetCritChance() const { return mCritStrikeChance; }
	double GetCritDmg() const { return mCritStrikeDmg; }
	double GetHitChance() const { return mHitChance; }
	WeaponType GetWeaponType() const { return mCharWeapon; }
};

