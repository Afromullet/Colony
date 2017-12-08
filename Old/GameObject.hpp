//
//  GameObject.hpp
//  Colony
//
//  Created by Sean on 7/28/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//




#ifndef GameObject_hpp
#define GameObject_hpp

#include "MVector.hpp"
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "EnumTypes.hpp"
#include "Creature.hpp"




class MovComponent; //This forward declaration allows the program to comppile. See note S1
class GraphicComponent;
class CollisionComponent;
class AIComponent;



//Rename to CreatureObject eventually
class GameObject
{
public:
    
    MVector velocity;
    MVector acceleration;
    MVector location;
    MVector seekTarget; //Location the object will seek out
    
    float maxSpeed;
    float maxForce;
    
    sf::RenderWindow *window; //The window this shape will appear in
    
    sf::CircleShape shape;
    sf::Color color;
    float radius;
     
    
    GameObject(MovComponent* mov, GraphicComponent* graphics,CollisionComponent* edgeDetection,AIComponent *basicAI);
    void update();
    void AIBehaviorUpdate(Behaviors behavior);
    void setWindow(sf::RenderWindow *_window);
  
    
    
private:
    MovComponent* mov_;
    GraphicComponent* graphics_;
    CollisionComponent* edgeCollision_;
    AIComponent *basicAI_;
};



 //Note S1: Whether or not you have MovComponent as its own file, a forward declaration is required here in movcomponnent for the progrma to compile.

class MovComponent
{
    
public:
    virtual ~MovComponent(){}
    virtual void update(GameObject &obj) = 0;
    
};

class GraphicComponent
{
public:
    virtual ~GraphicComponent(){}
    virtual void update(GameObject &obj) = 0;
    
};


class CollisionComponent
{
public:
    virtual ~CollisionComponent(){}
    virtual void update(GameObject &obj) = 0;
};

class AIComponent
{
public:
    virtual ~AIComponent(){}
    virtual void update(GameObject &obj, Behaviors behavior) = 0;
};







#endif /* GameObject_hpp */

