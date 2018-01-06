//
//  Filelogger.hpp
//  Colony
//
//  Created by Sean on 1/6/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Filelogger_hpp
#define Filelogger_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

//A class that handles writing to a file. For an error log for example

class FileLogger
{
private:
    
    std::ofstream file;
    
public:
    FileLogger(std::string filename);
    void writeToFile(std::string const &data);
    void closeFile();
    
};

#endif /* Filelogger_hpp */
