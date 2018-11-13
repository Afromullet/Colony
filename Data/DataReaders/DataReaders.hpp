//
//  DataReaders.hpp
//  Colony
//
//  Created by Sean on 4/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef DataReaders_hpp
#define DataReaders_hpp

#include <stdio.h>
#include <string>

#include "Plant.hpp"
#include "Resource.hpp"
#include "Ore.hpp"
#include <boost/range/irange.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include "Material.hpp"
#include "DataStorage.hpp"
#include "Biomes.hpp"
#include "Constants.hpp"
#include "Tree.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

#define MATERIAL_READER_INPUT_ERROR

//extern FileLogger dataReaderErrorLog;

void InitializeDataReaderErrorLog();

void ReadMaterialFile(const std::string fileName);
void ReadBiomeFile(const std::string fileName);
void ReadPlantFile(const std::string fileName);
void ReadOreFile(const std::string fileName);
void ReadTreeFile(const std::string fileName);

bool ValidateMaterialFile();

float convertFloatVal(std::string s);
int convertIntVal(std::string s);
int convertLevelVal(std::string s);
bool convertTruthValue(std::string truthVal);
EnOreType convertOreTypeVal(std::string str);


#endif /* DataReaders_hpp */
