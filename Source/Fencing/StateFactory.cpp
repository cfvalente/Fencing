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
	AttackIdleState::AnimationAsset = Animation;
}
class AttackIdleState* StateFactory::CreateAttackIdle(class AVegeta *Vegeta)
{
	return new AttackIdleState(Vegeta);
}

void StateFactory::SetDefendIdleAnimation(UAnimationAsset *Animation)
{
	DefendIdleState::AnimationAsset = Animation;
}
class DefendIdleState* StateFactory::CreateDefendIdle(class AVegeta *Vegeta)
{
	return new DefendIdleState(Vegeta);
}

void StateFactory::SetPunchAnimation(UAnimationAsset *Animation)
{
	PunchState::AnimationAsset = Animation;
}
class PunchState* StateFactory::CreatePunch(class AVegeta *Vegeta)
{
	return new PunchState(Vegeta);
}

void StateFactory::SetFeintAnimation(UAnimationAsset *Animation)
{
	FeintState::AnimationAsset = Animation;
}
class FeintState* StateFactory::CreateFeint(class AVegeta *Vegeta)
{
	return new FeintState(Vegeta);
}
