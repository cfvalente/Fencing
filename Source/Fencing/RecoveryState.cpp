// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "RecoveryState.h"

UAnimationAsset *RecoveryState::AnimationAsset = NULL;


void RecoveryState::Enter()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Recovery");
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void RecoveryState::Update()
{
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		if ((*it)->NotifyName.ToString() == "VegetaAnimEnd")
		{
			VegetaState *NewState;
			NewState = StateFactory::CreateDefendIdle(Vegeta);
			Vegeta->GetMesh()->Stop();
			NewState->Enter();
			Vegeta->SetState(NewState);
			return;
		}
	}
	if (Vegeta->Enemy != NULL)
	{
		bool EnemyActive = Vegeta->Enemy->IsStateActive();
		if (Vegeta->Enemy->GetState() == EVegetaState::Punch)
		{
			if (EnemyActive)
			{
				//DANO??? -- Tomei dano - permitir combos?
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
void RecoveryState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
RecoveryState::~RecoveryState()
{
}
