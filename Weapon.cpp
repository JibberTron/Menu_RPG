#include "Weapon.h"

void Weapon::SetWeaponStats(const double _dmg, const double _critChance, const double _hitChance)
{
    mWeaponDmg = _dmg;
    mCritStrikeChance = _critChance;
    mCritStrikeDmg = _dmg * 2;
    mHitChance = _hitChance;
}
