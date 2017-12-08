//
//  Equipment.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Equipment.hpp"

Equipment::Equipment(int _material, EnumFitsBodyPart _enFitsBodyPart, int _sEquipmentName): material(_material),enFitsBodyPart(_enFitsBodyPart),sEquipmentName(_sEquipmentName)
{
    
}


Equipment::Equipment() : material(1),enFitsBodyPart(enUndefinedBodyPart),sEquipmentName(2)
{
    
}

EnumFitsBodyPart Equipment::getBodyPart()
{
    return enFitsBodyPart;
}

int Equipment::getEquipmentName()
{
    return sEquipmentName;
}
 



void Equipment::setEquipmentName(int value)
{
    sEquipmentName = value;
}
 

void Equipment::setMaterial(int value)
{
    material = value;
    
}

void Equipment::setFitsBodyPart(EnumFitsBodyPart value)
{
    enFitsBodyPart = value;
    
}
