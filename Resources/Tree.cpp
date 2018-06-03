//
//  Tree.cpp
//  Colony
//
//  Created by Sean on 6/2/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Tree.hpp"
#include <iostream>

Tree treeResource[MAX_RESOURCES_PER_GROUP];
 int numTreeResources;

void InitializeTreeMaterials()
{
    std::string matName;
    for(int i =0; i < numTreeResources; i++)
    {
        matName = treeResource[i].getMaterialName();
        
        
        
        for(int j=0;j < materials.size(); j++)
        {
            
            if(matName == materials.at(j).getMaterialName())
            {
                treeResource[i].setMaterial(materials.at(j));
            }
        }
    }
    
    std::cout << "\n End";
}

Tree::Tree()
{
    
}

void Tree::setMaxHeight(float val)
{
    maxHeight = val;
}

void Tree::setMaxDiameter(float val)
{
    maxDiameter = val;
}

float Tree::getMaxHeight()
{
    return maxHeight;
}

float Tree::getMaxDiameter()
{
    return maxDiameter;
}
