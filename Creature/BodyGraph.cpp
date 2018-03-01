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

BodyPart defaultHeadBodyPart(enHeadBodyPart,false,true,false,false,"Head",10);
BodyPart defaultChestBodyPart(enChestBodyPart,false,true,false,false,"Chest",10);

using boost::typeindex::type_id_with_cvr;
BodyGraph::BodyGraph()
{
    headVertex  = boost::add_vertex(defaultHeadBodyPart,anatomyGraph);
    chestVertex = boost::add_vertex(defaultChestBodyPart,anatomyGraph);
    boost::add_edge(headVertex,chestVertex,anatomyGraph);
    numOfVertices = 2;
}


//Two hands, two legs, etc
void BodyGraph::AddPartsToChest(BodyPart p1,BodyPart p2)
{
    AnatomyVertex tempVertex = boost::add_vertex(p1,anatomyGraph);
    boost::add_edge(chestVertex,tempVertex,anatomyGraph);
    
    tempVertex = boost::add_vertex(p2,anatomyGraph);
    boost::add_edge(chestVertex,tempVertex,anatomyGraph);
    
    
    numOfVertices += 2;
    
    
}

void BodyGraph::AddArmPairToChest(BodyPart LeftArm,BodyPart RightArm,BodyPart LeftHand,BodyPart RightHand)
{
    
    if(LeftArm.enBodyPartType != enLeftArmBodyPart || RightArm.enBodyPartType != enRightArmBodyPart || LeftHand.enBodyPartType != enLeftHandBodyPart ||
       RightHand.enBodyPartType != enRightHandBodyPart)
    {
        std::cout << "Problem adding arms\n";
    }
    
    EnConnectionType conType;
    
    conType = enSymmetric;
    
    GraphConnection symConnection;
     GraphConnection dirConnection;
    
    symConnection.connection = enSymmetric;
    dirConnection.connection = enDirect;
    
 
    AnatomyVertex LAVert = boost::add_vertex(LeftArm,anatomyGraph);
    AnatomyVertex RAVert = boost::add_vertex(RightArm,anatomyGraph);
    AnatomyVertex LHVert = boost::add_vertex(LeftHand,anatomyGraph);
    AnatomyVertex RHVert = boost::add_vertex(RightHand,anatomyGraph);
    

    
    boost::add_edge(chestVertex,LAVert,dirConnection,anatomyGraph);
    boost::add_edge(chestVertex,RAVert,dirConnection,anatomyGraph);
    boost::add_edge(RAVert,RHVert,dirConnection,anatomyGraph);
    boost::add_edge(LAVert,LHVert,dirConnection,anatomyGraph);
    
    boost::add_edge(LAVert,RAVert,symConnection,anatomyGraph);
    
    numOfVertices += 4;
    
    
    
}

void BodyGraph::AddLegPairToChest(BodyPart LeftLeg,BodyPart RightLeg,BodyPart LeftFoot,BodyPart RightFoot)
{
    AnatomyVertex LLVert = boost::add_vertex(LeftLeg,anatomyGraph);
    AnatomyVertex RLVert = boost::add_vertex(RightLeg,anatomyGraph);
    AnatomyVertex LFVert = boost::add_vertex(LeftFoot,anatomyGraph);
    AnatomyVertex RFVert = boost::add_vertex(RightFoot,anatomyGraph);
    
    
    
    boost::add_edge(chestVertex,LLVert,anatomyGraph);
    boost::add_edge(chestVertex,RLVert,anatomyGraph);
    boost::add_edge(RLVert,RFVert,anatomyGraph);
    boost::add_edge(LLVert,LFVert,anatomyGraph);
    
    numOfVertices += 4;
}


boost::shared_ptr<std::vector<AnatomyVertex>> BodyGraph::getVertices()
{
    
   
    
    Anatomy_BFS_Visitor vis;
    breadth_first_search(anatomyGraph, vertex(0, anatomyGraph), visitor(vis));
    boost::shared_ptr<std::vector<AnatomyVertex>> aVec = vis.getVector();
    boost::shared_ptr<std::vector<AnatomyVertex>> nVec;
    
    return aVec;
}



//Since we can find the vertices by index, this just returns the indices
//TODO, don't think I need BFS..I should be able to just iterate using indices

std::vector<int>  BodyGraph::getVerticesOfType(const std::string &partName)
{
    Anatomy_BFS_Visitor vis;
    breadth_first_search(anatomyGraph, vertex(0, anatomyGraph), visitor(vis));
    boost::shared_ptr<std::vector<AnatomyVertex>> aVec = vis.getVector();
    std::vector<int> nVec;
    
    EnumBodyPart part1,part2;
    
    
    if(partName == "arm")
    {
        part1 = enLeftArmBodyPart;
        part2 = enRightArmBodyPart;
    }
    else if(partName == "hand")
    {
        part1 = enLeftHandBodyPart;
        part2 = enRightHandBodyPart;
    }
    else if(partName == "leg")
    {
        part1 = enLeftLegBodyPart;
        part2 = enRightLegBodyPart;
    }
    else if(partName == "foot")
    {
        part1 = enLeftLegBodyPart;
        part2 = enRightFootBodyPart;
    }
    
    
    std::cout << "\n Part Name " << partName;
    for(AnatomyVertex aVert : *aVec)
    {
        
        
        if(anatomyGraph[aVert].enBodyPartType == part1 || anatomyGraph[aVert].enBodyPartType == part2)
        {
            nVec.push_back(aVert);
        }
        
        //anatomyGraph[aVert].ApplyDamage(5);
        
        
    }
    
    return nVec;
    
    
    
    
}
void BodyGraph::printBody()
{
    BodyPart tempBodyPart;
    
    
    for(int i =0; i < numOfVertices; i++)
    {
        tempBodyPart = anatomyGraph[i];
        std::cout << tempBodyPart << "\n";
    }
    
    std::cout << "\n\n\n";
}

void BodyGraph::InitializeHandPairs()
{
    std::vector<int> hands = getVerticesOfType("hand");
    
    //Storing in a temporary type makes this easier because there might not be an equal number of hands
    
    std::shared_ptr<BodyPart> tShared;

    
    for(int i=0; i < hands.size(); i++)
    {
        if(anatomyGraph[hands.at(i)].enBodyPartType == enLeftHandBodyPart)
        {
            leftHands.push_back(&anatomyGraph[hands.at(i)]);
            //leftHands.push_back(std::make_shared<BodyPart>(anatomyGraph[hands.at(i)]));
            
        }
        else if(anatomyGraph[hands.at(i)].enBodyPartType == enLeftHandBodyPart)
        {
            rightHands.push_back(&anatomyGraph[hands.at(i)]);

            //rightHands.push_back(std::make_shared<BodyPart>(anatomyGraph[hands.at(i)]));
            
        }
        std::cout << anatomyGraph[hands.at(i)];
    }
    
    
    
}

void BodyGraph::EquipArmor(Item *item)
{
    EnumBodyPart partType = item->getBodyPart();
    
    //Finds the first non filled slot that can fit the item
    for(int i=0; i < numOfVertices; i++)
    {
        if(anatomyGraph[i].enBodyPartType == partType)
        {
           if(anatomyGraph[i].armor == NO_ARMOR)
           {
               anatomyGraph[i].EquipArmor(item);
               break;
           }
            
        }
    }
    
}

//Every body must have a head and chest
