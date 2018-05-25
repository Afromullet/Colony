//
//  EnumTypes.hpp
//  Colony
//
//  Created by Sean on 7/29/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#ifndef EnumTypes_h
#define EnumTypes_h

/*Some enumerated types used throughout the program. Not too sure if I should handle the parts that use enums the way I do. I rather use enums than class types, since not everything will be polymorphic or object oriented. For example, there's no need to have a different class for spears and swords. They just have to be broken down into some general properties and identified by their enum
 
 */


enum enBiomes{enDesertBiome,enForestBiome,enPlainsBiome,enSwampBiome,enWaterBiome,enBeachBiome,enJungleBiome,enSnowBiome};

enum TileTerrainType{enGrass1,enSnow1,enSwamp1,enFloor1,enWall1,enUndefinedTerrain,enDesert1,enSea1,enForest1,enPlain1,enMountain1};


enum AttackForceType{enCompression,enImpact,enTensile,enTorsion,enShear};
enum AttackType{enBlunt,enSlash,enPierce};

/*
 Fracture - bone Breaks
 Puctures - Piercing wounds. Severe punctures can damage organs
 Cut - Severity determines how much tissue and muscle is lost. Very severe cuts can remove limbs
 */
enum WoundType
{
    enMinorFracture,enModerateFracture,enMajorFracture, enMinorPuncture,enModeratePuncture,enMajorPuncture,enMinorCut,enModerateCut,enMajorCut,enMinorBruise,enModerateBruise,enMajorBruise,enRupture,enDismember
};



enum WoundSeverity
{
    enMinorWound,enModerateWound,enMajorWound
};

//TODO find a better place for this
struct AttackStats
{
    int damage;
    int range;
    int attackValue;
    bool isRangedAttack;
    float force; //The force applied by this attack
    float contactArea; //The size of the object used to attack. Used in stress calculation..This is the contact area
    AttackForceType enAttackForceType;
    AttackType attackType;
  
    
};







enum MoveDirection{Up,Left,Right,Down};

#endif /* EnumTypes_h */
