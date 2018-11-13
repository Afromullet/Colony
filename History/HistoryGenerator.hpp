//
//  HistoryGenerator.hpp
//  Colony
//
//  Created by Sean on 6/16/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef HistoryGenerator_hpp
#define HistoryGenerator_hpp

#include <stdio.h>
#include "HistoryTokenReader.hpp"
#include "DataStorage.hpp"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>
#include "Constants.hpp"

RewriteRules SelectStartingHistoryRule();

void ProcessRewrittenRule(RewriteRules &rules);
std::vector<int> getRewriteRulesIndices(std::string str);


#endif /* HistoryGenerator_hpp */
