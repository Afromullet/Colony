//
//  Material.cpp
//  Colony
//
//  Created by Sean on 3/31/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Material.hpp"

#include <iostream>
Material::Material()
{
    
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
    
    
    /*
    enMaterialEffect effect;
    AttackType attackType;
    float startForce;
    float endForce;
    float size;
    float ratio; //The ratio between start and end force..gives us an idea of how much force has been absorbed, and how severe the wound will be. The higher the number, the more damage
    WoundSeverity woundSeverity; //The kind of wound this attack causes
     */
}

void Material::PerformMaterialCalculations(float force,float size, AttackForceType enAttackForceType,AttackType attackType)
{
    SetupForce(force, size, enAttackForceType, attackType);
    CalculateForcePenentration();
    DetermineWoundSeverity();
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
    
    std::cout << "\nSize " << effect.size;
    
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
    std::cout << "\n Material Strength " << materialStrength;
    std::cout << "\n Size " << effect.size;
    std::cout << "\n Density " << density;
    std::cout << "\n Stress " << stress;
    std::cout << "\n Numerator calculation " << (materialStrength * (density * 0.420));
    std::cout << "\n Denominator " << effect.startForce;

    effect.endForce = (materialStrength * (density )) / (effect.startForce ); //0.773 is an arbitrary value
    effect.ratio = effect.startForce / effect.endForce;
    
    std::cout << "\n StartForce, endforce " << effect.startForce << "," << effect.endForce;
    std::cout << "\n Ratio " << effect. ratio;
    
    
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
    compDefStrength = compression;
    impactDefStrength = impact;
    tensileDefStrength = tensile;
    torsionDefStrenght = torsion;
    shearDefStrength = shear;
}


void Material::setFractureStrength(float compression,float impact,float tensile,float torsion,float shear)
{
    compFractStrength = compression;
    impactFractStrength = impact;
    tensileFractStrength = tensile;
    torsionFractStrenght = torsion;
    shearFractStrength = shear;
}

void Material::setDensity(float _density)
{
    density = _density;
}

void Material::setMaterialName(std::string name)
{
    materialName = name;
}

void Material::setAppliedForceEffects(AppliedForceEffect effect)
{
    effectsOnMaterial.push_back(effect);
}

std::string Material::getMaterialName()
{
    return materialName;
}

float Material::getDensity()
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
