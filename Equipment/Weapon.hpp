//
//  Weapon.hpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include <stdio.h>
#include "Equipment.hpp"
#include "Throwable.hpp"

#ifndef Weapon_hpp
#define Weapon_hpp





class Weapon : public Item, public Throwable
{
private:
    friend class Item;
    short int siRange;
    short int siDamage;
    EnumWeaponClass enWeaponClass;
    
    
public:
    
    bool operator==(const Weapon &other) const;
    
    //todo getters and setters
    Weapon(int _material,EnumBodyPart _enFitsBodyPart, std::string _sEquipmentName, short int _siRange,
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
    

    

    
    void calculateMaterialBonuses();
    
    short int getRange();
    short int getDamage();
    float getDamageModifier();
    EnumBodyPart getBodyPart();
    EnumWeaponClass getWeaponClass();
    EnumBonusType getAttackBonusType();
    bool isRangedWeapon();
    std::string getItemExamineString();
    
    

    //EnumBodyParts getBodyPart();
    
    
   
    
    void setRange(short int value);
    void setDamage(short int value);
    //void setItemName(int value);
    void setMaterial(int value);
    void setFitsBodyPart(EnumBodyPart value);
    void setWeaponClass(EnumWeaponClass weaponClass);
    void CalculateMaterialBonuses();
    void showItemStats();
    
    
    bool hasWeapon();
    
    
    
    
   
    void operator = (const Weapon &weapon ) {
        siRange = weapon.siRange;
        siDamage = weapon.siDamage;
        enWeaponClass = weapon.enWeaponClass;
     
        material = weapon.material;
        enFitsBodyPart = weapon.enFitsBodyPart;
        enItemType = weapon.enItemType;
        sEquipmentName = weapon.sEquipmentName;
        position = weapon.position;
        //inches = D.inches;
    }
    
    
    
    
    
};



#endif /* Weapon_hpp */
