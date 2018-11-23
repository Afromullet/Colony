//
//  BodyPart.hpp
//  Colony
//
//  Created by Sean on 1/3/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include <stdio.h>


#ifndef BodyPart_hpp
#define BodyPart_hpp

#include "Equipment.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"

#include "EnumTypes.hpp"
#include <string>
#include <vector>
#include "Tissue.hpp"
#include "ItemManager.hpp"
#include "Globals.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "BodyDefs.h"


#define ARM_STRING "arm"
#define LEG_STRING "leg"
#define FOOT_STRING "foot"
#define HAND_STRING "hand"

#define INVALID_BODY_PART "Invalid Body Part";


/*
 
 This is a generic class for a body part. Rather than breaking down the body part into separate clases,
 this class represents any sort of body part. The type of body part is determined by the bodyPartName string and the enBodyPartType enum
 

 
 
 */

//TODO, whatever can be private, make private


#define BP_BOOL_VALUES 8
#define BP_INT_VALUES 2
#define BP_STRING_VALUES 2
#define BP_FLOAT_VALUES 1
#define BP_ARMOR_VALUES 1
#define BP_WEAPON_VALUES 1

#define LOW_WOUND_LEVEL 10
#define MODERATE_WOUND_LEVEL 30
#define MAJOR_WOUND_LEVEL 50

#define LOW_PAIN 1
#define MODERATE_PAIN 2
#define HIGH_PAIN 3

#define LOW_BLEEDING_RATE 1
#define MODERATE_BLEEDING_RATE 2
#define HIGH_BLEEDING_RATE 3





class BodyPart
{
    
private:
    
    int id;
    int health;
    std::string bodyPartToken;
    std::string section;
    bool canHoldWeapon;
    bool canHoldArmor;
    bool canInteract;
    bool canMoveCreature; //Determines whether this part can be used for locomotion
    bool canSee;
    bool canSmell;
    bool canBreathe;
    bool isInternal;
    bool isOrgan;
    float fractureLevel; //Determines the severity of the fracture
    float bruiseLevel;
    float cutLevel;
    float piercedLevel;
    float bleedingRate;
    float painLevel;
    bool isRuptured;
    
    float relativeSize; //How large this part is in relation to the whole body. A percent..I.E, .53 is 53%
    
   
    std::vector<WoundType> wounds;
    std::vector<Tissue> tissues;
    std::string bodyPartName;
    Armor armor;
    Weapon weapon;
    
public:
    
    
    friend std::ostream& operator<<(std::ostream& os, const BodyPart& bp);
    
    //TODO make data fields private
    
    bool operator==(BodyPart &other) const;
    bool operator!=(BodyPart &other) const;
    void operator=(const BodyPart &other);
                    
    
    BodyPart();
    BodyPart(bool _canHoldWeapon, bool _canHoldArmor, bool _canInteract, bool _canMoveCreature,std::string _bodyPartName, int _health);
    BodyPart(std::string bptoken,std::string bpname);
    BodyPart(const BodyPart &other);
  
    //Use a tree to represent body parts..Well, do that later, when we want to describe a hieracy of what body part is connected to what
    //Don't want a separate class for body parts that can equip weapons and armor, so just fill the data as determined
    //by the canHoldWeapon and canHoldArmor. The additional space used by Armor and Weapon for every creature that may not even be able to use them is worth managing everything more easily
    
   
    void EquipArmor(Item *item);
    void EquipArmor(Armor val);
    
    void EquipWeapon(Item *item);

    std::vector<AppliedForceEffect> ApplyAttack(AttackStats params);
    void ApplyDamage(int damage);
    void ShowWounds();
    void ClearWounds();

    void setArmor(Armor val) ;
    void setWeapon(Weapon val) ;
    void setHealth(int val) ;
    void setArmorMaterialEffects(AppliedForceEffect val);
    void setHasWeapon(bool val);
    void setID(int val) ;
    void setBodyPartToken(std::string val) ;
    void setSection(std::string val) ;
    void setCanHoldWeapon(bool val) ;
    void setCanHoldArmor(bool val) ;
    void setCanInteract(bool val) ;
    void setCanMoveCreature(bool val) ;
    void setCanSee(bool val) ;
    void setCanSmell(bool val) ;
    void setCanBreathe(bool val);
    void setIsInternal(bool val) ;
    void setRelativeSize(float val) ;
    void setBodyPartName(std::string val) ;
    void increaseFractureLevel(float level);
    void increaseBruiseLevel(float level);
    void increaseCutLevel(float level);
    void increasePiercedLevel(float level);
    void setIsRuptured(bool val);
    void setIsOrgan(bool val);
    
    Armor getArmor() const;
    Weapon getWeapon() const;
    Armor &getArmorRef();
    Weapon &getWeaponRef();
    
    int getHealth() const;
    std::vector<AppliedForceEffect> &getArmorMaterialEffects();
    float getBodyPartSize(float totalBodySize) const; //Not sure why I pass the totalbodysize here, will keep it like that for now
    bool hasWeapon() const;
    int getID() const;
    std::string getBodyPartToken() const;
    std::string getSection() const;
    bool getCanHoldWeapon() const;
    bool getCanHoldArmor() const;
    bool getCanInteract() const;
    bool getCanMoveCreature() const;
    bool getCanSee() const;
    bool getCanSmell() const;
    bool getCanBreathe()const;
    bool getIsInternal() const;
    float getRelativeSize() const;
    std::string getBodyPartName() const;
    std::vector<WoundType> getWounds() const;
    std::vector<WoundType> &getWoundsRef() ;
    float getPainLevel();
    float getBleedingRate();
    bool getIsOrgan();
    
    void AddWound(WoundType woundType);
    
    
    void DetermineEffects(BodyPropertyTable &bpState);
    void DetermineFractureEffects(BodyPropertyTable &bpState);
    void DetermineCutEffects(BodyPropertyTable &bpState);
    void DeterminePiercedEffects(BodyPropertyTable &bpState);
    void DetermineBruiseEffects(BodyPropertyTable &bpState);
    void DetermineRupturedEffects(BodyPropertyTable &bpState);
    
    
    
    
   
    
    
};




void InitializeGlobalBodyParts();

#endif /* BodyPart_hpp */
