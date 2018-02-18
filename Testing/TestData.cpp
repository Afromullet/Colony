//
//  TestData.cpp
//  Colony
//
//  Created by Sean on 9/3/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "TestData.hpp"
#include "TestDataGenerator.hpp"
#include <cstdlib>

#ifdef DEBUG_OUTPUT
#include <fstream>
#include <iostream>
#endif

/*
 Todo, do better random generation
 Replace iterators with .size()
 
 
 */


BaseCreature testCreature1;

void setupTestCreatures()
{
    
    testCreature1 = basicOrc;
    testCreature1.setPosition(5, 5);
}

EnumArmorClass randArmorClass()
{
    int randNum = rand() % 3;
    
    switch(rand() % 3)
    {
        case 0:
            return enLight;
        case 1:
            return enMedium;
        case 2:
            return enHeavy;
    }
}

//To save myself some typing
short int randBonus()
{
    return rand() % 10;
    
}

//Need a longer range for ranged weapons...used for random ranged weapon generation
short int randRangeWeaponRange()
{
    return rand() & 50;
}



Chest generateChest()
{
    return Chest(randBonus());
}

Head generateHead()
{
    return Head(randBonus());
}



void printWeaponClass(EnumWeaponClass weaponClass)
{


    if(weaponClass == enLongSword)
    {
        //std::cout << "Weapon class: Longsword \n";
    }
    else if(weaponClass == enDagger)
    {
        //std::cout << "Weapon class: Dagger \n";
    }
    else if(weaponClass == enShortSword)
    {
        //std::cout << "Weapon class: Shortsword \n";
    }
    else if(weaponClass == enGreatsword)
    {
        //std::cout << "Weapon class: Greatsword \n";
    }
    else if(weaponClass == enCrossbow)
    {
        //std::cout << "Weapon class: Crossbow \n";
    }
    else if(weaponClass == enLongbow)
    {
        //std::cout << "Weapon class: Longbow \n";
    }
    else if(weaponClass == enUndefinedWeaponClass)
    {
        //std::cout << "Undefined Weapon Class \n";
    }
    else
    {
        //std::cout << "Did not add the condition yet so just printing the int associated with the weapon class enum" << weaponClass;
    }
}




std::string getWeaponClassString(EnumWeaponClass weaponClass)
{
    
    if(weaponClass == enLongSword)
    {
        return "Longsword";
    }
    else if(weaponClass == enDagger)
    {
        return "Dagger";
    }
    else if(weaponClass == enShortSword)
    {
        return "Shortsword";
    }
    else if(weaponClass == enGreatsword)
    {
        return "Greatsword";
    }
    else if(weaponClass == enCrossbow)
    {
        return "Crossbow";
    }
    else if(weaponClass == enLongbow)
    {
        return "Longbow";
    }
    else if(weaponClass == enUndefinedWeaponClass)
    {
        return "Undefined";
    }
    else
    {
        return "N/A";
    }

    
}





