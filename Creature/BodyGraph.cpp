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

void printBodyGraphEdges(const AnatomyGraph &graph)
{
    
    AnatomyEdgeIt ei,ei_end;
    AnatomyIndexMap indMap = get(vertex_index, graph); //Getting a proeprty map.
    for (boost::tie(ei, ei_end) = edges(graph); ei != ei_end; ++ei)
    {
        std::cout << "(" << graph[source(*ei, graph)].bodyPartName
        << "," << graph[target(*ei, graph)].bodyPartName << ") " << " ";
        printConnectionType(graph[*ei]);
        std::cout << "\n";
        
    }
}


using boost::typeindex::type_id_with_cvr;
BodyGraph::BodyGraph()
{

}




boost::shared_ptr<std::vector<AnatomyVertex>> BodyGraph::getVertices()
{
    
   
    
    Anatomy_BFS_Visitor vis;
    breadth_first_search(anatomyGraph, vertex(0, anatomyGraph), visitor(vis));
    boost::shared_ptr<std::vector<AnatomyVertex>> aVec = vis.getVector();
    boost::shared_ptr<std::vector<AnatomyVertex>> nVec;
    
    return aVec;
}
 


