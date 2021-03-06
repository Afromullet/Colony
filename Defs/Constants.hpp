//
//  Constants.hpp
//  Colony
//
//  Created by Sean on 5/21/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#ifndef Constants_h
#define Constants_h


//Size of the window
#define WINDOW_X 2000
#define WINDOW_Y 2000

#define ERROR_TILE_LOCATION "Tiles/errorTile.jpg"

#define TEST_WINDOW_X 1500
#define TEST_WINDOW_Y 1500

#define ERROR_VALUE -1
#define ERROR_STRING "UNDEFINED STRING"

#define LOW_LEVEL 1
#define MODERATE_LEVEL 2
#define HIGH_LEVEL 3

#define RED sf::Color(255, 0, 50)
#define GREEN sf::Color(0, 128, 0)

#define PI 3.14

#define DEFAULT_TILE_SIZE 4 //The default size of any tile, be it map or a creature

//Will have to be initialized since these values depend on several variables (Windows size and default tile size
extern const int MAP_WIDTH;
extern const int MAP_HEIGHT;
extern const int MAP_SIZE;


#endif /* Constants_h */

