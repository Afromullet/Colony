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

//Not much done yet. Remove this file later, this is just for testing. Radom item generation will have to be handled differently.

Armor GenerateRandomArmor();
Weapon GenerateRandomWeapon();
void RandomItemGen();
void PlaceItemsOnMap(Map &map);




#endif /* ItemGenerator_hpp */
