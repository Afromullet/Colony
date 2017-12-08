//
//  EnumTypes.hpp
//  Colony
//
//  Created by Sean on 7/29/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#ifndef EnumTypes_h
#define EnumTypes_h


enum TileTerrainType{enGrass1,enSnow1,enSwamp1,enFloor1,enWall1};

enum Behaviors
{
    SEEK=0,
    RANDOM_MOVE=1
};



//For equipment, to let us know what slot it fits it
enum EnumFitsBodyPart {enHead,enChest,enFeet,enLegs,enHands,enOneHanded,enTwoHanded,enUndefinedBodyPart};

//For specific body parts.
enum EnumBodyPart{enHeadBodyPart,enLeftArmBodyPart,enRightArmBodyPart,enLeftLegBodyPart,enRightLegBodyPart,enLeftFootBodyPart,enRightFootBodyPart,enChestBodyPart,enLeftHandBodyPart,enRightHandBodyPart};

//Don't want to make separate classes for right and lef limbs...Maybe there's a better option than enums to distinguish between limbs. research todo
enum EnumArmType{enLeftArm,enRightArm};
enum EnumHandType{enLeftHand,enRightHand};



enum EnumLegType{enLeftLeg,enRightLeg};
enum EnumFootType{enLeftFoot,enRightFoot};




enum EnumArmorBonusType {enArmorBonus,enDodgeMod,enDamageRed,enMoveMod};


//The various types of weapons
enum EnumWeaponClass{enDagger,enShortSword,enLongSword,enGreatsword,enLongbow,enCrossbow,enUndefinedWeaponClass};
enum EnumBonusType{enStrengthBonus,enDexterityBonus,enUndefinedBonus};

//The different armor classes
enum EnumArmorClass{enLight,enMedium,enHeavy,enBuckler,enLightShield,enHeavyShield,enUndefinedArmorClass};

enum EnSizeCategory{enSmallCreature,enMediumCreature,enLargeCreature};

enum EnMapCreatEvents{enMovement};


void PrintEnumBodyPart(EnumBodyPart enBodyPart);

enum MoveDirection{Up,Left,Right,Down};

#endif /* EnumTypes_h */
