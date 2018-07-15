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


SelectionWindow::SelectionWindow()
{
    
}

void SelectionWindow::SetupMainWindow(std::string tag, int xSize,int ySize,int xPosition,int yPosition,tgui::Gui &guiRef)
{
    mainWindowTag = tag;
    
    if(gui.get<SelectionWindowWidgetType>(mainWindowTag))
        guiRef.remove(mainWindow);
    
    mainWindow = SelectionWindowWidgetType::create();
    mainWindow->setSize(sf::Vector2f(xSize,ySize));
    mainWindow->setPosition(sf::Vector2f(xPosition,yPosition));
    mainWindow->hide();
    
    guiRef.add(mainWindow,mainWindowTag);

    
}

void SelectionWindow::SetupActionWindow(std::string tag, int xSize,int ySize,int xPosition,int yPosition,tgui::Gui &guiRef)
{
    
   
    additionalActionsWindowTag = tag;
    

    if(gui.get<AdditionalActionsWidgetType>(additionalActionsWindowTag))
        guiRef.remove(additional_ActionsWindow);
    

    //Defining the actions that the player can take when rightclicking in the inventory window
    additional_ActionsWindow = InventoryAdditionalActionsWidget::create();
    additional_ActionsWindow->setPosition(sf::Vector2f(xPosition,yPosition));
    additional_ActionsWindow->hide(); //It isn't shown until after right click so hide at startup
    guiRef.add(additional_ActionsWindow,additionalActionsWindowTag);
    
    

}
void SelectionWindow::SetupExamineWindow(std::string tag, int xSize,int ySize,int xPosition,int yPosition,tgui::Gui &guiRef)
{
    examineWindow.setupWidgets(guiRef,tag);
    examineWindow.hide();
}

void SelectionWindow::AddTextToMainWindow(const std::string &str)
{
    mainWindow->addItem(str);
}

void SelectionWindow::AddAdditionalAction(const std::string &str)
{
    additional_ActionsWindow->addItem(str);
}

void SelectionWindow::setCreature(BaseCreature *_creature)
{
    creature = _creature;
}

void SelectionWindow::showMainWindow()
{
    mainWindow->show();
}
void SelectionWindow::showAdditionalActionsWindow()
{
    additional_ActionsWindow->show();
}
void SelectionWindow::showExamineWindow()
{
    examineWindow.show();
}

void SelectionWindow::hideMainWindow()
{
    mainWindow->hide();
}
void SelectionWindow::hideAdditionalActionsWindow()
{
    additional_ActionsWindow->hide();
}
void SelectionWindow::hideExamineWindow()
{
    examineWindow.hide();
}

bool SelectionWindow::isMainWindowVisible()
{
     return mainWindow->isVisible();
}

bool SelectionWindow::isAdditionalActionsWindowVisible()
{
    return additional_ActionsWindow->isVisible();
}

bool SelectionWindow::isExamineWindowVisible()
{
    return examineWindow.isVisible();
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

void InventoryWindow::DoubleClickAction(std::string name)
{
    
    std::cout << "\n inv double click";
    curItemIndex = mainWindow->getSelectedItemIndex();
    additional_ActionsWindow->setSelectedItemByIndex(0);
    additional_ActionsWindow->show();
    
}

void InventoryWindow::AdditionalActionsDoubleClick(std::string name)
{
    AdditionalActionsHandler(name);

}



void InventoryWindow::AdditionalActionsHandler(std::string name)
{


    curActionsIndex = additional_ActionsWindow->getSelectedItemIndex();
    
    
    if(name == EXAMINE_OPTION)
    {
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
    
    additional_ActionsWindow->show();
    
    
    
    
}

void InventoryWindow::HandleEvent(sf::Event &event,tgui::Gui &guiRef)
{
    HandleInventoryWindowEvent(event,guiRef);
}


void InventoryWindow::HandleInventoryWindowEvent(sf::Event &event,tgui::Gui &guiRef)
{
    
    
    
    if(isAdditionalActionsWindowVisible() && !isExamineWindowVisible())
    {
        mainWindow->deselectItem(); //So that the inventory double click action is not triggered again when the additional actions window is open
    }
    else if(isExamineWindowVisible() && isAdditionalActionsWindowVisible() && isMainWindowVisible())
    {
        //So that the inventory double click action is not triggered again when the additional actions window is open
        mainWindow->deselectItem();
        additional_ActionsWindow->deselectItem();
    }
    
    if(!isMainWindowVisible())
    {
        if(event.key.code == OPEN_INVENTORY_KEY)
        {
            UpdateInventory();
            mainWindow->show();
        }
    }
    else if(isMainWindowVisible() && !isAdditionalActionsWindowVisible() && !isExamineWindowVisible())
    {
        if(event.key.code == CLOSE_WINDOW_KEY && event.type == sf::Event::KeyReleased)
        {
            mainWindow->removeAllItems();
            mainWindow->hide();
        }
        else if(event.key.code == DOWN_KEY && event.type == sf::Event::KeyReleased)
        {
            int index = mainWindow->getSelectedItemIndex();
            mainWindow->setSelectedItemByIndex(++index);
        }
        else if(event.key.code == UP_KEY && event.type == sf::Event::KeyReleased)
        {
            int index = mainWindow->getSelectedItemIndex();
            mainWindow->setSelectedItemByIndex(--index);
        }
        else if(event.key.code == SELECT_ACTION_KEY && event.type == sf::Event::KeyReleased)
        {
            
            curItemIndex = mainWindow->getSelectedItemIndex();
            additional_ActionsWindow->show();
        }
        
        
    }
    else if(isMainWindowVisible() && isAdditionalActionsWindowVisible() && !isExamineWindowVisible())
    {
        if(event.key.code == CLOSE_WINDOW_KEY && event.type == sf::Event::KeyReleased)
        {
            additional_ActionsWindow->hide();
        }
        else if(event.key.code == DOWN_KEY && event.type == sf::Event::KeyReleased)
        {
            
            int index = additional_ActionsWindow->getSelectedItemIndex();
            additional_ActionsWindow->setSelectedItemByIndex(++index);
        }
        else if(event.key.code == UP_KEY && event.type == sf::Event::KeyReleased)
        {
            int index = additional_ActionsWindow->getSelectedItemIndex();
            additional_ActionsWindow->setSelectedItemByIndex(--index);
        }
        else if(event.key.code == SELECT_ACTION_KEY && event.type == sf::Event::KeyReleased)
        {
            
            curActionsIndex = additional_ActionsWindow->getSelectedItemIndex();
            AdditionalActionsHandler(additional_ActionsWindow->getSelectedItem());
            //additionalActionsWindow->show();
        }
        
    }
    else if(isMainWindowVisible() && isAdditionalActionsWindowVisible() && isExamineWindowVisible())
    {
        if(event.key.code == CLOSE_WINDOW_KEY && event.type == sf::Event::KeyReleased)
        {
            hideExamineWindow();
            
        }
        
    }
}






void InventoryWindow::setupWidgets(tgui::Gui &guiRef,BaseCreature *_creature)
{
    
    creature = _creature;
    
    
    inventoryWindow.setCreature(_creature);
    
    SetupMainWindow(INVENTORY_WIDGET_TAG,INVENTORY_WINDOWX_SIZE,INVENTORY_WINDOWY_SIZE,INVENTORY_WINDOWX_POSITION,INVENTORY_WINDOWY_POSITION,guiRef);
    
    SetupActionWindow(INVENTORY_ADDITIONAL_ACTIONS_WIDGET_TAG,INVENTORY_WINDOWX_SIZE,INVENTORY_WINDOWY_SIZE,ADDIT_INVENTORY_ACTIONS_WINDOWX_POSITION,ADDIT_INVENTORY_ACTIONS_WINDOWY_POSITION,guiRef);
    
    SetupExamineWindow(examineWindowTag,0,0,0,0,guiRef);

    AddAdditionalAction(EXAMINE_OPTION);
    AddAdditionalAction(DROP_OPTION);
    AddAdditionalAction(EQUIP_OPTION);
}

void InventoryWindow::setupSignals()
{
    
    if(mainWindow)
    {
        mainWindow->connect(DOUBLE_CLICK_SIGNAL,&::InventoryWindow::DoubleClickAction,this);
    }
    
    additional_ActionsWindow->connect(DOUBLE_CLICK_SIGNAL,&::InventoryWindow::AdditionalActionsDoubleClick,this);
}



void InventoryWindow::UpdateInventory()
{
    int inventorySize = creature->inventory.getInventorySize();
    for(int i = 0; i < inventorySize; i++)
    {
        
        AddTextToMainWindow(creature->inventory.getItemNameAtIndex(i));
    }
}



bool InventoryWindow::isAnyWindowVisible()
{
    return mainWindow->isVisible() || additional_ActionsWindow->isVisible() || examineWindow.isVisible();
}

void SetupGUI(tgui::Gui &guiRef)
{
 
    
    
    defaultTheme = tgui::Theme::create("Black.txt");
    playerGUI.SetupPlayerGUI(guiRef,&player);
}









