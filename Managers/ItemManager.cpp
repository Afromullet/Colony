//
//  ItemManager.cpp
//  Colony
//
//  Created by Sean on 6/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "ItemManager.hpp"
#include "BodyGraph.hpp"



void ItemManager::operator=(ItemManager &other)
{
    std::vector<unique_ptr<Item>>::iterator iter;
    
    for(int i = 0; i < other.items.size(); i++)
    {
        items.push_back(std::move(other.items.at(i)));
    }
    
    
    other.items.clear();
}


/*
void ItemManager::operator=(ItemManager &&other)
{
    std::vector<unique_ptr<Item>>::iterator iter;
    
    for(int i = 0; i < other.items.size(); i++)
    {
        items.push_back(std::move(other.items.at(i)));
    }
    
}
 */

ItemManager& ItemManager::operator=(ItemManager&& other)
{
    std::vector<unique_ptr<Item>>::iterator iter;
    
    for(int i = 0; i < other.items.size(); i++)
    {
        items.push_back(std::move(other.items.at(i)));
    }
    
    return *this;
    
}




ItemManager::ItemManager()
{
    items.resize(0);
}

ItemManager::ItemManager(ItemManager &other)
{
    std::vector<unique_ptr<Item>>::iterator iter;
    
    for(int i = 0; i < other.items.size(); i++)
    {
        items.push_back(std::move(other.items.at(i)));
    }
    
}

ItemManager::ItemManager(ItemManager&& other)
{
    std::vector<unique_ptr<Item>>::iterator iter;
    
    for(int i = 0; i < other.items.size(); i++)
    {
        items.push_back(std::move(other.items.at(i)));
    }
}

void ItemManager::addItem(unique_ptr<Item> item)
{
    items.push_back(std::move(item));
}



void ItemManager::addArmor(Armor armor)
{
 
    bool itemFound = false;
    
    for(int i = 0; i < items.size(); i++)
    {
        if(armor.getTag() == items.at(i)->getTag())
        {
            items.at(i)->IncrementStackSize();
            //std::cout << "\n Found";
            return;
        }
    }
    
    if(!itemFound)
    {
        //armor.IncrementStackSize();
        std::unique_ptr<Item> it(new Armor(armor));
        items.push_back(std::move(it));
    }
    

    
}

void ItemManager::addWeapon(Weapon weapon)
{
  
    
    
    bool itemFound = false;
    
    for(int i = 0; i < items.size(); i++)
    {
        if(weapon.getTag() == items.at(i)->getTag())
        {
            items.at(i)->IncrementStackSize();
           // std::cout << "\n Found";
            return;
        }
    }
    
    if(!itemFound)
    {
       // weapon.IncrementStackSize();
        std::unique_ptr<Item> it(new Weapon(weapon));
        items.push_back(std::move(it));
    }
    
   // std::unique_ptr<Item> it(new Weapon(weapon));
   // items.push_back(std::move(it));
}

void ItemManager::showItemStats(int i)
{
    
    
    if(i >= items.size())
    {
        std::cout << "\n Invalid item slot";
        return;
    }
    
    items.at(i)->showItemStats();
}

void ItemManager::EquipItem(int i,CreatureBody &body)
{
    if(i >= items.size())
    {
        std::cout << "\n Invalid item slot";
        return;
    }
    
    body.Equip(std::move(items.at(i)),*this,i);
    
    
}

//Clears slot at index i
void ItemManager::ClearSlot(int i)
{
    items.erase(items.begin() + i);
}

void ItemManager::ReleaseAllMemory()
{
    for(int i = 0; i < items.size(); i++)
    {
        
    }
}

int ItemManager::getInventorySize()
{
    return items.size();
}
std::string ItemManager::getItemNameAtIndex(int i)
{
    if(i > items.size())
        return "";
    else
        return items.at(i)->getItemName();
    
}

std::string ItemManager::getItemDescriptionAtIndex(int i)
{
    
   // std::cout << "\n I " << i;
    
    if(items.size() == 0)
        return;
    
    if(i > items.size() || i < 0)
        return "";
    else
        return items.at(i)->getDescriptiveText();
}

int ItemManager::getItemStackSizeAtIndex(int i)
{
    if(i > items.size())
        return -1;
    else
        return items.at(i)->getStackSize();
}

std::string ItemManager::getItemNamesString()
{
    std::string str = "";
    for(int i = 0; i < items.size(); i++)
    {
        str = str +  items.at(i)->getItemName() + ",";

    }
    
    str.pop_back(); //Removes the last ,
    
    return str;
}

void ItemManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int i = 0; i < items.size(); i++)
    {
        
    }
}



//Move item from the tile to the creature
void ItemManager::TransferItemToCreature(BaseCreature &creature, Tile &tile,int offset)
{
    //std::unique_ptr<Item> tempitem(std::move(items.at(offset)));
    
    //Create a copy of the item if there is more than one. The unique pointer can remain in the inventory since there are still items of that kind left
    if (getItemStackSizeAtIndex(offset) > 1)
    {
        
        
        if (items.at(offset)->getItemType() == enArmorType)
        {
            items.at(offset)->DecrementStackSize();
            
            Armor *armor =  (Armor*)items.at(offset)->clone();
            armor->setStackSize(1);
            Armor arm(armor);
            creature.inventory.addArmor(arm);
            free(armor);
        }
        else if (items.at(offset)->getItemType() == enWeaponType)
        {
            items.at(offset)->DecrementStackSize();
            
            Weapon *weapon =  (Weapon*)items.at(offset)->clone();
            weapon->setStackSize(1);
            Weapon wep(weapon);
            creature.inventory.addWeapon(wep);
            free(weapon);
        }
    }
    else
    {
        
        creature.inventory.addItem(std::move(items.at(offset)));
        tile.inventory.ClearSlot(offset);
        
    }


}

//Move item from creature to tile
void ItemManager::TransferItemToTile(BaseCreature &creature, Tile &tile, int offset)
{
    
    tile.inventory.addItem(std::move(items.at(offset)));
    creature.inventory.ClearSlot(offset);
}
