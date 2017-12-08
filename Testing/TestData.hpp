//
//  TestData.hpp
//  Colony
//
//  Created by Sean on 9/3/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef TestData_hpp
#define TestData_hpp


#

#include <stdio.h>


#include <iostream>

#include <vector>
#include "Chest.hpp"
#include "Head.hpp"







//extern Weapon weapon1;



short int randBonus();
short int randRangeWeaponRange();

Armor GenerateArmor(EnumFitsBodyPart bodyPart);

Chest generateChest();
Head generateHead();
Weapon generateRandomWeapon();
EnumWeaponClass randomWeaponClass();

EnumArmorClass randArmorClass();


void printFitsBodypart(EnumFitsBodyPart enFitsBodyPart);
void printWeaponClass(EnumWeaponClass weaponClass);
std::string getFitsBodyPartString(EnumFitsBodyPart enFitsBodyPart);
std::string getWeaponClassString(EnumWeaponClass weaponClass);







#endif /* TestData_hpp */
