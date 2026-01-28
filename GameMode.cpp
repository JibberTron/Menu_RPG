#include "GameMode.h"

std::mt19937& GameMode::RNG()
{
    static std::mt19937 gen(std::random_device{}());
    return gen;
}

bool GameMode::RollChance(double _chance)
{
    static std::uniform_real_distribution<> dist(0.0, 1.0);
    return dist(RNG()) < _chance;
}

void GameMode::Attack(Character* _char)
{
    if (!_char) return;
    mHit = RollChance(_char->GetWeapon()->GetHitChance());
    double damage = _char->GetWeapon()->GetWeaponDmg();
    mCrit = false;

    if (mHit)
    {
        mCrit = RollChance(_char->GetWeapon()->GetCritChance());
        if (mCrit)
        {
            damage = _char->GetWeapon()->GetCritDmg();
        }
    }

    if (!mHit)
    {
        std::cout << "Miss\n";
    }
    else if (mCrit)
    {
        std::cout << "Critical Hit for " << damage << " damage\n";
    }
    else {
        std::cout << "Hit for " << damage << " damage\n";
    }

}
