//
//  Message.cpp
//  Colony
//
//  Created by Sean on 10/26/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Message.hpp"
#include "ErrorConstants.hpp"


MessagePacket::MessagePacket(std::string _fieldName,std::string val,bool _isLocked)
{
    fieldName = _fieldName;
    value = val;
    valueType = enString;
    isLocked = _isLocked;
    
}

MessagePacket::MessagePacket(std::string _fieldName,float val,bool _isLocked)
{
    fieldName = _fieldName;
    value = std::to_string(val);
    valueType = enNumerical;
    isLocked = _isLocked;
}


void Message::addPacket(std::string _fieldName,std::string val, bool isLocked)
{
    packets.push_back(MessagePacket(_fieldName,val,isLocked));
}
void Message::addPacket(std::string _fieldName,float val, bool isLocked)
{
    packets.push_back(MessagePacket(_fieldName,val,isLocked));
}

MessagePacket &Message::getMessagePacket(int i)
{
    if(i >= 0 and i < packets.size())
        return packets.at(i);
}
