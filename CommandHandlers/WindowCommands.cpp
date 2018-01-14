//
//  WindowCommands.cpp
//  Colony
//
//  Created by Sean on 1/13/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "WindowCommands.hpp"
#include "Constants.hpp"

void WindowCommands::addDataWindow(DataWindow _dataWindow, EnDataWindowType windowType)
{
    DataWindow tempWindow;
    tempWindow.setWindowPosition(sf::Vector2f(0,0));
    tempWindow.setWindowSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
    tempWindow.setFont("tnr.ttf");
    tempWindow.setTextSize(25);
    tempWindow.setWindowType(windowType);
    
    dataWindows.push_back(tempWindow); //TODO add check to make sure multiple windows of the same type can't be added
}


void WindowCommands::addDataWindow(DataWindow _dataWindow)
{

    dataWindows.push_back(_dataWindow); //TODO add check to make sure multiple windows of the same type can't be added
}

//The windowType determines the context..tells us what data to put in the window
void WindowCommands::GetWindowData(BaseCreature &creature,EnDataWindowType windowType)
{
    
    if(windowType == enInventoryWindow)
    {
        getInventoryData(creature,selectWindow(enInventoryWindow));
    }
    if(windowType == enEquipmentWindow)
    {
        getEquipmentData(creature,selectWindow(enEquipmentWindow));
    }
    
}

void WindowCommands::getInventoryData(BaseCreature &creature,DataWindow &dataWindow)
{
    
    if(dataWindow.getWindowType() != enInventoryWindow)
        return;
    
    
    std::list<Item*>::iterator itemIt;
    std::list<Item*> items = creature.getInventory();
    std::string tempString;
    int i = 0;
    for(itemIt = items.begin(); itemIt != items.end(); ++itemIt)
    {
        tempString = std::to_string(i) + " " + (*itemIt)->getItemName();
       // tempString.append(" ");
       // tempString.append((*itemIt)->getItemName());
        
        dataWindow.AddText(tempString);
        i++;
        
    }
    
    dataWindow.setTextColor(sf::Color::Red);
}

void WindowCommands::getEquipmentData(BaseCreature &creature,DataWindow &dataWindow)
{
    
    if(dataWindow.getWindowType() != enEquipmentWindow)
        return;
    
    
    std::vector<BodyPart*> bodyPartSchema = creature.getBodyPartSchema();
    std::string outString;
    for(int i = 0; i < bodyPartSchema.size(); i++)
    {
        outString = bodyPartSchema.at(i)->bodyPartName + " - Armor: " + bodyPartSchema.at(i)->armor.getItemName() + " Weapon: " + bodyPartSchema.at(i)->weapon.getItemName();
        dataWindow.AddText(outString);
    }
    
    dataWindow.setTextColor(sf::Color::Red);
}

void WindowCommands::setIsWindowOpen(EnDataWindowType windowType, bool truthValue)
{
    for(int i = 0; i < dataWindows.size(); i++)
    {
        if(dataWindows.at(i).getWindowType() == windowType)
            dataWindows.at(i).isOpen = truthValue;
    }
}

DataWindow& WindowCommands::selectWindow(EnDataWindowType windowType)
{
    for(int i = 0; i < dataWindows.size(); i++)
    {
        if(windowType == dataWindows.at(i).getWindowType())
            return dataWindows.at(i);
    }
    
}
void WindowCommands::setAllWindowsToClose()
{
    for(int i=0; i < dataWindows.size(); i++)
    {
        dataWindows.at(i).isOpen = false;
    }
}

void WindowCommands::clearWindowText(EnDataWindowType windowType)
{
    for(int i = 0; i < dataWindows.size(); i++)
    {
        if(dataWindows.at(i).getWindowType() == windowType)
            dataWindows.at(i).clearTextComponents();
    }
}