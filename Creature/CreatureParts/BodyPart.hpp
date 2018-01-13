//
//  BodyPart.hpp
//  Colony
//
//  Created by Sean on 1/3/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef BodyPart_hpp
#define BodyPart_hpp

#include <stdio.h>
#include "Weapon.hpp"
#include "Armor.hpp"

#include "EnumTypes.hpp"
#include <string>
#include <vector>
#





/*
 
 This is a generic class for a body part. Rather than breaking down the body part into separate clases,
 this class represents any sort of body part. The type of body part is determined by the bodyPartName string and the enBodyPartType enum
 

 
 
 */
class BodyPart
{
    
private:
    
    
public:
    
    //TODO make data fields private
    int health;
    bool canHoldWeapon;
    bool canHoldArmor;
    bool canInteract;
    bool canMoveCreature; //Determines whether this part can be used for locomotion
    std::string bodyPartName;
    
    BodyPart(EnumBodyPart _bodypartType,bool _canHoldWeapon, bool _canHoldArmor, bool _canInteract, bool _canMoveCreature,std::string _bodyPartName, int _health);
    
    BodyPart(bool _canHoldWeapon, bool _canHoldArmor, bool _canInteract, bool _canMoveCreature,std::string _bodyPartName, int _health);
    
    BodyPart(const BodyPart &bp);
  
    //Use a tree to represent body parts..Well, do that later, when we want to describe a hieracy of what body part is connected to what

    Armor armor;
    Weapon weapon;
    EnumBodyPart enBodyPartType;
    
    //Don't want a separate class for body parts that can equip weapons and armor, so just fill the data as determined
    //by the canHoldWeapon and canHoldArmor. The additional space used by Armor and Weapon for every creature that may not even be able to use them is worth managing everything more easily
    
    void EquipItem(Item *item);

    void setBodyPartType(EnumBodyPart _bodyPartType);
    Armor getArmor();
    Weapon getWeapon();
    
    int getHealth();
    
    void ApplyDamage(int damage);
    
    
    
};




void InitializeGlobalBodyParts();

#endif /* BodyPart_hpp */
