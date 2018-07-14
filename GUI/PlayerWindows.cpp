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



PlayerGUI::PlayerGUI()
{
  
}

void PlayerGUI::SetupPlayerGUI(tgui::Gui &guiRef,BaseCreature *_creature)
{
    creature = _creature;
    inventoryWindow.setupWidgets(guiRef);
    inventoryWindow.setupSignals();
}


void PlayerGUI::HandleInventoryEvent(sf::Event &event,tgui::Gui &guiRef)
{
     inventoryWindow.HandleEvent(event,guiRef,creature->inventory);
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
    
}

void InventoryWindow::InventoryDoubleClickAction(std::string name)
{
    std::cout << "\n inv double click";
    additionalActionsWindow->show();
    curItemIndex = inventoryBox->getSelectedItemIndex();
}

void InventoryWindow::AdditionalActionsDoubleClick(std::string name)
{
   
    std::cout << "\nSel It Index " << curItemIndex;
    
    
    if(name == EXAMINE_OPTION)
    {
        //examineWindow.setText("SAM LIKES PENIS");
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

void InventoryWindow::HandleEvent(sf::Event &event,tgui::Gui &guiRef,ItemManager &inventory)
{
    HandleAdditonalActionsWindowEvent(event,guiRef,inventory);
    HandleInventoryWindowEvent(event,guiRef,inventory);
}


void InventoryWindow::HandleInventoryWindowEvent(sf::Event &event,tgui::Gui &guiRef,ItemManager &inventory)
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
            
            UpdateInventory(inventory);
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
    }
    else if(inventoryBox->isVisible() && additionalActionsWindow->isVisible() && !examineWindow.isVisible())
    {
        if(event.key.code == CLOSE_WINDOW_KEY && event.type == sf::Event::KeyReleased)
        {
            additionalActionsWindow->hide();
            
            
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

void InventoryWindow::HandleAdditonalActionsWindowEvent(sf::Event &event,tgui::Gui &guiRef,ItemManager &inventory)
{
    
   
    if(additionalActionsWindow->isVisible())
    {
  
    }
}



void InventoryWindow::setupWidgets(tgui::Gui &guiRef)
{
    
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



void InventoryWindow::UpdateInventory(ItemManager &inventory)
{
    
    int inventorySize = inventory.getInventorySize();
    for(int i = 0; i < inventorySize; i++)
    {
        inventoryBox->addItem(inventory.getItemNameAtIndex(i));
    }
    
    
}


void InventoryWindow::setPosition(float x, float y)
{
    inventoryBox->setPosition(sf::Vector2f(x,y));
}
void InventoryWindow::setSize(float x, float y)
{
    inventoryBox->setSize(sf::Vector2f(x,y));
}







void SetupGUI(tgui::Gui &guiRef)
{
 
    
    
    defaultTheme = tgui::Theme::create("Black.txt");
    
   // inventoryWindow.setupWidgets(guiRef);
   // inventoryWindow.setupSignals();
    playerGUI.SetupPlayerGUI(guiRef,&player);
    //examineWindow.setupWidgets(guiRef,INVENTORY_EXAMINEBOX_TAG_MODIFIER);
    
}









