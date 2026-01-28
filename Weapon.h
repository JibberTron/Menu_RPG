#pragma once
#include <random>
#include <iostream>

enum class WeaponType
{
	MELEE = 1,
	RANGED = 2,
	CASTER = 3,
	HEALS = 4,
	DEFAULT_TYPE = 5
};

class Weapon
{
protected:
	double mWeaponDmg;
	double mCritStrikeChance;
	double mCritStrikeDmg;
	double mHitChance;
	WeaponType mCharWeapon = WeaponType::DEFAULT_TYPE;

public:
	Weapon(double _wepDmg, double _critChance, double _critDmg, double _hitChance) :
		mWeaponDmg(_wepDmg), mCritStrikeChance(_critChance), mCritStrikeDmg(_critDmg), mHitChance(_hitChance)
	{

	}
	
	virtual ~Weapon() = default;
	void SetWeaponStats(const double _dmg, const double _critChance, const double _hitChance);

	virtual void SetWeaponDmg(const double _dmg) = 0;
	virtual void SetCritChance(const double _critChance) = 0;
	virtual void SetHitChance(const double _hitChance) = 0;

	virtual double GetWeaponDmg() const = 0;
	virtual double GetCritChance() const = 0;
	virtual double GetCritDmg() const = 0;
	virtual double GetHitChance() const = 0;
	virtual WeaponType GetWeaponType() const = 0;

};

