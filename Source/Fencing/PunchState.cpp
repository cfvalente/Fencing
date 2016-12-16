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
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		if ((*it)->NotifyName.ToString() == "VegetaAnimEnd")
		{
			VegetaState *NewState;
			NewState = StateFactory::CreateAttackIdle(Vegeta);
			Vegeta->GetMesh()->Stop();
			NewState->Enter();
			Vegeta->SetState(NewState);
		}
		if ((*it)->NotifyName.ToString() == "VegetaActiveFrames")
		{
			if (Vegeta->Enemy != NULL)
			{
				switch (Vegeta->Enemy->GetState())
				{
					case EVegetaState::DefendIdle:
						break;
					case EVegetaState::Block:
						break;
					case EVegetaState::Reversal:
						break;
				}
			}
		}
	}

}
void PunchState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
PunchState::~PunchState()
{
}
