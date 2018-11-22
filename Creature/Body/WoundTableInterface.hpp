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

#define LOW_WOUND_LEVEL 10
#define MODERATE_WOUND_LEVEL 30
#define MAJOR_WOUND_LEVEL 50

class ImpactWoundInterface;
class ShearWoundInterface;


class WoundTableInterface
{
    
private:
    AnatomyGraph &graph;
    WoundTable &woundTable;
    
public:
    
    friend class ImpactWoundInterface;
    friend class ShearWoundInterface;

    
    WoundTableInterface(AnatomyGraph &_graph, WoundTable &table) : graph(_graph), woundTable(table)
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
        
        std::cout << "Processing Impact Wound Table";
    }

};




#endif /* WoundTableInterface_hpp */
