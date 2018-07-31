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

void InitializeTreeMaterials();

class Tree : public Plant
{
    
private:
    float maxHeight;
    float maxDiameter;
    
    
public:
    
    bool operator==(const Tree &other) const;
    bool operator=(const Tree &other) const;
    bool operator=(const Tree other);
    
    Tree();
    Tree(const Tree &other);
    
    void setMaxHeight(float val);
    void setMaxDiameter(float val);
    
    float getMaxHeight() const;
    float getMaxDiameter() const;
};

#endif /* Tree_hpp */
