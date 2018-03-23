//
//  BodyGraph.cpp
//  Colony
//
//  Created by Sean on 1/11/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "BodyGraph.hpp"
#include <boost/algorithm/string.hpp>  
#include <boost/type_index.hpp>
#include "BodyGraphGetters.hpp"
#include <string>

BodyPart defaultHeadBodyPart(false,true,false,false,"Head",10);
BodyPart defaultChestBodyPart(false,true,false,false,"Chest",10);
BodyPart defaultEmptyBodyPart(false,true,false,false,"Empty",10);



using boost::typeindex::type_id_with_cvr;


CreatureBody::CreatureBody()
{
    
}

void CreatureBody::openBodyTypeFile(const std::string &fileName)
{
    
    pt::read_xml(fileName, tree);
}


//Thi
void CreatureBody::readBodyTokenList()
{
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("bptokenlist"))
    {
        // The data function is used to access the data stored in a node.
        
        bodyTokenList.push_back(v.second.data());
    }
    
    
}

//Reads the Body Part section of the file..Generates the body parts and the vertices
void CreatureBody::GenerateVertices()
{
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    
    //Declaring the variables to make this more readable
    std::string bptoken,bpname,section;
    int holdsWeapon,holdsArmor,canInteract,canSee,canSmell,canBreathe;
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("bodyparts"))
    {
        if(v.first == "bpdescription")
        {
            bptoken = v.second.get<std::string>("bptoken");
            
            
            bpname = v.second.get<std::string>("bodypartname");
            section = v.second.get<std::string>("section");
            try
            {
                holdsArmor = convertTruthValue(v.second.get<std::string>("canholdarmor"));
            }
            catch(pt::ptree_bad_path)
            {
                holdsArmor = false;
            }
            
            
            try
            {
                holdsWeapon = convertTruthValue(v.second.get<std::string>("canholdweapon"));
            }
            catch(pt::ptree_bad_path)
            {
                holdsWeapon = false;
            }
            
            
            try
            {
                canSee = convertTruthValue(v.second.get<std::string>("cansee"));
            }
            catch(pt::ptree_bad_path)
            {
                canSee = false;
            }
            
            try
            {
                canSmell = convertTruthValue(v.second.get<std::string>("cansmell"));
            }
            catch(pt::ptree_bad_path)
            {
                canSmell = false;
            }
            
            try
            {
                canBreathe = convertTruthValue(v.second.get<std::string>("canbreathe"));
            }
            catch(pt::ptree_bad_path)
            {
                canBreathe = false;
            }
            
            try
            {
                canSmell = convertTruthValue(v.second.get<std::string>("cansmell"));
            }
            catch(pt::ptree_bad_path)
            {
                canSmell = false;
            }
            
            
            
            
            
            
            
            
            
            
            
            BodyPart bp(bptoken,bpname);
            
            bp.canHoldArmor = holdsArmor;
            bp.canHoldWeapon = holdsWeapon;
            bp.canSmell = canSmell;
            bp.canSee = canSee;
            bp.section = section;
            bp.armor = NO_ARMOR;
            
            
            
            boost::add_vertex(bp,anatomyGraph);
            
        }
        
    }
    
    
    
    
}

void CreatureBody::GenerateOrganVertices()
{
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    
    //Declaring the variables to make this more readable
    std::string bptoken,bpname,section;
    int holdsWeapon,holdsArmor,canInteract,canSee,canSmell,canBreathe;
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("organs"))
    {
        if(v.first == "bpdescription")
        {
            bptoken = v.second.get<std::string>("bptoken");
            
            section = v.second.get<std::string>("section");
            bpname = v.second.get<std::string>("bodypartname");
            
            
            
            
            //These exceptions are here because the user doesn't have to define these for a body part. Defining a body part will be much less painful if some less important parts can be left out
            
            
            try
            {
                holdsArmor = convertTruthValue(v.second.get<std::string>("canholdarmor"));
            }
            catch(pt::ptree_bad_path)
            {
                holdsArmor = false;
            }
            
            try
            {
                holdsWeapon = convertTruthValue(v.second.get<std::string>("canholdweapon"));
            }
            catch(pt::ptree_bad_path)
            {
                holdsWeapon = false;
            }
            
            
            try
            {
                canSee = convertTruthValue(v.second.get<std::string>("cansee"));
            }
            catch(pt::ptree_bad_path)
            {
                canSee = false;
            }
            
            try
            {
                canSmell = convertTruthValue(v.second.get<std::string>("cansmell"));
            }
            catch(pt::ptree_bad_path)
            {
                canSmell = false;
            }
            
            try
            {
                canBreathe = convertTruthValue(v.second.get<std::string>("canbreathe"));
            }
            catch(pt::ptree_bad_path)
            {
                canBreathe = false;
            }
            
            try
            {
                canSmell = convertTruthValue(v.second.get<std::string>("cansmell"));
            }
            catch(pt::ptree_bad_path)
            {
                canSmell = false;
            }
            
            
            
            
            
            
            
            BodyPart bp(bptoken,bpname);
            
            bp.canHoldArmor = holdsArmor;
            bp.canHoldWeapon = holdsWeapon;
            bp.canSmell = canSmell;
            bp.canSee = canSee;
            bp.canBreathe = canBreathe;
            bp.section = section;
            
            
            
            boost::add_vertex(bp,anatomyGraph);
            
        }
        
    }
    
}

void CreatureBody::GenerateEdges()
{
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    
    
    int bp1Index,bp2Index;
    GraphConnection conType;
    AnatomyIndexMap indMap = get(vertex_index, anatomyGraph); //Getting a proeprty map.
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("bodypartconnections"))
    {
        if(v.first == "bodypart")
        {
            
            
            bp1Index = GetVerticesWithToken(v.second.get<std::string>("bptoken"),anatomyGraph);
            bp2Index = GetVerticesWithToken(v.second.get<std::string>("connectsto"),anatomyGraph);
            
            
            //conType = convertConnectionType(v.second.get<std::string>("connectiontype"));
            conType.connection = convertConnectionType(v.second.get<std::string>("connectiontype"));
            
            boost::add_edge(indMap[bp1Index], indMap[bp2Index],conType, anatomyGraph);
            
            
            
            
            
            
            
            
        }
        // The data function is used to access the data stored in a node.
        std::cout << v.first << "\n";
    }
    
    
}

void CreatureBody::GenerateOrganEdges()
{
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    
    
    int bp1Index,bp2Index;
    GraphConnection conType;
    AnatomyIndexMap indMap = get(vertex_index, anatomyGraph); //Getting a proeprty map.
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("organsconnections"))
    {
        if(v.first == "organconnection")
        {
            
            
            bp1Index = GetVerticesWithToken(v.second.get<std::string>("bptoken"),anatomyGraph);
            bp2Index = GetVerticesWithToken(v.second.get<std::string>("connectsto"),anatomyGraph);
            
            
            conType.connection = convertConnectionType(v.second.get<std::string>("connectiontype"));
            
            boost::add_edge(indMap[bp1Index], indMap[bp2Index],conType, anatomyGraph);
            
            
            
            
            
            
            
            
        }
        // The data function is used to access the data stored in a node.
        std::cout << v.first << "\n";
    }
    
    
}


void CreatureBody::load()
{
    
    
    
    
    
    std::cout << "\n Starting schema";
    
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("bodypartconnections"))
    {
        if(v.first == "bodypart")
        {
            std::cout << v.second.get<std::string>("bptoken") << "\n";
            std::cout << v.second.get<std::string>("connectsto") << "\n";
            std::cout << v.second.get<std::string>("connectiontype") << "\n";
            
        }
        // The data function is used to access the data stored in a node.
        std::cout << v.first << "\n";
    }
    
    
    
    
    
}



//Can't use a boolean because -1 indicates that the truth value being passed is not the correct format
//Can just make this a function not in the scope of BodyTypeReader, since it'll be used in multiple places outside of the body type reader
int CreatureBody::convertTruthValue(std::string truthVal)
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


void CreatureBody::Equip(Item *item)
{
    
    for(int i =0; i < item->sections.size(); i++)
    {
        Anatomy_DFS_Section_Visitor vis(item->sections.at(i));
        depth_first_search(anatomyGraph,visitor(vis));
        std::vector<int> indices = vis.getVertexIndices();
        
        for(int j =0; j < indices.size(); j++)
        {
            if(item->getItemType() == enArmorType)
                anatomyGraph[indices.at(j)].EquipArmor(item);
        }
        
        
        
    }
}

void CreatureBody::EquipWeapon(Item *item)
{
    std::vector<int> indices = getVerticesThatCanHoldWeapons(anatomyGraph);
    
    if(item->getItemType() == enWeaponType)
    {
        Weapon *wep = dynamic_cast<Weapon*>(item);
        if(wep->enWeaponSize == enLargeWeapon)
        {
            //Need at least two hands
            if(indices.size() < 2)
            {
                std::cout << "\n Don't have two free hands.";
            }
            else
            {
                //Equip in the first available slots
                anatomyGraph[indices.at(0)].EquipWeapon(item);
                anatomyGraph[indices.at(1)].EquipWeapon(&WEAPON_SLOT_FILLED); //Ne
                
            }
            
            
            
        }
        else
        {
            for(int i = 0; i < indices.size(); i++)
            {
                if(anatomyGraph[i].weapon == NO_WEAPON)
                {
                    anatomyGraph[indices.at(i)].EquipWeapon(item);
                    break;
                    
                }//Change equip weapon function later so it just takes a weapon pointer
            }
            
        }
        
        //wep->isEquipped = true;
        //armor = *arm;
    }
    
    
    
}

void CreatureBody::AddWeapon(Weapon _weapon)
{
    weapons.push_back(_weapon);
}

void CreatureBody::InitializeBodypartEquipment()
{
    for(int i=0; i < num_vertices(anatomyGraph); i++)
    {
        anatomyGraph[i].EquipWeapon(&NO_WEAPON);
        anatomyGraph[i].EquipArmor(&NO_ARMOR);
        
    }
}

