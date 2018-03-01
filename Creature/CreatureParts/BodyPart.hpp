//
//  BodyPart.hpp
//  Colony
//
//  Created by Sean on 1/3/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include <stdio.h>
#include "Weapon.hpp"
#include "Armor.hpp"

#include "EnumTypes.hpp"
#include <string>
#include <vector>


#ifndef BodyPart_hpp
#define BodyPart_hpp


#define ARM_STRING "arm"
#define LEG_STRING "leg"
#define FOOT_STRING "foot"
#define HAND_STRING "hand"





/*
 
 This is a generic class for a body part. Rather than breaking down the body part into separate clases,
 this class represents any sort of body part. The type of body part is determined by the bodyPartName string and the enBodyPartType enum
 

 
 
 */

//TODO, whatever can be private, make private
class BodyPart
{
    
private:
    
    
public:
    
    
    friend std::ostream& operator<<(std::ostream& os, const BodyPart& bp);
    
    //TODO make data fields private
    int id;
    int health;
    bool canHoldWeapon;
    bool canHoldArmor;
    bool canInteract;
    bool canMoveCreature; //Determines whether this part can be used for locomotion
    std::string bodyPartName;
    BodyPart();
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
    
    void EquipArmor(Item *item);

    void setBodyPartType(EnumBodyPart _bodyPartType);
    Armor getArmor();
    Weapon getWeapon();
    
    int getHealth();
    
    void ApplyDamage(int damage);
    
    bool hasWeapon();
    
    
    
};




void InitializeGlobalBodyParts();

#endif /* BodyPart_hpp */
