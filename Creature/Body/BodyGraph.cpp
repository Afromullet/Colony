//
//  BodyGraph.cpp
//  Colony
//
//  Created by Sean on 1/11/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "BodyGraph.hpp"

#include "BodyGraphGetters.hpp"
#include <string>





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
    int holdsWeapon,holdsArmor,canInteract,canSee,canSmell,canBreathe,canMove,isOrgan;
    float relativeSize;
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
            
            
            try
            {
                relativeSize = std::stof(v.second.get<std::string>("relativesize"));
            }
            catch(pt::ptree_bad_path)
            {
                relativeSize = 10;
            }
            
            try
            {
                canInteract = convertTruthValue(v.second.get<std::string>("caninteract"));
            }
            catch(pt::ptree_bad_path)
            {
                canInteract = false;
            }
        
            try
            {
                canMove = convertTruthValue(v.second.get<std::string>("canmovecreature"));
            }
            catch(pt::ptree_bad_path)
            {
                canMove = false;
            }
            
            try
            {
                isOrgan = convertTruthValue(v.second.get<std::string>("isorgan"));
            }
            catch(pt::ptree_bad_path)
            {
                isOrgan = false;
            }
            
            
            
            
            
            
            
            
            
            
            BodyPart bp(bptoken,bpname);
            bp.setRelativeSize(relativeSize);
            bp.setCanHoldArmor(holdsArmor);
            bp.setCanHoldWeapon(holdsWeapon);
            bp.setCanSmell(canSmell);
            bp.setCanSee(canSee);
            bp.setSection(section);
            bp.setArmor(NO_ARMOR);
            bp.setCanBreathe(canBreathe);
            bp.setCanInteract(canInteract);
            bp.setCanMoveCreature(canMove);
            bp.setIsOrgan(isOrgan);
            
            if(canSmell)
            {
                bodyProperties.numSmellingParts += 1;
            }
            if(canSee)
            {
                bodyProperties.numSeeingParts += 1;
            }
            if(canBreathe)
            {
                bodyProperties.numBreathingParts += 1;
            }
            if(canInteract)
            {
                bodyProperties.numInteractingParts += 1;
            }
            if(canMove)
            {
                bodyProperties.numCanMoveParts += 1;
            }
            
            
            
            boost::add_vertex(bp,anatomyGraph);
            
        }
        
    }
    
    
    
    
}

void CreatureBody::GenerateOrganVertices()
{
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    
    //Declaring the variables to make this more readable
    std::string bptoken,bpname,section;
    int holdsWeapon,holdsArmor,canInteract,canSee,canSmell,canBreathe,canMove,isOrgan;
    float relativeSize;
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
            
            
            try
            {
                relativeSize = std::stof(v.second.get<std::string>("relativesize"));
            }
            catch(pt::ptree_bad_path)
            {
                relativeSize = 10;
            }
            
            try
            {
                canInteract = convertTruthValue(v.second.get<std::string>("caninteract"));
            }
            catch(pt::ptree_bad_path)
            {
                canInteract = false;
            }
            
            try
            {
                canMove = convertTruthValue(v.second.get<std::string>("canmovecreature"));
            }
            catch(pt::ptree_bad_path)
            {
                canMove = false;
            }
            
            try
            {
                isOrgan = convertTruthValue(v.second.get<std::string>("isorgan"));
            }
            catch(pt::ptree_bad_path)
            {
                isOrgan = false;
            }
            
            
            
            
            
            
            
            BodyPart bp(bptoken,bpname);
            bp.setRelativeSize(relativeSize);
            bp.setCanHoldArmor(holdsArmor);
            bp.setCanHoldWeapon(holdsWeapon);
            bp.setCanSmell(canSmell);
            bp.setCanSee(canSee);
            bp.setSection(section);
            bp.setArmor(NO_ARMOR);
            bp.setCanBreathe(canBreathe);
            bp.setCanInteract(canInteract);
            bp.setCanMoveCreature(canMove);
            bp.setIsOrgan(isOrgan);
            
            if(canSmell)
            {
                bodyProperties.numSmellingParts += 1;
            }
            if(canSee)
            {
                bodyProperties.numSeeingParts += 1;
            }
            if(canBreathe)
            {
               bodyProperties.numBreathingParts += 1;
            }
            if(canInteract)
            {
                bodyProperties.numInteractingParts += 1;
            }
            if(canMove)
            {
                bodyProperties.numCanMoveParts += 1;
            }
            
            
            
            
            
            
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
            
            conType.connectionProperty = convertConnectionPropertyType(v.second.get<std::string>("connectionproperty"));
            
            
            
            
            boost::add_edge(indMap[bp1Index], indMap[bp2Index],conType, anatomyGraph);
            
            
            
            
            
            
            
            
        }
        // The data function is used to access the data stored in a node.
    
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
     
    }
    
    
}


void CreatureBody::load()
{
    
    
    
    
    
 
    
    //BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("main.cats"))
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("bodypartconnections"))
    {
        if(v.first == "bodypart")
        {
             v.second.get<std::string>("bptoken");
             v.second.get<std::string>("connectsto");
             v.second.get<std::string>("connectiontype");
            
        }
        // The data function is used to access the data stored in a node.
        
    }
    
    
    
    
    
}



//Can't use a boolean because -1 indicates that the truth value being passed is not the correct format
//Can just make this a function not in the scope of BodyTypeReader, since it'll be used in multiple places outside of the body type reader
//Need to move this outside the class
int CreatureBody::convertTruthValue(std::string truthVal)
{
    std::transform(truthVal.begin(), truthVal.end(), truthVal.begin(), ::tolower);
    
    if(truthVal == "false")
    {
        
        return 0;
    }
    else if(truthVal == "true")
    {
        
        return 1;
    }
    
    
    return -1;
}



//Todo remove tempItems and just replace it with item. tempitem is left over from when I handled it a different way
/*
For armor:
 1) Get all of the sections the new armor covers
 2) Get all unique armor names covering those sections on the body
 3) Remove all armor on body covering the same section as the new armor
 4) Using the armorNames, remove leftovers
 
 */

/*
bool CreatureBody::Equip(std::unique_ptr<Item> item,ItemManager &inventory,int index)
{
    bool equipSuccess = false;
    std::string tempItemName;
    std::unique_ptr<Item> tempitem(std::move(item));
    inventory.ClearSlot(index);
    std::vector<int> sectionIndices;
 
    Armor arm;
    
    if(tempitem->getItemType() == enArmorType)
    {
        Armor *tempArmor  = dynamic_cast<Armor*>(tempitem.get());
        std::vector<string> armorNames; //Stores the names of the armors unequipped
        std::vector<Armor> unequippedArmor; //Stores the armor that has been unequipped
        
        for(int i =0; i < tempArmor->sections.size(); i++)
        {
            Anatomy_DFS_Section_Visitor vis(tempArmor->sections.at(i));
            depth_first_search(anatomyGraph,visitor(vis));
            sectionIndices = vis.getVertexIndices(); //Index of all the sections this armor covers
            
            //Need to unequip the armor for each section
            for(int j = 0; j < sectionIndices.size(); j++)
            {
                
                arm = anatomyGraph[sectionIndices.at(j)].getArmor();
                
                

                
            }
            
            //We have at least one valid section
            if(sectionIndices.size() > 0)
                equipSuccess = true;
            
            
            
            
        }
        
        
     
        
        
       if(equipSuccess == true)
       {
           
           
           //UnequipArmorByName(armorNames);
          //tempitem.release();
         //inventory.ClearSlot(index);
       }
        

    }
    
    else if(tempitem->getItemType() == enWeaponType)
    {
        Weapon *tempWeapon  = dynamic_cast<Weapon*>(tempitem.get());
        std::vector<int> indices = getVerticesThatCanHoldWeapons(anatomyGraph);
        
        
        UnequipWeaponBySection(indices,inventory,tempWeapon->getWeaponSize());
        
        if(tempWeapon->getWeaponSize() == enLargeWeapon)
        {
            if(indices.size() >= 2)
            {
               tempWeapon->EquipItem(anatomyGraph[indices.at(0)]);
               
                anatomyGraph[indices.at(1)].setWeapon(WEAPON_SLOT_FILLED);
                equipSuccess = true;
                
            }
            else
            {
                inventory.addItem(std::move(tempitem));
                return false;
            }
        }
        else
        {
            if(indices.size() >= 1)
            {
                 tempWeapon->EquipItem(anatomyGraph[indices.at(0)]);
                anatomyGraph[indices.at(1)].setWeapon(FIST_WEAPON);
                equipSuccess = true;
                
            }
            else
            {
                inventory.addItem(std::move(tempitem));
                return false;
            }
                
        }
        
        if(equipSuccess == true)
        {
            tempitem.release();
        }
        
        
        
        
    }
    

    
    
    return equipSuccess;
}


*/

 
 bool CreatureBody::Equip(std::unique_ptr<Item> item,ItemManager &inventory,int index)
 {
 bool equipSuccess = false;
 std::string tempItemName;
 std::unique_ptr<Item> tempitem(std::move(item));
 //  std::cout << "\n Name " << tempitem->getItemName();
 inventory.ClearSlot(index);
 
 
 
 if(tempitem->getItemType() == enArmorType)
 {
 Armor *tempArmor  = dynamic_cast<Armor*>(tempitem.get());
 
 std::cout << "\n Temp Armor " << tempArmor->getItemName();
 
 std::vector<string> armorNames; //Stores the names of the armors unequipped
 
 
 for(int i =0; i < tempArmor->sections.size(); i++)
 {
 Anatomy_DFS_Section_Visitor vis(tempArmor->sections.at(i));
 depth_first_search(anatomyGraph,visitor(vis));
 std::vector<int> indices = vis.getVertexIndices(); //Index of all the sections this armor covers
 
 
 //Since one piece can cover multiple items, for every piece that we remove, get the name so we can unequip it later
 for(int bpIndex = 0; bpIndex < indices.size(); bpIndex++)
 {
 tempItemName = anatomyGraph[bpIndex].getArmor().getItemName();
 if(std::find(armorNames.begin(),armorNames.end(),tempItemName) == armorNames.end())
 armorNames.push_back(tempItemName);
 
 }
 
 
 //The item can be equipped
 if(indices.size() > 0)
 {
 
 
 UnequipArmorBySection(indices, inventory);
 
 
 for(int j =0; j < indices.size(); j++)
 {
 
 //Creates a copy of the item. Adds what is currently in the slot to the inventory. Creates a copy
 //tempitem->EquipItem(anatomyGraph[indices.at(j)]);
 //Create a function that gets body parts by sections
 
 tempArmor->EquipItem(anatomyGraph[indices.at(j)]);
 equipSuccess = true;
 }
 }
 else
 {
 //No valid slot. Early exit
 //inventory.ClearSlot(index);
 inventory.addItem(std::move(tempitem));
 
 return false;
 }
 }
 
 if(equipSuccess == true)
 {
 
 
 UnequipArmorByName(armorNames);
 tempitem.release();
 //inventory.ClearSlot(index);
 }
 
 
 }
 
 else if(tempitem->getItemType() == enWeaponType)
 {
 Weapon *tempWeapon  = dynamic_cast<Weapon*>(tempitem.get());
 std::vector<int> indices = getVerticesThatCanHoldWeapons(anatomyGraph);
 
 
 UnequipWeaponBySection(indices,inventory,tempWeapon->getWeaponSize());
 
 if(tempWeapon->getWeaponSize() == enLargeWeapon)
 {
 if(indices.size() >= 2)
 {
 tempWeapon->EquipItem(anatomyGraph[indices.at(0)]);
 
 anatomyGraph[indices.at(1)].setWeapon(WEAPON_SLOT_FILLED);
 equipSuccess = true;
 
 }
 else
 {
 inventory.addItem(std::move(tempitem));
 return false;
 }
 }
 else
 {
 if(indices.size() >= 1)
 {
 tempWeapon->EquipItem(anatomyGraph[indices.at(0)]);
 anatomyGraph[indices.at(1)].setWeapon(FIST_WEAPON);
 equipSuccess = true;
 
 }
 else
 {
 inventory.addItem(std::move(tempitem));
 return false;
 }
 
 }
 
 if(equipSuccess == true)
 {
 tempitem.release();
 }
 
 
 
 
 }
 
 
 
 
 return equipSuccess;
 }

 
 


/*
 Only a single piece of armor per body part, but a piece of armor can cover multiple sections.
 
 Find all unique pieces of armor equipped on the vertices given by the indices vector
 
 
 
 */
void  CreatureBody::UnequipArmorBySection(std::vector<int> &indices,ItemManager &itemManager)
{
    std::vector<Armor> vecArmor;
    Armor tempArmor;
    
  
  
    
    for(int i = 0; i < indices.size(); i++)
    {
        tempArmor = anatomyGraph[indices.at(i)].getArmor();
        
        //Only proceed if there is armor equipped
        if(tempArmor != NO_ARMOR)
        {
            
            if(std::find(vecArmor.begin(),vecArmor.end(),tempArmor) == vecArmor.end())
            {
                itemManager.addArmor(tempArmor);
            }
          
            
            anatomyGraph[indices.at(i)].setArmor(NO_ARMOR); //Clear the armor slot
            
        }
        

    }
    

}

void CreatureBody::UnequipArmorByName(std::vector<string> &vec)
{
    
    std::vector<int> indices = getExternalBodyParts(anatomyGraph); //Only need external body parts
    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < indices.size(); j++)
        {
            if(vec.at(i) == anatomyGraph[indices.at(j)].getArmor().getItemName())
            {
                anatomyGraph[indices.at(j)].setArmor(NO_ARMOR);
            }
        }
        
    }
}


/*
 If the weapon is large, need two hands to equip it, so uneqip
 Don't need to check for duplicates like I do with armor, will unueqip from the first available lsots
 */
void CreatureBody::UnequipWeaponBySection(std::vector<int> &indices,ItemManager &itemManager,EnWeaponSize size)
{
    Weapon tempWep;
    
    //Select the first two set of hands
    
    //Need at least two hands for a weapon. Pick the first two vertices...Not worried about left-right handedness
    if(size == enLargeWeapon && indices.size() >= 2 )
    {
        
        tempWep = anatomyGraph[indices.at(0)].getWeapon();
        
        if(tempWep != FIST_WEAPON || tempWep != NO_WEAPON || tempWep != WEAPON_SLOT_FILLED)
        {
             itemManager.addWeapon(tempWep);
        }
        
         tempWep = anatomyGraph[indices.at(1)].getWeapon();
        
        if(tempWep != FIST_WEAPON || tempWep != NO_WEAPON || tempWep != WEAPON_SLOT_FILLED)
        {
             itemManager.addWeapon(tempWep);
        }
        
        
        
    }
    else if(indices.size() >= 1)
    {
        tempWep = anatomyGraph[indices.at(0)].getWeapon();
        
        if(tempWep != FIST_WEAPON || tempWep != NO_WEAPON || tempWep != WEAPON_SLOT_FILLED)
        {
            itemManager.addWeapon(tempWep);
        }
    }
    else
    {
        std::cout << "\n Not enough hands";
    }
    
    
    
    
    
}

void CreatureBody::EquipArmor(Item *item)
{
    
    
    for(int i =0; i < item->sections.size(); i++)
    {
        Anatomy_DFS_Section_Visitor vis(item->sections.at(i));
        depth_first_search(anatomyGraph,visitor(vis));
        std::vector<int> indices = vis.getVertexIndices();
        
        for(int j =0; j < indices.size(); j++)
        {
       
                anatomyGraph[indices.at(j)].EquipArmor(item);
            
        }
        
        
        
    }
}

void CreatureBody::EquipWeapon(Item *item)
{
    std::vector<int> indices = getVerticesThatCanHoldWeapons(anatomyGraph);
    
    //if(item->getItemType() == enWeaponType)
   // {
        Weapon *wep = dynamic_cast<Weapon*>(item);
    
 //   std::cout << "\n Damage and range " << wep->getDamage() << ", " << wep->isRangedWeapon();
        if(wep->getWeaponSize() == enLargeWeapon)
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
                if(anatomyGraph[i].getWeaponRef() == NO_WEAPON)
                {
                    anatomyGraph[indices.at(i)].EquipWeapon(item);
                    break;
                    
                }//Change equip weapon function later so it just takes a weapon pointer
            }
            
        }
        
        //wep->isEquipped = true;
        //armor = *arm;
    
    
    
    
}



void CreatureBody::InitializeBodypartEquipment()
{
    for(int i=0; i < num_vertices(anatomyGraph); i++)
    {
        anatomyGraph[i].EquipWeapon(&NO_WEAPON);
        anatomyGraph[i].EquipArmor(&NO_ARMOR);
        
    }
}

void CreatureBody::setName(std::string name)
{
    bodyName = name;
}

std::string CreatureBody::getName()
{
    return bodyName;
}

//N is the index of the node
/*
 What's the problem I need to solve here? Need to find a way to convert the force applied to a body part
 A function to map force to the vertices that force affects
 
 Blunt = Weighted with mass and desnity
 
 Maybe identify the kinds of wounds that a body can suffer from and then tie damage to that
 */
void CreatureBody::ApplyAttack(AttackStats attackStats, int n)
{
  
    
    std::vector<AppliedForceEffect> effects = anatomyGraph[n].ApplyAttack(attackStats);
    
    
}

void CreatureBody::PrintWounds()
{
    for(int i=0; i < num_vertices(anatomyGraph); i++)
    {
        
        if(anatomyGraph[i].getWounds().size() == 0)
            continue;
        
        std::cout << "Body Part: " << anatomyGraph[i].getBodyPartName() << "\n";
        for(int j=0; j < anatomyGraph[i].getWounds().size(); j++)
        {
            
            std::cout << "Wound: ";
            PrintWoundType(anatomyGraph[i].getWounds().at(j));
            std::cout << "\n";
        
         
            
        }
        
        std::cout << "\n";
    }
    
}

void CreatureBody::AddVertex(BodyPart &bp)
{
    
    boost::add_vertex(bp,anatomyGraph);
    
}

void CreatureBody::AddToPainLevel(float level)
{
    totalPain += level;
}


void CreatureBody::AddToBleedingRate(float rate)
{
    totalBleedingRate += rate;
}
/*
BodyPart& getBodyPartRef(AnatomyGraph *graph,int index)
{
    return &graph[index];
}
 */

std::vector<int> getVerticesThatCanHoldWeapons(const AnatomyGraph &graph)
{
    Anatomy_Basic_DFS_Visitor vis;
    depth_first_search(graph,visitor(vis));
    std::vector<int> indices = vis.getVertexIndices();
    std::vector<int> newIndices;
    for(int i=0; i < indices.size(); i++)
    {
        
        // std::cout << "\n BP name " <<  graph[indices.at(i)].bodyPartName<<"Can Hold weapon " << graph[indices.at(i)].canHoldWeapon;
        if(graph[indices.at(i)].getCanHoldWeapon() == true)
        {
            
            //Don't want to erase from the same array I am using
            newIndices.push_back(indices.at(i));
        }
        
    }
    
    
    return newIndices;
}

std::vector<int> getExternalBodyParts(const AnatomyGraph &graph)
{
    
    std::vector<int> indices;
    AnatomyEdgeIt ei,ei_end;
    AnatomyIndexMap indMap = get(vertex_index, graph); //Getting a proeprty map.
    for (boost::tie(ei, ei_end) = edges(graph); ei != ei_end; ++ei)
    {
        //printConnectionType(graph[*ei]);
        
        if(graph[*ei].connection == enExternal || graph[*ei].connection == enExternalLeft || graph[*ei].connection == enExternalRight)
        {
            if(std::find(indices.begin(),indices.end(),indMap[source(*ei, graph)]) == indices.end())
            {
                indices.push_back(indMap[source(*ei, graph)]);
            }
            
            if(std::find(indices.begin(),indices.end(),indMap[target(*ei, graph)]) == indices.end())
            {
                indices.push_back(indMap[target(*ei, graph)]);
            }
        }
    }
    
    return indices;
    
    
}

//For randomly attacking a body part
int getRandomExternalBodyParts(const AnatomyGraph &graph)
{
    AnatomyEdgeIt ei,ei_end;
    AnatomyIndexMap indMap = get(vertex_index, graph); //Getting a proeprty map.
    
    std::vector<int> indices = getExternalBodyParts(graph);
    
    
    return indices.at(rand() % indices.size());
    
    
}

//Gets the internal edges of a specific vertex
std::vector<int> getInternalVertices(int n,AnatomyGraph &graph)
{
    
    std::vector<int> tempVec;
    //Not in bounds
    if(n >= num_vertices(graph))
        return tempVec;
    
    AnatomyEdgeIt ei,ei_end;
    
    
    AnatomyIndexMap indMap = get(vertex_index, graph); //Getting a proeprty map.
    for (boost::tie(ei, ei_end) = edges(graph); ei != ei_end; ++ei)
    {
        
        if(graph[*ei].connection == enInternal || graph[*ei].connection == enInternalLeft ||
           graph[*ei].connection == enInternalRight)
        {
            
            //Only want the vertex it connects to
            if(indMap[source(*ei,graph)] == n)
            {
                tempVec.push_back(indMap[target(*ei,graph)]);
                std::cout << graph[indMap[target(*ei,graph)]];
                
            }
            
            // std::cout << "(" << indMap[source(*ei, graph)];
            
        }
        
    }
    
    return tempVec;
    
    
}

std::vector<int> getConnectedVertices(int n,AnatomyGraph &graph)
{
    std::vector<int> tempArr;
    
    AnatomyIndexMap indMap = get(vertex_index, graph);
    AnatomyAdjacencyIt neighbourIt, neighbourEnd;
    
    for(boost::tie(neighbourIt, neighbourEnd) = adjacent_vertices( indMap[n], graph ); neighbourIt != neighbourEnd; ++neighbourIt   )
    {
        
        tempArr.push_back(indMap[*neighbourIt]);
        //std:: cout <<  graph[*neighbourIt].getBodyPartName();
    }
    
    return tempArr;
}

void WoundReport(AnatomyGraph &graph)
{
    for(int i =0; i < num_vertices(graph); i++)
        graph[i].ShowWounds();
}

//Returns the vertex index
int GetVerticesWithToken(std::string bptoken, AnatomyGraph &graph)
{
    
    AnatomyIndexMap indMap = get(vertex_index, graph);
    
    
    for(int i=0; i < num_vertices(graph); i++)
    {
        
        
        if(graph[i].getBodyPartToken() == bptoken)
        {
            return i;
            
        }
    }
    
    return -1;
}


EnConnectionType convertConnectionType(std::string conType)
{
    std::transform(conType.begin(), conType.end(), conType.begin(), ::tolower);
    EnConnectionType con;
    
    if(conType == "direct")
    {
        con = enDirect;
        
    }
    else if(conType == "left")
    {
        con = enLeftConnection;
    }
    else if(conType == "right")
    {
        con = enRightConnection;
    }
    else if(conType == "internal")
    {
        con = enInternal;
    }
    else if(conType == "internalleft")
    {
        con = enInternalLeft;
    }
    else if(conType == "internalright")
    {
        con = enInternalRight;
    }
    else if(conType == "external")
    {
        con = enExternal;
    }
    else if(conType == "externalright")
    {
        con = enExternalRight;
    }
    else if(conType == "externalleft")
    {
        con = enExternalLeft;
    }
    else
    {
        con = enInvalidConnection;
    }
    
    return con;
}

EnConnectionProperty convertConnectionPropertyType(std::string conType)
{
    std::transform(conType.begin(), conType.end(), conType.begin(), ::tolower);
    EnConnectionProperty con;
    
    if(conType == "bone")
    {
        con = enBone;
        
    }
    else if(conType == "joint")
    {
        con = enJoint;
    }
    else if(conType == "connectivetissue")
    {
        con = enConnectiveTissue;
    }
    
    return con;
    
}

void printConnectionType(GraphConnection con)
{
    if(con.connection == enExternalLeft)
    {
        std::cout << "External Left";
    }
    else if(con.connection == enExternalRight)
    {
        std::cout << "External Right";
    }
    else if(con.connection == enExternal)
    {
        std::cout << "External";
    }
    else if(con.connection == enInternalLeft)
    {
        std::cout << "Internal Left";
    }
    else if(con.connection == enInternalRight)
    {
        std::cout << "Internal Right";
    }
    else if(con.connection == enInternal)
    {
        std::cout << "Internal";
    }
    else if(con.connection == enLeftConnection)
    {
        std::cout << "Left Connection";
    }
    else if(con.connection == enRightConnection)
    {
        std::cout << "Right connection";
    }
    else if(con.connection == enDirect)
    {
        std::cout << "Direct connection";
    }
    else if(con.connection == enSymmetric)
    {
        std::cout << "Symmetric connection";
    }
    
}

void printConnectionProperty(GraphConnection con)
{
    if(con.connectionProperty == enBone)
    {
        std::cout << "Bone";
    }
    else if(con.connectionProperty == enJoint)
    {
        std::cout << "Joint";
    }
    else if(con.connectionProperty == enConnectiveTissue)
    {
        std::cout << "Connective Tissue";
    }
    
}

void printBodyGraphEdges(const AnatomyGraph &graph)
{
    
    AnatomyEdgeIt ei,ei_end;
    AnatomyIndexMap indMap = get(vertex_index, graph); //Getting a proeprty map.
    for (boost::tie(ei, ei_end) = edges(graph); ei != ei_end; ++ei)
    {
        std::cout << "(" << graph[source(*ei, graph)].getBodyPartName()
        << "," << graph[target(*ei, graph)].getBodyPartName() << ") " << " ";
        //printConnectionType(graph[*ei]);
        std::cout << "\n";
        
    }
}

void printBodyGraphVertices(const AnatomyGraph &graph)
{
    AnatomyVertexIt vi,vi_end;
    
    //Printing the properties
    
    for(boost::tie(vi,vi_end) = vertices(graph); vi != vi_end; ++vi)
    {
        std::cout << graph[*vi].getBodyPartName() << "\n";
        // std::cout << graph[*vi].armor.getItemName();
        std::cout << graph[*vi] << "\n";
        
    }
}


int getFirstUnequippedFromSection(const AnatomyGraph &graph,const std::string &section)
{
    Anatomy_DFS_Section_Visitor vis(section);
    depth_first_search(graph,visitor(vis));
    std::vector<int> indices = vis.getVertexIndices();
    
    for(int i =0; i < indices.size(); i++)
    {
        
        /*
         if(graph[indices.at(i)].getArmor().getItemName() == "No Armor")
         {
         
         std::cout << "\n Returning " << i;
         //return indices.at(i);
         
         }
         */
        
        
        if(graph[indices.at(i)].getArmor() == NO_ARMOR)
        {
            
            std::cout << "\n Returning " << i;
            return indices.at(i);
            
        }
    }
    
    return -1;
    
    
    
}


WoundTable::WoundTable()
{
    
}



void WoundTable::AddElement(int index, WoundType woundType)
{
    //std::vector<WoundTableElement>::iterator it;
    
    
    bool elementFound = false;
    WoundTableElement temp = WoundTableElement(index,woundType);
    std::vector<WoundTableElement>::iterator it;
    it = std::find(table.begin(),table.end(),temp);
            
    if( it != table.end())
    {
        
        it->addWoundType(woundType);
    }
    else
    {
        table.push_back(WoundTableElement(index,woundType));
    }
        
    
}






