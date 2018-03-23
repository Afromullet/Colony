//
//  Task.hpp
//  Colony
//
//  Created by Sean on 3/23/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Task_hpp
#define Task_hpp

#include <stdio.h>
#include "MovementAction.hpp"
#include "ExamineAction.hpp"


#include <boost/graph/adjacency_list.hpp>

using namespace boost;

//A task is a graph consisting of actions
typedef boost::adjacency_list<vecS, vecS, directedS,AbstractAction*> TaskGraph; //Bodypart is the Vertex Property

typedef boost::graph_traits<TaskGraph>::vertex_descriptor TaskVertex;
typedef boost::graph_traits<TaskGraph>::edge_descriptor TaskEdge;

typedef boost::graph_traits <TaskGraph>::edge_iterator TaskEdgeIt;
typedef boost::graph_traits<TaskGraph>::vertex_iterator TaskVertexIt;

typedef boost::property_map<TaskGraph, vertex_index_t>::type TaskIndexMap;

class Task
{
    
private:
    
    
public:
    Task();
    
    TaskGraph graph;
    
    void AddEdge(AbstractAction *action);
    
};


#endif /* Task_hpp */
