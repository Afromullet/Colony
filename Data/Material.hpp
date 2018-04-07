//
//  Material.hpp
//  Colony
//
//  Created by Sean on 3/31/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Material_hpp
#define Material_hpp

#include <stdio.h>
#include <string>
#include "EnumTypes.hpp"
#include <vector>

//Inspired by Dwarf Fortress
//Not an accurate representation of material science...
/*
 If shear strength of attacking material < strength of defending material, do nothing
 
If shear fracture strength of material > shear fracture sstrength of defending material
    Dent/Bent material, maybe cause bruising
 Else
    Cut through material. Damage tissue, cut through tissue
 
 
 if impact strngth < impact strength of defending material
    Deflect
 
 If impact strength > defending material impact strength
    Dent/Bent, cause bruises
 
 if impact fracture strenght > defending equivalent
    Dent/bent armor more, heavier bruising
    If much greater, break bones, internal damage
 
 
 
 */

/*
 
 The idea is to take the different kind of forces and for that kind of force, determine how the material is effected
 
 defSrength is resistance to deformation.
 fractStrength is resistance to fracture
 
 comp - compressive force

 Impact - sudden strikes
 
 Compressive - Pressure (Pushes) (deforms the material, i.e, turning steel into a sheet or armor into a ball)
 
 Tensile - Pulling (elongates, breaks the material into two)
 
 Torsion - Twisting
 
 Shear - Cutting
 

ductility - ability to undergo significant plastic deformation without rupture - under tensile stress
 
 malleability - ability to deform under compressive stress. more malleable, easier to change shape with compressive force
 
 

 Effects on material s according to force applied:
 
 Tension - Elongates the material, eventually tears it apart
 Compression - Squeezes the material together, decreasing its size
 Shear - A crack of Tear forms in the material
 Torsion - ???
 Impact - Applies force beneath the armor, can break through it also
 
 
 Somehow calculate plasticity for each characteristics with the force and density
 
 
stress applied = force / area
 
 
 Material can absorb force..Even if the material is cut through, there was still some force absorbed
 
 */

/*The type of force applied determines how the material deforms
Or fractures. Shear will cut through the armor, impact will shatter it, etc
 
 DefEffects are deformation Effects and FracEffects are fracture effects
 
 This lets us identify what sort of effect is being applied
 
 */
enum enMaterialEffect
{
    enCompDefEffect,
    enImpactDefEffect,
    enTensileDefEffect,
    enTorsionDefEffect,
    enShearDefEffect,
    enCompFracEffect,
    enImpactFracEffect,
    enTensileFracEffect,
    enTorsionFracEffect,
    enShearFracEffect,
    enNoEffect
};

/*The size determines how exactly the object can be damaged
A small shearing force (I.E, spear tip) would cut material differently than a sword blade, for example
 
 enMaterialEffect only identifies what kind of effect it is..AppliedMaterialEffect contains all of the
 data needed to calculate the results of an effect
 
 */
struct AppliedMaterialEffect
{
    enMaterialEffect effect;
    float force;
    float size; 
};


/*
 
 
 Impact Strength determines toughness.
 
 */
class Material
{
private:
    std::vector<AppliedMaterialEffect> effectsOnMaterial; //Stores the effects on materials so that we know how to damage the material
    
    
    //Past this point, the object starts plastic deformation (elastic limit)
    float compDefStrength;
    float impactDefStrength;
    float tensileDefStrength;
    float torsionDefStrenght;
    float shearDefStrength;
    
    
    //Past this point the object starts to break (fracture strength)
    float compFractStrength;
    float impactFractStrength;
    float tensileFractStrength;
    float torsionFractStrenght;
    float shearFractStrength;
    
    

    
    
    float plasticity; //The higher this, the harder the material to deform
    float density;
     std::string materialName;
    
    
    
public:
    Material();
    
    friend std::ostream& operator<<(std::ostream& os, const Material& mat);
    

    
    //Perofrms the calculations to determine what kind of force is applied
    void SetupForce(float force,float size, AttackForceType enAttackForceType);
    void SetupShearForce(float force,float size);
    void SetupImpactForce(float force,float size);
    void SetupCompressionForce(float force,float size);
    void SetupTensileForce(float force,float size);
    void SetupTorsionForce(float force,float size);
    
    
     //Performs the calculations for the effect of a force
    void ApplyMaterialEffects();
    
    void ApplyImpactEffect(AppliedMaterialEffect effect);
    void ApplyShearEffect(AppliedMaterialEffect effect);
    void ApplyCompressionEffect(AppliedMaterialEffect effect);
    void ApplyTensileEffect(AppliedMaterialEffect effect);
    void ApplyTorsionEffect(AppliedMaterialEffect effect);
    
    void CalculateForcePenentration(AppliedMaterialEffect &effect);
    void ApplyForcePenentration(AppliedMaterialEffect &effect,float materialStrength);
   
   
    
    
    
    
    
    
    void setDeformationStrenghts(float compression,float impact,float tensile,float torsion,float shear);
    void setFractureStrength(float compression,float impact,float tensile,float torsion,float shear);
    void setDensity(float _density);
    void setMaterialName(std::string name);
    std::string getMaterialName();
    float getDensity();
    const std::vector<AppliedMaterialEffect> &getAppliedMaterialEffects();
    
    
    
    bool isValidMaterial();
    

    
    
   
    

    

    
};

#endif /* Material_hpp */
