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
bool isInventoryWindowOpen = false;
bool isEquipmentWindowOpen = false;

WindowCommands playerWindowCommands;

std::vector<sf::Vector2i> square;
MapEffect targettingSquare;
DataWindow inventoryWindow;
DataWindow equipmentWindow;
void HandlePlayerInput(sf::Event &event, MapData &mapdata, BaseCreature &creature)
{
    
    //Target square starts at player origin
    
    //playerWindowCommands.h
    
    
    if (event.type == sf::Event::KeyPressed)
    {
  
        playerWindowCommands.SelectWindowCommand(event.key.code);
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
            else if(playerWindowCommands.isAnyWindowOpen())
            {
                //todo
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
            else if(playerWindowCommands.isAnyWindowOpen())
            {
                //todo
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
            
            DataWindow window = playerWindowCommands.selectWindow(enInventoryWindow);
           
            if(!window.isOpen)
            {
                playerWindowCommands.GetWindowData(creature, enInventoryWindow);
                playerWindowCommands.setIsWindowOpen(enInventoryWindow, true);
            }
            /*
           // mapdata.window->draw(invWindow);
            if(!isInventoryWindowOpen)
            {
                AddItemsToInventoryWindow(creature);
                isInventoryWindowOpen = true;
            }
            
            creature.PrintInventory();
             */
        }
        else if(event.key.code == sf::Keyboard::P)
        {
     
            DataWindow window = playerWindowCommands.selectWindow(enEquipmentWindow);
            if(!window.isOpen)
            {
                playerWindowCommands.GetWindowData(creature, enEquipmentWindow);
                playerWindowCommands.setIsWindowOpen(enEquipmentWindow, true);
            }
          
            
        }
        else if(event.key.code == sf::Keyboard::E)
        {
            
            
            
            // mapdata.window->draw(invWindow);
            if(!isInventoryWindowOpen)
            {
                
                AddItemsToInventoryWindow(creature);
                isInventoryWindowOpen = true;
            }
   
            
        
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
        
  
            playerWindowCommands.setAllWindowsToClose();
            
            //Inefficient..todo, clear window only when data has changed..or append only what's missing
            for(int i =0; i < playerWindowCommands.dataWindows.size(); i++)
            {
                playerWindowCommands.dataWindows.at(i).clearTextComponents();
            }
            mapdata.map->RemoveEffect(targettingSquare);
            if(usingTargetSquare)
                usingTargetSquare = false;
            if(isInventoryWindowOpen)
            {
                isInventoryWindowOpen = false;
                inventoryWindow.clearTextComponents();
            }
            if(isEquipmentWindowOpen)
            {
                isEquipmentWindowOpen = false;
                equipmentWindow.clearTextComponents();
            }
         
            
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

void InitializeInventoryWindow()
{
    inventoryWindow.setWindowPosition(sf::Vector2f(0,0));
    inventoryWindow.setWindowSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
    inventoryWindow.setFont("tnr.ttf");
    inventoryWindow.setTextSize(50);
    inventoryWindow.setWindowType(enInventoryWindow);
    inventoryWindow.isOpen = false;
    
    equipmentWindow.setWindowPosition(sf::Vector2f(0,0));
    equipmentWindow.setWindowSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
    equipmentWindow.setFont("tnr.ttf");
    equipmentWindow.setTextSize(25);
    equipmentWindow.setWindowType(enEquipmentWindow);
    equipmentWindow.isOpen = false;
    
    playerWindowCommands.addDataWindow(inventoryWindow);
    playerWindowCommands.addDataWindow(equipmentWindow);
    
    for(int i =0; i < playerWindowCommands.dataWindows.size(); i++)
    {
        playerWindowCommands.dataWindows.at(i).initBasicHighlightSquare();
        //playerWindowCommands.dataWindows.at(i).MoveHighlightSquare(5);
    }
    
    
    
    
    /*
    inventoryWindow.AddText("abc");
    inventoryWindow.AddText("xyz");
    inventoryWindow.setTextColor(sf::Color::Red);
     */
}

void AddItemsToInventoryWindow(BaseCreature &creature)
{
    std::list<Item*>::iterator itemIt;
    std::list<Item*> items = creature.getInventory();
    std::string tempString;
    int i = 0;
    for(itemIt = items.begin(); itemIt != items.end(); ++itemIt)
    {
        tempString = std::to_string(i);
        tempString.append(" ");
        tempString.append((*itemIt)->getItemName());
       
        inventoryWindow.AddText(tempString);
        i++;
     
    }
    
    inventoryWindow.setTextColor(sf::Color::Red);
}

//Prints only the equipped items
void AddToEquipmentWindow(BaseCreature &creature)
{
    std::vector<BodyPart*> bodyPartSchema = creature.getBodyPartSchema();
    std::string outString;
    for(int i = 0; i < bodyPartSchema.size(); i++)
    {
        outString = bodyPartSchema.at(i)->bodyPartName + " - Armor: " + bodyPartSchema.at(i)->armor.getItemName() + " Weapon: " + bodyPartSchema.at(i)->weapon.getItemName();
        equipmentWindow.AddText(outString);
    }
    
    equipmentWindow.setTextColor(sf::Color::Red);
    

}

/*
 

 *
 */

