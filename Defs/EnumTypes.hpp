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



enum EnItemType {enArmorType,enWeaponType,enArmor,enWeapon};
//For equipment, to let us know what slot it fits it
//enum EnumFitsBodyPart {enHead,enChest,enFeet,enLegs,enHands,enOneHanded,enTwoHanded,enUndefinedBodyPart,enArms};


//Don't want to make separate classes for right and lef limbs...Maybe there's a better option than enums to distinguish between limbs. research todo










enum MoveDirection{Up,Left,Right,Down};

#endif /* EnumTypes_h */
