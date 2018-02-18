//
//  PlayerControls.cpp
//  Colony
//
//  Created by Sean on 1/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "PlayerControls.hpp"
#include "Pathfinding.hpp"
#include "Globals.hpp"

#include "TestData.hpp"
#include "BasicBehavior.hpp"
bool usingTargetSquare = false;
bool isInventoryWindowOpen = false;
bool isEquipmentWindowOpen = false;

WindowCommands playerWindowCommands;

std::vector<sf::Vector2i> square;
MapEffect targettingSquare;
DataWindow inventoryWindow;
DataWindow equipmentWindow;
bool HandlePlayerInput(sf::Event &event, MapData &mapdata, BaseCreature &creature)
{
    
    //Target square starts at player origin
    
    //playerWindowCommands.h
    
    
    while(!PlayerActionTaken)
    {
    
    if (event.type == sf::Event::KeyPressed)
    {
        PlayerActionTaken = true;
  
       //playerWindowCommands.handleOpenWindowCommand(event.key.code);
        playerWindowCommands.handleOpenMainWindow(event.key.code);
        for(int i = 0; i < playerWindowCommands.dataWindows.size(); i++)
        {
          
            if(playerWindowCommands.dataWindows.at(i).isOpen)
            {
                playerWindowCommands.dataWindows.at(i).clearTextComponents();
                playerWindowCommands.GetWindowData(creature, playerWindowCommands.dataWindows.at(i).getWindowType(),playerWindowCommands.dataWindows.at(i));
            
                
                playerWindowCommands.handleMainWindowAction(creature,playerWindowCommands.dataWindows.at(i), event.key.code);
               // playerWindowCommands.handleOpenWindowAction(creature,playerWindowCommands.dataWindows.at(i).getWindowType(), event.key.code);
            }
            
            
        }
         
        
        
        
        if(event.key.code == sf::Keyboard::Right)
        {
            if(usingTargetSquare)
            {
                ControlTargetSquare(Right,mapdata);
            }
            
            else if(!playerWindowCommands.isAnyWindowOpen())
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
            else if(!playerWindowCommands.isAnyWindowOpen())
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
            else if(!playerWindowCommands.isAnyWindowOpen())
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
            else if(!playerWindowCommands.isAnyWindowOpen())
            {
                MovePlayer(Down, creature,*mapdata.map);
            }
        }
        else if(event.key.code == sf::Keyboard::G)
        {
    
            creature.PickupItem(*mapdata.map,mapdata.itemsOnMap);
            
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
            //mapdata.map->RemoveEffect(targettingSquare);
            if(usingTargetSquare == false)
            {
                
                //targettingSquare.addTilePositions(targettingSquare.getLine(0, 0, 0, 10));
                
                for(int i=0; i < 12; i++)
                {
                 
                    // targettingSquare.addTilePositions(targettingSquare.getLine(i, i, 10, i));
                    //targettingSquare.addTilePositions(targettingSquare.getLine(creature.getPosition().x, creature.getPosition().y, creature.getPosition().x+i, creature.getPosition().y+i));
                }
            
  
                int pX = creature.getPosition().x;
                int pY = creature.getPosition().y;
                
                int nX; //= pX;// + 4;
                int nY; // = pY + 4;
                //targettingSquare.addTilePositions(sf::Vector2i(nX,nY));
                double angle;
                
                
            
                
                
                
                int xDistance = 6;
                int yDistance = 6;
                
                
                int xOrg = creature.getPosition().x;
                int yOrg = creature.getPosition().y;
                
                //Origin of the cone's base
                int x0Base = xOrg+xDistance;
                int y0Base = yOrg+yDistance;
                
                //End point of the base
                int x1Base = xOrg+xDistance;
                int y1Base = yOrg-yDistance;
                
                //End point of the first side..The start point is the origin
                int x1Side0 = xOrg+xDistance;
                int y1Side0 = yOrg + yDistance;
                
                //End point of the second side..The start point is the origin
                int x1Side1 = xOrg+xDistance;
                int y1Side1 = yOrg-yDistance;
                
                std::cout << "\nOrigin: " << xOrg << "," << yOrg;
                
                std::cout << "\nBase Start " << x0Base << "," << y0Base;
                std::cout << "\nBase End " << x1Base << "," << y1Base;
                
                std::cout << "\nSide0 End " << x1Side0 << "," << y1Side0;
                std::cout << "\nSide1 End " << x1Side1 << "," << y1Side1;
                
             

                
                
                targettingSquare.addTilePositions(targettingSquare.getLine(xOrg, yOrg, x1Side0, y1Side0));
                
                targettingSquare.addTilePositions(targettingSquare.getLine(xOrg, yOrg, x1Side1, y1Side1));
                
                 targettingSquare.addTilePositions(targettingSquare.getLine(x0Base, y0Base, x1Base, y1Base));


              


               
               
                
               // targettingSquare.setCircle(10, 10, 10);
            //targettingSquare.setLine(creature.getPosition(), 2,Up);
            targettingSquare.vertices = mapdata.map->getVertices(targettingSquare.tilePositions);
            targettingSquare.setColor(sf::Color::Yellow);
            targettingSquare.setID(AssignEffectID());
            mapdata.map->AddEffect(targettingSquare.id, targettingSquare.vertices);
            }
            
        }
        else if(event.key.code == sf::Keyboard::B)
        {
            
            int x,y;
            std::cout << "Enter x\n";
            std::cin >> x;
            std::cout << "Enter y;";
            std::cin >> y;
            
            
            
            
            GridLocation start,end;
            start.x = creature.getPosition().x;
            start.y = creature.getPosition().y;
            
            if(!mapdata.map->Map2D[x][y].getCanHoldCreature())
            {
                std::cout << "Selected tile cannot hold creature";
                return true;
            }
            
            end.x = x;
            end.y = y;
            
            std::map<GridLocation,GridLocation> cameFrom =  aStarSearch(caMap,  start,  end);
            
            
            std::vector<GridLocation> path = recontructPath(start,end, cameFrom);
            // aStarSearch(caMap,  start,  end);
            std::vector<sf::Vector2i> walkPath;
            
            for(int i =0; i < path.size(); i++)
            {
                
                creature.AddToPath(sf::Vector2i(path.at(i).x,path.at(i).y));
                
            }


        
        }
        else if(event.key.code == sf::Keyboard::W)
         {
             creature.WalkPath(*mapdata.map);
         }
        else if(event.key.code == sf::Keyboard::X)
        {
            
            std::cout << "\n Target location " << testCreature1.getPosition().x << "," << testCreature1.getPosition().y;
           ApproachCreature(*mapdata.map, creature, testCreature1);
             ApproachCreature(*mapdata.map, creature, mapdata.creaturesOnMap.front());
        }
        else if(event.key.code == sf::Keyboard::Space)
        {
            std::list<Item*> items = mapdata.itemsOnMap;
            std::list<Item*>::iterator itemIt;
            
            std::cout << "\n Items on map size " << items.size();
            
            
            
           
        }
        
        
    
    
    
    }
    
    return true;
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
    

    

    
    DataWindow invSelectWindow; //Move to top of class, replace inventory window and equipment window with temp window
    DataWindow exInvWindow;
    invSelectWindow.setWindowSize(sf::Vector2f(150 , 150));
    invSelectWindow.setWindowPosition(sf::Vector2f(WINDOW_X/2 - invSelectWindow.rectangle.getSize().x,WINDOW_Y/2 - invSelectWindow.rectangle.getSize().y));
    invSelectWindow.setFont("tnr.ttf");
    invSelectWindow.setTextSize(25);
    invSelectWindow.setWindowType(enInventorySelectWindow);
    invSelectWindow.isOpen = false;
    invSelectWindow.setWindowColor(sf::Color::Green);
    invSelectWindow.isHighlightOpen = false;
    
    exInvWindow.setWindowSize(sf::Vector2f(300 , 300));
    exInvWindow.setWindowPosition(sf::Vector2f(WINDOW_X/2 - exInvWindow.rectangle.getSize().x,WINDOW_Y/2 - exInvWindow.rectangle.getSize().y));
    exInvWindow.setFont("tnr.ttf");
    exInvWindow.setTextSize(25);
    exInvWindow.setWindowType(enExamineItemWindow);
    exInvWindow.isOpen = false;
    exInvWindow.setWindowColor(sf::Color::Green);
    exInvWindow.isHighlightOpen = false;
    
    invSelectWindow.AddSubWindow(exInvWindow);
    inventoryWindow.AddSubWindow(invSelectWindow);
    playerWindowCommands.addDataWindow(inventoryWindow);
    playerWindowCommands.addDataWindow(equipmentWindow);
    playerWindowCommands.addDataWindow(invSelectWindow);
    playerWindowCommands.addDataWindow(exInvWindow);
    
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
    
    BasicHighlightColor.a = 90;
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

