#include "Ranged.h"

void Ranged::SetWeaponDmg(const double _dmg)
{
    mWeaponDmg = _dmg;
}

void Ranged::SetCritChance(const double _critChance)
{
    mCritStrikeChance = _critChance;
}

void Ranged::SetHitChance(const double _hitChance)
{
    mHitChance = _hitChance;
}
