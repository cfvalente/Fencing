// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "BlockState.h"


UAnimationAsset *BlockState::AnimationAsset = NULL;

void BlockState::Enter()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Block");
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}

void BlockState::Update()
{
	bool Active = false;
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		if ((*it)->NotifyName.ToString() == "VegetaAnimEnd")
		{
			if (Block)
			{
				//DANO -- Tomei chip damage e mudei de estado
				VegetaState *NewState;
				NewState = StateFactory::CreateDefendIdle(Vegeta);
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
	if (Vegeta->Enemy != NULL && !(Block))
	{
		bool EnemyActive = Vegeta->Enemy->IsStateActive();
		if (Vegeta->Enemy->GetState() == EVegetaState::Punch)
		{
			if (Active && EnemyActive)
			{
				Block = true;
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
void BlockState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
BlockState::~BlockState()
{
}