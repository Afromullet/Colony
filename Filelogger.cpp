//
//  Filelogger.cpp
//  Colony
//
//  Created by Sean on 1/6/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Filelogger.hpp"
#

FileLogger::FileLogger(std::string filename) : file(filename,std::ofstream::out)
{
    
    if(!file.is_open())
    {
        std::cout << "Error opening file";
        
    }
    
}



void FileLogger::writeToFile(std::string const &data)
{
    
    
    file << data;
    //file.close();
    
}

void FileLogger::closeFile()
{
    file.close();
}
 
