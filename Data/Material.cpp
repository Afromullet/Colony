//
//  Material.cpp
//  Colony
//
//  Created by Sean on 3/31/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Material.hpp"


bool Material::operator==(const Material &other) const
{
    
    
    if(compDefStrength == other.compDefStrength && impactDefStrength == other.impactDefStrength && tensileDefStrength == other.tensileDefStrength && torsionDefStrenght == other.torsionDefStrenght && shearDefStrength == other.shearDefStrength)
    {
        
        //Nested if statements make it easier to read
        if(compFractStrength == other.compFractStrength && impactFractStrength == other.impactFractStrength && tensileFractStrength == other.tensileFractStrength && torsionFractStrenght == other.torsionFractStrenght && shearFractStrength == other.shearFractStrength)
            
            
            if(plasticity == other.plasticity && density == other.density && materialName == other.materialName)
                    return true;
    }
    
    
    return false;
    
}

bool Material::operator!=(const Material &other) const
{
    return !(*this == other);
}


void Material::operator=(const Material &other)
{
    compDefStrength = other.compDefStrength;
    impactDefStrength = other.impactDefStrength;
    tensileDefStrength = other.tensileDefStrength;
    torsionDefStrenght = other.torsionDefStrenght;
    shearDefStrength = other.shearDefStrength;
    
    plasticity = other.plasticity;
    density = other.density;
    
    compFractStrength = other.compFractStrength;
    impactFractStrength = other.impactFractStrength;
    tensileFractStrength = other.tensileFractStrength;
    torsionFractStrenght = other.torsionFractStrenght;
    shearFractStrength = other.shearFractStrength;
    
    materialName = other.materialName;
}


#include <iostream>
Material::Material()
{
    compDefStrength= DEFAULT_MATERIAL_VALUE ;
    impactDefStrength= DEFAULT_MATERIAL_VALUE ;
    tensileDefStrength= DEFAULT_MATERIAL_VALUE ;
    torsionDefStrenght= DEFAULT_MATERIAL_VALUE ;
    shearDefStrength= DEFAULT_MATERIAL_VALUE ;
    
    density = DEFAULT_MATERIAL_VALUE;
    plasticity = DEFAULT_MATERIAL_VALUE;

    compFractStrength= DEFAULT_MATERIAL_VALUE ;
    impactFractStrength= DEFAULT_MATERIAL_VALUE ;
    tensileFractStrength= DEFAULT_MATERIAL_VALUE ;
    torsionFractStrenght= DEFAULT_MATERIAL_VALUE ;
    shearFractStrength= DEFAULT_MATERIAL_VALUE ;
    
    materialName = ERROR_STRING_INPUT;
    
    
}

Material::Material(const Material &other)
{
    compDefStrength = other.compDefStrength;
    impactDefStrength = other.impactDefStrength;
    tensileDefStrength = other.tensileDefStrength;
    torsionDefStrenght = other.torsionDefStrenght;
    shearDefStrength = other.shearDefStrength;
    
    density = other.density;
    plasticity = other.plasticity;
    
    compFractStrength = other.compFractStrength;
    impactFractStrength = other.impactFractStrength;
    tensileFractStrength  = other.tensileFractStrength;
    torsionFractStrenght = other.torsionFractStrenght;
    shearFractStrength = other.shearFractStrength;
    
    materialName = other.materialName;
    
}

std::ostream& operator<<(std::ostream& os, const Material& mat)
{
    os <<
    "\n Compact Deformation Strength: " << mat.compDefStrength
    << "\n Impact Deformation Strength: " << mat.impactDefStrength
    << "\n Tension Deformation Strength: " << mat.tensileDefStrength
    << "\n Torsion Deformation Strength: " << mat.torsionDefStrenght
    << "\n Shear Deformation Strength: " << mat.shearDefStrength
    <<"\n Compact Deformation Strength: " << mat.compFractStrength
    << "\n Impact Deformation Strength: " << mat.impactFractStrength
    << "\n Tension Deformation Strength: " << mat.tensileFractStrength
    << "\n Torsion Deformation Strength: " << mat.torsionFractStrenght
    << "\n Shear Deformation Strength: " << mat.shearFractStrength;

    
    
    return os;

}

std::ostream& operator<<(std::ostream& os, const AppliedForceEffect& mat)
{
    
    os <<
    "\n MaterialEffect, attackType,startFoce,endForce,size,ratio,woundSeverity\n"
    << mat.effect << "," << mat.startForce << "," << mat.endForce << "," << mat.size << "," << mat.ratio << "," << mat.woundSeverity;
    
    

    
    return os;
}

//Although material effects is an array, currently only one effect if applied per attack
//Wound severity is calculated as part of the force calculation
bool Material::PerformMaterialCalculations(float force,float size, AttackForceType enAttackForceType,AttackType attackType)
{
    
    if(force < 0 || size < 0)
    {
        effectsOnMaterial.clear();
        return false;
    }
    
    
    effectsOnMaterial.clear();
    SetupForce(force, size, enAttackForceType, attackType); //Calculates what kind of deformation the material suffers from
    CalculateForcePenentration(); //Calculates how much force the material absorbs
    DetermineWoundSeverity();
    return true;
}

/*
 The SetupXXXForce function populates the materialEffects vector, which contains an effect type and
 everything needed to calculate the results of that effect
 
 */
 void Material::SetupForce(float force,float size, AttackForceType enAttackForceType,AttackType attackType)
{
    
    if(enAttackForceType == enCompression)
    {
        SetupCompressionForce(force, size,attackType);
    }
    else if(enAttackForceType == enImpact)
    {
        SetupImpactForce(force, size,attackType);
    }
    else if(enAttackForceType == enTensile)
    {
        SetupTensileForce(force, size,attackType);
    }
    else if(enAttackForceType == enTorsion)
    {
        SetupTorsionForce(force, size,attackType);
    }
    else if(enAttackForceType == enShear)
    {
        SetupShearForce(force, size,attackType);
    }
}


void Material::SetupImpactForce(float force,float size,AttackType attackType)
{
    int stress = force / size;
    AppliedForceEffect effect;
    effect.size = size;
    effect.startForce = force;
    effect.attackType = attackType;
    

    
    if(stress > impactDefStrength)
    {
        
        if(stress > impactFractStrength)
        {
            effect.effect = enImpactFracEffect;
        }
        else
        {
            effect.effect = enImpactDefEffect;
        }
        
    }
    else
    {
        effect.effect = enNoEffect;
    }
    
    effectsOnMaterial.push_back(effect);
  
}

void Material::SetupShearForce(float force,float size,AttackType attackType)
{
    int stress = force / size;
    AppliedForceEffect effect;
    effect.size = size;
    effect.startForce = force;
    effect.attackType = attackType;
    
    if(stress > shearDefStrength)
    {
        if(stress > shearFractStrength)
        {
            effect.effect = enShearFracEffect;
        }
        else
        {
            effect.effect = enShearDefEffect;
        }
        
        
        
    }
    else
    {
        effect.effect = enNoEffect;
    }
    
    effectsOnMaterial.push_back(effect);
    
    
    
}

void Material::SetupCompressionForce(float force,float size,AttackType attackType)
{
    
    
}

void Material::SetupTensileForce(float force,float size,AttackType attackType)
{
    
}

void Material::SetupTorsionForce(float force,float size,AttackType attackType)
{
    
}

/*Changes the state of materialEffect

 Whatever force is left for a particular effect determines how much force is applied beneath the material. If a spear were used, and there is no force left, then there is no damage left to be done. If there's still force left, then the damage can be applied to whatever is beneath. This represents material force absorbtion
 
 
 
 */
//Calculates how much force is absorbed by the armor, and how much is passed underneath it
void Material::CalculateForcePenentration(AppliedForceEffect &effect)
{
    
    if(effect.effect == enCompDefEffect)
        ApplyForcePenentration(effect,compDefStrength);
    else if(effect.effect == enImpactDefEffect)
        ApplyForcePenentration(effect,impactDefStrength);
    else if(effect.effect == enTensileDefEffect)
        ApplyForcePenentration(effect,tensileDefStrength);
    else if(effect.effect == enTorsionDefEffect)
        ApplyForcePenentration(effect,torsionDefStrenght);
    else if(effect.effect == enShearDefEffect)
        ApplyForcePenentration(effect,shearDefStrength);
    else if(effect.effect == enCompFracEffect)
        ApplyForcePenentration(effect,compFractStrength);
    else if(effect.effect == enImpactFracEffect)
        ApplyForcePenentration(effect,impactFractStrength);
    else if(effect.effect == enTensileFracEffect)
        ApplyForcePenentration(effect,tensileFractStrength);
    else if(effect.effect == enTorsionFracEffect)
        ApplyForcePenentration(effect,torsionFractStrenght);
    else if(effect.effect == enShearFracEffect)
        ApplyForcePenentration(effect,shearFractStrength);
   
  
}

void Material::CalculateForcePenentration()
{
    
    AppliedForceEffect effect;
    for(int i = 0; i < effectsOnMaterial.size(); i++)
    {
        AppliedForceEffect &effect = effectsOnMaterial.at(i);
        
        if(effect.effect == enCompDefEffect)
            ApplyForcePenentration(effect,compDefStrength);
        else if(effect.effect == enImpactDefEffect)
            ApplyForcePenentration(effect,impactDefStrength);
        else if(effect.effect == enTensileDefEffect)
            ApplyForcePenentration(effect,tensileDefStrength);
        else if(effect.effect == enTorsionDefEffect)
            ApplyForcePenentration(effect,torsionDefStrenght);
        else if(effect.effect == enShearDefEffect)
            ApplyForcePenentration(effect,shearDefStrength);
        else if(effect.effect == enCompFracEffect)
            ApplyForcePenentration(effect,compFractStrength);
        else if(effect.effect == enImpactFracEffect)
            ApplyForcePenentration(effect,impactFractStrength);
        else if(effect.effect == enTensileFracEffect)
            ApplyForcePenentration(effect,tensileFractStrength);
        else if(effect.effect == enTorsionFracEffect)
            ApplyForcePenentration(effect,torsionFractStrenght);
        else if(effect.effect == enShearFracEffect)
            ApplyForcePenentration(effect,shearFractStrength);
        
    }
}
/*Determines how much force is absorbed by the material.
 Divides the strength * density * some factor and divides it by the force
 
 */
void Material::ApplyForcePenentration(AppliedForceEffect &effect,float materialStrength)
{
    float stress = effect.startForce;// / effect.size;



    
    effect.endForce = (materialStrength * density)  / effect.startForce ; //0.773 is an arbitrary value
    effect.ratio = effect.endForce / effect.startForce;
    

  
    
    //If it is just a deformation effect, further reduce the damage, as the armor wasn't penetrated
    if(effect.effect == enShearDefEffect || effect.effect == enCompDefEffect || effect.effect == enTorsionDefEffect || effect.effect == enTensileDefEffect || effect.effect == enImpactDefEffect)
    {
        effect.ratio *= 0.5;
    }
    
}

void Material::DetermineWoundSeverity()
{
    
    for(int i=0; i < effectsOnMaterial.size(); i++)
    {
        
      
        if(effectsOnMaterial.at(i).endForce <= MINOR_DAMAGE_LIMIT)
        {
            effectsOnMaterial.at(i).woundSeverity = enMinorWound;
        }
        else if(effectsOnMaterial.at(i).endForce >= MEDIUM_DAMAGE_LIMIT && effectsOnMaterial.at(i).endForce < MAJOR_DAMAGE_LIMIT)
        {
            effectsOnMaterial.at(i).woundSeverity = enModerateWound;
        }
        else if(effectsOnMaterial.at(i).endForce >= MAJOR_DAMAGE_LIMIT)
        {
            effectsOnMaterial.at(i).woundSeverity = enMajorWound;
        }
    }
}

bool Material::isValidMaterial()
{
    return (compDefStrength < 0) || (impactDefStrength < 0) || (tensileDefStrength < 0) || (torsionDefStrenght < 0)|| (shearDefStrength < 0)|| (compFractStrength < 0)|| (impactFractStrength < 0)|| (tensileFractStrength < 0)|| (torsionFractStrenght < 0)|| (shearFractStrength < 0);
}


void Material::setDeformationStrenghts(float compression,float impact,float tensile,float torsion,float shear)
{
    
    compDefStrength = IS_NUM_GT_0(compression);
    impactDefStrength = IS_NUM_GT_0(impact);
    tensileDefStrength = IS_NUM_GT_0(tensile);
    torsionDefStrenght = IS_NUM_GT_0(torsion);
    shearDefStrength = IS_NUM_GT_0(shear);
}


void Material::setFractureStrength(float compression,float impact,float tensile,float torsion,float shear)
{
    compFractStrength = IS_NUM_GT_0(compression);
    impactFractStrength = IS_NUM_GT_0(impact);
    tensileFractStrength = IS_NUM_GT_0(tensile);
    torsionFractStrenght = IS_NUM_GT_0(torsion);
    shearFractStrength = IS_NUM_GT_0(shear);
}

void Material::setDensity(float _density)
{
    density = IS_NUM_GT_0(_density);
}

void Material::setMaterialName(std::string name)
{
    materialName = name;
}

void Material::setAppliedForceEffects(AppliedForceEffect effect)
{
    effectsOnMaterial.push_back(effect);
}

std::string Material::getMaterialName() const
{
    return materialName;
}

float Material::getDensity() const
{
    return density;
}

std::vector<AppliedForceEffect>& Material::getAppliedForceEffects()
{
    return effectsOnMaterial;
}

void Material::clearAppliedMaterialEffects()
{
    effectsOnMaterial.clear();
}
