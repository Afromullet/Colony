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
#include <memory>

#include "Constants.hpp"


InventoryWindow inventoryWindow;
ExamineWindow examineWindow;

PlayerGUI playerGUI;

tgui::Theme::Ptr defaultTheme;

float INVENTORY_WINDOWX_SIZE = WINDOW_X/2;
float INVENTORY_WINDOWY_SIZE = WINDOW_Y/2;
float INVENTORY_WINDOWX_POSITION = WINDOW_X/4;
float INVENTORY_WINDOWY_POSITION = 0;

float ADDIT_INVENTORY_ACTIONS_WINDOWX_SIZE = WINDOW_X / 4;
float ADDIT_INVENTORY_ACTIONS_WINDOWY_SIZE = WINDOW_Y / 4;
float ADDIT_INVENTORY_ACTIONS_WINDOWX_POSITION = INVENTORY_WINDOWX_POSITION + INVENTORY_WINDOWX_SIZE / 2;
float ADDIT_INVENTORY_ACTIONS_WINDOWY_POSITION = INVENTORY_WINDOWY_SIZE / 2;

float EXAMINE_INV_WINDOW_X_SIZE;
float EXAMINE_INV_WINDOW_Y_SIZE;
float EXAMINE_INV_WINDOW_X_POSITION = INVENTORY_WINDOWX_POSITION + INVENTORY_WINDOWX_SIZE / 2;
float EXAMINE_INV_WINDOW_Y_POSITION = INVENTORY_WINDOWY_SIZE / 2;


float EQUIPMENT_WINDOWX_SIZE = WINDOW_X/2;
float EQUIPMENT_WINDOWY_SIZE  = WINDOW_Y/2;
float EQUIPMENT_WINDOWX_POSITION = WINDOW_X/4;
float EQUIPMENT_WINDOWY_POSITION = 0;


float ADDIT_EQUIPMENT_ACTIONS_WINDOWX_SIZE = WINDOW_X / 4;
float ADDIT_EQUIPMENT_ACTIONS_WINDOWY_SIZE = WINDOW_Y / 4;
float ADDIT_EQUIPMENT_ACTIONS_WINDOWX_POSITION = EQUIPMENT_WINDOWX_POSITION + ADDIT_EQUIPMENT_ACTIONS_WINDOWX_SIZE / 2;
float ADDIT_EQUIPMENT_ACTIONS_WINDOWY_POSITION  = EQUIPMENT_WINDOWY_SIZE / 2;


PlayerGUI::PlayerGUI()
{
  
}

void PlayerGUI::SetupPlayerGUI(tgui::Gui &guiRef,BaseCreature *_creature)
{
    creature = _creature;
    inventoryWindow.setupWidgets(guiRef,_creature);
    inventoryWindow.setupSignals();
    //EquipmentWindow.setupWidgets(guiRef,_creature);
   // EquipmentWindow.setupSignals();
}


void PlayerGUI::HandleInventoryEvent(sf::Event &event,tgui::Gui &guiRef)
{
    //Don't want to move when navigating through the inventory
     if(inventoryWindow.isAnyWindowVisible())
         creature->setCanMove(false);
     else
         creature->setCanMove(true);
    
     inventoryWindow.HandleEvent(event,guiRef);
}

void SelectionWindow::SetupMainWindow(std::string tag, int xSize,int ySize,int xPosition,int yPosition,tgui::Gui &guiRef)
{
    mainWindowTag = tag;
    
    if(gui.get<SelectionWindowWidgetType>(mainWindowTag))
        guiRef.remove(mainWindow);
    
 
    
    mainWindow = SelectionWindowWidgetType::create();
    mainWindow->setSize(sf::Vector2f(xSize,ySize));
    mainWindow->setPosition(sf::Vector2f(xPosition,yPosition));
    //mainWindow->hide();
    
    guiRef.add(mainWindow,mainWindowTag);

    
}

SelectionWindow::SelectionWindow()
{
    
}

void SelectionWindow::SetupActionWindow(std::string tag, int xSize,int ySize,int xPosition,int yPosition,tgui::Gui &guiRef)
{
    
}
void SelectionWindow::SetupExamineWindow(std::string tag, int xSize,int ySize,int xPosition,int yPosition,tgui::Gui &guiRef)
{
    
}

void SelectionWindow::AddTextToMainWindow(const std::string &str)
{
    mainWindow->addItem(str);
}

void SelectionWindow::setCreature(BaseCreature *_creature)
{
    creature = _creature;
}


ExamineWindow::ExamineWindow()
{
    
}


void ExamineWindow::show()
{
    examineBox->show();
}

void ExamineWindow::hide()
{
    examineBox->hide();
}

bool ExamineWindow::isVisible()
{
    return examineBox->isVisible();
}

void ExamineWindow::setText(const std::string &str)
{
    
    examineBox->setText(str);
}


//This widget is different than windows that have signals, but for the sake of consistently
//This one is also going to be created in a similar manner
void ExamineWindow::setupWidgets(tgui::Gui &guiRef,std::string _tag)
{
    tag = _tag;
    
    
    if(gui.get<ExamineBoxWidgetType>(tag))
        guiRef.remove(examineBox);
    
    examineBox = ExamineBoxWidgetType::create();
    
    examineBox->setPosition(sf::Vector2f(EXAMINE_INV_WINDOW_X_POSITION,EXAMINE_INV_WINDOW_Y_POSITION));
    examineBox->setReadOnly();
    examineBox->hide();
    guiRef.add(examineBox,tag);
    
}







InventoryWindow::InventoryWindow()
{
    curItemIndex = 0;
    curActionsIndex = 0;
    
}

void InventoryWindow::InventoryDoubleClickAction(std::string name)
{
    std::cout << "\n inv double click";
    curItemIndex = inventoryBox->getSelectedItemIndex();
    additionalActionsWindow->setSelectedItemByIndex(0);
    additionalActionsWindow->show();
    
}

void InventoryWindow::AdditionalActionsDoubleClick(std::string name)
{
    AdditionalActionsHandler(name);

}



void InventoryWindow::AdditionalActionsHandler(std::string name)
{

    
    curActionsIndex = additionalActionsWindow->getSelectedItemIndex();
    
    
    if(name == EXAMINE_OPTION)
    {
        //examineWindow.setText("Test");
        if(creature->inventory.getInventorySize() > 0)
            examineWindow.setText(creature->inventory.getItemDescriptionAtIndex(curItemIndex));
        
        examineWindow.show();
        std::cout << "\n Examining";
    }
    else if(name == DROP_OPTION)
    {
        std::cout << "\n Dropping";
    }
    else if(name == EQUIP_OPTION)
    {
        std::cout << "\n Equipping";
    }
    
    additionalActionsWindow->show();
}

void InventoryWindow::HandleEvent(sf::Event &event,tgui::Gui &guiRef)
{
    
    HandleInventoryWindowEvent(event,guiRef);
    
    
    //if(inventory.getInventorySize() > 0)
     //   examineWindow.setText(inventory.getItemDescriptionAtIndex(curItemIndex));
}


void InventoryWindow::HandleInventoryWindowEvent(sf::Event &event,tgui::Gui &guiRef)
{
    

    //Consider using textbox rendere, and when the additional action window is open
    //Change the color of the inventoryBox selector to the background, so that it doesn't display
    //when the player scrolls over the window with the additional actions window open todo
    
    
    
    if(additionalActionsWindow->isVisible() && !examineWindow.isVisible())
    {
        
        
        inventoryBox->deselectItem(); //So that the inventory double click action is not triggered again when the additional actions window is open
    }
    else if(examineWindow.isVisible() && additionalActionsWindow->isVisible() && inventoryBox->isVisible())
    {
        //So that the inventory double click action is not triggered again when the additional actions window is open
        inventoryBox->deselectItem();
        
        additionalActionsWindow->deselectItem();
    }
    
    if(!inventoryBox->isVisible())
    {
        if(event.key.code == OPEN_INVENTORY_KEY)
        {
            
            UpdateInventory();
            inventoryBox->show();
            
        }
    }
    else if(inventoryBox->isVisible() && !additionalActionsWindow->isVisible() && !examineWindow.isVisible())
    {
        if(event.key.code == CLOSE_WINDOW_KEY && event.type == sf::Event::KeyReleased)
        {
            inventoryBox->removeAllItems();
            inventoryBox->hide();
         
        }
        else if(event.key.code == DOWN_KEY && event.type == sf::Event::KeyReleased)
        {
        
            int index = inventoryBox->getSelectedItemIndex();
            inventoryBox->setSelectedItemByIndex(++index);
        }
        else if(event.key.code == UP_KEY && event.type == sf::Event::KeyReleased)
        {
            int index = inventoryBox->getSelectedItemIndex();
            inventoryBox->setSelectedItemByIndex(--index);
        }
        else if(event.key.code == SELECT_ACTION_KEY && event.type == sf::Event::KeyReleased)
        {
            
            curItemIndex = inventoryBox->getSelectedItemIndex();
            additionalActionsWindow->show();
        }
        
        
    }
    else if(inventoryBox->isVisible() && additionalActionsWindow->isVisible() && !examineWindow.isVisible())
    {
        if(event.key.code == CLOSE_WINDOW_KEY && event.type == sf::Event::KeyReleased)
        {
            additionalActionsWindow->hide();
        }
        else if(event.key.code == DOWN_KEY && event.type == sf::Event::KeyReleased)
        {
            
            int index = additionalActionsWindow->getSelectedItemIndex();
            additionalActionsWindow->setSelectedItemByIndex(++index);
        }
        else if(event.key.code == UP_KEY && event.type == sf::Event::KeyReleased)
        {
            int index = additionalActionsWindow->getSelectedItemIndex();
            additionalActionsWindow->setSelectedItemByIndex(--index);
        }
        else if(event.key.code == SELECT_ACTION_KEY && event.type == sf::Event::KeyReleased)
        {
            
            curActionsIndex = additionalActionsWindow->getSelectedItemIndex();
            AdditionalActionsHandler(additionalActionsWindow->getSelectedItem());
            //additionalActionsWindow->show();
        }
        
    }
    else if(inventoryBox->isVisible() && additionalActionsWindow->isVisible() && examineWindow.isVisible())
    {
        if(event.key.code == CLOSE_WINDOW_KEY && event.type == sf::Event::KeyReleased)
        {
            examineWindow.hide();
            
        }
  
    }
    
    
}






void InventoryWindow::setupWidgets(tgui::Gui &guiRef,BaseCreature *_creature)
{
    
    creature = _creature;
    
    
    inventoryWindow.setCreature(_creature);
    
    SetupMainWindow(INVENTORY_WIDGET_TAG,INVENTORY_WINDOWX_SIZE,INVENTORY_WINDOWY_SIZE,INVENTORY_WINDOWX_POSITION,INVENTORY_WINDOWY_POSITION,guiRef);
    
    
    
    
    
    
    
    
    
    inventoryBoxTag = INVENTORY_WIDGET_TAG;
    additionalActionsBoxTag = INVENTORY_ADDITIONAL_ACTIONS_WIDGET_TAG;
    examineWindowTag =INVENTORY_EXAMINEBOX_TAG;
    
    if(gui.get<InventoryWidgetType>(inventoryBoxTag))
        guiRef.remove(inventoryBox);
    
    if(gui.get<InventoryAdditionalActionsWidget>(additionalActionsBoxTag))
        guiRef.remove(additionalActionsWindow);
    
    inventoryBox = InventoryWidgetType::create();
    inventoryBox->setSize(sf::Vector2f(INVENTORY_WINDOWX_SIZE,INVENTORY_WINDOWY_SIZE));
    inventoryBox->setPosition(sf::Vector2f(INVENTORY_WINDOWX_POSITION,INVENTORY_WINDOWY_POSITION));
    inventoryBox->hide();
    
    guiRef.add(inventoryBox,inventoryBoxTag);
    
    //Defining the actions that the player can take when rightclicking in the inventory window
    additionalActionsWindow = InventoryAdditionalActionsWidget::create();
    additionalActionsWindow->setPosition(sf::Vector2f(ADDIT_INVENTORY_ACTIONS_WINDOWX_POSITION,ADDIT_INVENTORY_ACTIONS_WINDOWY_POSITION));
    //additionalActionsWindow->setSize(ADDIT_INVENTORY_ACTIONS_WINDOWX_SIZE,ADDIT_INVENTORY_ACTIONS_WINDOWY_SIZE);
    additionalActionsWindow->addItem(EXAMINE_OPTION);
    additionalActionsWindow->addItem(DROP_OPTION);
    additionalActionsWindow->addItem(EQUIP_OPTION);
    additionalActionsWindow->hide(); //It isn't shown until after right click so hide at startup
    guiRef.add(additionalActionsWindow,additionalActionsBoxTag);
    
    examineWindow.setupWidgets(guiRef,examineWindowTag);
    
}

void InventoryWindow::setupSignals()
{
    if(inventoryBox)
    {
        inventoryBox->connect(DOUBLE_CLICK_SIGNAL,&::InventoryWindow::InventoryDoubleClickAction,this);
    }
    
    additionalActionsWindow->connect(DOUBLE_CLICK_SIGNAL,&::InventoryWindow::AdditionalActionsDoubleClick,this);
}



void InventoryWindow::UpdateInventory()
{
    int inventorySize = creature->inventory.getInventorySize();
    for(int i = 0; i < inventorySize; i++)
    {
        inventoryBox->addItem(creature->inventory.getItemNameAtIndex(i));
        AddTextToMainWindow(creature->inventory.getItemNameAtIndex(i));
    }
}


int InventoryWindow::getCurItemIndex()
{
    return curItemIndex;
}

bool InventoryWindow::isAnyWindowVisible()
{
    return inventoryBox->isVisible() || additionalActionsWindow->isVisible() || examineWindow.isVisible();
}

bool InventoryWindow::isInventoryWindowVisible()
{
    return inventoryBox->isVisible();
}

bool InventoryWindow::isadditionalActionWindowVisible()
{
    return additionalActionsWindow->isVisible();
}

bool InventoryWindow::isExamineWindowVisible()
{
    return examineWindow.isVisible();
}

void InventoryWindow::setPosition(float x, float y)
{
    inventoryBox->setPosition(sf::Vector2f(x,y));
}
void InventoryWindow::setSize(float x, float y)
{
    inventoryBox->setSize(sf::Vector2f(x,y));
}


EquipmentWindow::EquipmentWindow()
{
    curItemIndex = 0;
    curActionsIndex = 0;
}

void EquipmentWindow::EquipDoubleClickAction(std::string name)
{
    std::cout << "\n Eq double click";
    curItemIndex = equipmentBox->getSelectedItemIndex();
    additionalActionsWindow->setSelectedItemByIndex(0);
    additionalActionsWindow->show();
}

void EquipmentWindow::AdditionalActionsDoubleClick(std::string name)
{
    if(equipmentBox)
    {
        equipmentBox->connect(DOUBLE_CLICK_SIGNAL,&::EquipmentWindow::EquipDoubleClickAction,this);
    }
    
    additionalActionsWindow->connect(DOUBLE_CLICK_SIGNAL,&::EquipmentWindow::AdditionalActionsDoubleClick,this);
}

void EquipmentWindow::setupWidgets(tgui::Gui &guiRef,BaseCreature *_creature)
{
    
    creature = _creature;
    equipmentBoxTag = EQUIPMENT_WIDGET_TAG;
    additionalActionsBoxTag = EQUIMENT_ADDITIONAACTIONS_WIDGET_TAG;
    examineWindowTag =EQUIPMENT_EXAMINEBOX_TAG;
    
    if(gui.get<EquipmentWidgetType>(equipmentBoxTag))
        guiRef.remove(equipmentBox);
    
    if(gui.get<EquipmentAdditActionsWidget>(additionalActionsBoxTag))
        guiRef.remove(additionalActionsWindow);
    
    equipmentBox = EquipmentWidgetType::create();
    equipmentBox->setSize(sf::Vector2f(EQUIPMENT_WINDOWX_SIZE,EQUIPMENT_WINDOWY_SIZE));
    equipmentBox->setPosition(sf::Vector2f(EQUIPMENT_WINDOWX_POSITION,EQUIPMENT_WINDOWY_POSITION));
    equipmentBox->hide();
    
    guiRef.add(equipmentBox,equipmentBoxTag);
    
    //Defining the actions that the player can take when rightclicking in the inventory window
    additionalActionsWindow = EquipmentAdditActionsWidget::create();
    additionalActionsWindow->setPosition(sf::Vector2f(ADDIT_EQUIPMENT_ACTIONS_WINDOWX_POSITION,ADDIT_EQUIPMENT_ACTIONS_WINDOWY_POSITION));
    //additionalActionsWindow->setSize(ADDIT_INVENTORY_ACTIONS_WINDOWX_SIZE,ADDIT_INVENTORY_ACTIONS_WINDOWY_SIZE);
    additionalActionsWindow->addItem(EXAMINE_OPTION);
    additionalActionsWindow->addItem(DROP_OPTION);
    additionalActionsWindow->addItem(EQUIP_OPTION);
    additionalActionsWindow->hide(); //It isn't shown until after right click so hide at startup
    guiRef.add(additionalActionsWindow,additionalActionsBoxTag);
    
    examineWindow.setupWidgets(guiRef,examineWindowTag);
}

void EquipmentWindow::setupSignals()
{
    
}


void EquipmentWindow::UpdateEquipment()
{
    
}

int EquipmentWindow::getCurItemIndex()
{
    return curItemIndex;
}

bool EquipmentWindow::isAnyWindowVisible()
{
    return equipmentBox->isVisible() || additionalActionsWindow->isVisible() || examineWindow.isVisible();

}

bool EquipmentWindow::isEquipmentWindowVisible()
{
    return equipmentBox->isVisible();
}

bool EquipmentWindow::isadditionalActionWindowVisible()
{
    return additionalActionsWindow->isVisible();
}

bool EquipmentWindow::isExamineWindowVisible()
{
    return examineWindow.isVisible();
}


void SetupGUI(tgui::Gui &guiRef)
{
 
    
    
    defaultTheme = tgui::Theme::create("Black.txt");
    
   // inventoryWindow.setupWidgets(guiRef);
   // inventoryWindow.setupSignals();
    playerGUI.SetupPlayerGUI(guiRef,&player);
    //examineWindow.setupWidgets(guiRef,INVENTORY_EXAMINEBOX_TAG_MODIFIER);
    
}









