//
//  Action.hpp
//  Colony
//
//  Created by Sean on 11/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Action_hpp
#define Action_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <queue>


/*
 There is an action queue, which is why there is an action parent class.
 Every subclass will not be required to implement all of the virtual function, so they are not pure virtual functions.
 
 This makes it easier to handle things at a higher level without having to worry about separate types of actions, I.E, attack actions, move actions, etc etc
 */
class Action
{

    
    
    
protected:
    Action();
    Action(int prior);
    int priority;
    
    
public:
    

    bool actionComplete; //For an action that is performed more than one time
    
    
    
    ~Action()
    {
        
    }
    virtual void Execute() = 0;
    
    void setPriority(int val);
    int getPriority();
    
    
    friend bool operator<(const Action& lhs, const Action& rhs)
    {
        return lhs.priority < rhs.priority;
    }
    
    friend bool operator>(const Action& lhs, const Action& rhs)
    {
        return lhs.priority > rhs.priority;
    }
    
    
    
    
};



#endif /* Action_hpp */
