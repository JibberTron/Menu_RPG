#include "Melee.h"

void Melee::SetWeaponDmg(const double _dmg)
{
    mWeaponDmg = _dmg;
}

void Melee::SetCritChance(const double _critChance)
{
    mCritStrikeChance = _critChance;
}

void Melee::SetHitChance(const double _hitChance)
{
    mHitChance = _hitChance;
}
