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

// maybe do a heal method with certain amount of heal based on the char unless your a priest
// maybe pass through both character as a way to take health away if the other player is getting hit
void GameMode::Attack(Character* _attacker, Character* _victim)
{
    if (!_attacker) return;
    unsigned int health = _victim->GetHealth();
    mHit = RollChance(_attacker->GetWeapon()->GetHitChance());
    double damage = _attacker->GetWeapon()->GetWeaponDmg();
    mCrit = false;

    if (mHit)
    {
        mCrit = RollChance(_attacker->GetWeapon()->GetCritChance());
        if (mCrit)
        {
            damage = _attacker->GetWeapon()->GetCritDmg();
        }
    }

    if (!mHit)
    {
        std::cout << _attacker->GetFirstName() << " Misses\n";
    }
    else if (mCrit)
    {
        std::cout << _attacker->GetFirstName() << " Critical Hit's for " << damage << " damage\n";
        health -= damage;
        _victim->SetHealth(health);
        std::cout << _victim->GetFirstName() << "'s health reduces by " << damage;
        
    }
    else {
        std::cout << _attacker->GetFirstName() << " Hit's for " << damage << " damage\n";
        health -= damage;
        _victim->SetHealth(health);
        std::cout << _victim->GetFirstName() << "'s health reduces by " << damage;
    }

}
