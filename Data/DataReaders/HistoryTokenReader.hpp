//
//  HistoryTokenReader.hpp
//  Colony
//
//  Created by Sean on 6/10/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef HistoryTokenReader_hpp
#define HistoryTokenReader_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "DataStorage.hpp"
#include "GenericReaders.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>      // std::stringstream
#include <boost/regex.hpp>


#define MAX_REWRITE_RULES 300
#define MAX_SECONDARY_RULES 10

#define REWRITE_SEPERATOR "->"
#define REWRITE_SEPERATOR_SIZE 2
#define L_SB_TOKEN '['
#define R_SB_TOKEN ']'

//Will need to implement the rule reader in a better way in the future.

struct RewriteRules
{
    std::string initialRule;
    std::string rewrittenRule;
    std::vector<std::string> vecRewrittenRule;
    //std::string secondaryRules[MAX_SECONDARY_RULES];
    //int numOfSecondaryRules = 0;
};

extern RewriteRules startRewriteRules[MAX_REWRITE_RULES];
extern int numOfStartRewriteRules;


extern RewriteRules arGrammarRewriteRules[MAX_REWRITE_RULES];
extern int numOfGrammarRewriteRules;


void ReadInitialHistoryTokens();
void ReadFirstRewriteRules();
std::size_t FindRewriteSeperator(const std::string &str);
void SplitRulesOnSeperator(const std::string &str);
void SplitGrammarRulesOnSeperator(const std::string &str);
void SplitBySqBracket(const std::string &str);
void ReadGrammarRules();


#endif /* HistoryTokenReader_hpp */
