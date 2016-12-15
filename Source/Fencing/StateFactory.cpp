// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "StateFactory.h"

void StateFactory::SetIdleAnimation(UAnimationAsset *Animation)
{
	IdleState::AnimationAsset = Animation;
}
class IdleState* StateFactory::CreateIdle(class AVegeta *Vegeta)
{
	return new IdleState(Vegeta);
}

void StateFactory::SetAttackIdleAnimation(UAnimationAsset *Animation)
{
	IdleState::AnimationAsset = Animation;
}
class AttackIdleState* StateFactory::CreateAttackIdle(class AVegeta *Vegeta)
{
	return new AttackIdleState(Vegeta);
}

void StateFactory::SetPunchAnimation(UAnimationAsset *Animation)
{
	IdleState::AnimationAsset = Animation;
}
class PunchState* StateFactory::CreatePunch(class AVegeta *Vegeta)
{
	return new PunchState(Vegeta);
}
