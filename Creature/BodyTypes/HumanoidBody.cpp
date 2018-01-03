//
//  HumanoidBody.cpp
//  Colony
//
//  Created by Sean on 12/5/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "HumanoidBody.hpp"
#include <typeinfo>

//Set the basic parameters,,.Does not set limb health..when you create a random creature (probably a factory), ensure that you also initialize the paremeters in Body including chest health and such etc todo
HumanoidBody::HumanoidBody()
{
    leftArm.setLimbType(enArmLeft);
    rightArm.setLimbType(enArmRight);
    rightArm.hand.setAppendageType(enHandRight);
    leftArm.hand.setAppendageType(enHandLeft);
}

//Doesn't have an attack bonus yet since that is calculated based on creature attacks
std::list<AttackParameters> HumanoidBody::getAttacks()
{
    std::list<AttackParameters> attackParameters;
    AttackParameters tempAttackParams;
    
    Hand tempHand = rightArm.hand;
    
    tempAttackParams.damage = tempHand.getWeapon().getDamage();
    std::cout << "\nDamage " << tempAttackParams.damage << "\n";
    

    
    
    //Need to handle this another way..Need to figure out why the pointer is not copying correctly into weapon if I use the reference, i,e tempAttackParams.weapon = &tempHand.getWeaponRef();
    tempAttackParams.weapon = tempHand.getWeapon().clone(); //Is this inefficient? The item now exists twice in memory..todo investigate IMPORTANT
    
    std::cout << "\n Ref Damage " << tempAttackParams.weapon->getDamage() << "\n";
    
    //If right hand is unarmed, just use that..For now, two handed weapons are always equipped in the right hand
    
    if(tempHand.getWeapon().getWeaponClass() == enUnarmed)
    {
        attackParameters.push_back(tempAttackParams);
    }
    
    else if(tempHand.getWeapon().getBodyPart() == enFitsOneHand)
    {
        
        attackParameters.push_back(tempAttackParams);
        std::cout << "\n Ref Damage " << tempAttackParams.weapon->getDamage() << "\n";
        std::cout << "\n Ref2 Damage " << attackParameters.front().weapon->getDamage() << "\n";
        
        //Check the other hand
        
        tempHand = leftArm.hand;
        //Only get second attack if there's a weapon in the second hand
        if(tempHand.getWeapon().getWeaponClass() != enUnarmed)
        {
            tempAttackParams.damage = tempHand.getWeapon().getDamage();
            attackParameters.push_back(tempAttackParams);
        }
    }
    else if(tempHand.getWeapon().getBodyPart() == enFitsBothHands)
    {
        attackParameters.push_back(tempAttackParams);
    }
    
    
    std::list<AttackParameters>::iterator atIt;
    std::cout << "\n End Damage " << attackParameters.front().weapon->getDamage() << "\n";
    

    return attackParameters;
    
}

//Just using rand to determne what body part to attack. TODO, choose random body part to attacj a better way than rand()
void HumanoidBody::AttackRandomBodyPart(int attackBonus, int damage)
{
    
 
    switch(rand() % 5)
    {
        case 0:
            if(attackBonus >= leftArm.getArmArmor().siGetArmorBonus())
            {
                leftArm.ApplyDamage(damage);
                SubtractFromTotalHealth(damage);
            }
            break;
        case 1:
            if(attackBonus >= rightArm.getArmArmor().siGetArmorBonus())
            {
                rightArm.ApplyDamage(damage);
                SubtractFromTotalHealth(damage);
            }
            
            break;
        case 2:
            if(attackBonus >= leftLeg.getLegArmor().siGetArmorBonus())
            {
      
                leftLeg.ApplyDamage(damage);
                SubtractFromTotalHealth(damage);
            }
            
            break;
        case 3:
            if(attackBonus >= rightLeg.getLegArmor().siGetArmorBonus())
            {
                rightLeg.ApplyDamage(damage);
                SubtractFromTotalHealth(damage);
            }
            
            break;
        case 4:
            if(attackBonus >= getHead().getHeadArmor().siGetArmorBonus())
            {
                getHead().damageHead(damage);
                SubtractFromTotalHealth(damage);
            
            }
            break;
        case 5:
            if(attackBonus >= getChest().getChestArmor().siGetArmorBonus())
            {
                getChest().damageChest(damage);
                SubtractFromTotalHealth(damage);
            }
            
            break;
    
    }
        
}

 void HumanoidBody::CalculateHealth()
{
    int totalHealth = leftArm.getLimbHealth() + rightArm.getLimbHealth() + leftLeg.getLimbHealth() + rightLeg.getLimbHealth() + getHead().getHeadHealth() + getChest().getChestHealth();
    setTotalHealth(totalHealth);
}

//Automatically choses the slot the item fits in.
//Much easier to do that way, than allowing the player to choose which slot to equip it in and then checking if it is a valid slot.


//TODO, unequip item if it was stored in the equipped slot and set values accordingly
//i.e, setisequipped of that item
void HumanoidBody::EquipItem(Item *item)
{
    if(item->getItemType() == enArmorType)
    {
        Armor *arm = dynamic_cast<Armor*>(item);

        
        switch(arm->getBodyPart())
        {
            case enHeadBodyPart:
                head.setHeadArmor(*arm);
               // arm->setIsEquipped(true);
                break;
            case enChestBodyPart:
                //chest.getChestArmor().setIsEquipped(false);
                chest.setChestArmor(*arm);
                //arm->setIsEquipped(true);
                break;
            case enLegsBodyPart:
                leftLeg.setLegArmor(*arm);
                rightLeg.setLegArmor(*arm);
                //arm->setIsEquipped(true);
                break;
            case enHandsBodyPart:
                leftArm.setHandArmor(*arm);
                rightArm.setHandArmor(*arm);
                //arm->setIsEquipped(true);
                break;
            case enFeetBodyPart:
                leftLeg.setFootArmor(*arm);
                rightLeg.setFootArmor(*arm);
                //arm->setIsEquipped(true);
                break;
        }
        
        
    }
    else if(item->getItemType() == enWeaponType)
    {
        Weapon *wep = dynamic_cast<Weapon*>(item);
        //If weapon is two handed, set fist weapon in other hand
        switch(wep->getBodyPart())
        {
            case enFitsOneHand:
                rightArm.hand.setWeapon(*wep);
                leftArm.hand.setWeapon(FIST_WEAPON);
                wep->setIsEquipped(true);
                break;
            case enFitsBothHands:
                rightArm.hand.setWeapon(*wep);
                leftArm.hand.setWeapon(FIST_WEAPON);
                wep->setIsEquipped(true);
                break;
        }
        
    }
       //std::shared_ptr<Armor> der = static_pointer_cast(Item>);
    //rightLeg.setLegArmor(item);
    std::cout << "\nName: " << chest.getChestArmor().getItemName() << "\n";

 
    
}

void HumanoidBody::PrintEquippedItems()
{
    
    std::cout << "Head Armor " << getHead().getHeadArmor().getItemName() <<  "\n";
    std::cout << "Chest Armor " << getChest().getChestArmor().getItemName() << "\n";
    std::cout << "Leg Armor " << leftLeg.getLegArmor().getItemName() << "\n";
    std::cout << "Hand Armor " << leftArm.getHandArmor().getItemName() << "n";
    std::cout << "Foot Armor " << leftLeg.getFootArmor().getItemName() << "\n";
    std::cout << "Weapon " << rightArm.hand.getWeapon().getItemName() << "\n";

    

    
}