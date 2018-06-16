//
//  HistoryGenerator.cpp
//  Colony
//
//  Created by Sean on 6/16/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "HistoryGenerator.hpp"
#include "DataStorage.hpp"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>
#include "Constants.hpp"

/*
 1) Select initial rule
 2) For every rewrite rule for the initial rule, continue to rewrite it until they are all terminal symbols
 
 
 */

//Randomly select a starting rule based on InitialHistoryTokens, which are define in a file
RewriteRules SelectStartingHistoryRule()
{
    boost::random::mt19937 gen(std::time(0));
    boost::random::uniform_int_distribution<> dist(1, initialHistoryTokens.size());
    
   
    
    int selection = rand() & initialHistoryTokens.size()-1;
 
    
    for(int i = 0; i < numOfStartRewriteRules; i++)
    {
        
      
     
        if(startRewriteRules[i].initialRule == initialHistoryTokens.at(selection))
        {
            
            
         
            return startRewriteRules[i];
        }
    }
    
    RewriteRules invalidRule;
    
    invalidRule.initialRule = ERROR_STRING;
    invalidRule.rewrittenRule = ERROR_STRING;
    
    return invalidRule;
    
}

/*
 For every rule in rules.vecWrittenRule
    1) If there is a rewrite rule defined, rewrite it
    2)  Otherwise, add it to the finalRules vector
 
 
 
 */
void ProcessRewrittenRule(RewriteRules &rules)
{
    
    
    
   
    for(int i=0; i < rules.vecRewrittenRule.size(); i++)
    {
        getRewriteRulesIndices(rules.vecRewrittenRule.at(i));
    }
    
}

//For a particular token (str), return the indices of all rules that match it in startRewriteRules. This is so that we can choose which rule we want to use
//If this returns a vector of size 0, then we have a terminal symbol
std::vector<int> getRewriteRulesIndices(std::string &str)
{
    std::vector<int> indices;
    
    for(int i=0; i < numOfStartRewriteRules; i++)
        if(str == startRewriteRules[i].initialRule)
            indices.push_back(i);
        
    
    
    return indices;
}




