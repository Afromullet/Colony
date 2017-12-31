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

enum TileTerrainType{enGrass1,enSnow1,enSwamp1,enFloor1,enWall1,enUndefinedTerrain};

enum Behaviors
{
    SEEK=0,
    RANDOM_MOVE=1
};


enum EnItemType {enArmorType,enWeaponType};
//For equipment, to let us know what slot it fits it
enum EnumFitsBodyPart {enHead,enChest,enFeet,enLegs,enHands,enOneHanded,enTwoHanded,enUndefinedBodyPart,enArms};

//For specific body parts.
enum EnumBodyPart{enHeadBodyPart,enLeftArmBodyPart,enRightArmBodyPart,enLeftLegBodyPart,enRightLegBodyPart,enLeftFootBodyPart,enRightFootBodyPart,enChestBodyPart,enLeftHandBodyPart,enRightHandBodyPart,enUndefinedPart,enLegsBodyPart,enArmsBodyPart,enHandsBodyPart,enFeetBodyPart,enFitsOneHand,enFitsBothHands};

//Don't want to make separate classes for right and lef limbs...Maybe there's a better option than enums to distinguish between limbs. research todo

//The various types of weapons
enum EnumWeaponClass{enDagger,enShortSword,enLongSword,enGreatsword,enLongbow,enCrossbow,enMace,enHammer,enUndefinedWeaponClass};
enum EnumBonusType{enStrengthBonus,enDexterityBonus,enUndefinedBonus};

//The different armor classes
enum EnumArmorClass{enLight,enMedium,enHeavy,enBuckler,enLightShield,enHeavyShield,enUndefinedArmorClass};

void PrintEnumBodyPart(EnumBodyPart enBodyPart);

enum MoveDirection{Up,Left,Right,Down};

#endif /* EnumTypes_h */
