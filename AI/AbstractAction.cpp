//
//  AbstractAction.cpp
//  Colony
//
//  Created by Sean on 3/22/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "AbstractAction.hpp"


AbstractAction::AbstractAction(Map &_map,BaseCreature &_creature) : map(_map),creature(_creature)
{
    
}

void AbstractAction::AddPOI(PointOfInterest poi)
{
    pointsOfInterest.addPointOfInterest(poi);
}

void AbstractAction::AddDestination(GridLocation loc)
{
    destinations.push_back(loc);
}

void AbstractAction::setMap(Map &_map)
{
    map = _map;
}


void AbstractAction::setCreature(BaseCreature &_creature)
{
    creature = _creature;
}

int AbstractAction::getDestinationsSize()
{
    return destinations.size();
}

std::vector<GridLocation>& AbstractAction::getDestinations()
{
    return destinations;
    
}

GridLocation AbstractAction::getDestination(int index)
{
    return destinations.at(index);
}

void AbstractAction::clearPath()
{
    creature.clearPath();
}
