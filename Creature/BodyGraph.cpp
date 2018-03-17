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
 


