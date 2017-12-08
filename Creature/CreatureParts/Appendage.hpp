//
//  Appendage.hpp
//  Colony
//
//  Created by Sean on 12/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Appendage_hpp
#define Appendage_hpp

#include <stdio.h>
#

enum AppendageType
{
    enHand,
    enFoot,
    enHandRight,
    enHandLeft,
    enFootRight,
    enFootLeft
};

class Appendage
{
    
protected:
    AppendageType appendageType;
    int appendageHealth;
    
    
public:
    Appendage();
    Appendage(AppendageType _appendageType);
    
    AppendageType getAppendageType();
    int getHealth();
    
    void setAppendageType(AppendageType _appendageType);
    void setHealth(int _health);
    
};

#endif /* Appendage_hpp */
