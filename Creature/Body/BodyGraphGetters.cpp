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
