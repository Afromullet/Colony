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
    friend class Item;
    short int siRange;
    short int siDamage;
    EnumWeaponClass enWeaponClass;
    
    
public:
    //todo getters and setters
    Weapon(int _material,EnumBodyPart _enFitsBodyPart, int _sEquipmentName, short int _siRange,
   short int _siDamage,EnumWeaponClass _enWeaponClass);
    Weapon();
    
    Weapon(const Weapon &weapon);
    Weapon(Weapon &weapon);

    
    //Once you get armor working, implement this just like you did with armor
    Weapon* clone() const
    {
        return new Weapon(*this);
    }
    
    Weapon  *create() const
    {
        return new Weapon();
    }
    

    
    /*
    virtual Weapon* clone() const
    {
        return new Weapon(*this);
    }
    */
    //int getItemName();
    
    void calculateMaterialBonuses();
    
    short int getRange();
    short int getDamage();
    float getDamageModifier();
    EnumBodyPart getBodyPart();
    EnumWeaponClass getWeaponClass();
    EnumBonusType getAttackBonusType();


    //EnumBodyParts getBodyPart();
    
    
   
    
    void setRange(short int value);
    void setDamage(short int value);
    //void setItemName(int value);
    void setMaterial(int value);
    void setFitsBodyPart(EnumBodyPart value);
    void setWeaponClass(EnumWeaponClass weaponClass);
    void CalculateMaterialBonuses();
    void showItemStats();
    
    
    
   
    
    
    
    
    
};

#endif /* Weapon_hpp */
