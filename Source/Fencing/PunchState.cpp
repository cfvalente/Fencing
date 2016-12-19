// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "PunchState.h"

UAnimationAsset *PunchState::AnimationAsset = NULL;


void PunchState::Enter()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Punch");
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void PunchState::Update()
{
	bool Active = false;
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		if ((*it)->NotifyName.ToString() == "VegetaAnimEnd")
		{
			VegetaState *NewState;
			NewState = StateFactory::CreateAttackIdle(Vegeta);
			Vegeta->GetMesh()->Stop();
			NewState->Enter();
			Vegeta->SetState(NewState);
			return;
		}
		if ((*it)->NotifyName.ToString() == "VegetaActiveFrames")
		{
			Active = true;
		}
	}
	if (Vegeta->Enemy != NULL && !(Punch) && Active)
	{
		bool EnemyActive = Vegeta->Enemy->IsStateActive();
		switch (Vegeta->Enemy->GetState())
		{
			case EVegetaState::Reversal:
				if (EnemyActive)
				{
					//DANO??? -- Tomei dano???
					VegetaState *NewState;
					NewState = StateFactory::CreateDefendIdle(Vegeta);
					Vegeta->GetMesh()->Stop();
					NewState->Enter();
					Vegeta->SetState(NewState);
					return;
				}
				else if (!(EnemyActive))
				{
					// Particulas e som
					Punch = true;
					return;
				}
				break;
			case EVegetaState::Block:
				Punch = true;
				if (EnemyActive)
				{
					//Som e Particulas de block
				}
				else
				{
					//Som e particulas normais
				}
				break;
			case EVegetaState::DefendIdle:
				Punch = true;
				//Som e particulas
				break;
			case EVegetaState::Recovery:
				/* Permitir combos? */
				Punch = true;
				// Som e particulas
				break;
		}
	}
}
void PunchState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
bool PunchState::IsActive()
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
PunchState::~PunchState()
{
}
