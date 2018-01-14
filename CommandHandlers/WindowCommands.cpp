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
    tempWindow.isHighlightOpen = false;
    
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
    else if(windowType == enEquipmentWindow)
    {
        getEquipmentData(creature,selectWindow(enEquipmentWindow));
    }
    else if(windowType == enInventorySelectWindow)
    {
        //This can just be added at window initialization.
        DataWindow &dataWindow = selectWindow(enInventorySelectWindow);
        
        dataWindow.AddText("x) Examine");
        dataWindow.AddText("e) Equip");
        dataWindow.AddText("t) Throw");
        dataWindow.setTextColor(sf::Color::Red);
        
        
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



void WindowCommands::handleOpenWindowCommand(sf::Keyboard::Key key)
{
    EnDataWindowType windowType;
    
    if(key == sf::Keyboard::I)
    {
        DataWindow &dataWindow = selectWindow(enInventoryWindow);
        dataWindow.isOpen = true;
    }
    else if(key == sf::Keyboard::P)
    {
        DataWindow &dataWindow = selectWindow(enEquipmentWindow);
        dataWindow.isOpen = true;
    }
}

void WindowCommands::handleOpenWindowAction(EnDataWindowType windowType,sf::Keyboard::Key key)
{
    DataWindow &tempWindow = selectWindow(windowType);
    
    if(tempWindow.getWindowType() == enInventoryWindow)
        handleInventoryWindowAction(tempWindow, key);
    else if(tempWindow.getWindowType() == enEquipmentWindow)
    {
        handleEquipmentWindowAction(tempWindow, key);
    }
    if(tempWindow.getWindowType() == enInventorySelectWindow)
    {
        handleInventorySelectionWindowAction(tempWindow, key);
    }
    
    
}
//Handle Equipment and Inventory action handle the actions when the window is open
//The movemet actions for a window can eventually be handled alltogether, no need to have one function for each window to handle it
void WindowCommands::handleInventoryWindowAction(DataWindow& _dataWindow,sf::Keyboard::Key key)
{
    
    if(_dataWindow.getWindowType() != enInventoryWindow)
        return;
    
    
   DataWindow &tempWindow = selectWindow(enInventorySelectWindow);
    
    //To be extra safe
    if(!_dataWindow.isOpen)
        return;
    
    if(tempWindow.isOpen == false)
    {
        if(key == sf::Keyboard::Down)
        {
            _dataWindow.MoveHighlightSquare(_dataWindow.highlightPosition + 1);
            //tempWindow.setYTextOffset(1);
        }
        else if(key == sf::Keyboard::Up)
        {
            _dataWindow.MoveHighlightSquare(_dataWindow.highlightPosition - 1);
            //tempWindow.setYTextOffset(1);
        
        }
    }
    
    
    if(key == sf::Keyboard::Space)
    {
        tempWindow.isHighlightOpen = false;
        handleSelectionWindowAction(tempWindow,key);
    }
 

}

void WindowCommands::handleEquipmentWindowAction(DataWindow& _dataWindow,sf::Keyboard::Key key)
{
    
    if(_dataWindow.getWindowType() != enEquipmentWindow)
        return;
    
    
    
    
    //To be extra safe
    if(!_dataWindow.isOpen)
        return;
    
    if(key == sf::Keyboard::Down)
    {
        _dataWindow.MoveHighlightSquare(_dataWindow.highlightPosition + 1);
        //tempWindow.setYTextOffset(1);
    }
    else if(key == sf::Keyboard::Up)
    {
        _dataWindow.MoveHighlightSquare(_dataWindow.highlightPosition - 1);
        //tempWindow.setYTextOffset(1);
        
    }
    
    
}

void WindowCommands::handleSelectionWindowAction(DataWindow& _dataWindow,sf::Keyboard::Key key)
{
    
    //Also add equipmentSelectWindow
    if(_dataWindow.getWindowType() != enInventorySelectWindow)
        return;
    


   
    if(_dataWindow.getWindowType() == enInventorySelectWindow)
        handleInventorySelectionWindowAction(_dataWindow, key);
    
    
}

void WindowCommands::handleInventorySelectionWindowAction(DataWindow& _dataWindow,sf::Keyboard::Key key)
{
    if(_dataWindow.getWindowType() != enInventorySelectWindow)
        return;
    
    //To be extra safe
    _dataWindow.isOpen = true;
     _dataWindow.isHighlightOpen = true;
    
    if(key == sf::Keyboard::Down)
    {
        _dataWindow.MoveHighlightSquare(_dataWindow.highlightPosition + 1);
        //tempWindow.setYTextOffset(1);
    }
    else if(key == sf::Keyboard::Up)
    {
        _dataWindow.MoveHighlightSquare(_dataWindow.highlightPosition - 1);
        //tempWindow.setYTextOffset(1);
        
    }
    
}

//Returns true if at least one window is open
bool WindowCommands::isAnyWindowOpen()
{
    for(int i = 0; i < dataWindows.size(); i++)
    {
        if(dataWindows.at(i).isOpen)
            return true;
    }
    
    return false;
}

