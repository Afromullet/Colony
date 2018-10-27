//
//  Message.hpp
//  Colony
//
//  Created by Sean on 10/26/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Message_hpp
#define Message_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "EnumTypes.hpp"


//Need a window to handle displaying information in the environment to the player
//Everything at a given point in the environment can be accessed with an (x,y) pair
//Tile[x][y]..MapEffects[X,Y} and so on..So the idea behind this class is to gather
//all of that information...A class that implements this handles what is sent, and how to proceed when receiving a message


//
struct MessagePacket
{
    
    
public:
    MessagePacket(std::string _fieldName,std::string val,bool _isLocked);
    MessagePacket(std::string _fieldName,float val,bool _isLocked);
    
    
private:
    ValueType valueType;
    std::string fieldName;
    std::string value; //Stores the value as a string
    bool isLocked; //Can the value be edited after initialization?
    

    
    
    
};

class Message
{
    
public:
    
    
    std::vector<MessagePacket> packets;
  
    virtual void SendMessage() = 0;
    
    void addPacket(std::string _fieldName,std::string val, bool isLocked);
    void addPacket(std::string _fieldName,float val, bool isLocked);
    
    MessagePacket &getMessagePacket(int i);
    

    
    
};

#endif /* Message_hpp */
