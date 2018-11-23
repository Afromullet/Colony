//
//  AttackHandler.cpp
//  Colony
//
//  Created by Sean on 3/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "AttackHandler.hpp"
#include "ImpactWoundInterface.hpp"
#include "ShearWoundInterface.hpp"

//Need to be display what body part has been targeted and what kind of wound has been applied
/*
 At this point, the game will have to responsd to several things
 
 1) The effects of wound on the body
 2) Whether any vertices have to be removed from the graph
 3) The location of the wound
 
 */

struct WoundIdentifier
{
    
};

void Single_Attack_Melee(AttackStats &attack, BaseCreature &defender)
{
    int target = getRandomExternalBodyParts(defender.body.anatomyGraph);
    
    std::cout << "\n Target " << target;
    
    
    defender.body.anatomyGraph[target].getArmorRef().getMaterialRef().PerformMaterialCalculations(attack.force,attack.contactArea,attack.enAttackForceType,attack.attackType);
    std::vector<AppliedForceEffect> &effects = defender.body.anatomyGraph[target].getArmorRef().getMaterialRef().getAppliedForceEffects();
    
    WoundCalculations woundCalcs(target);
    
    for(int i=0;i<effects.size();i++)
    {
        woundCalcs.ApplyWound(effects.at(i),defender.body.anatomyGraph); //Changes the sate of the defenders body graph
    }
    
    //Here I need to merge the woundCalc wouldTable with the defender woundTable
    
     defender.body.woundTable = woundCalcs.woundTable;
    ImpactWoundInterface impact(defender.body.anatomyGraph,defender.body.woundTable,defender.body);
    ShearWoundInterface shear(defender.body.anatomyGraph,defender.body.woundTable,defender.body);
   
    
    defender.body.woundTableInterface = &impact;
    defender.body.woundTableInterface->ProcesWoundTable();
    defender.body.woundTableInterface = &shear;
    defender.body.woundTableInterface->ProcesWoundTable();
    
    
    
    
    
}

void AttackCreature_Melee(BaseCreature &attacker,BaseCreature &defender)
{
    attacker.calculateAttackParameters();
    
    
    
    for(int i = 0; i < attacker.getAttacks().size(); i++)
    {
        int target = getRandomExternalBodyParts(defender.body.anatomyGraph);
        
        if(!attacker.getAttacks().at(i).isRangedAttack)
        {
            
       
            if(attacker.getAttacks().at(i).attackValue > defender.body.anatomyGraph[target].getArmor().siGetArmorBonus())
            {
                std::cout << "\n Hit";
                defender.body.anatomyGraph[target].ApplyDamage(attacker.getAttacks().at(i).damage);
                defender.setTotalHealth(defender.getTotalHealth() - attacker.getAttacks().at(i).damage);
                
            }
            else
            {
                std::cout << "\n Miss";
                
                
            }
            

        }
           
        //if(attackers.attacks.at(i).attackValue > )
        
    }
    
}

void AttackCreature_Ranged(BaseCreature &attacker,BaseCreature &defender)
{
    attacker.calculateAttackParameters();
    
    
    int distance = std::abs(attacker.getPosition().x - defender.getPosition().x) + std::abs(attacker.getPosition().y - defender.getPosition().y);
    
    
    
    for(int i = 0; i < attacker.getAttacks().size(); i++)
    {
        int target = getRandomExternalBodyParts(defender.body.anatomyGraph);
        
         std::cout << "\n Weapon range " << attacker.getAttacks().at(i).range;
        std::cout << "\n Is Ranged " << attacker.getAttacks().at(i).isRangedAttack;
        
        if(attacker.getAttacks().at(i).isRangedAttack)
        {
            
           
            if(attacker.getAttacks().at(i).range < distance)
            {
                std::cout << "\n Target too far away";
                continue;
            }
            std::cout << "\n Attack Value, Armor Bonus: " << attacker.getAttacks().at(i).attackValue << "," << defender.body.anatomyGraph[target].getArmor().siGetArmorBonus();
            if(attacker.getAttacks().at(i).attackValue > defender.body.anatomyGraph[target].getArmor().siGetArmorBonus())
            {
                std::cout << "\n Hit";
                defender.body.anatomyGraph[target].ApplyDamage(attacker.getAttacks().at(i).damage);
                defender.setTotalHealth(defender.getTotalHealth() - attacker.getAttacks().at(i).damage);
                
            }
            else
            {
                std::cout << "\n Miss";
                
                
            }
            
            std::cout << "\n Remaining health" <<  defender.body.anatomyGraph[target].getHealth();
            std::cout << "\n Remaining total health " << defender.getTotalHealth();
        }
        
        //if(attackers.attacks.at(i).attackValue > )
        
    }

}

//Performs the attack calculations for attacking a body part
void AttackBodyPart(AttackStats stats,int index,AnatomyGraph &graph)
{
    std::vector<AppliedForceEffect> effects = graph[index].ApplyAttack(stats); //For now only apply the first effect
    WoundCalculations woundCalcs(index);
    woundCalcs.ApplyWound(effects.at(0),graph);
}

//For providing some info to display to the user following a attack
std::string getAttackString(BaseCreature &attacker, BaseCreature &defender,AttackStats &stats)
{
    std::string tempString = "Attacks with a";
    
    if(stats.attackType == enPierce)
    {
        tempString += " Thrust";
    }
    else if(stats.attackType == enBlunt)
    {
        tempString += " Slam";
    }
    else if(stats.attackType == enSlash)
    {
        tempString += " Slash";
    }
    
    return tempString;
    
}
