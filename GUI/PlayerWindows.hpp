//
//  PlayerWindows.hpp
//  Colony
//
//  Created by Sean on 7/7/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef PlayerWindows_hpp
#define PlayerWindows_hpp

#include <stdio.h>
#include "BaseCreature.hpp"
#include "BodyGraph.hpp"
#include <string>



void BodyPartWindow(AnatomyGraph &anatomy);
std::string FormatBodyPartString(AnatomyGraph &anatomy);
std::string FormatInventoryString(ItemManager &inventory);



#endif /* PlayerWindows_hpp */
