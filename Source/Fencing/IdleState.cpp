// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "IdleState.h"

UAnimationAsset *IdleState::AnimationAsset = NULL;

void IdleState::Enter()
{
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void IdleState::HandleInput(int Button)
{
	switch (Button)
	{
	case 0:
		break;
	case 1:
		break;
	default:
		break;
	}
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