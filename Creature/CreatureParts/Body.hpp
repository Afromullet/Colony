//
//  Body.hpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Body_hpp
#define Body_hpp

#include <stdio.h>
#include "Chest.hpp"
#include "Head.hpp"

/*A basic body consists of a chest and head. Appendages and limbs are subclasses implemented in the.
E.X: A Basic Humanoid is a subclass with Limbs and Appendages that represent arms and legs.
 So there'll have to be a "BasicHumanoid" subclass
 */
class Body
{
    
private:
    
    Chest chest;
    Head head;
    int health; //Health of all body parts combined
    float bloodRemaining; //The lower this value is, the more blood the creature lost
    
public:
    
     ~Body(){};
    virtual void CalculateHealth() = 0; //Calculates health based on the limb and appendage setup of the creature
    
    virtual void AttackRandomBodyPart(int attackBonus, int damage) = 0; //If something attempts to attack the creature. Since there are many different body parts, this is a virtual function
    
    virtual Body* clone() const = 0; 
    
    void setBloodRemaining(float _bloodRemaining);
    void setHead(Head _head);
    void setChest(Chest _chest);

    
    
    float getBloodRemaining();
    Head getHead();
    Chest getChest();
    

};
#endif /* Body_hpp */
