//
//  ItemGenerator.hpp
//  Colony
//
//  Created by Sean on 12/15/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef ItemGenerator_hpp
#define ItemGenerator_hpp

#include <stdio.h>
#include "Equipment.hpp"
#include <list>
#include "Map.hpp"

extern std::list<Item> itemsOnMap;

//For testing...need to get inventory and equipping items owrking
void RandomItemGen();
void PlaceItemsOnMap(Map &map);

#endif /* ItemGenerator_hpp */
