// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "PunchState.h"

UAnimationAsset *PunchState::AnimationAsset = NULL;


void PunchState::Enter()
{
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void PunchState::HandleButton1()
{
	VegetaState *NewState;
	NewState = StateFactory::CreateIdle(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
}
void PunchState::Update()
{
	// Detecta os Notify existentes(?)
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, (*it)->NotifyName.ToString());
	}

}
void PunchState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
PunchState::~PunchState()
{
}
