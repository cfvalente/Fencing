// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
#include "IdleState.h"
/**
 * 
 */
class FENCING_API StateFactory
{
public:
	static void SetIdleAnimation(UAnimationAsset *Animation);
	static class IdleState *CreateIdle(class AVegeta *Vegeta);
};
