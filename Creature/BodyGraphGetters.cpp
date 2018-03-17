//
//  BodyGraphGetters.cpp
//  Colony
//
//  Created by Sean on 3/11/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "BodyGraphGetters.hpp"


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

void printBodyGraphVertices(const AnatomyGraph &graph)
{
    AnatomyVertexIt vi,vi_end;
    
    //Printing the properties
    
    for(boost::tie(vi,vi_end) = vertices(graph); vi != vi_end; ++vi)
    {
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
        
        
        if(graph[indices.at(i)].armor.sEquipmentName == "No Armor")
        {
            
            std::cout << "\n Returning " << i;
            return indices.at(i);
            
        }
    }
    
    return -1;
    

    
}

std::vector<int> getVerticesThatCanHoldWeapons(const AnatomyGraph &graph)
{
    Anatomy_Basic_DFS_Visitor vis;
    depth_first_search(graph,visitor(vis));
    std::vector<int> indices = vis.getVertexIndices();
    std::vector<int> newIndices;
    for(int i=0; i < indices.size(); i++)
    {
      
        std::cout << "\n BP name " <<  graph[indices.at(i)].bodyPartName<<"Can Hold weapon " << graph[indices.at(i)].canHoldWeapon;
        if(graph[indices.at(i)].canHoldWeapon == true)
        {
         
            //Don't want to erase from the same array I am using
            newIndices.push_back(indices.at(i));
        }
        
    }
    
    
    return newIndices;
}