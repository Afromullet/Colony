//
//  DataReaders.cpp
//  Colony
//
//  Created by Sean on 4/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "DataReaders.hpp"
#include <boost/range/irange.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include "Material.hpp"
#include "DataStorage.hpp"
using namespace boost;
namespace pt = boost::property_tree;


FileLogger dataReaderErrorLog("DataReaderErrorLog.xml");

void ReadMaterialFile(const std::string fileName)
{
   
    
    pt::ptree tree;
    Material material;
    float compression,impact,tensile,torsion,shear,density;
    

    try
    {
        pt::read_xml("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/MaterialFiles/BasicMaterials.xml", tree);
        
       // pt::read_xml("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/BasicHumanoidBody.xml", tree);
    }
    catch(boost::property_tree::xml_parser::xml_parser_error& ex)
    {
        std::cout << "'\n Failed reading";
        
        
        //std::cout <<
    }
   
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("materiallist"))
    {
        
        std::cout << v.first << "\n";
        // The data function is used to access the data stored in a node.
        
        
        //Even if just one of these values fails reading, the entire material becomes invalid, so just one try/catch is needed for hadling a batch path
        
        
        try
        {
            
          
       
            
            compression = convertFloatVal(v.second.get<std::string>("CompressionDeformationStrenth"));
            impact = convertFloatVal(v.second.get<std::string>("ImpactDeformationStrength"));
            tensile = convertFloatVal(v.second.get<std::string>("TensileDeformationStrength"));
            torsion = convertFloatVal(v.second.get<std::string>("TorsionDeformationStrength"));
            shear = convertFloatVal(v.second.get<std::string>("ShearDeformationStrength"));
            material.setDeformationStrenghts(compression,impact,tensile,torsion,shear);
       
            
            compression = convertFloatVal(v.second.get<std::string>("CompressionFractureStrength"));
            impact = convertFloatVal(v.second.get<std::string>("ImpactFractureStrength"));
            tensile = convertFloatVal(v.second.get<std::string>("TensileFractureStrength"));
            torsion = convertFloatVal(v.second.get<std::string>("TorsionFractureStrength"));
            shear = convertFloatVal(v.second.get<std::string>("ShearFractureStrength"));
            material.setFractureStrength(compression,impact,tensile,torsion,shear);
            
            density = convertFloatVal(v.second.get<std::string>("Density"));
            
            material.setDensity(density);
            
            
            
          
            
         
        }
        catch(pt::ptree_bad_path)
        {
            material.setDeformationStrenghts(-1,-1,-1,-1,-1);
            material.setFractureStrength(-1,-1,-1,-1,-1);
            material.setDensity(-1);
            
            
        }
        
        
        materials.push_back(material);
        
        //bodyTokenList.push_back(v.second.data());
    }
    
    
}


bool ValidateMaterialFile()
{
    for(int i=0; i < materials.size(); i++)
    {
        if(!materials.at(i).isValidMaterial())
        {
            
        }
    }
    
}
float convertFloatVal(std::string s)
{
    float retVal;
    
    try
    {
        retVal = std::stof(s);
    }
    catch(const std::invalid_argument& ia)
    {
        retVal = -1;
    }
    catch(const std::out_of_range& oor)
    {
        retVal = -1;
    }
    
    return retVal;
}
int convertIntVal(std::string s)
{
    int retVal;
    
    try
    {
        retVal = std::stoi(s);
    }
    catch(const std::invalid_argument& ia)
    {
        retVal = -1;
    }
    catch(const std::out_of_range& oor)
    {
        retVal = -1;
    }
    
    return retVal;
    
}
