//
//  MapData.cpp
//  Colony
//
//  Created by Sean on 12/31/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "MapData.hpp"

MapData::MapData()
{
    
}

void MapData::DrawCreaturesOnMap()
{
    std::list<BaseCreature>::iterator iter;
    for(iter = creaturesOnMap.begin(); iter != creaturesOnMap.end(); ++iter)
    {
        window->draw(iter->creatureTile);
    }
    
    
}

void MapData::DrawItemsOnMap()
{
    std::list<Item*>::iterator itemIterator;
    for(itemIterator = itemsOnMap.begin(); itemIterator != itemsOnMap.end(); ++itemIterator)
    {
        window->draw((*itemIterator)->tile);
    }
    
}
//If a creature is killed, remove it from the map of the creature list
//TODO, maybe change interaction of drawing betweenmap and creature later to make associating a creautre with a map easier..Maybe add a safety check for when a creature is first created, to see if it is still on any other map
//Since it's just for testing right now, removing creature if health is below 30
//Is this an efficient way to do it? Probably not, since I am checking every iteration if a creature is dead. Handle this differently
void MapData::RemoveDeadCreature()
{
    std::list<BaseCreature>::iterator i = creaturesOnMap.begin();
    while (i != creaturesOnMap.end())
    {
        if(i->getBody()->getTotalHealth() < 30)
        {
            map->Map2D[i->getPosition().x][i->getPosition().y].ClearCreatureOnTile();
            creaturesOnMap.erase(i++);  // alternatively, i = items.erase(i);
        }
        else
        {
            ++i;
        }
    }
}

void MapData::AddItemToMap(Item *item)
{
    itemsOnMap.push_back(item);
}

void MapData::AddCreatureToMap(BaseCreature creature)
{
    creaturesOnMap.push_back(creature);
}

void MapData::PlaceCreaturesOnMap()
{
    std::list<BaseCreature>::iterator iter;
    for(iter = creaturesOnMap.begin(); iter != creaturesOnMap.end(); ++iter)
    {
        BaseCreature &creat = *iter;
        map->Map2D[iter->getPosition().x][iter->getPosition().y].SetCreatureOnTile(&creat);
    }
    
}

void MapData::PlaceItemsOnMap()
{
    //Texture name is hardcoded atm
    std::list<Item*>::iterator itemit;
    for(itemit = itemsOnMap.begin(); itemit != itemsOnMap.end(); ++itemit)
    {
        //TODO...Do some research on whether setting a pointer with a list iterator like that is a bad idea
        
        (*itemit)->tile.loadTile("blessed_blade.png", sf::Vector2u(32,32), sf::Vector2u((*itemit)->getPosition().x,(*itemit)->getPosition().y));
        map->Map2D[(*itemit)->getPosition().x][(*itemit)->getPosition().y].SetItemOnTile(*itemit);
    }
}



void MapData::setMap(Map *_map)
{
    map = _map;
}


void MapData::setItemsOnMap(std::list<Item*> _itemsOnMap)
{
    
}


void MapData::setCreaturesOnMap(std::list<BaseCreature> _lCreatures)
{
    
}

void MapData::SetWindow(sf::RenderWindow *_window)
{
    window = _window;
}