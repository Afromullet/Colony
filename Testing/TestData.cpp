//
//  TestData.cpp
//  Colony
//
//  Created by Sean on 9/3/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "TestData.hpp"
#include <cstdlib>

#ifdef DEBUG_OUTPUT
#include <fstream>
#include <iostream>
#endif

/*
 Todo, do better random generation
 Replace iterators with .size()
 
 
 */

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

Weapon generateRandomWeapon()
{
    short int randWeaponClass = rand() % 6;
    Weapon weapon(randBonus(),enOneHanded,randBonus(),1,randBonus(),enUndefinedWeaponClass);
       
    
    if(randWeaponClass == 0)
    {
        weapon.setWeaponClass(enDagger);
    
        
    }
    else if(randWeaponClass == 1)
    {
        weapon.setWeaponClass(enShortSword);
        
    }
    else if(randWeaponClass == 2)
    {
        weapon.setWeaponClass(enLongSword);
        
    }
    else if(randWeaponClass == 3)
    {
        weapon.setWeaponClass(enGreatsword);
        weapon.setFitsBodyPart(enTwoHanded);
        
    }
    else if(randWeaponClass == 4)
    {
        weapon.setWeaponClass(enLongbow);
        weapon.setFitsBodyPart(enTwoHanded);
        weapon.setRange(randRangeWeaponRange());

    }
    else if(randWeaponClass == 5)
    {
        weapon.setWeaponClass(enCrossbow);
        weapon.setFitsBodyPart(enTwoHanded);
        weapon.setRange(randRangeWeaponRange());
    }
 
    
    return weapon;
    
    
    
}

Armor GenerateArmor(EnumFitsBodyPart bodyPart)
{
    
    //Worry about generating random floats for the float params later. Not needed riht now
    Armor armor(randBonus(),randBonus(),randBonus(),randBonus(),randBonus(),randBonus(),randArmorClass());
    if(bodyPart == enChest)
    {
        armor.setFitsBodyPart(enChest);
    }
    else if(bodyPart == enHead)
    {
        armor.setFitsBodyPart(enHead);
        
    }
    else if(bodyPart == enFeet)
    {
        armor.setFitsBodyPart(enFeet);
    }
    else if(bodyPart == enHands)
    {
        armor.setFitsBodyPart(enHands);
    }
    else if(bodyPart == enLegs)
    {
        armor.setFitsBodyPart(enLegs);
    }
    
    return armor;
}

Chest generateChest()
{
    return Chest(randBonus());
}

Head generateHead()
{
    return Head(randBonus());
}

void printFitsBodypart(EnumFitsBodyPart enFitsBodyPart)
{
    if(enFitsBodyPart == enChest)
    {
        //std::cout << "Fits" << "Chest" << "\n";
    }
    else if(enFitsBodyPart == enHead)
    {
        //std::cout << "Fits" << "Head" << "\n";
        
    }
    else if(enFitsBodyPart == enFeet)
    {
        //std::cout << "Fits" << "Feet" << "\n";
    }
    else if(enFitsBodyPart == enHands)
    {
        //std::cout << "Fits" << "Hands" << "\n";
    }
    else if(enFitsBodyPart == enLegs)
    {
        //std::cout << "Fits" << "Legs" << "\n";
    }
    else if(enFitsBodyPart == enTwoHanded)
    {
        //std::cout << "Fits Two handed\n";
    }
    else if(enFitsBodyPart == enOneHanded)
    {
        //std::cout << "Fits one handed\n";
    }
    else if(enFitsBodyPart == enUndefinedBodyPart)
    {
        //std::cout << "Fits undefined body part\n";
    }
    else
    {
        //std::cout << "Did not add the condition yet so just printing the int associated with the fits body part enum" << enFitsBodyPart;
    }
    
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

std::string getFitsBodyPartString(EnumFitsBodyPart enFitsBodyPart)
{
    if(enFitsBodyPart == enChest)
    {
        return "Chest";
        
    }
    else if(enFitsBodyPart == enHead)
    {
        return "Head";
        
    }
    else if(enFitsBodyPart == enFeet)
    {
        return "Feet";
    }
    else if(enFitsBodyPart == enHands)
    {
        return "Hands";
    }
    else if(enFitsBodyPart == enLegs)
    {
        return "Legs";
    }
    else if(enFitsBodyPart == enUndefinedBodyPart)
    {
        return "Undefined Body Part";
    }
    else if(enFitsBodyPart == enTwoHanded)
    {
        return "Two handed";
    }
    else if(enFitsBodyPart == enOneHanded)
    {
        return "One handed";
    }
    else
    {
        return "N/A";
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





