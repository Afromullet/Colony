//
//  WindowCommands.hpp
//  Colony
//
//  Created by Sean on 1/13/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef WindowCommands_hpp
#define WindowCommands_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "BaseCreature.hpp"
#include "DataWindow.hpp"
#include <vector>


//The EnDataWindow identifies what sort of data we display in the window
//This class just holds a data window, and chooses the appropriate actions on how to treat it
//based on the window type
class WindowCommands
{


    
    
 
public:
    
    std::vector<DataWindow> dataWindows;
    
    
    void addDataWindow(DataWindow _dataWindow, EnDataWindowType windowType);
    void addDataWindow(DataWindow _dataWindow);
    void GetWindowData(BaseCreature &creature,EnDataWindowType windowType);
    void getInventoryData(BaseCreature &creature,DataWindow &dataWindow);
    void getEquipmentData(BaseCreature &creature,DataWindow &dataWindow);
    void setIsWindowOpen(EnDataWindowType windowType, bool truthValue);
    DataWindow& selectWindow(EnDataWindowType windowType);
    void setAllWindowsToClose();
    void clearWindowText(EnDataWindowType windowType);
    void HandleWindowCommand(sf::Keyboard::Key key,EnDataWindowType windowType);
    void SelectWindowCommand(sf::Keyboard::Key key);
    
    bool isAnyWindowOpen();
 
    
   
    
    
};

#endif /* WindowCommands_hpp */
