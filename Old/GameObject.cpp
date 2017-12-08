//
//  GameObject.cpp
//  Colony
//
//  Created by Sean on 7/28/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#include "GameObject.hpp"
#include "BasicAIComponent.hpp"


//class MovComponent;

GameObject::GameObject(MovComponent* mov,GraphicComponent* graphics,CollisionComponent* edgeDetection,AIComponent *basicAI) :
mov_(mov),graphics_(graphics),edgeCollision_(edgeDetection),basicAI_(basicAI)
{
    
}

void GameObject::update()
{
    mov_->update(*this);
    graphics_->update(*this);
    edgeCollision_->update(*this);
    
    
}

void GameObject::AIBehaviorUpdate(Behaviors behavior)
{
    basicAI_->update(*this,behavior);
}

//Sets the window on which the shape is displayed
void GameObject::setWindow(sf::RenderWindow *_window)
{
    window = _window;
}

