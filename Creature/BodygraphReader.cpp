//
//  BodygraphReader.cpp
//  Colony
//
//  Created by Sean on 3/9/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "BodygraphReader.hpp"

void BodyTypeReader::openBodyTypeFile(const std::string &fileName)
{
   
    pt::read_xml(fileName, tree);
}


//Thi
void BodyTypeReader::readBodyTokenList()
{
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("bptokenlist"))
    {
        // The data function is used to access the data stored in a node.
     
        bodyTokenList.push_back(v.second.data());
    }
    
 
}

//Reads the Body Part section of the file..Generates the body parts and the vertices
void BodyTypeReader::GenerateVertices()
{
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    
    //Declaring the variables to make this more readable
    std::string bptoken,bpname;
    int holdsWeapon,holdsArmor,canInteract;
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("bodyparts"))
    {
        if(v.first == "bpdescription")
        {
            bptoken = v.second.get<std::string>("bptoken");
            bpname = v.second.get<std::string>("bodypartname");
            holdsWeapon = convertTruthValue(v.second.get<std::string>("canholdweapon"));
            holdsArmor = convertTruthValue(v.second.get<std::string>("canholdarmor"));
            canInteract = convertTruthValue(v.second.get<std::string>("caninteract"));
    
           
            if(holdsWeapon == -1 || holdsArmor == -1 || canInteract == -1)
            {
                std::cout << "\n Invalid Hold weapon, hold armor or can interact\n";
                return;
            }
            
            
             boost::add_vertex(BodyPart(bptoken,bpname,holdsWeapon,holdsArmor,canInteract),anatomyGraph);
            
        }

    }
}

void BodyTypeReader::GenerateEdges()
{
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("bodypartconnections"))
    {
        if(v.first == "bodypart")
        {
            std::cout << v.second.get<std::string>("bptoken") << "\n";
            std::cout << v.second.get<std::string>("connection") << "\n";
            
        }
        // The data function is used to access the data stored in a node.
        std::cout << v.first << "\n";
    }

    
}


void BodyTypeReader::load()
{
  

    

    
    std::cout << "\n Starting schema";
    
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("bodypartconnections"))
    {
        if(v.first == "bodypart")
        {
            std::cout << v.second.get<std::string>("bptoken") << "\n";
            std::cout << v.second.get<std::string>("connection") << "\n";
            
        }
        // The data function is used to access the data stored in a node.
        std::cout << v.first << "\n";
    }



    
    
}



//Can't use a boolean because -1 indicates that the truth value being passed is not the correct format
//Can just make this a function not in the scope of BodyTypeReader, since it'll be used in multiple places outside of the body type reader
int BodyTypeReader::convertTruthValue(std::string truthVal)
{
    std::transform(truthVal.begin(), truthVal.end(), truthVal.begin(), ::tolower);
    
    if(truthVal == "false")
    {
        std::cout << "\n False";
        return 0;
    }
    else if(truthVal == "true")
    {
        std::cout << "\n true";
        return 1;
    }
    
    std::cout << "\n Invalid truth val";
    return -1;
}