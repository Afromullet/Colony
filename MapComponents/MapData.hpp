//
//  MapData.hpp
//  Colony
//
//  Created by Sean on 12/31/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//



#ifndef MapData_hpp
#define MapData_hpp

#include "Map.hpp"
#include <stdio.h>
#include <memory>



//Stores all of the data assocaited with a map

class MapData
{
private:
    
    //std::vector<std::unique_ptr<Item>> items;
    
    
public:
    std::vector<std::unique_ptr<Item>> items;
    
    MapData();
    MapData(MapData &other);
    
    //Make private later
    sf::RenderWindow *window;
    Map *map;
    std::list<Item*> itemsOnMap;
    std::list<BaseCreature> creaturesOnMap;


    void DrawCreaturesOnMap();
    void DrawItemsOnMap();
    void RemoveDeadCreature();
    
    void AddItemToMap(Item *item);
    void AddItemToMap(std::unique_ptr<Item> item);
    void AddCreatureToMap(BaseCreature creature);
    void PlaceCreaturesOnMap();
    void PlaceItemsOnMap();
    void setMap(Map *_map);
    void setItemsOnMap(std::list<Item*> _itemsOnMap);
    void setCreaturesOnMap(std::list<BaseCreature> _lCreatures);
    void SetWindow(sf::RenderWindow *_window);
};


#endif /* MapData_hpp */
