//
//  Equipment.hpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Equipment_hpp
#define Equipment_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "EnumTypes.hpp"

//TODO rename enbodypart to something that indicates it is the body part the equipment fits to

//TODO...GetEquipmentParameters. Returns a hashtable of equipment parameters. Whenever this funtion is called, it is up to the user to parse those parameters. I.E

class Equipment
{

private:
    int material;
    EnumFitsBodyPart enFitsBodyPart;
    int sEquipmentName;
    
public:
    Equipment(int _material, EnumFitsBodyPart _enFitsBodyPart, int _sEquipmentName);
    Equipment();
    virtual ~Equipment(){};
    virtual void calculateMaterialBonuses() = 0;

    int getEquipmentName();
    EnumFitsBodyPart getBodyPart();
    
    void setEquipmentName(int value);
    void setMaterial(int value);
    void setFitsBodyPart(EnumFitsBodyPart value);

    
    
  
    
    
    
};

#endif /* Equipment_hpp */
