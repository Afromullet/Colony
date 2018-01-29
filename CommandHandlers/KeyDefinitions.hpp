//
//  KeyDefinitions.hpp
//  Colony
//
//  Created by Sean on 1/14/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//


#include <stdio.h>
#include <SFML/Graphics.hpp>

#ifndef KeyDefinitions_hpp
#define KeyDefinitions_hpp



//They aren't constants because I don't want to have to reload the game to change key configurations. Still using all caps though

extern sf::Keyboard::Key OPEN_INVENTORY_KEY;
extern sf::Keyboard::Key OPEN_EQUIPMENT_KEY;
extern sf::Keyboard::Key OPEN_SELECTION_WINDOW_KEY;
extern sf::Keyboard::Key CLOSE_WINDOW_KEY;
extern sf::Keyboard::Key SELECT_ACTION_KEY;
#endif /* KeyDefinitions_hpp */
