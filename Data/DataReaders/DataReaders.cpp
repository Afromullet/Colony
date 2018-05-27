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
#include "Biomes.hpp"
#include "Constants.hpp"


using namespace boost;
namespace pt = boost::property_tree;


FileLogger dataReaderErrorLog("DataReaderErrorLog.xml");

void ReadMaterialFile(const std::string fileName)
{
   
    
    pt::ptree tree;
    Material material;
    float compression,impact,tensile,torsion,shear,density;
    std::string matName;
    

    try
    {
        pt::read_xml(fileName, tree);
        
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
            
            material.setMaterialName(v.second.get<std::string>("Name"));
            
            material.setDensity(density);
            
            
            
          
            
         
        }
        catch(pt::ptree_bad_path)
        {
            material.setDeformationStrenghts(ERROR_VALUE,ERROR_VALUE,ERROR_VALUE,ERROR_VALUE,ERROR_VALUE);
            material.setFractureStrength(ERROR_VALUE,ERROR_VALUE,ERROR_VALUE,ERROR_VALUE,ERROR_VALUE);
            material.setDensity(ERROR_VALUE);
            
            
        }
        
        
        materials.push_back(material);
        
        //bodyTokenList.push_back(v.second.data());
    }
    
    
}

void ReadBiomeFile(const std::string fileName)
{
    
    pt::ptree tree;
    Biome biome;
    float lowTemp,highTemp;
    std::string biomeName;
    
    
    try
    {
        pt::read_xml(fileName, tree);
        
        // pt::read_xml("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/BasicHumanoidBody.xml", tree);
    }
    catch(boost::property_tree::xml_parser::xml_parser_error& ex)
    {
        std::cout << "'\n Failed reading";
        
        
        //std::cout <<
    }
    
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("biomelist"))
    {
        
        std::cout << v.first << "\n";
        // The data function is used to access the data stored in a node.
        
        
        //Even if just one of these values fails reading, the entire material becomes invalid, so just one try/catch is needed for hadling a batch path
        
        
        try
        {
            
            
            
            
            lowTemp = convertFloatVal(v.second.get<std::string>("LowTemp"));
            highTemp = convertFloatVal(v.second.get<std::string>("HighTemp"));
         
            
            biome.setBiomeName(v.second.get<std::string>("Name"));
            biome.setTemperatureLimits(lowTemp, highTemp);
            

            
            
            
            
        }
        catch(pt::ptree_bad_path)
        {
      
            biome.setBiomeName(ERROR_STRING);
            biome.setTemperatureLimits(ERROR_VALUE, ERROR_VALUE);

            
        }
        
        
        vecBiome.push_back(biome);
        
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
    
    return true;
    
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
