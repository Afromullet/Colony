//
//  Armor.hpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//




#ifndef Armor_hpp
#define Armor_hpp

#include <stdio.h>
#include "Equipment.hpp"
#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include "UtilMacros.h"

class Armor : public Item
{
private:
    friend class Item;
    short int siArmorBonus;
    float fDodgeModifier;
    float fDamageReduction;
    float fMovementModifier;
    

    
  
    
public:
    
    bool operator==(const Armor &other) const;
    bool operator!=(const Armor &other) const;
    void operator=(const Armor &other) ;
    
   
    Armor(Material _material,std::string _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier);

     

    
    Armor(const Armor &other);
    Armor(const Armor *other);
   

    

    Armor();
  //  ~Armor();
   
    

    
    Armor *clone() const
    {
        return new Armor(*this);
    }
    
    
    Armor  *create() const
    {
        return new Armor();
    }
    
    
    
    
    std::string getItemExamineString() const;
    void showItemStats() const;
    void EquipItem(BodyPart &bp);
    
    void PrintArmorStatistics();
    
    void AddToItemManager(ItemManager &manager);

 
    
   
    //int getItemName();
    short int siGetArmorBonus() const ;
    float fGetDodgeModifier() const;
    float fGetDamageReduction() const;
    float fGetMovementModifier() const;
    
    void setArmorBonus(short int value);
    void setDodgeModifier(float value);
    void setDamageReduction(float value);
    void setMovementModifier(float value);
    void setMaterial(Material value);
   
    
    
    
    
    
 
    
    
    
};


extern Armor NO_ARMOR;


#endif /* Armor_hpp */
