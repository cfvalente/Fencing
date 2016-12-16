// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "DefendIdleState.h"

UAnimationAsset *DefendIdleState::AnimationAsset = NULL;


void DefendIdleState::Enter()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "DefendIdle");
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void DefendIdleState::HandleButton1()
{
	/*
	VegetaState *NewState;
	NewState = StateFactory::CreatePunch(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
	*/
}
void DefendIdleState::HandleButton2()
{
	/*
	VegetaState *NewState;
	NewState = StateFactory::CreateFeint(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
	*/
}
void DefendIdleState::Update()
{
}
void DefendIdleState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
DefendIdleState::~DefendIdleState()
{
}
