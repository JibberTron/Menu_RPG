#include "Undead.h"

void Undead::SetClass(const CharacterClass _class)
{
	mClass = _class;
}

void Undead::SetWeapon(const CharacterClass _class)
{
	switch (_class)
	{
	case CharacterClass::WARRIOR:
		if (mWeapon)
		{
			delete mWeapon;
			mWeapon = nullptr;
		}

		mWeapon = new Melee();
		if (mWeapon)
		{
			mWeapon->SetWeaponStats(mWeapon->GetWeaponDmg(), mWeapon->GetCritChance(), mWeapon->GetHitChance());
		}
		break;

	case CharacterClass::ARCHER:
		if (mWeapon)
		{
			delete mWeapon;
			mWeapon = nullptr;
		}

		mWeapon = new Ranged();
		if (mWeapon)
		{
			mWeapon->SetWeaponStats(mWeapon->GetWeaponDmg(), mWeapon->GetCritChance(), mWeapon->GetHitChance());
		}

		break;

	case CharacterClass::MAGE:

		break;

	case CharacterClass::DEATH_KNIGHT:
		if (mWeapon)
		{
			delete mWeapon;
			mWeapon = nullptr;
		}

		mWeapon = new Melee();
		if (mWeapon)
		{
			mWeapon->SetWeaponStats(mWeapon->GetWeaponDmg(), mWeapon->GetCritChance(), mWeapon->GetHitChance());
		}
		break;

	default:
	
		break;
	}
}


