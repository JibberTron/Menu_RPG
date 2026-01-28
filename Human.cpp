#include "Human.h"

void Human::SetClass(const CharacterClass _class)
{
	mClass = _class;
}

void Human::SetWeapon(const CharacterClass _class)
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

	case CharacterClass::PRIEST:

		break;

	default:
		break;
	}
}
