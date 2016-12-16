// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "FeintState.h"


UAnimationAsset *FeintState::AnimationAsset = NULL;

void FeintState::Enter()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Feint");
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}

void FeintState::Update()
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
void FeintState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
FeintState::~FeintState()
{
}