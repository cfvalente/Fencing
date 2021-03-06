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
	VegetaState *NewState;
	NewState = StateFactory::CreateBlock(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
	return;
}
void DefendIdleState::HandleButton2()
{
	VegetaState *NewState;
	NewState = StateFactory::CreateReversal(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
	return;
}
void DefendIdleState::Update()
{
	if (Vegeta->Enemy != NULL)
	{
		bool EnemyActive = Vegeta->Enemy->IsStateActive();
		if (Vegeta->Enemy->GetState() == EVegetaState::Punch)
		{
			if (EnemyActive)
			{
				//DANO -- Tomei dano
				VegetaState *NewState;
				NewState = StateFactory::CreateRecovery(Vegeta);
				Vegeta->GetMesh()->Stop();
				NewState->Enter();
				Vegeta->SetState(NewState);
				return;
			}
		}
	}
}
void DefendIdleState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
DefendIdleState::~DefendIdleState()
{
}
