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

bool ValidateMaterialFile();

float convertFloatVal(std::string s);
int convertIntVal(std::string s);

#endif /* DataReaders_hpp */
