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
