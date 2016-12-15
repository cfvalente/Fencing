// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "AttackIdleState.h"

UAnimationAsset *AttackIdleState::AnimationAsset = NULL;


void AttackIdleState::Enter()
{
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void AttackIdleState::HandleButton1()
{
	VegetaState *NewState;
	NewState = StateFactory::CreatePunch(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
}
void AttackIdleState::HandleButton2()
{
	VegetaState *NewState;
	NewState = StateFactory::CreateIdle(Vegeta); // Deveria ser Feint
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
}
void AttackIdleState::Update()
{
	// Detecta os Notify existentes(?)
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, (*it)->NotifyName.ToString());
	}

}
void AttackIdleState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
AttackIdleState::~AttackIdleState()
{
}
