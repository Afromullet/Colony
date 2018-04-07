//
//  Armor.hpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include <stdio.h>
#include "Equipment.hpp"


#ifndef Armor_hpp
#define Armor_hpp




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
    
    Armor(Material _material,std::string _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier);

     Armor(std::string itemName);
    Armor(std::string itemName, std::string _section);
    
    Armor(const Armor &armor);
    Armor(Armor &armor);
    
    Armor();
    
    
    Armor *clone() const
    {
        return new Armor(*this);
    }
    
    Armor  *create() const
    {
        return new Armor();
    }
    

    
    /*
    virtual Armor* clone() const
    {
        return new Armor(*this);
    }
     */
   
  
    
   
    //int getItemName();
    short int siGetArmorBonus();
    float fGetDodgeModifier();
    float fGetDamageReduction();
    float fGetMovementModifier();

  
    std::string getItemExamineString();
    

    
    void setArmorBonus(short int value);
    void setDodgeModifier(float value);
    void setDamageReduction(float value);
    void setMovementModifier(float value);
    void calculateMaterialBonuses();
    
    //void setItemName(int value);
    void setMaterial(Material value);
   

    
    void PrintArmorStatistics();
    void showItemStats();
    
    
    
 
    
    
    
};



#endif /* Armor_hpp */
