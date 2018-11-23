//
//  ImpactWoundInterface.hpp
//  Colony
//
//  Created by Sean on 11/14/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef ImpactWoundInterface_hpp
#define ImpactWoundInterface_hpp

#include <stdio.h>
#include "WoundTableInterface.hpp"



class ImpactWoundInterface : public WoundTableInterface
{
    
    
public:
    
    ImpactWoundInterface(AnatomyGraph &graph, WoundTable &table,CreatureBody &_body) :
    WoundTableInterface(graph,table,_body)
    {
        
    }
    
    
    void ProcessElement(WoundTableElement &element);
    //void ProcesWoundTable();
    void ApplyFracture(int bpIndex,WoundType woundType);
    void ApplyBruise(int bpIndex,WoundType woundType);
    void ApplyRupture(int bpIndex,WoundType woundType);
};

#endif /* ImpactWoundInterface_hpp */
