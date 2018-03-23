//
//  BodygraphReader.hpp
//  Colony
//
//  Created by Sean on 3/9/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef BodygraphReader_hpp
#define BodygraphReader_hpp

#include <stdio.h>
#include<iostream>
#include<string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <BodyGraph.hpp>

namespace pt = boost::property_tree;

//Rename class..just use this as the bodygraph later

class CreatureBody
{
    
private:
    pt::ptree tree;
    std::string m_file;
    std::vector<std::string> bodyTokenList;
    
public:
    
    AnatomyGraph anatomyGraph;

    
    std::vector<Weapon> weapons; //Need to handle weapons differently because of things such as two handed weapons and what not. EquipWeapon inside BodyPart won't work because two handed weapons require two hands, and a BodyPart only knows about itself
    
 
    
    CreatureBody();
    
    void GenerateVertices();
    void GenerateOrganVertices();
    void GenerateEdges();
    void GenerateOrganEdges();
    void AddWeapon(Weapon _weapon);
    
    void InitializeBodypartEquipment();
    
    
 
    void load();
    void openBodyTypeFile(const std::string &fileName);
    void readBodyTokenList();
    int convertTruthValue(std::string truthVal);
    
    void Equip(Item *item);
    void EquipWeapon(Item *item);
    
   
    
};



#endif /* BodygraphReader_hpp */
