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