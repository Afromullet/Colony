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
#include "KeyDefinitions.hpp"


//The EnDataWindow identifies what sort of data we display in the window
//This class just holds a data window, and chooses the appropriate actions on how to treat it
//based on the window type
class WindowCommands
{


    
    
 
public:
    
    std::vector<DataWindow> dataWindows;
    
    
    void addDataWindow(DataWindow _dataWindow);
    void GetWindowData(BaseCreature &creature,EnDataWindowType windowType,DataWindow &dataWindow);
    void getInventoryData(BaseCreature &creature,DataWindow &dataWindow);
    void getEquipmentData(BaseCreature &creature,DataWindow &dataWindow);
    bool isAnyWindowOpen();
    
    DataWindow& selectWindow(EnDataWindowType windowType);
    DataWindow& selectWindow(EnDataWindowType mainWindowType,EnDataWindowType subWindowType);
    void setAllWindowsToClose();
    void clearWindowText(EnDataWindowType windowType);
   
   

    void handleWindowHighlighter(DataWindow& _dataWindow,sf::Keyboard::Key key);
    void handleOpenMainWindow(sf::Keyboard::Key key);
    void handleMainWindowAction(BaseCreature &creature, EnDataWindowType windowType,sf::Keyboard::Key key);
    void handleSubWindowAction(BaseCreature &Creature, EnDataWindowType windowType,sf::Keyboard::Key key);
    
    
   
 
    
   
    
    
};

#endif /* WindowCommands_hpp */
