//
//  ItemManager.cpp
//  Colony
//
//  Created by Sean on 6/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "ItemManager.hpp"
#include "BodyGraph.hpp"
#include <iterator>
#include <memory>


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
            std::cout << "\n Found";
            return;
        }
    }
    
    if(!itemFound)
    {
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
            std::cout << "\n Found";
            return;
        }
    }
    
    if(!itemFound)
    {
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

void ItemManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int i = 0; i < items.size(); i++)
    {
        
    }
}
