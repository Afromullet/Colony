//
//  BodyPart.cpp
//  Colony
//
//  Created by Sean on 1/3/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "BodyPart.hpp"

//Read these from a file later and store in a vector of strings
//That way it can be customized easily by reading from files









std::ostream& operator<<(std::ostream& os, const BodyPart& bp)
{
    /*
    os << "\nBodypart Name " << bp.bodyPartName << "\nHealth " << bp.health << "\nCan Hold Armor " << bp.canHoldArmor << "\nCan Hold Weapon " << bp.canHoldWeapon << "\nCan Interact " << bp.canInteract << "\nArmor Name " << bp.armor.sEquipmentName << "\nCan Breathe " << bp.canBreathe << "\nCan See " << bp.canSee << "\n Can smell " << bp.canSmell << "\n Token " << bp.bodyPartToken << "\n Section " << bp.section << "\nWeapon Name " << bp.weapon.sEquipmentName  << "\n\n";
     */
    return os;
    
}



bool BodyPart::operator==(BodyPart &other) const
{
    if(id == other.id && health == other.health && bodyPartToken == other.bodyPartToken && section == other.section && canHoldWeapon == other.canHoldWeapon && canHoldArmor == other.canHoldArmor && canInteract == other.canInteract)
    {
        if(canMoveCreature == other.canMoveCreature && canSee == other.canSee && canSmell == other.canSmell && canBreathe == other.canBreathe && isInternal == other.isInternal)
            
        {
            if(relativeSize == other.relativeSize && tissues == other.tissues && bodyPartName == other.bodyPartName && wounds == other.wounds && armor == other.armor && weapon == other.weapon && fractureLevel == other.fractureLevel && bruiseLevel == other.bruiseLevel && cutLevel == other.cutLevel && piercedLevel == other.piercedLevel)
            {
                return true;
            }
        }
    }
}


bool BodyPart::operator!=(BodyPart &other) const
{
    return !(*this == other);
}


void BodyPart::operator=(const BodyPart &other)
{
    id = other.id;
    health = other.health;
    bodyPartToken = other.bodyPartToken;
    section = other.section;
    canHoldWeapon = other.canHoldWeapon;
    canHoldArmor = other.canHoldArmor;
    canInteract = other.canInteract;
    canMoveCreature = other.canMoveCreature;
    canSee = other.canSee;
    canSmell = other.canSmell;
    canBreathe = other.canBreathe;
    isInternal = other.isInternal;
    
    relativeSize = other.relativeSize;
    tissues = other.tissues;
    bodyPartName = other.bodyPartName;
    wounds = other.wounds;
    armor = other.armor;
    weapon = other.weapon;
    fractureLevel = other.fractureLevel;
    bruiseLevel = other.bruiseLevel;
    cutLevel = other.cutLevel;
    piercedLevel = other.piercedLevel;
 
}
 

BodyPart::BodyPart() : armor(NO_ARMOR),weapon(NO_WEAPON)
{
    canHoldArmor = true;
    canHoldWeapon = true;

    health = 1;
    id = -1;
    
    bodyPartName = INVALID_BODY_PART;
}

BodyPart::BodyPart(bool _canHoldWeapon, bool _canHoldArmor, bool _canInteract, bool _canMoveCreature,std::string _bodyPartName, int _health) : canHoldArmor(_canHoldArmor),canHoldWeapon(_canHoldWeapon),armor(NO_ARMOR),weapon(NO_WEAPON),health(1), bodyPartName(_bodyPartName)
{
    fractureLevel = 0;
    bruiseLevel = 0;
    cutLevel = 0;
    piercedLevel = 0;
}



BodyPart::BodyPart(std::string bptoken,std::string bpname) : bodyPartToken(bptoken),bodyPartName(bpname)
{
    health = 10;
    fractureLevel = 0;
    bruiseLevel = 0;
    cutLevel = 0;
    piercedLevel = 0;
}



BodyPart::BodyPart(const BodyPart& other)
{
    id = other.id;
    health = other.health;
    bodyPartToken = other.bodyPartToken;
    section = other.section;
    canHoldWeapon = other.canHoldWeapon;
    canHoldArmor = other.canHoldArmor;
    canInteract = other.canInteract;
    canMoveCreature = other.canMoveCreature;
    canSee = other.canSee;
    canSmell = other.canSmell;
    canBreathe = other.canBreathe;
    isInternal = other.isInternal;
    
    
    relativeSize = other.relativeSize;
    tissues = other.tissues;
    bodyPartName = other.bodyPartName;
    wounds = other.wounds;
    armor = other.armor;
    weapon = other.weapon;
    fractureLevel = other.fractureLevel;
    bruiseLevel = other.bruiseLevel;
    cutLevel = other.cutLevel;
    piercedLevel = other.piercedLevel;
    
   
    
}

void BodyPart::EquipArmor(Armor val)
{
    if(armor.isValidSection(section))
    {
        if(canHoldArmor)
            
            //if(item->getItemType() == enArmorType && canHoldArmor)
        {
            val.setIsEquipped(true);
            
            armor = val;
            std::cout << "\n Equipped";
            
            std::cout << "\n Equipment Name " << armor.getItemName();
        }
        
    }
}


void BodyPart::EquipArmor(Item *item)
{
    
    if(item->isValidSection(section))
    {
        if(canHoldArmor)

        //if(item->getItemType() == enArmorType && canHoldArmor)
        {
            Armor *arm = dynamic_cast<Armor*>(item);
            arm->setIsEquipped(true);
            armor = *arm;
            std::cout << "\n Equipped";
            
            std::cout << "\n Equipment Name " << armor.getItemName();
        }
        
    }
}

void BodyPart::EquipWeapon(Item *item)
{
    Weapon *wep = dynamic_cast<Weapon*>(item);
  //  std::cout << "\n Damage and range " << wep->getDamage() << ", " << wep->isRangedWeapon();
    wep->setIsEquipped(true);
    weapon = *wep;
    
  //  std::cout << "\n Damage and range " << weapon.getDamage() << ", " << weapon.isRangedWeapon();
    

}


void BodyPart::ApplyDamage(int damage)
{
    health -= damage;
}

//Applies an attack to this body part
std::vector<AppliedForceEffect> BodyPart::ApplyAttack(AttackStats params)
{
    
    std::vector<AppliedForceEffect> effects;
    armor.getMaterialRef().PerformMaterialCalculations(params.force,params.contactArea,params.enAttackForceType,params.attackType);
    effects = getArmorMaterialEffects();
    
    return effects;
    
    
}

void BodyPart::ShowWounds()
{
    std::cout << "Body Part Name: " << bodyPartName << std::endl;
    for(int i =0; i < wounds.size(); i++)
    {
        std::cout << wounds.at(i) << std::endl;
    }
}

void BodyPart::ClearWounds()
{
    wounds.clear();
}


void BodyPart::setArmor(Armor val)
{
    armor = val;
}

void BodyPart::setWeapon(Weapon val)
{
    weapon = val;
}

void BodyPart::setHealth(int val)
{
    health = val;
}

void BodyPart::setArmorMaterialEffects(AppliedForceEffect val)
{
    
}

void BodyPart::setHasWeapon(bool val)
{
    //hasWeapon = val;
}

void BodyPart::setID(int val)
{
    id = val;
}

void BodyPart::setBodyPartToken(std::string val)
{
    bodyPartToken = val;
}

void BodyPart::setSection(std::string val)
{
    section = val;
}

void BodyPart::setCanHoldWeapon(bool val)
{
    canHoldWeapon = val;
}

void BodyPart::setCanHoldArmor(bool val)
{
    canHoldArmor = val;
}

void BodyPart::setCanInteract(bool val)
{
    canInteract = val;
}

void BodyPart::setCanMoveCreature(bool val)
{
    canMoveCreature = val;
}

void BodyPart::setCanSee(bool val)
{
    canSee = val;
}

void BodyPart::setCanSmell(bool val)
{
    canSmell = val;
}

void BodyPart::setCanBreathe(bool val)
{
    canBreathe = val;
}

void BodyPart::setIsInternal(bool val)
{
    isInternal = val;
}

void BodyPart::setRelativeSize(float val)
{
    if(relativeSize < 0)
        return;
    relativeSize = val;
}

void BodyPart::setBodyPartName(std::string val)
{
    bodyPartName = val;
}

void BodyPart::increaseFractureLevel(float level)
{
    fractureLevel += level;
}

void BodyPart::increaseBruiseLevel(float level)
{
    bruiseLevel += level;
}

void BodyPart::increaseCutLevel(float level)
{
    cutLevel += level;
}

void BodyPart::increasePiercedLevel(float level)
{
    piercedLevel += level;
}

void BodyPart::setIsRuptured(bool val)
{
    isRuptured = val;
}




int BodyPart::getHealth() const
{
    return health;
}


Armor BodyPart::getArmor() const
{
    return armor;
}

Weapon BodyPart::getWeapon() const
{
    return weapon;
}

Armor& BodyPart::getArmorRef()
{
    return armor;
}


Weapon& BodyPart::getWeaponRef()
{
    return weapon;
}

std::vector<AppliedForceEffect>& BodyPart::getArmorMaterialEffects()
{
    return armor.getMaterialRef().getAppliedForceEffects();
}

//Calculates the body parts size in units based on the total size passed as a parameter. RelativeSize is a percent
float BodyPart::getBodyPartSize(float totalBodySize) const
{
    return totalBodySize * relativeSize;
}


bool BodyPart::hasWeapon() const
{
    
    //return true;
}


int BodyPart::getID() const
{
    return id;
}

std::string BodyPart::getBodyPartToken() const
{
    return bodyPartToken;
}

std::string BodyPart::getSection() const
{
    return section;
}

bool BodyPart::getCanHoldWeapon() const
{
    return canHoldWeapon;
    
}

bool BodyPart::getCanHoldArmor() const
{
    return canHoldArmor;
}

bool BodyPart::getCanInteract() const
{
    return canInteract;
}

bool BodyPart::getCanMoveCreature() const
{
    return canMoveCreature;
}

bool BodyPart::getCanSee() const
{
    return canSee;
}

bool BodyPart::getCanBreathe()const
{
    return canBreathe;
}

bool BodyPart::getCanSmell() const
{
    return canSmell;
}

bool BodyPart::getIsInternal() const
{
    return isInternal;
}

float BodyPart::getRelativeSize() const
{
    return relativeSize;
}

std::string BodyPart::getBodyPartName() const
{
    return bodyPartName;
}


std::vector<WoundType> BodyPart::getWounds() const
{
    return wounds;
}

std::vector<WoundType>& BodyPart::getWoundsRef() 
{
    return wounds;
}

void BodyPart::AddWound(WoundType woundType)
{
    wounds.push_back(woundType);
}



