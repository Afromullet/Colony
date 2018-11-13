//
//  KeyDefinitions.hpp
//  Colony
//
//  Created by Sean on 1/14/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//



#ifndef KeyDefinitions_hpp
#define KeyDefinitions_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>


//They aren't constants because I don't want to have to reload the game to change key configurations. Still using all caps though

extern sf::Keyboard::Key OPEN_INVENTORY_KEY;
extern sf::Keyboard::Key OPEN_TILE_KEY;
extern sf::Keyboard::Key OPEN_EQUIPMENT_KEY;
extern sf::Keyboard::Key OPEN_SELECTION_WINDOW_KEY;
extern sf::Keyboard::Key CLOSE_WINDOW_KEY;
extern sf::Keyboard::Key SELECT_ACTION_KEY;

extern sf::Keyboard::Key UP_KEY;
extern sf::Keyboard::Key DOWN_KEY;
extern sf::Keyboard::Key LEFT_KEY;
extern sf::Keyboard::Key RIGHT_KEY;
#endif /* KeyDefinitions_hpp */
