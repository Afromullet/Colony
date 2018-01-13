//
//  PlayerControls.cpp
//  Colony
//
//  Created by Sean on 1/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "PlayerControls.hpp"
#include "Globals.hpp"


bool usingTargetSquare = false;
std::vector<sf::Vector2i> square;
MapEffect targettingSquare;

void HandlePlayerInput(sf::Event &event, MapData &mapdata, BaseCreature &creature)
{
    
    //Target square starts at player origin
    
    
    if (event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Right)
        {
            if(usingTargetSquare)
            {
                ControlTargetSquare(Right,mapdata);
            }
            else
            {
                MovePlayer(Right, creature,*mapdata.map);
            }
            
        }
        
        else if(event.key.code == sf::Keyboard::Left)
        {
            
            if(usingTargetSquare)
            {
                ControlTargetSquare(Left,mapdata);
            }
            else
            {
                MovePlayer(Left, creature,*mapdata.map);
            }
            
            
           
        }
        
        else if(event.key.code == sf::Keyboard::Up)
        {
            
            
            
            if(usingTargetSquare)
            {
                ControlTargetSquare(Up,mapdata);
            }
            else
            {
                MovePlayer(Up, creature,*mapdata.map);
            }
            
            
        }
        
        else if(event.key.code == sf::Keyboard::Down)
        {
            if(usingTargetSquare)
            {
                ControlTargetSquare(Down,mapdata);
            }
            else
            {
                MovePlayer(Down, creature,*mapdata.map);
            }
        }
        else if(event.key.code == sf::Keyboard::G)
        {
            //player.PickupItem(caMap,itemsOnMap);
            creature.PickupItem(*mapdata.map,mapdata.itemsOnMap);
            
            
        }
        else if(event.key.code == sf::Keyboard::I)
        {
            creature.PrintInventory();
        }
        else if(event.key.code == sf::Keyboard::P)
        {
            //creature.getBody()->PrintEquippedItems();
            creature.PrintEquipment();
            
        }
        else if(event.key.code == sf::Keyboard::E)
        {
            creature.PrintInventory();
            int n;
            std::cout << "\nEnter item index \n";
            std::cin >> n;
            creature.EquipItemFromInventory(n);
            std::cout << "Equipped";
            int k = 3;
            
        }
        else if(event.key.code == sf::Keyboard::F)
        {
            //Fire ranged weapon
            
            
        }
        else if(event.key.code == sf::Keyboard::A)
        {
         
            creature.CalculateAttackParameters();
        }
        else if(event.key.code == sf::Keyboard::T)
        {
            
            //Don't want to allow target square to be pressed twice and count vertices twice...add check to see if we are currently targetting
            
            if(usingTargetSquare == false)
            {
                targettingSquare.setSquare(creature.getPosition(), 1);
                targettingSquare.vertices = mapdata.map->getVertices(targettingSquare.tilePositions);
                targettingSquare.setColor(sf::Color::Yellow);
                targettingSquare.setID(AssignEffectID());
                mapdata.map->AddEffect(targettingSquare.id, targettingSquare.vertices);
            }
            
          
            
            usingTargetSquare = true;
            //Target square
        }
        else if(event.key.code == sf::Keyboard::S)
        {
       
            std::vector<BaseCreature*> vecCreatures = mapdata.map->getCreatures(targettingSquare.tilePositions);
           
            for(int i=0; i < vecCreatures.size(); i++)
            {
                std::cout << "\nPosition: " << vecCreatures.at(i)->getPosition().x << "," << vecCreatures.at(i)->getPosition().y;
                
                vecCreatures.at(i)->totalHealth = 0;
            }
           
            std::cout << "\n";
        }
        else if(event.key.code == sf::Keyboard::Escape)
        {
        
            mapdata.map->RemoveEffect(targettingSquare);
            usingTargetSquare = false;
            
         
            
        }
        
        //For increasing and decreasing targetting square size..for testing
        else if(event.key.code == sf::Keyboard::LBracket)
        {
            if(usingTargetSquare)
            {
                //Can't reduce any further
                if(targettingSquare.squareSize == 1)
                {
                    return;
                }
                mapdata.map->RemoveEffect(targettingSquare);
                
                targettingSquare.setSquare(targettingSquare.tilePositions.at(0), targettingSquare.squareSize -= 1);
                targettingSquare.vertices = mapdata.map->getVertices(targettingSquare.tilePositions);
                targettingSquare.setColor(sf::Color::Yellow);
                targettingSquare.setID(AssignEffectID());
                mapdata.map->AddEffect(targettingSquare.id, targettingSquare.vertices);

            }
        }

        else if(event.key.code == sf::Keyboard::RBracket)
        {
            if(usingTargetSquare)
            {
                mapdata.map->RemoveEffect(targettingSquare);
                targettingSquare.setSquare(targettingSquare.tilePositions.at(0), targettingSquare.squareSize += 1);
                targettingSquare.vertices = mapdata.map->getVertices(targettingSquare.tilePositions);
                targettingSquare.setColor(sf::Color::Yellow);
                targettingSquare.setID(AssignEffectID());
                mapdata.map->AddEffect(targettingSquare.id, targettingSquare.vertices);
            }
        
        }
        else if(event.key.code == sf::Keyboard::L)
        {
            mapdata.map->RemoveEffect(targettingSquare);
            targettingSquare.setLine(targettingSquare.tilePositions.at(0), 1,Up);
            targettingSquare.vertices = mapdata.map->getVertices(targettingSquare.tilePositions);
            targettingSquare.setColor(sf::Color::Yellow);
            targettingSquare.setID(AssignEffectID());
            mapdata.map->AddEffect(targettingSquare.id, targettingSquare.vertices);
            
        }
        
    
    
    
    }
    
}

/*
 
 
 */
void ControlTargetSquare(MoveDirection moveDir,MapData &mapdata)
{
    if(moveDir == Up)
    {
    
        targettingSquare.MoveSquare(0, -1);

    }
    else if(moveDir == Down)
    {
        targettingSquare.MoveSquare(0, 1);
    }
    else if(moveDir == Left)
    {
        targettingSquare.MoveSquare(-1, 0);
    }
    else if(moveDir == Right)
    {
        targettingSquare.MoveSquare(1, 0);
    }
    
    //mapdata.map->setEffectColor(targettingSquare.getID(), sf::Color::Yellow);
    targettingSquare.vertices = mapdata.map->getVertices(targettingSquare.tilePositions);
    targettingSquare.setColor(sf::Color::Yellow);
    mapdata.map->setEffectColor(targettingSquare.getID(), sf::Color::Yellow);
    mapdata.map->UpdateEffect(targettingSquare);
}
