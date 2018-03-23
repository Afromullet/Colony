//
//  WorldStates.cpp
//  Colony
//
//  Created by Sean on 3/18/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "WorldStates.hpp"


POIKnowledge::POIKnowledge()
{
    
}
void POIKnowledge::addPointOfInterest(PointOfInterest poi)
{
    pointsOfInterest.push_back(poi);
}
