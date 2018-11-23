//
//  ShearWoundInterface.hpp
//  Colony
//
//  Created by Sean on 11/14/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef ShearWoundInterface_hpp
#define ShearWoundInterface_hpp

#include <stdio.h>
#include "ImpactWoundInterface.hpp"


class ShearWoundInterface : public WoundTableInterface
{
    
    
public:
    ShearWoundInterface(AnatomyGraph &graph, WoundTable &table,CreatureBody &_body) :
    WoundTableInterface(graph,table,_body)
    {
        
    }
    
    void ProcessElement(WoundTableElement &element);
    //void ProcesWoundTable();
    void ApplyCut(int bpIndex,WoundType woundType);
    void ApplyDismember(int bpIndex,WoundType woundType);
    void ApplyPuncture(int bpIndex,WoundType woundType);
};


#endif /* ShearWoundInterface_hpp */
