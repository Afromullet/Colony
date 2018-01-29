//
//  BodyGraph.hpp
//  Colony
//
//  Created by Sean on 1/11/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <list>
#include "BodyPart.hpp"

#ifndef BodyGraph_hpp
#define BodyGraph_hpp


class BodyGraph
{
    std::vector< std::list< std::pair<BodyPart, BodyPart> > > graph;
    
    void addEdge(BodyPart part1, BodyPart part2);
};

#endif /* BodyGraph_hpp */
