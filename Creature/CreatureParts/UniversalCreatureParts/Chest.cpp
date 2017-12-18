//
//  Chest.cpp
//  Colony
//
//  Created by Sean on 9/3/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Chest.hpp"

Chest::Chest(Armor _armor, short int _chestHealth) : armor(_armor), health(_chestHealth)
{
    bodyPart = enChestBodyPart;
    
}


Chest::Chest(short int _chestHealth) : health(_chestHealth)
{
    bodyPart = enChestBodyPart;
}

Chest::Chest() : health(10)
{
    bodyPart = enChestBodyPart;
}


Armor Chest::getChestArmor(){return armor;}
short int Chest::getChestHealth(){return health;}

void Chest::setChestArmor(Armor value)
{
    if(value.getBodyPart() == enChest)
    {
        armor = value;
    }
    else
    {
        //std::cout << armor.getEquipmentName() << " does not fit into chest armor slot";
    }
}
void Chest::setChestHealth(short int value){health = value;}

//Returns true if hit succeeded, returns false if not
bool Chest::doesAttackHitChest(short int attackBonus)
{
    return attackBonus >= armor.siGetArmorBonus();
}

int Chest::damageChest(short int damage)
{
    health -= damage;
}