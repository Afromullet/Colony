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
       // getEquipmentData(creature,selectWindow(enEquipmentWindow));
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
    
    return dataWindows.at(0);
    
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
    
    //fix this temporary
    DataWindow &tempWindow = dataWindows.at(0);
     return tempWindow.getSubWindow(subWindowType);
    
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

void WindowCommands::handleMainWindowAction(BaseCreature &creature, DataWindow &dataWindow,sf::Keyboard::Key key)
{

    
    //If only the main window is open
    if(!dataWindow.anySubWindowsOpen() && dataWindow.isOpen)
    {
        handleWindowHighlighter(dataWindow,key);
        
        if(key == CLOSE_WINDOW_KEY)
            dataWindow.isOpen = false;
        else if(key == SELECT_ACTION_KEY)
        {
            std::cout << "\n Offset " << dataWindow.highlightPosition;
        }
        
    }
    
    

    
    handleSubWindowAction(creature,dataWindow,key); //Each window handles its own subwindow
    
    
    
    
}


//Window type is the window whose subwindows we are selecting
//The logic the sub windows currently follow is based on the hardcoded hierachy when initializing all window types
//I'm just checking a windows sub window and deciding on a list of known actions
void WindowCommands::handleSubWindowAction(BaseCreature &Creature, DataWindow &mainWindow,sf::Keyboard::Key key)
{
    
    
    
       DataWindow &subWindow = mainWindow.getSubWindow(enInventorySelectWindow);
    
        
    //If the main window is an inventory window, then we can
    //Control the highlighter and select something from the inventory
    //The inventory window currently only has one subwindow sub window
    if(mainWindow.getWindowType() == enInventoryWindow && mainWindow.isOpen)
    {
        //Subwindows not yet opened
        if(key == OPEN_SELECTION_WINDOW_KEY && !subWindow.isOpen)
        {
            
            GetWindowData(Creature, enInventorySelectWindow, subWindow);
            subWindow.PrintTextToConsole();
            subWindow.isOpen = true;
            subWindow.initBasicHighlightSquare();
            
        }
        
        else if(subWindow.isOpen)
        {
            if(subWindow.getWindowType() == enInventorySelectWindow)
            {
                mainWindow.isHighlightOpen = false;
                if(key == CLOSE_WINDOW_KEY)
                    subWindow.isOpen = false;
                else if(key == SELECT_ACTION_KEY)
                {
                    //Hardcoded based on the values set in GetWindowData..todo change
                    if(subWindow.highlightPosition == 0)
                    {
                        DataWindow &examineWindow = subWindow.getSubWindow(enExamineItemWindow);

                        examineWindow.isOpen = true;
                        examineWindow.initBasicHighlightSquare();
                    }
                }
            }
        }
        
    }
    
    if(mainWindow.anySubWindowsOpen() && mainWindow.isOpen)
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
