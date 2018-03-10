//
//  BodygraphReader.hpp
//  Colony
//
//  Created by Sean on 3/9/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef BodygraphReader_hpp
#define BodygraphReader_hpp

#include <stdio.h>
#include<iostream>
#include<string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <BodyGraph.hpp>

namespace pt = boost::property_tree;


struct BodyTypeReader
{
    AnatomyGraph anatomyGraph;
    pt::ptree tree;
    std::string m_file;
    std::vector<std::string> bodyTokenList;
 
    
    void GenerateVertices();
    void GenerateEdges();
 
    void load();
    void openBodyTypeFile(const std::string &fileName);
    void readBodyTokenList();
    int convertTruthValue(std::string truthVal);
    
};



#endif /* BodygraphReader_hpp */
