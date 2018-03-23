//
//  WorldStates.hpp
//  Colony
//
//  Created by Sean on 3/18/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef WorldStates_hpp
#define WorldStates_hpp

#include <stdio.h>
#include "Pathfinding.hpp"
#include <boost/property_map/property_map.hpp>
enum POIType{enWeaponPOI,enArmorPOI,enFoodPOI,enWaterPOI,enAllyPOI,enEnemyPOI,enItemPOI,enCreaturePOI};

struct PointOfInterest
{
    GridLocation location;
    POIType type;
};


class POIKnowledge
{
private:
    std::vector<PointOfInterest> pointsOfInterest;
    
    
public:
    POIKnowledge();
    
    void addPointOfInterest(PointOfInterest poi);
    std::vector<PointOfInterest> getPOIs();
};




#endif /* WorldStates_hpp */
