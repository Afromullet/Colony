//
//  Head.cpp
//  Colony
//
//  Created by Sean on 9/3/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Head.hpp"

Head::Head(Armor _armor,short int _headHealth) : armor(_armor),headHealth(_headHealth)
{
    bodyPart = enChestBodyPart;
}

Head::Head(short int _headHealth) : headHealth(_headHealth)
{
    bodyPart = enChestBodyPart;
}

Head::Head() : headHealth(10)
{
    bodyPart = enChestBodyPart;
}

Armor Head::getHeadArmor(){return armor;}
short int  Head::getHeadHealth(){return headHealth;}

void  Head::setHeadArmor(Armor value)
{
    if(value.getBodyPart() == enHead)
    {
        armor = value;
    }
    else
    {
        //std::cout << value.getEquipmentName() << " does not fit into head armor slot";
    }
    
}
void  Head::setHeadHealth(short int value){headHealth = value;}

bool Head::doesAttackHitHead(short int attackBonus)
{
    return attackBonus >= armor.siGetArmorBonus();    
}

int Head::damageHead(short int damage)
{
    headHealth -= damage;
}