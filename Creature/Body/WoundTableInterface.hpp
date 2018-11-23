//
//  WoundTableInterface.hpp
//  Colony
//
//  Created by Sean on 11/14/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//



#ifndef WoundTableInterface_hpp
#define WoundTableInterface_hpp

#include <stdio.h>
#include "BodyGraph.hpp"
#include "BodyPart.hpp"


class ImpactWoundInterface;
class ShearWoundInterface;


class WoundTableInterface
{
    
private:
    CreatureBody &body;
    AnatomyGraph &graph;
    WoundTable &woundTable;
    
public:
    
    friend class ImpactWoundInterface;
    friend class ShearWoundInterface;

    
    void operator=(const BodyPart &other)
    {
        //body.
    }
    
    WoundTableInterface(AnatomyGraph &_graph, WoundTable &table, CreatureBody &_body) : graph(_graph), woundTable(table), body(_body)
    {
        
    }
    
    
    
 
    virtual void ProcessElement(WoundTableElement &element) = 0; //Implements the logic for handling a single ement of a table;
   // virtual void ProcesWoundTable() = 0; //Implements the logic for handling the entire table
    
    void ProcesWoundTable()
    {
        
        
        //graph[vert1]->increaseFractureLevel(10);
        //vert1.increaseFractureLevel(10);
        
        std::vector<WoundTableElement>::iterator it;
        for(it = woundTable.table.begin(); it != woundTable.table.end(); )
        {
            
 
            ProcessElement(*it);
            
            if(it->woundTypes.size() == 0)
            {
                woundTable.table.erase(it);
            }
            else
            {
                ++it;
            }
            
                
            
            
        }
        
   
    }

};




#endif /* WoundTableInterface_hpp */
