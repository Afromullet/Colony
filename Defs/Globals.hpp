//
//  Globals.hpp
//  Colony
//
//  Created by Sean on 5/22/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//





#ifndef Globals_hpp
#define Globals_hpp
#include <TGUI/TGUI.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <Vector>
#include <iostream>
#include "Constants.hpp"
#include <string>
#include "MapData.hpp"
#include "Constants.hpp"
#include <TGUI/TGUI.hpp>
#define MAX_CREATURES_PER_MAP 100
//extern FileLogger errorLog;

extern sf::RenderWindow window;
extern tgui::Gui gui;
//Read these from a file later and store in a vector of strings
//That way it can be customized easily by reading from files





extern sf::Font defaultFont;
//extern tgui::Font tguiFont;

void InitializeGlobals();
void InitializeWindows();

extern sf::Color yellow;


extern std::vector<int> allEffectIDs;

bool doesEffectIDExist(int id);

int AssignEffectID();

extern sf::Color BasicHighlightColor;

//extern MapData mapdata;





#endif /* Globals_hpp */
