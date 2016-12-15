// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
#include "IdleState.h"
#include "PunchState.h"
#include "AttackIdleState.h"
/**
 * 
 */
class FENCING_API StateFactory
{
public:
	static void SetIdleAnimation(UAnimationAsset *Animation);
	static class IdleState *CreateIdle(class AVegeta *Vegeta);

	static void SetAttackIdleAnimation(UAnimationAsset *Animation);
	static class AttackIdleState *CreateAttackIdle(class AVegeta *Vegeta);

	static void SetPunchAnimation(UAnimationAsset *Animation);
	static class PunchState *CreatePunch(class AVegeta *Vegeta);
};
