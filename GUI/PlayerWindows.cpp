//
//  PlayerWindows.cpp
//  Colony
//
//  Created by Sean on 7/7/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "PlayerWindows.hpp"


InventoryWindow inventoryWindow;
ExamineWindow examineWindow;

PlayerGUI playerGUI;
TileGUI  tileGUI;


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
    //creature = _creature;
    inventoryWindow.setupWidgets(INVENTORY_WIDGET_TAG,EQUIPMENT_EXAMINEBOX_TAG,INVENTORY_ADDITIONAL_ACTIONS_WIDGET_TAG,guiRef,_creature);
    inventoryWindow.setupSignals();
    
    equipmentWindow.setupWidgets(EQUIPMENT_WIDGET_TAG,EQUIPMENT_EXAMINEBOX_TAG,EQUIMENT_ADDITIONAACTIONS_WIDGET_TAG,guiRef,_creature);
    equipmentWindow.setupSignals();
}


//TODO handle window opening so that only one window at a time can be opened
//Maybe add a "Close all windows except xxx function that takes a widget as a parameter that closes
//All functions except the ones passed as a parameter
void PlayerGUI::HandleWindowEvent(sf::Event &event,tgui::Gui &guiRef)
{
    //Don't want to move when navigating through the inventory
     if(inventoryWindow.isAnyInitialWindowVisible())
         inventoryWindow.creature->setCanMove(false);
     else
         inventoryWindow.creature->setCanMove(true);
    
    
     if(inventoryWindow.isAnyWindowVisible())
     {
         equipmentWindow.HideAllWindows();
     }
    else if(equipmentWindow.isAnyWindowVisible())
    {
        inventoryWindow.HideAllWindows();
    }
     
    
     inventoryWindow.HandleEvent(event,guiRef);
     equipmentWindow.HandleEvent(event,guiRef);
}



TileGUI::TileGUI()
{
    
}

void TileGUI::SetupTileGUI(tgui::Gui &guiRef,BaseCreature *_creature, Map *_map)
{
    creature = _creature;
   // map = _map;
    inventoryWindow.setMap(_map);
    inventoryWindow.setCreature(_creature);
    inventoryWindow.setupWidgets(TILE_INVENTORY_WIDGET_TAG,TILE_EXAMINEBOX_TAG,TILE_INVENTORY_ADDITIONAL_ACTIONS_WIDGET_TAG,guiRef,_creature);
    inventoryWindow.setupSignals();
    
    
    equipmentWindow.setupWidgets(EQUIPMENT_WIDGET_TAG,TILE_EXAMINEBOX_TAG,EQUIMENT_ADDITIONAACTIONS_WIDGET_TAG,guiRef,_creature);
    equipmentWindow.setupSignals();
     
}


//TODO handle window opening so that only one window at a time can be opened
//Maybe add a "Close all windows except xxx function that takes a widget as a parameter that closes
//All functions except the ones passed as a parameter
void TileGUI::HandleWindowEvent(sf::Event &event,tgui::Gui &guiRef)
{
    //Don't want to move when navigating through the inventory
    if(inventoryWindow.isAnyInitialWindowVisible())
        creature->setCanMove(false);
    else
        creature->setCanMove(true);
    
    
    if(inventoryWindow.isAnyWindowVisible())
    {
       // equipmentWindow.HideAllWindows();
    }
    else if(equipmentWindow.isAnyWindowVisible())
    {
        inventoryWindow.HideAllWindows();
    }
    
    
    inventoryWindow.HandleEvent(event,guiRef);
    equipmentWindow.HandleEvent(event,guiRef);
}



SelectionWindow::SelectionWindow()
{
    curItemIndex = 0;
    curActionsIndex = 0;
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
    examineWindow.setupWidgets(guiRef,tag,EXAMINE_INV_WINDOW_X_POSITION,EXAMINE_INV_WINDOW_Y_POSITION);
    examineWindow.hide();
}

void SelectionWindow::MainDoubleClickAction(std::string name)
{
    
    std::cout << "\n inv double click";
    curItemIndex = mainWindow->getSelectedItemIndex();
    additional_ActionsWindow->setSelectedItemByIndex(0); //Can't remember why this is here
    additional_ActionsWindow->show();
    
}

bool SelectionWindow::isAnyInitialWindowVisible()
{
    return mainWindow->isVisible() || additional_ActionsWindow->isVisible() || examineWindow.isVisible();
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
void ExamineWindow::setupWidgets(tgui::Gui &guiRef,std::string _tag,int xPosition, int yPosition)
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

    
}


void InventoryWindow::AdditionalActionsDoubleClick(std::string name)
{
    AdditionalActionsHandler(name);
}



void InventoryWindow::AdditionalActionsHandler(std::string name)
{


    curActionsIndex = additional_ActionsWindow->getSelectedItemIndex();
    std::cout << "\n Current INdex " << curItemIndex;
    
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
        //creature->inventory.TransferItemToTile(*creature,*tile,curItemIndex);
    }
    else if(name == EQUIP_OPTION)
    {
        creature->EquipItem(curItemIndex);
        mainWindow->hide();
        UpdateMainWindow();
        mainWindow->show();
        additional_ActionsWindow->hide();
        
        std::cout << "\n Equipping";
    }
    
    additional_ActionsWindow->show();
    
    
    
    
}

void InventoryWindow::HandleEvent(sf::Event &event,tgui::Gui &guiRef)
{
    HandleWindowEvent(event,guiRef);
}


void InventoryWindow::HandleWindowEvent(sf::Event &event,tgui::Gui &guiRef)
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
            UpdateMainWindow();
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






void InventoryWindow::setupWidgets(const std::string &mainWindowTag,const std::string &exWindowTag, const std::string &additionalActionsWindowTag, tgui::Gui &guiRef,BaseCreature *_creature)
{
    
    creature = _creature;
    
    examineWindowTag = exWindowTag;
    inventoryWindow.setCreature(_creature);
    
    SetupMainWindow(mainWindowTag,INVENTORY_WINDOWX_SIZE,INVENTORY_WINDOWY_SIZE,INVENTORY_WINDOWX_POSITION,INVENTORY_WINDOWY_POSITION,guiRef);
    
    SetupActionWindow(additionalActionsWindowTag,INVENTORY_WINDOWX_SIZE,INVENTORY_WINDOWY_SIZE,ADDIT_INVENTORY_ACTIONS_WINDOWX_POSITION,ADDIT_INVENTORY_ACTIONS_WINDOWY_POSITION,guiRef);
    
    SetupExamineWindow(examineWindowTag,0,0,0,0,guiRef);

    AddAdditionalAction(EXAMINE_OPTION);
    AddAdditionalAction(DROP_OPTION);
    AddAdditionalAction(EQUIP_OPTION);
}

void InventoryWindow::setupSignals()
{
    
    if(mainWindow)
    {
        mainWindow->connect(DOUBLE_CLICK_SIGNAL,&::InventoryWindow::MainDoubleClickAction,this);
    }
    
    additional_ActionsWindow->connect(DOUBLE_CLICK_SIGNAL,&::InventoryWindow::AdditionalActionsDoubleClick,this);
}



void InventoryWindow::UpdateMainWindow()
{
    int inventorySize = creature->inventory.getInventorySize();
    mainWindow->removeAllItems();
    for(int i = 0; i < inventorySize; i++)
    {
        
        AddTextToMainWindow(creature->inventory.getItemNameAtIndex(i) + "  " + std::to_string(creature->inventory.getItemStackSizeAtIndex(i)));
    }
}

bool InventoryWindow::isAnyWindowVisible()
{
    isAnyInitialWindowVisible();
}

void InventoryWindow::HideAllWindows()
{
    mainWindow->hide();
    additional_ActionsWindow->hide();
    examineWindow.hide();
}

EquipmentWindow::EquipmentWindow()
{
    
    
}


void EquipmentWindow::AdditionalActionsDoubleClick(std::string name)
{
    AdditionalActionsHandler(name);
}



void EquipmentWindow::AdditionalActionsHandler(std::string name)
{
    
    
    curActionsIndex = additional_ActionsWindow->getSelectedItemIndex();
    
    std::string str = "";
    
    if(name == EXAMINE_OPTION)
    {
        std::vector<WoundType> &wounds = creature->body.anatomyGraph[curItemIndex].getWoundsRef();
        
        
        if(wounds.size() == 0)
        {
            str = "No wounds";
        }
        else
        {
            for(int i = 0; i < wounds.size(); i++)
            {
                str += GetWoundType(wounds.at(i)) + ", ";
            }
        }

        
        examineWindow.setText(str);
        
    //examineWindow.setText(creature->body.anatomyGraph[curItemIndex].getBodyPartName());
        
        str = "";
        examineWindow.show();
        std::cout << "\n Examining";
    }
 
    
    additional_ActionsWindow->show();
    
    
    
    
}

void EquipmentWindow::HandleEvent(sf::Event &event,tgui::Gui &guiRef)
{
    HandleWindowEvent(event,guiRef);
}


void EquipmentWindow::HandleWindowEvent(sf::Event &event,tgui::Gui &guiRef)
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
        if(event.key.code == OPEN_EQUIPMENT_KEY)
        {
            UpdateMainWindow();
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






void EquipmentWindow::setupWidgets(const std::string &mainWindowTag,const std::string &exWindowTag, const std::string &additionalActionsWindowTag, tgui::Gui &guiRef,BaseCreature *_creature)
{
    
    creature = _creature;
    
    examineWindowTag = exWindowTag;
    inventoryWindow.setCreature(_creature);
    
    SetupMainWindow(mainWindowTag,EQUIPMENT_WINDOWX_SIZE,EQUIPMENT_WINDOWY_SIZE,EQUIPMENT_WINDOWX_POSITION,EQUIPMENT_WINDOWY_POSITION,guiRef);
    
    SetupActionWindow(additionalActionsWindowTag,EQUIPMENT_WINDOWX_SIZE,EQUIPMENT_WINDOWY_SIZE,ADDIT_EQUIPMENT_ACTIONS_WINDOWX_POSITION,ADDIT_EQUIPMENT_ACTIONS_WINDOWY_POSITION,guiRef);
    
    SetupExamineWindow(examineWindowTag,0,0,0,0,guiRef);
    
    AddAdditionalAction(EXAMINE_OPTION);

}

void EquipmentWindow::setupSignals()
{
    
    if(mainWindow)
    {
        mainWindow->connect(DOUBLE_CLICK_SIGNAL,&::EquipmentWindow::MainDoubleClickAction,this);
    }
    
    additional_ActionsWindow->connect(DOUBLE_CLICK_SIGNAL,&::EquipmentWindow::AdditionalActionsDoubleClick,this);
}



void EquipmentWindow::UpdateMainWindow()
{
    
    std::string bpName;
    std::vector<int> parts = getExternalBodyParts(creature->body.anatomyGraph);
    int inventorySize = creature->inventory.getInventorySize();
    
    

    std::string eqString = "";
    int offset = 0;
    for(int i = 0; i < parts.size(); i++)
    {
        BodyPart &bp =  creature->body.anatomyGraph[parts.at(i)];
        
        //If body part can hold neither weapon nor armor, no need to check ti
        if(!bp.getCanHoldArmor() && !bp.getCanHoldWeapon())
            continue;
        
        eqString += bp.getBodyPartName();
        
        if(bp.getCanHoldWeapon())
            eqString += " Weapon:" + bp.getWeaponRef().getItemName();
        
        if(bp.getCanHoldArmor())
            eqString += " Armor:" + bp.getArmorRef().getItemName();
    
        
        
        AddTextToMainWindow(eqString);
        
        eqString = "";
    }
}

bool EquipmentWindow::isAnyWindowVisible()
{
    isAnyInitialWindowVisible();
}


void EquipmentWindow::HideAllWindows()
{
    mainWindow->hide();
    additional_ActionsWindow->hide();
    examineWindow.hide();
    
}


TileInventoryWindow::TileInventoryWindow()
{
    
    
}


void TileInventoryWindow::AdditionalActionsDoubleClick(std::string name)
{
    AdditionalActionsHandler(name);
}



void TileInventoryWindow::AdditionalActionsHandler(std::string name)
{
    
    
    curActionsIndex = additional_ActionsWindow->getSelectedItemIndex();
    std::cout << "\n Current INdex " << curItemIndex;
    
    if(name == EXAMINE_OPTION)
    {
        /*
        if(creature->inventory.getInventorySize() > 0)
            examineWindow.setText(creature->inventory.getItemDescriptionAtIndex(curItemIndex));
        */
        examineWindow.show();
        std::cout << "\n Examining";
    }
    else if(name == GRAB_OPTION)
    {
        

        
        tile->inventory.TransferItemToCreature(*creature,*tile,curItemIndex);
       
        mainWindow->hide();
        UpdateMainWindow();
        mainWindow->show();
        additional_ActionsWindow->hide();
        
        

    }
    
    additional_ActionsWindow->show();
    
    
    
    
}

void TileInventoryWindow::HandleEvent(sf::Event &event,tgui::Gui &guiRef)
{
    HandleWindowEvent(event,guiRef);
}


void TileInventoryWindow::HandleWindowEvent(sf::Event &event,tgui::Gui &guiRef)
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
        
        
        if(event.key.code == OPEN_TILE_KEY)
        {
            
         
            tile = &map->Map2D[creature->getPosition().x][creature->getPosition().y];
            UpdateMainWindow();
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






void TileInventoryWindow::setupWidgets(const std::string &mainWindowTag,const std::string &exWindowTag, const std::string &additionalActionsWindowTag, tgui::Gui &guiRef,BaseCreature *_creature)
{
    
    creature = _creature;
    
    examineWindowTag = exWindowTag;
    inventoryWindow.setCreature(_creature);
    
    SetupMainWindow(mainWindowTag,INVENTORY_WINDOWX_SIZE,INVENTORY_WINDOWY_SIZE,INVENTORY_WINDOWX_POSITION,INVENTORY_WINDOWY_POSITION,guiRef);
    
    SetupActionWindow(additionalActionsWindowTag,INVENTORY_WINDOWX_SIZE,INVENTORY_WINDOWY_SIZE,ADDIT_INVENTORY_ACTIONS_WINDOWX_POSITION,ADDIT_INVENTORY_ACTIONS_WINDOWY_POSITION,guiRef);
    
    SetupExamineWindow(examineWindowTag,0,0,0,0,guiRef);
    
    AddAdditionalAction(EXAMINE_OPTION);
    AddAdditionalAction(GRAB_OPTION);
}

void TileInventoryWindow::setupSignals()
{
    
    if(mainWindow)
    {
        mainWindow->connect(DOUBLE_CLICK_SIGNAL,&::TileInventoryWindow::MainDoubleClickAction,this);
    }
    
    additional_ActionsWindow->connect(DOUBLE_CLICK_SIGNAL,&::TileInventoryWindow::AdditionalActionsDoubleClick,this);
}



void TileInventoryWindow::UpdateMainWindow()
{
    int inventorySize = tile->inventory.getInventorySize();
    mainWindow->removeAllItems();
    
    if(NULL == tile)
        return;
    
    
    for(int i = 0; i < inventorySize; i++)
    {
        
        
        AddTextToMainWindow(tile->inventory.getItemNameAtIndex(i) + "  " + std::to_string(tile->inventory.getItemStackSizeAtIndex(i)));
        
    }

}

bool TileInventoryWindow::isAnyWindowVisible()
{
    isAnyInitialWindowVisible();
}

void TileInventoryWindow::HideAllWindows()
{
    mainWindow->hide();
    additional_ActionsWindow->hide();
    examineWindow.hide();
}

void TileInventoryWindow::setTile(Map &map, int x, int y)
{
    
}


void TileInventoryWindow::setMap(Map *_map)
{
    map = _map;
}

 void TileInventoryWindow::setCreature(BaseCreature *_creature)
{
    creature = _creature;
}

void SetupGUI(tgui::Gui &guiRef)
{
 


    
    defaultTheme = tgui::Theme::create("Black.txt");
    playerGUI.SetupPlayerGUI(guiRef,&player);
   tileGUI.SetupTileGUI(guiRef,&player,mapdata.map);

}









