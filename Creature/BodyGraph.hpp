//
//  BodyGraph.hpp
//  Colony
//
//  Created by Sean on 1/11/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <list>
#include "BodyPart.hpp"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/pending/indirect_cmp.hpp>
#include <boost/range/irange.hpp>
#include <string>
#include "Globals.hpp"

using namespace boost;
#ifndef BodyGraph_hpp
#define BodyGraph_hpp



enum EnConnectionType {enSymmetric,enDirect};

typedef struct _GraphConnection
{
    EnConnectionType connection;
}GraphConnection;

extern BodyPart defaultHeadBodyPart;
extern BodyPart defaultChestBodyPart;
typedef boost::adjacency_list<vecS, vecS, bidirectionalS,BodyPart,GraphConnection> AnatomyGraph; //Bodypart is the Vertex Property

typedef boost::graph_traits<AnatomyGraph>::vertex_descriptor AnatomyVertex;
typedef boost::graph_traits<AnatomyGraph>::edge_descriptor AnatomyEdge;

typedef boost::graph_traits <AnatomyGraph>::edge_iterator anatomyEdgeIt;
typedef boost::graph_traits<AnatomyGraph>::vertex_iterator anatomyVertexIt;



typedef std::map<AnatomyVertex,AnatomyVertex> AnatomyMap;

typedef boost::property_map<AnatomyGraph, vertex_index_t>::type IndexMap;




class Anatomy_BFS_Visitor : public boost::default_bfs_visitor
{

public:
    
     Anatomy_BFS_Visitor(): anatomyVerts(new std::vector<AnatomyVertex>()){}
    void discover_vertex(AnatomyVertex u, const AnatomyGraph & g) const
    {
        std::cout << u << std::endl;
        anatomyVerts->push_back(u);
    }
    
    boost::shared_ptr<std::vector<AnatomyVertex>> getVector()
    {
        return anatomyVerts;
    }

    
private:
    boost::shared_ptr<std::vector<AnatomyVertex>> anatomyVerts;
    };



class BodyGraph
{
    
private:
    
    //Every body needs a head and a chest
    AnatomyVertex headVertex;
    AnatomyVertex chestVertex;
    
    //Keeping tracks of hands makes things easier for purposes of weapons
    std::vector<BodyPart*> leftHands;
    std::vector<BodyPart*> rightHands;
    
public:


    
    BodyGraph();
    
    AnatomyGraph anatomyGraph;
    
 
    



    
    
    //Two hands, two legs, etc
    void AddPartsToChest(BodyPart p1,BodyPart p2);
    void AddArmPairToChest(BodyPart LeftArm,BodyPart RightArm,BodyPart LeftHand,BodyPart RightHand);
    void AddLegPairToChest(BodyPart LeftLeg,BodyPart RightLeg,BodyPart LeftFoot,BodyPart RightFoot);
    
    
    boost::shared_ptr<std::vector<AnatomyVertex>> getVertices();
  

    std::vector<int>  getVerticesOfType(const std::string &partName);
    
    void printBody();
    void InitializeHandPairs();
    void EquipArmor(Item *item);
    
    
    
     int numOfVertices;
    

   
   

};
 

#endif /* BodyGraph_hpp */
