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

class Armor : public Item
{
private:
    short int siArmorBonus;
    float fDodgeModifier;
    float fDamageReduction;
    float fMovementModifier;
    EnumArmorClass enArmorClass;
    
public:
    Armor(int _material, EnumFitsBodyPart _enFitsBodyPart, int _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier,EnumArmorClass _enArmorClas);
    Armor(int _material,int _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier,EnumArmorClass _enArmorClas);
    
    Armor();
    
    /*
    virtual Armor* clone() const
    {
        return new Armor(*this);
    }
     */
   
  
    
   
    int getItemName();
    short int siGetArmorBonus();
    float fGetDodgeModifier();
    float fGetDamageReduction();
    float fGetMovementModifier();
    EnumFitsBodyPart getBodyPart();
    EnumArmorClass getArmorClass();

    

    
    void setArmorBonus(short int value);
    void setDodgeModifier(float value);
    void setDamageReduction(float value);
    void setMovementModifier(float value);
    void calculateMaterialBonuses();
    
    void setItemName(int value);
    void setMaterial(int value);
    void setFitsBodyPart(EnumFitsBodyPart value);
    void CalculateMaterialBonuses();
    
    
    
 
    
    
    
};

#endif /* Armor_hpp */
