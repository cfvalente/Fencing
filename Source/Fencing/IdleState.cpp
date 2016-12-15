// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "IdleState.h"


UAnimationAsset *IdleState::AnimationAsset = NULL;

void IdleState::Enter()
{
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
class VegetaState * IdleState::HandleButton1()
{
	/* Exemplo do que fazer */

	VegetaState *NewState;
	NewState = StateFactory::CreateIdle(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	return NewState;
}
void IdleState::Update()
{
	// Detecta o Notify State
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->ActiveAnimNotifyState.CreateIterator(); it; ++it )
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, *it->NotifyName.ToString());
	}
	// Detecta o Notify lancado nesse tick
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, (*it)->Notify->GetName());
	}

}
void IdleState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
IdleState::~IdleState()
{

}