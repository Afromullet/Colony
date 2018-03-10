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
#include <string>

BodyPart defaultHeadBodyPart(enHeadBodyPart,false,true,false,false,"Head",10);
BodyPart defaultChestBodyPart(enChestBodyPart,false,true,false,false,"Chest",10);
BodyPart defaultEmptyBodyPart(enEmptyBodyPart,false,true,false,false,"Empty",10);


//Returns the vertex index
int GetVerticesWithToken(std::string bptoken, AnatomyGraph &graph)
{
    
    AnatomyIndexMap indMap = get(vertex_index, graph);
    

    for(int i=0; i < num_vertices(graph); i++)
    {
    
   
        if(graph[i].bodyPartToken == bptoken)
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
    else
    {
        con = enInvalidConnection;
    }
    
    return con;
    

    
}

void printBodyGraphEdges(const AnatomyGraph &graph)
{
    
    AnatomyEdgeIt ei,ei_end;
    AnatomyIndexMap indMap = get(vertex_index, graph); //Getting a proeprty map.
    for (boost::tie(ei, ei_end) = edges(graph); ei != ei_end; ++ei)
    {
        std::cout << "(" << graph[source(*ei, graph)].bodyPartName
        << "," << graph[target(*ei, graph)].bodyPartName << ") ";
        
    }
}


using boost::typeindex::type_id_with_cvr;
BodyGraph::BodyGraph()
{
    chestVertex = boost::add_vertex(defaultChestBodyPart,anatomyGraph);
    headVertex  = boost::add_vertex(defaultHeadBodyPart,anatomyGraph);
    
    boost::add_edge(chestVertex,headVertex,anatomyGraph);
    numOfVertices = 2;
}




boost::shared_ptr<std::vector<AnatomyVertex>> BodyGraph::getVertices()
{
    
   
    
    Anatomy_BFS_Visitor vis;
    breadth_first_search(anatomyGraph, vertex(0, anatomyGraph), visitor(vis));
    boost::shared_ptr<std::vector<AnatomyVertex>> aVec = vis.getVector();
    boost::shared_ptr<std::vector<AnatomyVertex>> nVec;
    
    return aVec;
}
 


//Adds the left part and right part to the chest and creates a symmetric connection between the left and right part
void BodyGraph::AddSymmetricPairToChest(BodyPart leftPart, BodyPart rightPart)
{
    
    
    AnatomyVertex leftVert = boost::add_vertex(leftPart,anatomyGraph);
    AnatomyVertex rightVert = boost::add_vertex(rightPart,anatomyGraph);

    
    
    GraphConnection con;
    con.connection = enSymmetric;
    
    boost::add_edge(leftVert, rightVert, con, anatomyGraph);

    
    con.connection = enLeftConnection;
    boost::add_edge(leftVert, chestVertex, con, anatomyGraph);
    boost::add_edge(rightVert, chestVertex, con, anatomyGraph);
}

//Creates two vertices, both created from "part", and creates a symmetric conenction between them
void BodyGraph::AddSymmetricPairToChest(BodyPart part)
{
    AnatomyVertex leftVert = boost::add_vertex(part,anatomyGraph);
    AnatomyVertex rightVert = boost::add_vertex(part,anatomyGraph);
    
    GraphConnection con;
    
    con.connection = enSymmetric;
    boost::add_edge(leftVert, rightVert, con, anatomyGraph);
    
    con.connection = enLeftConnection;
    boost::add_edge(leftVert, chestVertex, con, anatomyGraph);
    
    con.connection = enRightConnection;
    boost::add_edge(rightVert, chestVertex, con, anatomyGraph);

    

    
    
  
}

//Adds the part as a left or right part, and then creates an empty symmetric equivalent
//Left or right identifies the non empty part
void BodyGraph::AddPartToChest(BodyPart part,GraphConnection leftOrRight)
{
    AnatomyVertex vert;
    AnatomyVertex emptyVert;
    GraphConnection con;
    
    vert = boost::add_vertex(part,anatomyGraph);
    emptyVert = boost::add_vertex(defaultEmptyBodyPart,anatomyGraph);
    
    if(leftOrRight.connection == enRightConnection)
    {
        con.connection = enRightConnection;
        boost::add_edge(vert, chestVertex, con, anatomyGraph);
        
        con.connection = enLeftConnection;
        boost::add_edge(emptyVert, chestVertex, con, anatomyGraph);
   
        
    }
    else if(leftOrRight.connection == enLeftConnection)
    {
        
        
        con.connection = enRightConnection;
        boost::add_edge(emptyVert, chestVertex, con, anatomyGraph);
        con.connection = enLeftConnection;
        boost::add_edge(vert, chestVertex, con, anatomyGraph);
       
    }
   
    
    
    
    con.connection = enSymmetric;
    boost::add_edge(vert, emptyVert, con, anatomyGraph);
    



    
}