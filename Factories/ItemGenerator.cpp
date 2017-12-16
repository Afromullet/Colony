//
//  ItemGenerator.cpp
//  Colony
//
//  Created by Sean on 12/15/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "ItemGenerator.hpp"
#include "Constants.hpp"
#include "Globals.hpp"
#include "Map.hpp"

std::list<Item> itemsOnMap;

//For testing...need to get inventory and equipping items owrking
void RandomItemGen()
{
    for(int i = 0; i < 10; i++)
    {
        Item item;
        item.setItemName(100);
        int randX,randY;
        randX = rand() % MAP_WIDTH;
        randY = rand() % MAP_HEIGHT;
        
        item.tile.loadTile("blessed_blade.png", sf::Vector2u(32,32), sf::Vector2u(randX,randY));
    
        item.setPosition(randX, randY);
        
        item.tile.setPosition(randX, randY);
        
        item.setItemID(rand() % 1000);
        item.localItemID = rand() % 500;
        
     
        itemsOnMap.push_back(item);
    }
}

void PlaceItemsOnMap(Map &map)
{
    std::list<Item>::iterator itemit;
    for(itemit = itemsOnMap.begin(); itemit != itemsOnMap.end(); ++itemit)
    {
        //TODO...Do some research on whether setting a pointer with a list iterator like that is a bad idea
       
        map.Map2D[itemit->getPosition().x][itemit->getPosition().y].SetItemOnTile(&*itemit);
    }
}