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




///The typedefs for the widgets are here in case I ever choose to change the widget type.
typedef tgui::ListBox InventoryWidgetType;
typedef tgui::ListBox InventoryAdditionalActionsWidget;
typedef tgui::TextBox ExamineBoxWidgetType;




//Tags for each type of widget
#define INVENTORY_WIDGET_TAG "INVENTORY_COMBO_BOX"
#define INVENTORY_ADDITIONAL_ACTIONS_WIDGET_TAG "INVENTORY_RIGHTCLICK_BOX"
#define INVENTORY_EXAMINEBOX_TAG "EXAMINE_INVENTORY"





//Actions for the Inventory Right Click Menu. The Letter) is the keyboard instead of click option
#define EXAMINE_OPTION "Examine"
#define DROP_OPTION "Drop"
#define EQUIP_OPTION "Equip"

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
    
    void setupWidgets(tgui::Gui &guiRef,std::string _tag); //There can be multiple types of examine boxes, that's what the tag modifier is for
    
    

};



class InventoryWindow
{
private:
    InventoryWidgetType::Ptr inventoryBox;
    InventoryAdditionalActionsWidget::Ptr additionalActionsWindow;
    ExamineWindow examineWindow;
    
    
    std::string inventoryBoxTag;
    std::string additionalActionsBoxTag;
    std::string examineWindowTag;
    
    int curItemIndex;
    
public:
    
    InventoryWindow();
    
    
    void InventoryDoubleClickAction(std::string name);
    void AdditionalActionsDoubleClick(std::string name);
    
   
    
    void HandleEvent(sf::Event &event,tgui::Gui &guiRef,ItemManager &inventory);
    void HandleInventoryWindowEvent(sf::Event &event,tgui::Gui &guiRef,ItemManager &inventory);
    void HandleAdditonalActionsWindowEvent(sf::Event &event,tgui::Gui &guiRef,ItemManager &inventory);
    
       

    void setupWidgets(tgui::Gui &guiRef);
    void setupSignals();
       
    void UpdateInventory(ItemManager &inventory);
    
    void setPosition(float x, float y);
    void setSize(float x, float y);
    
};



class PlayerGUI
{
private:
    InventoryWindow inventoryWindow;
    BaseCreature *creature;
    
    
public:
    PlayerGUI();
    void HandleEvent(sf::Event &event,tgui::Gui &guiRef,ItemManager &inventory);
    void HandleInventoryEvent(sf::Event &event,tgui::Gui &guiRef);
    void SetupPlayerGUI(tgui::Gui &guiRef,BaseCreature *_creature);
    
    
};



extern InventoryWindow inventoryWindow;
extern ExamineWindow examineWindow;
extern PlayerGUI playerGUI;


void SetupGUI(tgui::Gui &guiRef);
void SetupGUIWidgets();
void SetupGUISignals();



#endif /* PlayerWindows_hpp */
