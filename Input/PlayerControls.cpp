//
//  PlayerControls.cpp
//  Colony
//
//  Created by Sean on 1/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "PlayerControls.hpp"



bool PlayerActionTaken = false;
bool usingTargetSquare = false;
bool isInventoryWindowOpen = false;
bool isEquipmentWindowOpen = false;


std::vector<sf::Vector2i> square;
MapEffect targettingSquare;

bool HandlePlayerInput(sf::Event &event, MapData &mapdata, BaseCreature &creature)
{
    
    //Target square starts at player origin
    
    //playerWindowCommands.h
    

    
    //movementAction.setCreature(creature);
   // PlayerActionTaken = true;
   // while(!PlayerActionTaken)
    //{
    
    if (event.type == sf::Event::KeyPressed)
    {
        PlayerActionTaken = true;
  
  
         
        
        
        
        if(event.key.code == sf::Keyboard::Right)
        {
            if(usingTargetSquare)
            {
                ControlTargetSquare(Right,mapdata);
            }
            
            else
            {
                if(creature.getCanMove())
                    CreatureMovesToTile(creature,*mapdata.map,Right);
                   // MovePlayer(Right, creature,*mapdata.map);
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
                if(creature.getCanMove())
                    CreatureMovesToTile(creature,*mapdata.map,Left);
                    //MovePlayer(Left, creature,*mapdata.map);
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
                if(creature.getCanMove())
                    CreatureMovesToTile(creature,*mapdata.map,Up);
                   // MovePlayer(Up, creature,*mapdata.map);
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
                if(creature.getCanMove())
                    CreatureMovesToTile(creature,*mapdata.map,Down);
                   // MovePlayer(Down, creature,*mapdata.map);
            }
        }
        else if(event.key.code == sf::Keyboard::G)
        {
    
            creature.PickupItem(*mapdata.map,mapdata.itemsOnMap);
            
        }
        else if(event.key.code == sf::Keyboard::E)
        {
            
            
         
            
            
        }
        else if(event.key.code == sf::Keyboard::A)
        {
         
            //creature.CalculateAttackParameters();
        }
        else if(event.key.code == sf::Keyboard::T)
        {
            
            //Don't want to allow target square to be pressed twice and count vertices twice...add check to see if we are currently targetting
            
            std::cout << "\n Choose Shape: 0 = Circle, 1 = Square, 2 = Line";
            int selection;
            
            if(usingTargetSquare == false)
            {
                
                std::cin >> selection;
                
                if(selection == 0)
                    targettingSquare.setCircle(10,10,5);
                else if(selection == 1)
                    targettingSquare.setSquare(creature.getPosition(), 1);
                    
                    
                //
                
                targettingSquare.vertices = mapdata.map->getVertices(targettingSquare.tilePositions);
                targettingSquare.setColor(sf::Color::Yellow);
                targettingSquare.setID(AssignEffectID());
                mapdata.map->AddEffect(targettingSquare.getID(), targettingSquare.vertices);
            }
            
          
            
            usingTargetSquare = true;
            //Target square
        }
        else if(event.key.code == sf::Keyboard::C)
        {
            mapdata.map->RemoveEffect(targettingSquare);
            usingTargetSquare = false;
        }
        else if(event.key.code == sf::Keyboard::S)
        {
       
            std::vector<BaseCreature*> vecCreatures = mapdata.map->getCreatures(targettingSquare.tilePositions);
           
            for(int i=0; i < vecCreatures.size(); i++)
            {
                std::cout << "\nPosition: " << vecCreatures.at(i)->getPosition().x << "," << vecCreatures.at(i)->getPosition().y;
                
                vecCreatures.at(i)->setTotalHealth(0);
            }
           
            std::cout << "\n";
        }
        //For increasing and decreasing targetting square size..for testing
        else if(event.key.code == sf::Keyboard::LBracket)
        {
            if(usingTargetSquare)
            {
                //Can't reduce any further
                if(targettingSquare.getSquareSize() == 1)
                {
                    //break;
                }
                mapdata.map->RemoveEffect(targettingSquare);
                
                targettingSquare.setSquareSize(targettingSquare.getSquareSize() - 1);
                targettingSquare.setSquare(targettingSquare.tilePositions.at(0), targettingSquare.getSquareSize());
                
                targettingSquare.vertices = mapdata.map->getVertices(targettingSquare.tilePositions);
                targettingSquare.setColor(sf::Color::Yellow);
                targettingSquare.setID(AssignEffectID());
                mapdata.map->AddEffect(targettingSquare.getID(), targettingSquare.vertices);

            }
        }

        else if(event.key.code == sf::Keyboard::RBracket)
        {
            if(usingTargetSquare)
            {
                mapdata.map->RemoveEffect(targettingSquare);
                targettingSquare.setSquareSize(targettingSquare.getSquareSize() + 1);

                targettingSquare.setSquare(targettingSquare.tilePositions.at(0), targettingSquare.getSquareSize());
                targettingSquare.vertices = mapdata.map->getVertices(targettingSquare.tilePositions);
                targettingSquare.setColor(sf::Color::Yellow);
                targettingSquare.setID(AssignEffectID());
                mapdata.map->AddEffect(targettingSquare.getID(), targettingSquare.vertices);
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
            mapdata.map->AddEffect(targettingSquare.getID(), targettingSquare.vertices);
            }
            
        }
        else if(event.key.code == sf::Keyboard::B)
        {
            
            int x,y;
            std::cout << "Enter x";
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
            
            std::map<GridLocation,GridLocation> cameFrom =  aStarSearch(*mapdata.map,  start,  end);
            
            
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
             //movementAction.PerformAction();
             ///sBehavior.ExamineSurroundingTask(creature, *mapdata.map);
         }
        else if(event.key.code == sf::Keyboard::X)
        {
            
        
        }
        else if(event.key.code == sf::Keyboard::Space)
        {
            //creature.setWeaponAttackSchema();
            
            
            
           
        }
        else if(event.key.code == sf::Keyboard::M)
        {
            
            GridLocation loc;
            loc.x = 15;
            loc.y = 15;
      
           // sBehavior.SelectRandomSearchLocation(mapdata.map->GetWidth(), mapdata.map->GetHeight(),*mapdata.map);
            
            
           // sBehavior.AddLocationToPath(creature, *mapdata.map, 0);
          //  sBehavior.RemoveLocationFromPath(0);
            
            
            
        }
        else if(event.key.code == sf::Keyboard::X)
        {
            

        }
        
        
    
    
    
    }
    
    //return true;
   // }
    
    return true;
}

/*
 
 
 */
void ControlTargetSquare(MoveDirection moveDir,MapData &mapdata)
{
    if(moveDir == Up)
    {
    
        targettingSquare.MoveShape(0, -1);

    }
    else if(moveDir == Down)
    {
        targettingSquare.MoveShape(0, 1);
    }
    else if(moveDir == Left)
    {
        targettingSquare.MoveShape(-1, 0);
    }
    else if(moveDir == Right)
    {
        targettingSquare.MoveShape(1, 0);
    }
    
    //mapdata.map->setEffectColor(targettingSquare.getID(), sf::Color::Yellow);
    targettingSquare.vertices = mapdata.map->getVertices(targettingSquare.tilePositions);
    targettingSquare.setColor(sf::Color::Yellow);
    mapdata.map->setEffectColor(targettingSquare.getID(), sf::Color::Yellow);
    mapdata.map->UpdateEffect(targettingSquare);
}

