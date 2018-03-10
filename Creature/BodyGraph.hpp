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
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/graph_utility.hpp>
#include <string>
#include "Globals.hpp"

using namespace boost;
#ifndef BodyGraph_hpp
#define BodyGraph_hpp




enum EnConnectionType {enSymmetric,enDirect,enLeftConnection,enRightConnection};

typedef boost::property < boost::edge_weight_t, double> EdgeWeightProp;

typedef struct _GraphConnection
{
    EnConnectionType connection;
    EdgeWeightProp weightProperty;
}GraphConnection;

extern BodyPart defaultHeadBodyPart;
extern BodyPart defaultChestBodyPart;
extern BodyPart defaultEmptyBodyPart;





typedef boost::adjacency_list<vecS, vecS, bidirectionalS,BodyPart,GraphConnection,EdgeWeightProp> AnatomyGraph; //Bodypart is the Vertex Property

typedef boost::graph_traits<AnatomyGraph>::vertex_descriptor AnatomyVertex;
typedef boost::graph_traits<AnatomyGraph>::edge_descriptor AnatomyEdge;

typedef boost::graph_traits <AnatomyGraph>::edge_iterator AnatomyEdgeIt;
typedef boost::graph_traits<AnatomyGraph>::vertex_iterator AnatomyVertexIt;



//typedef std::map<AnatomyVertex,AnatomyVertex> AnatomyMap;

typedef boost::property_map<AnatomyGraph, vertex_index_t>::type AnatomyIndexMap;


class edge_predicate_c {
public:
    edge_predicate_c() : graph_m(0) {}
    edge_predicate_c(AnatomyGraph& graph) : graph_m(&graph) {}
    bool operator()(const AnatomyEdge& edge_id) const {
        EnConnectionType type = (*graph_m)[edge_id].connection;
        return (type == enLeftConnection);
    }
private:
    AnatomyGraph* graph_m;
};


//Todo get all arm vertices and their connection etc for all other limbs

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

class Anatomy_DFS_Visitor : public boost::default_dfs_visitor
{
public:
    
    Anatomy_DFS_Visitor(): anatomyVerts(new std::vector<AnatomyVertex>()){}
    void discover_vertex(AnatomyVertex u, const AnatomyGraph & g) const
    {
     //   std::cout << u << std::endl;
        
       // std::cout << g[u];
        anatomyVerts->push_back(u);
    }
    
    void tree_edge(AnatomyEdge e, const AnatomyGraph& g)
    {
        std::cout << e;
    }
    
    
    
    
    boost::shared_ptr<std::vector<AnatomyVertex>> getVector()
    {
        return anatomyVerts;
    }
    
private:
    boost::shared_ptr<std::vector<AnatomyVertex>> anatomyVerts;
    
    
    
};


//Returns the vertex index
int GetVerticesWithToken(std::string bptoken, const AnatomyGraph &graph);

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
    
 
    



    

    
    
 
    
    
    boost::shared_ptr<std::vector<AnatomyVertex>> getVertices();
    void AddSymmetricPairToChest(BodyPart leftPart, BodyPart rightPart);
    void AddSymmetricPairToChest(BodyPart part);
    void AddPartToChest(BodyPart part,GraphConnection leftOrRight);
    
    
    
     int numOfVertices;
    

   
   

};
 

#endif /* BodyGraph_hpp */


