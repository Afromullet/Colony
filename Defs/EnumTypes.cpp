//
//  EnumTypes.cpp
//  Colony
//
//  Created by Sean on 11/27/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include <stdio.h>
#include "EnumTypes.hpp"
#include <string>
#include <iostream>
/*
    enum EnumBodyPart{enHeadBodyPart,enLeftArmBodyPart,enRightArmBodyPart,enLeftLegBodyPart,enRightLegBodyPart,enLeftFootBodyPart,enRightFootBodyPart,enChestBodyPart,enLeftHandBodyPart,enRightHandBodyPart};
 
 */
void PrintEnumBodyPart(EnumBodyPart enBodyPart)
{
    std::string out;
    
    if(enBodyPart == enHeadBodyPart)
    {
        out = "Head";
    }
    else if(enBodyPart == enLeftArmBodyPart)
    {
        out = "Left Armm";
    }
    else if(enBodyPart == enRightArmBodyPart )
    {
        out = "Right Arm";
    }
    
    else if(enBodyPart == enLeftHandBodyPart)
    {
        out = "Left Hand";
    }
    
    else if(enBodyPart == enRightHandBodyPart )
    {
        out = "Right Hand";
    }
    
    else if(enBodyPart == enChestBodyPart)
    {
        out = "Chest";
    }
    else if(enBodyPart == enLeftLegBodyPart)
    {
        out = "Left Leg";
    }
    
    else if(enBodyPart == enRightLegBodyPart)
    {
        out = "Right Leg";
    }
    
    else if(enBodyPart == enLeftFootBodyPart)
    {
        out = "Left Foot";
    }
    
    else if(enBodyPart == enRightFootBodyPart)
    {
        out = "Right Foot";
    }
  
    
    
   // //std::cout << out;
 
    
}