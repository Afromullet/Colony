//
//  DataReaders.cpp
//  Colony
//
//  Created by Sean on 4/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "DataReaders.hpp"



using namespace boost;
namespace pt = boost::property_tree;


//FileLogger dataReaderErrorLog("DataReaderErrorLog.xml");

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
        
       // std::cout << v.first << "\n";
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
    float lowTemp,highTemp,treeLevel,vegetationLevel,wildlifeLevel;
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
        
       // std::cout << v.first << "\n";
        // The data function is used to access the data stored in a node.
        
        
        //Even if just one of these values fails reading, the entire material becomes invalid, so just one try/catch is needed for hadling a batch path
        
        
        try
        {
            
            
            
            
            lowTemp = convertFloatVal(v.second.get<std::string>("LowTemp"));
            highTemp = convertFloatVal(v.second.get<std::string>("HighTemp"));
            treeLevel = (float)convertLevelVal(v.second.get<std::string>("TreeLevel"));
            vegetationLevel = (float)convertLevelVal(v.second.get<std::string>("VegetationLevel"));
            wildlifeLevel = (float)convertLevelVal(v.second.get<std::string>("WildlifeLevel"));
                                        
           
            biome.setBiomeName(v.second.get<std::string>("Name"));
            biome.setTemperatureLimits(lowTemp, highTemp);
            biome.setVegetationLevel(vegetationLevel);
            biome.setTreelevel(treeLevel);
            biome.setWildlifeLevel(wildlifeLevel);
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

void ReadPlantFile(const std::string fileName)
{
    pt::ptree tree;
    
    bool isRenewable,isEdible,yieldSeeds;
    float rarity,growthRate;
    std::string name,biomes;
    std::string materialString;
    
    
    std::string biomeName;
    
    Plant plant;
    
    
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
    
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("plantlist"))
    {
        
       // std::cout << v.first << "\n";
        // The data function is used to access the data stored in a node.
        
        
        //Even if just one of these values fails reading, the entire material becomes invalid, so just one try/catch is needed for hadling a batch path
        

        
        try
        {
        
            name = v.second.get<std::string>("name");
            biomes = v.second.get<std::string>("biomes");
            materialString = v.second.get<std::string>("material");
            isEdible = convertTruthValue(v.second.get<std::string>("edible"));
            rarity = convertFloatVal(v.second.get<std::string>("rarity"));
            growthRate = convertFloatVal(v.second.get<std::string>("growthrate"));
        
            

            yieldSeeds = convertTruthValue(v.second.get<std::string>("yieldseeds"));
            
            plant.setName(name);
            plant.setResourceCategory(enPlant);
            plant.setIsRenewable(true);
            plant.setRarity(rarity);
            plant.setIsRenewable(isEdible);
            plant.setYieldSeeds(yieldSeeds);
            plant.setMaterialName(materialString);
            plant.setGrowthRate(growthRate);
            
            std::vector<std::string> &biomeVec = plant.getBiomeVecRef();
            
            boost::split(biomeVec,biomes,boost::is_any_of(","));
            
        }
        catch(pt::ptree_bad_path)
        {
            plant.setName(ERROR_STRING);
            plant.setResourceCategory(enErrorResourceCategory);
            plant.setIsRenewable(true);
            plant.setRarity(ERROR_VALUE);
            plant.setIsRenewable(isEdible);
            plant.setYieldSeeds(yieldSeeds);

            //TODO
            
        }
        
        
        plantResource[numPlantResources] = plant;
        numPlantResources++;
        
    }
    
}

void ReadOreFile(const std::string fileName)
{
    pt::ptree tree;
    
    
    float rarity;
    std::string name,materialString,oreType;
    EnOreType EnOreType;
  
    
    
    
    Ore ore;
    

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
    
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("orelist"))
    {
        
        // std::cout << v.first << "\n";
        // The data function is used to access the data stored in a node.
        
        
        //Even if just one of these values fails reading, the entire material becomes invalid, so just one try/catch is needed for hadling a batch path
        
        
        
        try
        {
            
            //float rarity;
           // std::string name,materialString,oreType;
            
            ore.setIsEdible(false);
            ore.setIsRenewable(false);
            
            name = v.second.get<std::string>("name");
            materialString = v.second.get<std::string>("material");
            rarity = convertFloatVal(v.second.get<std::string>("rarity"));
            EnOreType = convertOreTypeVal(v.second.get<std::string>("oretype"));
            
            
            
          //  std::cout << "\n Name " << name;

            ore.setName(name);
            ore.setOreType(EnOreType);
            ore.setResourceCategory(enOre);
            ore.setRarity(rarity);
            ore.setMaterialName(materialString);
            
            
           
            
            
     
            
           
            
     
            
          
            
        }
        catch(pt::ptree_bad_path)
        {
            ore.setName(ERROR_STRING);
            ore.setResourceCategory(enErrorResourceCategory);
            ore.setIsRenewable(false);
            ore.setRarity(ERROR_VALUE);
            ore.setIsRenewable(false);
            ore.setOreType(enErrorOreType);
        
            
            //TODO
            
        }
        
        
        if(ore.getOreType() == enGemOre)
        {
            gemResources[numGemResources] = ore;
            numGemResources++;
        }
        else if(ore.getOreType() == enStoneOre)
        {
            stoneResources[numStoneResources] = ore;
            numStoneResources++;
        }
        else if(ore.getOreType() == enMetalOre)
        {
            metalResources[numMetalResources] = ore;
            numMetalResources++;
        }
        
        //plantResource[numPlantResources] = plant;
       // numPlantResources++;
        
    }
    

    
}


void ReadTreeFile(const std::string fileName)
{
    pt::ptree tree;
    
    bool isRenewable,isEdible,yieldSeeds;
    float rarity,growthRate,maxDiameter,maxHeight;
    std::string name,biomes;
    std::string materialString;
    
    
    std::string biomeName;
    
    Tree plant;
    
    
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
    
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("treelist"))
    {
        
        // std::cout << v.first << "\n";
        // The data function is used to access the data stored in a node.
        
        
        //Even if just one of these values fails reading, the entire material becomes invalid, so just one try/catch is needed for hadling a batch path
        
        
        
        try
        {
            
            name = v.second.get<std::string>("name");
            biomes = v.second.get<std::string>("biomes");
            materialString = v.second.get<std::string>("material");
            isEdible = convertTruthValue(v.second.get<std::string>("edible"));
            rarity = convertFloatVal(v.second.get<std::string>("rarity"));
            growthRate = convertFloatVal(v.second.get<std::string>("growthrate"));
            maxDiameter = convertFloatVal(v.second.get<std::string>("maxdiameter"));
            maxHeight = convertFloatVal(v.second.get<std::string>("maxheight"));
            
            
            yieldSeeds = convertTruthValue(v.second.get<std::string>("yieldseeds"));
            
            plant.setName(name);
            plant.setResourceCategory(enTree);
            plant.setIsRenewable(true);
            plant.setRarity(rarity);
            plant.setIsRenewable(isEdible);
            plant.setYieldSeeds(yieldSeeds);
            plant.setMaterialName(materialString);
            plant.setGrowthRate(growthRate);
            plant.setMaxHeight(maxHeight);
            plant.setMaxDiameter(maxDiameter);
            
            std::vector<std::string> &biomeVec = plant.getBiomeVecRef();
            
            boost::split(biomeVec,biomes,boost::is_any_of(","));
            
        }
        catch(pt::ptree_bad_path)
        {
            plant.setName(ERROR_STRING);
            plant.setResourceCategory(enErrorResourceCategory);
            plant.setIsRenewable(true);
            plant.setRarity(ERROR_VALUE);
            plant.setIsRenewable(isEdible);
            plant.setYieldSeeds(yieldSeeds);
            
            //TODO
            
        }
        
        
        treeResource[numTreeResources] = plant;
        numTreeResources++;
        
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

int convertLevelVal(std::string s)
{
    if(s=="Low")
    {
        return LOW_LEVEL;
    }
    else if(s =="Moderate")
    {
        return MODERATE_LEVEL;
    }
    else if(s == "High")
    {
        return HIGH_LEVEL;
    }
    else
    {
        return ERROR_VALUE;
    }
}

//Need to handle invalid value
bool convertTruthValue(std::string truthVal)
{
    std::transform(truthVal.begin(), truthVal.end(), truthVal.begin(), ::tolower);
    
    if(truthVal == "false")
    {
        
        return false;
    }
    else if(truthVal == "true")
    {
        
        return true;
    }
}

EnOreType convertOreTypeVal(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    if(str == "stone")
    {
        
        return enStoneOre;
    }
    else if(str == "metal")
    {
        
        return enMetalOre;
    }
    else if(str == "gem")
    {
        return enGemOre;
    }
    else
    {
        return enErrorOreType;
    }
     
}
