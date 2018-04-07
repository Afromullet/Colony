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

/*
 The SetupXXXForce function populates the materialEffects vector, which contains an effect type and
 everything needed to calculate the results of that effect
 
 */
 void Material::SetupForce(float force,float size, AttackForceType enAttackForceType)
{
    
    if(enAttackForceType == enCompression)
    {
        SetupCompressionForce(force, size);
    }
    else if(enAttackForceType == enImpact)
    {
        SetupImpactForce(force, size);
    }
    else if(enAttackForceType == enTensile)
    {
        SetupTensileForce(force, size);
    }
    else if(enAttackForceType == enTorsion)
    {
        SetupTorsionForce(force, size);
    }
    else if(enAttackForceType == enShear)
    {
        SetupShearForce(force, size);
    }
}


void Material::SetupImpactForce(float force,float size)
{
    int stress = force / size;
    AppliedMaterialEffect effect;
    effect.size = size;
    effect.force = force;
    
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

void Material::SetupShearForce(float force,float size)
{
    int stress = force / size;
    AppliedMaterialEffect effect;
    effect.size = size;
    effect.force = force;
    
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

void Material::SetupCompressionForce(float force,float size)
{
    
    
}

void Material::SetupTensileForce(float force,float size)
{
    
}

void Material::SetupTorsionForce(float force,float size)
{
    
}

/*Changes the state of materialEffect

 Whatever force is left for a particular effect determines how much force is applied beneath the material. If a spear were used, and there is no force left, then there is no damage left to be done. If there's still force left, then the damage can be applied to whatever is beneath. This represents material force absorbtion
 
 
 
 */
//Calculates how much force is absorbed by the armor, and how much is passed underneath it
void Material::CalculateForcePenentration(AppliedMaterialEffect &effect)
{
    
    float strength;
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

/*Determines how much force is absorbed by the material. 
 Divides the strength * density * some factor and divides it by the force
 
 */
void Material::ApplyForcePenentration(AppliedMaterialEffect &effect,float materialStrength)
{
    float stress = effect.force / effect.size;
    effect.force = (materialStrength * (density * 0.420)) / effect.force; //0.773 is an arbitrary value
    
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

std::string Material::getMaterialName()
{
    return materialName;
}

float Material::getDensity()
{
    return density;
}

const std::vector<AppliedMaterialEffect>& Material::getAppliedMaterialEffects()
{
    return effectsOnMaterial;
}
