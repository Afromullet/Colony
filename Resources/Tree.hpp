//
//  Tree.hpp
//  Colony
//
//  Created by Sean on 6/2/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "Plant.hpp"

extern Tree treeResource[MAX_RESOURCES_PER_GROUP];
extern int numTreeResources;

class Tree : public Plant
{
    
private:
    float maxHeight;
    float maxDiameter;
    
    
public:
    Tree();
};

#endif /* Tree_hpp */
