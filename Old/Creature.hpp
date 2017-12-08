//
//  Creature.hpp
//  Colony
//
//  Created by Sean on 10/13/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//



#ifndef Creature_hpp
#define Creature_hpp

#include <stdio.h>
#include "BodySchema.hpp"
#include "Constants.hpp"
#include "TileMap.hpp"





class Creature;
class MovementComponent;





class Creature
{
    
public:
    Creature();
    Creature(BodySchema schema);
    Creature(BodySchema schema,short int _movSpeed,short int bab,short int str, short int agi, short int end, short int _mind,short int _will,short int cha);
    
    void loadCreatureTile(const std::string& tileset, int tileXSize,int tileYSize);
    
    //Getters
    
    BodySchema getBodySchema();
    BodySchema& getBodySchemaRef();

    short int getAttackValue();
    short int getMeleeAttackValue();
    short int getRangedAttackValue();
    short int getStrength();
    short int getAgility();
    
    sf::Vector2u  getPosition();
    sf::Vector2u  getPrevePosition();
    sf::Vector2u getVelocity();
    
    
    //Setters
    void setPosition(short int x, short int y);
    void setVelocity(int x, int y);
    void setMovementComponent(MovementComponent *_movComponent);
    
    
    bool MoveCreature(int x, int y);
    
    
    
    
    
    void UpdatePosition();
    
    
  
    
    
    CreatureTile creatureTile;
    
    sf::Vector2u velocity; //Represents basic direction
    sf::Vector2u position;
    sf::Vector2u prevPosition;
    
        
private:
    BodySchema bodySchema;
    
    
    short int attackValue;
    //std::vector<short int> baseAttackBonus;
    short int strength;
    short int agility;
    short int endurance;
    short int mind;
    short int will;
    short int charisma;
    short int moveSpeed;

    EnSizeCategory sizeCategory;
    MovementComponent *movComponent;
    

    
    
    
    
};

class MovementComponent 
{
    
public:
    virtual ~MovementComponent(){}
    virtual void update(Creature &obj) = 0;
    
};


#endif /* Creature_hpp */
