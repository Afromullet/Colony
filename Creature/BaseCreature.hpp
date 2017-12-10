//
//  AbstractCreature.hpp
//  Colony
//
//  Created by Sean on 12/5/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef AbstractCreature_hpp
#define AbstractCreature_hpp

#include <stdio.h>
#include "EntityTile.hpp"
#include "Body.hpp"
//todo rename..not abstract anymore
class BaseCreature
{
private:
    short int attackValue;
    short int strength;
    short int agility;
    short int endurance;
    short int mind;
    short int will;
    short int charisma;
    short int moveSpeed; //Currently both x and y speed
    
    Body *body;
public:
    
    BaseCreature();
   // BaseCreature(const BaseCreature &creature);
    
    EntityTile creatureTile;
    sf::Vector2u velocity; //Represents basic direction..Not used at the moment.
    sf::Vector2u position;
    sf::Vector2u prevPosition; //Not used at the moment
    
    //TODO add some check to ensure the creature tile is initialized
    void loadCreatureTile(const std::string& tileset, int tileXSize,int tileYSize);
    
    //Getters
    short int getAttackValue();
    short int getMeleeAttackValue();
    short int getRangedAttackValue();
    short int getStrength();
    short int getAgility();
    sf::Vector2u  getPosition();
    sf::Vector2u  getPrevePosition();
    sf::Vector2u getVelocity();
    Body* getBody();
    
    //Setters
    void setPosition(short int x, short int y);
    void setVelocity(int x, int y);
    void setBody(Body *_body);
    void CloneBody(Body *_body);
    
    bool MoveCreature(int x, int y);
    
    bool isAlive; //For testing

    
};



#endif /* AbstractCreature_hpp */
