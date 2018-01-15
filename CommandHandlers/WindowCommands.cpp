//
//  WindowCommands.cpp
//  Colony
//
//  Created by Sean on 1/13/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "WindowCommands.hpp"
#include "Constants.hpp"



void WindowCommands::addDataWindow(DataWindow _dataWindow)
{

    dataWindows.push_back(_dataWindow); //TODO add check to make sure multiple windows of the same type can't be added
}

//The windowType determines the context..tells us what data to put in the window
void WindowCommands::GetWindowData(BaseCreature &creature,EnDataWindowType windowType,DataWindow &dataWindow)
{
    
    if(windowType == enInventoryWindow)
    {
        getInventoryData(creature,selectWindow(enInventoryWindow));
        
        for(int i = 0; i < dataWindows.size(); i++)
        {
            //Setup sup windows
            DataWindow &tempWindow = dataWindow.getSubWindow(enInventorySelectWindow);
            tempWindow.clearTextComponents();
            tempWindow.AddText("x) Examine");
            tempWindow.AddText("e) Equip");
            tempWindow.AddText("t) Throw");
            tempWindow.setTextColor(sf::Color::Red);
        }
    }
    else if(windowType == enEquipmentWindow)
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

bool WindowCommands::isAnyWindowOpen()
{
    bool retVal = false;
    
    for(int i=0; i < dataWindows.size(); i++)
    {
        if(dataWindows.at(i).isOpen)
        {
            retVal = true;
            break;
            
        }
        else
        {
            
            //Search the sub windows
            for(int j=0; j > dataWindows.at(i).subWindows.size(); j++)
            {
                if(dataWindows.at(i).subWindows.at(j).isOpen)
                {
                    retVal = true;
                    break;
                }
            }
            
        }
        
    }
    
    return retVal;
}

DataWindow& WindowCommands::selectWindow(EnDataWindowType windowType)
{
    for(int i = 0; i < dataWindows.size(); i++)
    {
        if(windowType == dataWindows.at(i).getWindowType())
            return dataWindows.at(i);
    }
    
}

//Returns the sub window of a particual type
DataWindow& WindowCommands::selectWindow(EnDataWindowType mainWindowType,EnDataWindowType subWindowType)
{
    for(int i = 0; i < dataWindows.size(); i++)
    {
        if(mainWindowType == dataWindows.at(i).getWindowType())
        {
            DataWindow &tempWindow = dataWindows.at(i);
         
            DataWindow &subWindow =  tempWindow.getSubWindow(subWindowType);
           
            
            return tempWindow.getSubWindow(subWindowType);
        }
        
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







void WindowCommands::handleOpenMainWindow(sf::Keyboard::Key key)
{
   // setAllWindowsToClose(); //First want to close all existing windows. Starting fresh
    
    if(key == OPEN_INVENTORY_KEY)
    {
        selectWindow(enInventoryWindow).isOpen = true;
    }
    else if(key == OPEN_EQUIPMENT_KEY)
    {
        selectWindow(enEquipmentWindow).isOpen = true;
    }
    
    
}

void WindowCommands::handleMainWindowAction(BaseCreature &creature, EnDataWindowType windowType,sf::Keyboard::Key key)
{
    DataWindow &tempWindow = selectWindow(windowType);
    
    if(!tempWindow.anySubWindowsOpen() && tempWindow.isOpen)
    {
        handleWindowHighlighter(tempWindow,key);
        
        if(key == CLOSE_WINDOW_KEY)
            tempWindow.isOpen = false;
        else if(key == SELECT_ACTION_KEY)
        {
            std::cout << "\n Offset " << tempWindow.highlightPosition;
        }
        
    }
    
    handleSubWindowAction(creature,windowType,key);
    
    
}

void WindowCommands::handleSubWindowAction(BaseCreature &Creature, EnDataWindowType windowType,sf::Keyboard::Key key)
{
    DataWindow &tempWindow = selectWindow(windowType);
    DataWindow &subWindow = tempWindow.getSubWindow(enInventorySelectWindow);
    DataWindow &subSubWindow = subWindow.getSubWindow(enExamineItemWindow);
  
        
    //Open the correct sub window and handle behavior
    if(tempWindow.getWindowType() == enInventoryWindow && tempWindow.isOpen)
    {
        if(key == OPEN_SELECTION_WINDOW_KEY && !subWindow.isOpen)
        {
            
            GetWindowData(Creature, enInventorySelectWindow, subWindow);
            subWindow.PrintTextToConsole();
            subWindow.isOpen = true;
            subWindow.initBasicHighlightSquare();
            
        }
        else if(subWindow.isOpen)
        {
            if(key == CLOSE_WINDOW_KEY)
                subWindow.isOpen = false;
            else if(key == SELECT_ACTION_KEY)
            {
                //Hardcoded based on the values set in GetWindowData..todo change
                if(subWindow.highlightPosition == 0)
                {
                    
                    subSubWindow.isOpen = true;
                    subSubWindow.initBasicHighlightSquare();
                    
                    
                    
                }
                std::cout << "\n Offset " << subWindow.highlightPosition;
            }
            
            
        }
        
        
    }
    
    if(tempWindow.anySubWindowsOpen() && tempWindow.isOpen)
    {
        handleWindowHighlighter(subWindow,key);
    }
    
    
}

void WindowCommands::handleWindowHighlighter(DataWindow& _dataWindow,sf::Keyboard::Key key)
{
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