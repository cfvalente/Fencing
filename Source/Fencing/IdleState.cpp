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
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "Idle Update!");
}
void IdleState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
IdleState::~IdleState()
{

}