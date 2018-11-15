//
//  BodyGraph.hpp
//  Colony
//
//  Created by Sean on 1/11/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//



#include "Globals.hpp"


#include "Wound.hpp"





#ifndef BodyGraph_hpp
#define BodyGraph_hpp

#include "EnumTypes.hpp"
#include "BodyPart.hpp"
#include "ItemManager.hpp"
#include "Equipment.hpp"
#include <memory>
#include <string>

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
using namespace boost;



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



//Using a struct so that a wound table can handle its own insertions and finding of elements
//Don't need this to be a class because it only has a few operations and no polymorphism is intended. It's just a lookup table




struct WoundTableElement
{
public:
    
    int index;
    std::vector<WoundType> woundTypes;
    
    friend bool operator==(const WoundTableElement &lhs,const WoundTableElement &rhs)
    {
        
        return lhs.index == rhs.index;
        
        
    }
    
    void operator=(const WoundTableElement &other)
    {
        index = other.index;
        woundTypes.insert(woundTypes.end(),other.woundTypes.begin(),other.woundTypes.end());
        
    }
    
    WoundTableElement(int _index, WoundType wound)
    {
        index = _index;
        woundTypes.push_back(wound);
    }
    
    WoundTableElement()
    {
        
    }
    
    void addWoundType(WoundType type)
    {
        woundTypes.push_back(type);
    }
    
    
};

struct WoundTable
{
    std::vector<WoundTableElement> table;
    
    
    
    //Need to merge tables when the creatures woundTable gets updated
    void operator=(const WoundTable &other)
    {
        std::vector<WoundTableElement>::iterator it;
        for(int i = 0; i < other.table.size(); i++)
        {
            
      
            
            it = std::find(table.begin(),table.end(),other.table.at(i));
            
            if( it != table.end())
            {
                
                *it = other.table.at(i);
                //it->addWoundType(woundType);
            }
            else
            {
                table.push_back(other.table.at(i));
                
               // table.push_back(WoundTableElement(index,other.at());
            }
         
           
        }
        
        
    }
    
    
    WoundTable();
    
    
    
    
    void AddElement(int index, WoundType woundType);
    
    void AddElement(WoundTableElement &other)
    {
        table.push_back(other);
    }
    
    
    
};


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
    WoundTable woundTable;//A one dimensional table I guess? Takes extra space, but it's better than having to search the graph for every wound
    
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
    void UnequipArmorByName(std::vector<std::string> &vec);
    void UnequipWeaponBySection(std::vector<int> &indices,ItemManager &itemManager,EnWeaponSize size);
    void EquipArmor(Item *item);
    void EquipWeapon(Item *item);
    void ApplyAttack(AttackStats attackStats, int n);
    void PrintWounds();
    
    void AddVertex(BodyPart &bp);
    
   
   
    
    
    
    
    
};



//Returns the vertex index
int GetVerticesWithToken(std::string bptoken,  AnatomyGraph &graph);
EnConnectionType convertConnectionType(std::string conType);
EnConnectionProperty convertConnectionPropertyType(std::string conType);
void printBodyGraphEdges(const AnatomyGraph &graph);
void printConnectionType(GraphConnection con);
void printConnectionProperty(GraphConnection con);
void printBodyGraphVertices(const AnatomyGraph &graph);


std::vector<int> getExternalBodyParts(const AnatomyGraph &graph);
int getRandomExternalBodyParts(const AnatomyGraph &graph);

int getFirstUnequippedFromSection(const AnatomyGraph &graph, const std::string &section);
std::vector<int> getVerticesThatCanHoldWeapons(const AnatomyGraph &graph);
std::vector<int> getInternalVertices(int n,AnatomyGraph &graph);
std::vector<int> getConnectedVertices(int n,AnatomyGraph &graph);

void WoundReport(AnatomyGraph &graph);




#endif /* BodyGraph_hpp */


