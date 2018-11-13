//
//  ItemManager.hpp
//  Colony
//
//  Created by Sean on 6/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//




#ifndef ItemManager_hpp
#define ItemManager_hpp

#include <stdio.h>
#include <memory>
#include <iterator>
#include <memory>

#include "Equipment.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"



using namespace std;

#define MSG_ITEMANAGER_ITEMANMES_TYPE "item_name_msg"
#define MSG_ITEMMANAGER_ITEMNAME_FIELD "itemnames_field"

class CreatureBody;
class Tile;
class BaseCreature;

class ItemManager : public sf::Drawable, public sf::Transformable
{
private:
    std::string getItemNamesString();
    
    
public:
    
    std::vector<unique_ptr<Item>> items;
    
    void operator=(ItemManager &other);
    
    //void operator=(ItemManager &&other);
    ItemManager& operator=(ItemManager&& other);
    
    

    
    
    
    ItemManager();
    ItemManager(ItemManager &other);
    ItemManager(ItemManager&& other);
    
    
    void addItem(unique_ptr<Item> item);
    void addArmor(Armor armor);
    void addWeapon(Weapon weapon);
    void showItemStats(int i);
    void EquipItem(int i,CreatureBody &body);
    
    void ClearSlot(int i); //Clears slot at index i
    
    void ReleaseAllMemory();
    
    int getInventorySize();
    std::string getItemNameAtIndex(int i);
    std::string getItemDescriptionAtIndex(int i);
    int getItemStackSizeAtIndex(int i);
 
    void TransferItemToCreature(BaseCreature &creature, Tile &tile, int offset); //Move item from the tile to the creature
    void TransferItemToTile(BaseCreature &creature, Tile &tile, int offset); //Move item from the tile to the creature
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    

    
    //void MoveInventory(
    
    
    
};

#endif /* ItemManager_hpp */
