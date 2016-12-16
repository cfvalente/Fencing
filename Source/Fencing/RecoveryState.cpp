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
			NewState = StateFactory::CreateAttackIdle(Vegeta);
			Vegeta->GetMesh()->Stop();
			NewState->Enter();
			Vegeta->SetState(NewState);
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
