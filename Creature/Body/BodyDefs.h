//
//  BodyDefs.h
//  Colony
//
//  Created by Sean on 11/22/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef BodyDefs_h
#define BodyDefs_h


struct BodyPropertyTable
{
    int numBreathingParts;
    int numSeeingParts;
    int numInteractingParts;
    int numSmellingParts;
    int numCanMoveParts;
    
    void operator=(const BodyPropertyTable other) 
    {
        numBreathingParts = other.numBreathingParts;
        numSeeingParts = other.numSeeingParts;
        numInteractingParts = other.numInteractingParts;
        numSmellingParts = other.numSmellingParts;
        numCanMoveParts = other.numCanMoveParts;
    }
    
    BodyPropertyTable()
    {
        
        numBreathingParts = 0;
        numSeeingParts = 0;
        numInteractingParts = 0;
        numSmellingParts = 0;
        numCanMoveParts = 0;
        
    }
};

#endif /* BodyDefs_h */
