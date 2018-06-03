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
#include "FileLogger.hpp"

#define MATERIAL_READER_INPUT_ERROR

extern FileLogger dataReaderErrorLog;

void InitializeDataReaderErrorLog();

void ReadMaterialFile(const std::string fileName);
void ReadBiomeFile(const std::string fileName);
void ReadPlantFile(const std::string fileName);

bool ValidateMaterialFile();

float convertFloatVal(std::string s);
int convertIntVal(std::string s);
int convertLevelVal(std::string s);
bool convertTruthValue(std::string truthVal);

#endif /* DataReaders_hpp */
