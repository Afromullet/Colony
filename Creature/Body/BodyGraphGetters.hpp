//
//  BodyGraphGetters.hpp
//  Colony
//
//  Created by Sean on 3/11/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef BodyGraphGetters_hpp
#define BodyGraphGetters_hpp

#include <stdio.h>
#include "BodyGraph.hpp"
#include <string>
#include <vector>

//These are functions which access data from the BodyGraph. 
class Anatomy_DFS_Section_Visitor : public boost::default_dfs_visitor
{
public:
    
    Anatomy_DFS_Section_Visitor(std::string section):
    anatomyVerts(new std::vector<AnatomyVertex>()), searchSection(section)
    {
        
    }
    void discover_vertex(AnatomyVertex u, const AnatomyGraph & g) const
    {
        if(g[u].getSection() == searchSection)
            anatomyVerts->push_back(u);
    }
    

    boost::shared_ptr<std::vector<AnatomyVertex>> getVector()
    {
        return anatomyVerts;
    }
    
    std::vector<int> getVertexIndices()
    {
        //For some reason,
        for(int i =0; i < anatomyVerts->size(); i++)
        {
            vectorIndices.push_back(anatomyVerts->at(i));
        }
        
        return vectorIndices;
    }
    
    
    

    
private:
    boost::shared_ptr<std::vector<AnatomyVertex>> anatomyVerts;
    std::vector<int> vectorIndices;
    
    AnatomyIndexMap indMap;
    std::string searchSection;
    
    
    
};


class Anatomy_Basic_DFS_Visitor : public boost::default_dfs_visitor
{
public:
    
    Anatomy_Basic_DFS_Visitor() :
    anatomyVerts(new std::vector<AnatomyVertex>())
    {
        
    }
    void discover_vertex(AnatomyVertex u, const AnatomyGraph & g) const
    {
            anatomyVerts->push_back(u);
    }
    
    
    boost::shared_ptr<std::vector<AnatomyVertex>> getVector()
    {
        return anatomyVerts;
    }
    
    std::vector<int> getVertexIndices()
    {
        //For some reason,
        for(int i =0; i < anatomyVerts->size(); i++)
        {
            vectorIndices.push_back(anatomyVerts->at(i));
        }
        
        return vectorIndices;
    }
    
    
    
    
    
private:
    boost::shared_ptr<std::vector<AnatomyVertex>> anatomyVerts;
    std::vector<int> vectorIndices;
    
    AnatomyIndexMap indMap;
    
    
    
    
};






#endif /* BodyGraphGetters_hpp */
