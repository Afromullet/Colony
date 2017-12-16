//
//  Weapon.hpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include <stdio.h>
#include "Equipment.hpp"


class Weapon : public Item
{
private:
    short int siRange;
    short int siDamage;
    EnumWeaponClass enWeaponClass;
    
    
public:
    //todo getters and setters
    Weapon(int _material,EnumFitsBodyPart _enFitsBodyPart, int _sEquipmentName, short int _siRange,
   short int _siDamage,EnumWeaponClass _enWeaponClass);
    Weapon();
    
    int getItemName();
    
    void calculateMaterialBonuses();
    
    short int getRange();
    short int getDamage();
    float getDamageModifier();
    EnumFitsBodyPart getBodyPart();
    EnumWeaponClass getWeaponClass();
    EnumBonusType getAttackBonusType();


    //EnumBodyParts getBodyPart();
    
    
   
    
    void setRange(short int value);
    void setDamage(short int value);
    void setItemName(int value);
    void setMaterial(int value);
    void setFitsBodyPart(EnumFitsBodyPart value);
    void setWeaponClass(EnumWeaponClass weaponClass);
    
    
    
    
    
};

#endif /* Weapon_hpp */
