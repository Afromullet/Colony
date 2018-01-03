//
//  PlayerControls.cpp
//  Colony
//
//  Created by Sean on 1/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "PlayerControls.hpp"


void HandlePlayerInput(sf::Event &event, MapData &mapdata, BaseCreature &creature)
{
    
    if (event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Right)
        {
            MovePlayer(Right, creature,*mapdata.map);
            
        }
        
        else if(event.key.code == sf::Keyboard::Left)
        {
            MovePlayer(Left, creature,*mapdata.map);
        }
        
        else if(event.key.code == sf::Keyboard::Up)
        {
            
            MovePlayer(Up, creature,*mapdata.map);
            
        }
        
        else if(event.key.code == sf::Keyboard::Down)
        {
            MovePlayer(Down, creature,*mapdata.map);
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
            creature.getBody()->PrintEquippedItems();
            
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
        
    }
    
}
