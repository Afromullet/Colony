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

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/pending/indirect_cmp.hpp>
#include <boost/range/irange.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include "Globals.hpp"
#include "EnumTypes.hpp"
#include <memory>
#include "ItemManager.hpp"




using namespace boost;
#ifndef BodyGraph_hpp
#define BodyGraph_hpp


#include "BodyPart.hpp"




//Internal edge means that it is "inside" of the body part. Don't want to have a graph with both directed and non directed edges
//So the second of the values in the ordered pair is the part that is internal. (Chest,Lung) with enInternal edge property means that the lung is internal. TODO check if boost graph always adds edges in the order that the function is called , add_edge(a,b) creating (a,b) and never (b,a)
enum EnConnectionType {enSymmetric,enDirect,enLeftConnection,enRightConnection,enInvalidConnection,enInternal,enInternalLeft,enInternalRight,enExternalLeft,enExternalRight,enExternal,enExternalLeftFront,enExternalRightFront};

enum EnConnectionProperty
{
    enBone,enJoint,enConnectiveTissue,enInvalidEdgeConnection
};

enum BodyPartPosition
{
    enFrontPosition,enBackPosition,enLeftPosition,enRightPosition
    
};



typedef boost::property < boost::edge_weight_t, double> EdgeWeightProp;

typedef struct _GraphConnection
{
    EnConnectionType connection;
    EnConnectionProperty connectionProperty;
    EdgeWeightProp weightProperty;
}GraphConnection;





typedef boost::adjacency_list<vecS, vecS, bidirectionalS,BodyPart,GraphConnection,EdgeWeightProp> AnatomyGraph; //Bodypart is the Vertex Property

typedef boost::graph_traits<AnatomyGraph>::vertex_descriptor AnatomyVertex;
typedef boost::graph_traits<AnatomyGraph>::edge_descriptor AnatomyEdge;

typedef boost::graph_traits <AnatomyGraph>::edge_iterator AnatomyEdgeIt;
typedef boost::graph_traits<AnatomyGraph>::vertex_iterator AnatomyVertexIt;
typedef boost::graph_traits<AnatomyGraph>::adjacency_iterator AnatomyAdjacencyIt;


//typedef std::map<AnatomyVertex,AnatomyVertex> AnatomyMap;

typedef boost::property_map<AnatomyGraph, vertex_index_t>::type AnatomyIndexMap;


namespace pt = boost::property_tree;

//Rename class..just use this as the bodygraph later

class CreatureBody
{
    
private:
    pt::ptree tree;
    std::string m_file;
    std::vector<std::string> bodyTokenList;
    float bodySize;
    std::string bodyName;
    
public:
    
    AnatomyGraph anatomyGraph;
    
    CreatureBody();
  
    
    void GenerateVertices();
    void GenerateOrganVertices();
    void GenerateEdges();
    void GenerateOrganEdges();
    void InitializeBodypartEquipment();
    
    void setName(std::string name);
    std::string getName();
    
    void load();
    void openBodyTypeFile(const std::string &fileName);
    void readBodyTokenList();
    int convertTruthValue(std::string truthVal);
    bool Equip(std::unique_ptr<Item> item,ItemManager &inventory,int index);
    void UnequipArmorBySection(std::vector<int> &indices,ItemManager &itemManager);
    void UnequipWeaponBySection(std::vector<int> &indices,ItemManager &itemManager,EnWeaponSize size);
    void EquipArmor(Item *item);
    void EquipWeapon(Item *item);
    void ApplyAttack(AttackStats attackStats, int n);
    void PrintWounds();
    
    void AddVertex(BodyPart &bp);
   
    
    
    
    
    
};






#endif /* BodyGraph_hpp */


