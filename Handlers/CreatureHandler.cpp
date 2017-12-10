//
//  CreatureHandler.cpp
//  Colony
//
//  Created by Sean on 12/9/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "CreatureHandler.hpp"
#include "Globals.hpp"

//Handles cleanup for when a dead creature dies
//TODO buggy at the moment..does not delete the right creature in all cases
void RemoveDeadCreature(Map &_map,std::list<BaseCreature> &creatures)
{
   // int prevSize = _creatureList.size();
 
    std::vector<BaseCreature>::iterator it;
    std::vector<BaseCreature> tempVector;

    
    


    /*
    
    for(int i = 0; i < _creatureList.size(); i++)
    {
        //Currently using a hardcoded value for testing purpose
        if(_creatureList.at(i).getBody()->getTotalHealth() < 30)
        {
            
            
            
            _map.Map2D[_creatureList.at(i).getPosition().x][_creatureList.at(i).getPosition().y].ClearCreatureOnTile();
            
            
            _creatureList.erase(_creatureList.begin() + i);
            
           _creatureList.at(i).isAlive = false;
            
             
        }
    }
     */
    
    std::list<BaseCreature>::iterator i = lCreatures.begin();
    while (i != lCreatures.end())
    {
       
        if(i->getBody()->getTotalHealth() < 30)
        {
            _map.Map2D[i->getPosition().x][i->getPosition().y].ClearCreatureOnTile();
            lCreatures.erase(i++);  // alternatively, i = items.erase(i);
            

        }
        else
        {
           
            ++i;
        }
    }
   

    
}