//
//  HumanoidBody.cpp
//  Colony
//
//  Created by Sean on 12/5/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "HumanoidBody.hpp"

HumanoidBody::HumanoidBody()
{
    leftArm.setLimbType(enArmLeft);
    rightArm.setLimbType(enArmRight);
    rightArm.hand.setAppendageType(enHandRight);
    leftArm.hand.setAppendageType(enHandLeft);
    
    
    
    
}

void HumanoidBody::AttackRandomBodyPart(int attackBonus, int damage)
{
    
    std::cout << "attack\n";
    
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
    
    std::cout << "Total Health left: " << getTotalHealth() << "\n";

    
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
            case enHead:
                head.setHeadArmor(*arm);
                arm->setIsEquipped(true);
                break;
            case enChest:
                chest.setChestArmor(*arm);
                arm->setIsEquipped(true);
                break;
            case enArms:
                leftArm.setArmArmor(*arm);
                rightArm.setArmArmor(*arm);
                arm->setIsEquipped(true);
                break;
            case enLegs:
                leftLeg.setLegArmor(*arm);
                rightLeg.setLegArmor(*arm);
                arm->setIsEquipped(true);
                break;
            case enHands:
                leftArm.setHandArmor(*arm);
                rightArm.setHandArmor(*arm);
                arm->setIsEquipped(true);
                break;
            case enFeet:
                leftLeg.setFootArmor(*arm);
                rightLeg.setFootArmor(*arm);
                arm->setIsEquipped(true);
                break;
        }
        
        
    }
    else if(item->getItemType() == enWeaponType)
    {
        Weapon *wep = dynamic_cast<Weapon*>(item);
        //If weapon is two handed, need a way to identify in the second hand that the equipped weapon is two handed todo
        switch(wep->getBodyPart())
        {
            case enOneHanded:
                rightArm.hand.setWeapon(*wep);
                wep->setIsEquipped(true);
                break;
            case enTwoHanded:
                rightArm.hand.setWeapon(*wep);
                wep->setIsEquipped(true);
                break;
        }
        
    }
       //std::shared_ptr<Armor> der = static_pointer_cast(Item>);
    //rightLeg.setLegArmor(item);
 
}

void HumanoidBody::PrintEquippedItems()
{
    
    std::cout << "Head Armor " << getHead().getHeadArmor().getItemName() << getHead().getHeadArmor().getItemType() << "\n";
    std::cout << "Chest Armor " << getChest().getChestArmor().getItemName() << getChest().getChestArmor().getItemType() << "\n";
    std::cout << "Leg Armor " << leftLeg.getLegArmor().getItemName() << leftLeg.getLegArmor().getItemType() << "\n";
    
}