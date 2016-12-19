// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "AttackIdleState.h"

UAnimationAsset *AttackIdleState::AnimationAsset = NULL;


void AttackIdleState::Enter()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "AttackIdle");
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void AttackIdleState::HandleButton1()
{
	VegetaState *NewState;
	NewState = StateFactory::CreatePunch(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
	return;
}
void AttackIdleState::HandleButton2()
{
	VegetaState *NewState;
	NewState = StateFactory::CreateFeint(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
	return;
}
void AttackIdleState::Update()
{
}
void AttackIdleState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
AttackIdleState::~AttackIdleState()
{
}
