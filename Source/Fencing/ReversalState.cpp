// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "ReversalState.h"

UAnimationAsset *ReversalState::AnimationAsset = NULL;


void ReversalState::Enter()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Reversal");
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void ReversalState::Update()
{
	bool Active = false;
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		if ((*it)->NotifyName.ToString() == "VegetaAnimEnd")
		{
			if (Reversal)
			{
				//DANO??? -- Dei dano(? - Acho que faz sentido reversal dar dano) e mudei de estado
				// Particulas e som
				VegetaState *NewState;
				NewState = StateFactory::CreateAttackIdle(Vegeta);
				Vegeta->GetMesh()->Stop();
				NewState->Enter();
				Vegeta->SetState(NewState);
				return;
			}
			else
			{
				VegetaState *NewState;
				NewState = StateFactory::CreateDefendIdle(Vegeta);
				Vegeta->GetMesh()->Stop();
				NewState->Enter();
				Vegeta->SetState(NewState);
				return;
			}

		}
		if ((*it)->NotifyName.ToString() == "VegetaActiveFrames")
		{
			Active = true;
		}
	}
	if (Vegeta->Enemy != NULL && !(Reversal))
	{
		bool EnemyActive = Vegeta->Enemy->IsStateActive();
		if (Vegeta->Enemy->GetState() == EVegetaState::Punch)
		{
			if (Active && EnemyActive)
			{
				Reversal = true;
				return;
			}
			else if (!(Active) && EnemyActive)
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
void ReversalState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
bool ReversalState::IsActive()
{
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		if ((*it)->NotifyName.ToString() == "VegetaActiveFrames")
		{
			return true;
		}
	}
	return false;
}
ReversalState::~ReversalState()
{
}
