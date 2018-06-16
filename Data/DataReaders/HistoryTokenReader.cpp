//
//  HistoryTokenReader.cpp
//  Colony
//
//  Created by Sean on 6/10/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "HistoryTokenReader.hpp"
#include "DataStorage.hpp"
#include "GenericReaders.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>      // std::stringstream
#include <boost/regex.hpp>


RewriteRules startRewriteRules[MAX_REWRITE_RULES];
int numOfStartRewriteRules = 0;


RewriteRules arGrammarRewriteRules[MAX_REWRITE_RULES];
int numOfGrammarRewriteRules = 0;

//Reads the initial valid tokens. There are the tokens before any rewrite is perform, the starting set
void ReadInitialHistoryTokens()
{
    
    
    std::string validHistoryTokens (read_from_file("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/HistoryData/InitialHistoryTokens.txt"));
    
    std::stringstream ss(validHistoryTokens);
    std::string to;

    std::string line;
    while(std::getline(ss, line))
    {
        if( line != "")
        {
            initialHistoryTokens.push_back(line);
        }
        
    }
}

void ReadFirstRewriteRules()
{
    std::string validHistoryTokens (read_from_file("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/HistoryData/BasicRewriteRules.txt"));
    
    std::stringstream ss(validHistoryTokens);
    std::string to;
    
    std::string line,startRule,endRule;
   
    
    while(std::getline(ss, line))
    {
        if( line != "")
        {
            SplitRulesOnSeperator(line);
            
        }
        
    }
    
    
    std::string validGrammarTokens (read_from_file("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/LanguageData/EnglishGrammarRules.txt"));
    
    std::stringstream ss2(validGrammarTokens);
    std::string to2;
    
    
    
    
    while(std::getline(ss2, line))
    {
        if( line != "")
        {
            SplitGrammarRulesOnSeperator(line);
            
        }
        
    }
    
    
    

    
}

std::size_t FindRewriteSeperator(const std::string &str)
{
    std::size_t found = str.find(REWRITE_SEPERATOR);
    if (found!=std::string::npos)
        return found;
    

}

//Splits the string on -> . For example [A]->[B][C] is split into [A] and [B][C]. [A] will be in RewriteRules.initialRule, [B][C] will be in
//RewriteRules.rewrittenRule
void SplitRulesOnSeperator(const std::string &str)
{
    RewriteRules rules;
    std::size_t found = FindRewriteSeperator(str);
    std::cout << "\n Found at " << found;
    
    for(int i=0; i < found;i++)
    {
        rules.initialRule += str.at(i);
        
    }
    
    for(int i = found+REWRITE_SEPERATOR_SIZE; i < str.size(); i++)
    {
        rules.rewrittenRule += str.at(i);
    }
    
    
    
    
    
    std::string s = "";
    

    for(int i = 0; i < rules.rewrittenRule.size(); i++)
    {
       
        if(rules.rewrittenRule.at(i) == L_SB_TOKEN)
        {
            s = "[";
        }
        else if(rules.rewrittenRule.at(i) != R_SB_TOKEN)
        {
            s += rules.rewrittenRule.at(i);
        }
        else if(rules.rewrittenRule.at(i) == R_SB_TOKEN)
        {
            s+= "]";
            rules.vecRewrittenRule.push_back(s);
           
        }
        //std::cout << " " << rules.rewrittenRule.at(i);
    }
    
 
    startRewriteRules[numOfStartRewriteRules] = rules;
    numOfStartRewriteRules++;
    
    
}


//Needlessly duplicated, could just pass a reference to the array in SplitRulesOnSeperator, but I don't want to mess with it now, just working on a proof of concept
void SplitGrammarRulesOnSeperator(const std::string &str)
{
    RewriteRules rules;
    std::size_t found = FindRewriteSeperator(str);
    std::cout << "\n Found at " << found;
    
    for(int i=0; i < found;i++)
    {
        rules.initialRule += str.at(i);
        
    }
    
    for(int i = found+REWRITE_SEPERATOR_SIZE; i < str.size(); i++)
    {
        rules.rewrittenRule += str.at(i);
    }
    
    
    
    
    
    std::string s = "";
    
    
    for(int i = 0; i < rules.rewrittenRule.size(); i++)
    {
        
        if(rules.rewrittenRule.at(i) == L_SB_TOKEN)
        {
            s = "[";
        }
        else if(rules.rewrittenRule.at(i) != R_SB_TOKEN)
        {
            s += rules.rewrittenRule.at(i);
        }
        else if(rules.rewrittenRule.at(i) == R_SB_TOKEN)
        {
            s+= "]";
            rules.vecRewrittenRule.push_back(s);
            
        }
        //std::cout << " " << rules.rewrittenRule.at(i);
    }
    
    
    arGrammarRewriteRules[numOfGrammarRewriteRules] = rules;
    numOfGrammarRewriteRules++;
    
    
}


//Should probably be in a better place since it could be used outside history. Then again, I probably won't use it for more than history gen
void ReadGrammarRules()
{
    
    
}

