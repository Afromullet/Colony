//
//  PlayerWindows.cpp
//  Colony
//
//  Created by Sean on 7/7/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "PlayerWindows.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "Globals.hpp"


void BodyPartWindow(AnatomyGraph &anatomy)
{
    std::string bodyParts = FormatBodyPartString(anatomy);
    
    
    
    ImGui::Begin("Sample window"); // begin window
    float color[3] = { 0.f, 0.f, 0.f };
    sf::Color bgColor;
    char windowTitle[255] = "ImGui + SFML = <3";
    // Background color edit
    if (ImGui::ColorEdit3("Background color", color)) {
        // this code gets called if color value changes, so
        // the background color is upgraded automatically!
        bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
        bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
        bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
    }
    
    // Window title text edit
    ImGui::InputText("Window title", windowTitle, 255);
    
    if (ImGui::Button("Update window title")) {
        // this code gets if user clicks on the button
        // yes, you could have written if(ImGui::InputText(...))
        // but I do this to show how buttons work :)
        window.setTitle(windowTitle);
    }
    
    
    // Background color edit
    if (ImGui::ColorEdit3("MOre color", color)) {
        // this code gets called if color value changes, so
        // the background color is upgraded automatically!
        bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
        bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
        bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
    }
    
    
    
    if (ImGui::Button("Aba")) {
        // this code gets if user clicks on the button
        // yes, you could have written if(ImGui::InputText(...))
        // but I do this to show how buttons work :)
        
        std::cout << "\n Printing stuff";
        
    }
    
 
    ImGui::Text("%s",bodyParts.c_str());
    
    
    
    
    ImGui::End(); // end window
}

std::string FormatBodyPartString(AnatomyGraph &anatomy)
{
    
    std::string tempString = "";
    
    
    for(int i =0; i < num_vertices(anatomy); i++)
    {
        tempString += anatomy[i].getBodyPartName() + "\n* Armor " + anatomy[i].getArmorRef().getItemName() + "\n *Weapon" +
        anatomy[i].getWeaponRef().getItemName() + "\n";
        
    }
    
    return tempString;
    
    
}
 
