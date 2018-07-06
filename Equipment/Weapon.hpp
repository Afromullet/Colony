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


enum EnWeaponSize{enSmallWeapon,enMediumWeapon,enLargeWeapon};

class Weapon : public Item
{
private:
    friend class Item;
    short int siRange;
    short int siDamage;
    int contactArea;
    bool isTwohanded;
    bool isRanged;
    EnWeaponSize enWeaponSize;
    
    
public:
    
    bool operator==(const Weapon &other) const;
    bool operator!=(const Weapon &other) const;
    void operator=(const Weapon &other);
    
    //todo getters and setters
    Weapon(Material _material, std::string _sEquipmentName, short int _siRange,
   short int _siDamage);
    
    Weapon();
    Weapon(const Weapon &weapon);
    
    
    Weapon(std::string _itemname,std::string _section);
    
   // ~Weapon();
    
    
    //Once you get armor working, implement this just like you did with armor
    Weapon* clone() const
    {
        return new Weapon(*this);
    }
    
    Weapon  *create() const
    {
        return new Weapon();
    }
    
    
    void showItemStats() const;
    std::string getItemExamineString() const;
    
    
    void AddToItemManager(ItemManager &manager);
    
    void EquipItem(BodyPart &bp,ItemManager &itemManager);
    
    
    void calculateMaterialBonuses();
    
    
    short int getRange() const;
    short int getDamage() const;
    float getDamageModifier() const;
    bool isRangedWeapon() const;
    bool hasWeapon() const;
    EnWeaponSize getWeaponSize() const;
    
    void setIsRanged(bool value);
    void setRange(short int value);
    void setDamage(short int value);
    //void setItemName(int value);
    void setMaterial(Material value);
    void setWeaponSize(EnWeaponSize _size);

};



#endif /* Weapon_hpp */
