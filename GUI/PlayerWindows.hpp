//
//  PlayerWindows.hpp
//  Colony
//
//  Created by Sean on 7/7/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef PlayerWindows_hpp
#define PlayerWindows_hpp

#include <stdio.h>
#include "BaseCreature.hpp"
#include "BodyGraph.hpp"
#include <string>

#include <TGUI/TGUI.hpp>
#include "KeyDefinitions.hpp"
#include <memory>

#include "BaseCreature.hpp"
#include "Map.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "Globals.hpp"
#include <memory>

//#include "BodyGraphGetters.hpp"
#include "Constants.hpp"
#include "Wound.hpp"





///The typedefs for the widgets are here in case I ever choose to change the widget type.

typedef tgui::ListBox SelectionWindowWidgetType;
typedef tgui::ListBox AdditionalActionsWidgetType;
typedef tgui::TextBox ExamineBoxWidgetType;



typedef tgui::ListBox InventoryWidgetType;
typedef tgui::ListBox InventoryAdditionalActionsWidget;



typedef tgui::ListBox EquipmentWidgetType;
typedef tgui::ListBox EquipmentAdditActionsWidget;
typedef tgui::ListBox EquipmentExamineBoxWidgetType;


#define MAIN_WINDOW_WIDGETTYPE_TEXT "ListBox"
#define ADDITACTIONS_WIDGETTYPE_TEXT "ListBox"
#define EXAMINEWINDOW_WIDGETTYPE_TEXT "TextBox"

//Tags for each type of widget
#define INVENTORY_WIDGET_TAG "INVENTORY_COMBO_BOX"
#define INVENTORY_ADDITIONAL_ACTIONS_WIDGET_TAG "INVENTORY_RIGHTCLICK_BOX"
#define INVENTORY_EXAMINEBOX_TAG "EXAMINE_INVENTORY"

#define EQUIPMENT_WIDGET_TAG "EQUIPMENT"
#define EQUIMENT_ADDITIONAACTIONS_WIDGET_TAG "EQUIPMENT_ADDITIONALACTIONS_BOX"
#define EQUIPMENT_EXAMINEBOX_TAG "EXAMINE_EQUIPMENT_BOX"


#define TILE_INVENTORY_WIDGET_TAG "TILE_INVENTORY_COMBO_BOX"
#define TILE_INVENTORY_ADDITIONAL_ACTIONS_WIDGET_TAG "TILE_INVENTORY_RIGHTCLICK_BOX"
#define TILE_INVENTORY_EXAMINEBOX_TAG "TILE_EXAMINE_INVENTORY"

#define TILE_EXAMINEBOX_TAG "TILE_EXAMINE_BOX"


//Actions for the Inventory Right Click Menu. The Letter) is the keyboard instead of click option
#define EXAMINE_OPTION "Examine"
#define DROP_OPTION "Drop"
#define EQUIP_OPTION "Equip"
#define GRAB_OPTION "Grab"


//Default theme for the widgets
extern tgui::Theme::Ptr defaultTheme;

//Defines for the widget signals. Making it a define to reduce likelihood of typos
#define DOUBLE_CLICK_SIGNAL "DoubleClicked"
#define SINGLE_CLICK_SIGNAL "MousePressed"

extern float INVENTORY_WINDOWX_SIZE;
extern float INVENTORY_WINDOWY_SIZE;
extern float INVENTORY_WINDOWX_POSITION;
extern float INVENTORY_WINDOWY_POSITION;

extern float ADDIT_INVENTORY_ACTIONS_WINDOWX_SIZE;
extern float ADDIT_INVENTORY_ACTIONS_WINDOWY_SIZE;
extern float ADDIT_INVENTORY_ACTIONS_WINDOWX_POSITION;
extern float ADDIT_INVENTORY_ACTIONS_WINDOWY_POSITION;


extern float EXAMINE_INV_WINDOW_X_SIZE;
extern float EXAMINE_INV_WINDOW_Y_SIZE;
extern float EXAMINE_INV_WINDOW_X_POSITION;
extern float EXAMINE_INV_WINDOW_Y_POSITION;

extern float EQUIPMENT_WINDOWX_SIZE;
extern float EQUIPMENT_WINDOWY_SIZE;
extern float EQUIPMENT_WINDOWX_POSITION;
extern float EQUIPMENT_WINDOWY_POSITION;

extern float ADDIT_EQUIPMENT_ACTIONS_WINDOWX_SIZE;
extern float ADDIT_EQUIPMENT_ACTIONS_WINDOWY_SIZE;
extern float ADDIT_EQUIPMENT_ACTIONS_WINDOWX_POSITION;
extern float ADDIT_EQUIPMENT_ACTIONS_WINDOWY_POSITION;


/*
 An examinewindow is a window that displays text. It's pretty much just a textbox
 
 */
class ExamineWindow
{
private:
    ExamineBoxWidgetType::Ptr examineBox;
    std::string tag; //There are multiple places that use the examinebox, so store the tag an instance uses
    
    
    
public:
    ExamineWindow();
    
    void show();
    void hide();
    bool isVisible();
    
    void setText(const std::string &str);
    
    void setupWidgets(tgui::Gui &guiRef,std::string _tag,int xPosition, int yPosition); //There can be multiple types of examine boxes, that's what the tag modifier is for
    
    
    
};


/*
 
 A window that displays options of things to select
 
 I.E, select an item, you can "examine,drop,equip" so we'd end up with a window like this:
 
 --------
 -Look   -
 -Drop   -
 -Equip  -
 _________
 
 
 
 Te AdditionalActionsHandler handles the actions for the selection
 


*/
class SelectionWindow
{
private:


    

 
protected:
    
    SelectionWindowWidgetType::Ptr mainWindow;
    AdditionalActionsWidgetType::Ptr additional_ActionsWindow;
    ExamineWindow examineWindow;
    
    BaseCreature *creature;
    
    std::string mainWindowTag;
    std::string additionalActionsWindowTag;
    std::string examineWindowTag;
    
    int curItemIndex;
    int curActionsIndex;
    
public:
    

    
    SelectionWindow();
    
    void SetupMainWindow(std::string tag, int xSize,int ySize,int xPosition,int yPosition,tgui::Gui &guiRef);
    void SetupActionWindow(std::string tag, int xSize,int ySize,int xPosition,int yPosition,tgui::Gui &guiRef);
    void SetupExamineWindow(std::string tag, int xSize,int ySize,int xPosition,int yPosition,tgui::Gui &guiRef);
    
    void MainDoubleClickAction(std::string name);
    bool isAnyInitialWindowVisible();
    
    //Registered to the tgui double click actions
    virtual void AdditionalActionsDoubleClick(std::string name) = 0; 
    
    //Name is the name of the action in the selection window.  Implements the logic for action of name n
    virtual void AdditionalActionsHandler(std::string name) = 0;
    
    //Connects the action to the gui elements
    virtual void setupSignals() = 0;
    
    //Handles the keyboard-window logic..I.E, if window1 is open and window2 is not, you can move in windows1
    virtual void HandleEvent(sf::Event &event,tgui::Gui &guiRef) = 0;
    virtual void UpdateMainWindow() = 0;
    virtual void HideAllWindows() = 0;
    virtual bool isAnyWindowVisible() = 0;
   // virtual void AddActionWindowOption(const std::string str) = 0;
    
    void AddTextToMainWindow(const std::string &str);
    void AddAdditionalAction(const std::string &str);
    
    void setCreature(BaseCreature *_creature);
    
    void showMainWindow();
    void showAdditionalActionsWindow();
    void showExamineWindow();
    
    void hideMainWindow();
    void hideAdditionalActionsWindow();
    void hideExamineWindow();
    
    
    bool isMainWindowVisible();
    bool isAdditionalActionsWindowVisible();
    bool isExamineWindowVisible();
    
    
    
    
};







class InventoryWindow : public SelectionWindow
{

   
public:
    
    InventoryWindow();
    BaseCreature *creature;
    
   
    void AdditionalActionsDoubleClick(std::string name);
    void AdditionalActionsHandler(std::string name);
    void HandleEvent(sf::Event &event,tgui::Gui &guiRef);
    void HandleWindowEvent(sf::Event &event,tgui::Gui &guiRef);
    void setupWidgets(const std::string &mainWindowTag, const std::string &exWindowTag,const std::string &additionalActionsWindowTag,tgui::Gui &guiRef,BaseCreature *_creature);
    void setupSignals();
    void UpdateMainWindow();
    bool isAnyWindowVisible();
    void HideAllWindows();

};

class EquipmentWindow : public SelectionWindow
{

public:
    
    EquipmentWindow();
    
    
    
    void AdditionalActionsDoubleClick(std::string name);
    void AdditionalActionsHandler(std::string name);
    void HandleEvent(sf::Event &event,tgui::Gui &guiRef);
    void HandleWindowEvent(sf::Event &event,tgui::Gui &guiRef);
    void setupWidgets(const std::string &mainWindowTag, const std::string &exWindowTag,const std::string &additionalActionsWindowTag,tgui::Gui &guiRef,BaseCreature *_creature);
    void setupSignals();
    
    void UpdateMainWindow();

    bool isAnyWindowVisible();
    void HideAllWindows();
    
    
    
    
    
    
    
    
};
//Creature inventory window and tile inventory window are so similar that I
//Really shouldn't have to create this subclass. Unfortunately I didn't anticipate
//that I would just reuse itemanager for the tile inventory.



class TileInventoryWindow : public SelectionWindow
{
private:

    Tile *tile;
    BaseCreature *creature;
    Map *map;
    


public:
    
    TileInventoryWindow();
    
    
    
    void AdditionalActionsDoubleClick(std::string name);
    
    
    void AdditionalActionsHandler(std::string name);
    
    void HandleEvent(sf::Event &event,tgui::Gui &guiRef);
    void HandleWindowEvent(sf::Event &event,tgui::Gui &guiRef);
    
    void setTile(Map &map, int x, int y);
    void setupWidgets(const std::string &mainWindowTag, const std::string &exWindowTag,const std::string &additionalActionsWindowTag,tgui::Gui &guiRef,BaseCreature *_creature);
    void setupSignals();
    void setMap(Map *_map);
    void setCreature(BaseCreature *_creature);
    
    void UpdateMainWindow();
    bool isAnyWindowVisible();
    void HideAllWindows();
    
    
    
    
    
    
    
    
};






class PlayerGUI
{
private:
    InventoryWindow inventoryWindow;
    EquipmentWindow equipmentWindow;
   
    
    BaseCreature *creature;
    
    
public:
    PlayerGUI();
    void HandleEvent(sf::Event &event,tgui::Gui &guiRef);
    void HandleWindowEvent(sf::Event &event,tgui::Gui &guiRef);
    void SetupPlayerGUI(tgui::Gui &guiRef,BaseCreature *_creature);
    
    
};

class TileGUI
{
private:
    TileInventoryWindow inventoryWindow;
    EquipmentWindow equipmentWindow;
   // Map *map;
    
    BaseCreature *creature;
    
    
public:
    TileGUI();
    void HandleEvent(sf::Event &event,tgui::Gui &guiRef);
    void HandleWindowEvent(sf::Event &event,tgui::Gui &guiRef);
    void SetupTileGUI(tgui::Gui &guiRef,BaseCreature *_creature, Map *_map);
    
    
};




extern InventoryWindow inventoryWindow;
extern ExamineWindow examineWindow;
extern PlayerGUI playerGUI;
extern TileGUI  tileGUI;


void SetupGUI(tgui::Gui &guiRef);
void SetupGUIWidgets();
void SetupGUISignals();



#endif /* PlayerWindows_hpp */
