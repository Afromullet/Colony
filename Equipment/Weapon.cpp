//
//  Weapon.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Weapon.hpp"

bool Weapon::operator==(const Weapon &other) const
{
    if(siRange == other.siRange && siDamage == other.siDamage)
    {
       
        return true;
    }
    return false;
}

//todo add "Blank" weapon for when no weapon is equipped..and also something to identify a two handed weapon is equipped
Weapon::Weapon(int _material, std::string _sEquipmentName, short int _siRange,short int _siDamage):
        Item::Item(_material,_sEquipmentName),
        siRange(_siRange),siDamage(_siDamage)
{




}


Weapon::Weapon() : Item(-1,"No Weapon"),siRange(-1),siDamage(-1)
{
    
   
   
}


Weapon::Weapon(std::string _itemname,std::string _section) : Item(_itemname,_section) {
    
}



Weapon::Weapon(const Weapon &weapon)
{
  
    position = weapon.position;
   
    sEquipmentName = weapon.sEquipmentName;
    siRange = weapon.siRange;
    siDamage = weapon.siDamage;
 
    
    
}
Weapon::Weapon(Weapon &weapon)
{
 
    position = weapon.position;
 
    sEquipmentName = weapon.sEquipmentName;
    siRange = weapon.siRange;
    siDamage = weapon.siDamage;

}




short int Weapon::getRange(){return siRange;}
short int Weapon::getDamage(){return siDamage;}






std::string Weapon::getItemExamineString()
{
    std::string tempString;
    tempString = "\nItem Name: "  + sEquipmentName;
    tempString = "\Damage: "  + siDamage;
    tempString = "\nRange "  + siRange;
    
    return tempString; 
    
}

void Weapon::setRange(short int value){siRange = value;}
void Weapon::setDamage(short int value){siDamage = value;}
//void Weapon::setItemName(int value){Item::setItemName(value);}
void Weapon::setMaterial(int value){Item::setMaterial(1);}




void Weapon::calculateMaterialBonuses()
{
        
}

void Weapon::CalculateMaterialBonuses()
{
    
}

void Weapon::showItemStats()
{
    
    std::cout << "Item Name" << getItemName()<< "\n";
    std::cout << "Damage" << siDamage << "\n";
    std::cout << "Range" <<  siRange<< "\n";

    
}


