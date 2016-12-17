// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
#include "IdleState.h"
#include "PunchState.h"
#include "AttackIdleState.h"
#include "DefendIdleState.h"
#include "FeintState.h"
#include "ReversalState.h"
#include "BlockState.h"
#include "RecoveryState.h"

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

	static void SetFeintAnimation(UAnimationAsset *Animation);
	static class FeintState *CreateFeint(class AVegeta *Vegeta);

	static void SetReversalAnimation(UAnimationAsset *Animation);
	static class ReversalState *CreateReversal(class AVegeta *Vegeta);

	static void SetBlockAnimation(UAnimationAsset *Animation);
	static class BlockState *CreateBlock(class AVegeta *Vegeta);

	static void SetDefendIdleAnimation(UAnimationAsset *Animation);
	static class DefendIdleState *CreateDefendIdle(class AVegeta *Vegeta);

	static void SetRecoveryAnimation(UAnimationAsset *Animation);
	static class RecoveryState *CreateRecovery(class AVegeta *Vegeta);
};
