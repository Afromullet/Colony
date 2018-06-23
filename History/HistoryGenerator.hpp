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


RewriteRules SelectStartingHistoryRule();

void ProcessRewrittenRule(RewriteRules &rules);
std::vector<int> getRewriteRulesIndices(std::string str);


#endif /* HistoryGenerator_hpp */
