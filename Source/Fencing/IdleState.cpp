// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "IdleState.h"


UAnimationAsset *IdleState::AnimationAsset = NULL;

void IdleState::Enter()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Idle");
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void IdleState::HandleButton1()
{
	/* Exemplo do que fazer - Talvez mudar para jump na versao final */

	VegetaState *NewState;
	NewState = StateFactory::CreateAttackIdle(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
}

void IdleState::HandleButton2()
{
	/* Exemplo do que fazer - Talvez mudar para jump na versao final */
	//////////////////////////////////
	VegetaState *NewState;
	NewState = StateFactory::CreateAttackIdle(Vegeta);
	Vegeta->GetMesh()->Stop();
	NewState->Enter();
	Vegeta->SetState(NewState);
}

void IdleState::Update()
{
	if (Vegeta->Enemy != NULL)
	{
		VegetaState *NewState;
		NewState = StateFactory::CreateAttackIdle(Vegeta);
		Vegeta->GetMesh()->Stop();
		NewState->Enter();
		Vegeta->SetState(NewState);
	}
	// Detecta o Notify State
	/*for (auto it = Vegeta->GetMesh()->AnimScriptInstance->ActiveAnimNotifyState.CreateIterator(); it; ++it )
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, *it->NotifyName.ToString());
	}*/
	// Detecta os Notify existentes(?)
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, (*it)->Notify->GetName());
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, (*it)->NotifyName.ToString());
	}

}
void IdleState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
IdleState::~IdleState()
{
}