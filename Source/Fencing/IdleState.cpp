// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "IdleState.h"


void IdleState::Enter()
{
	//Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void IdleState::HandleInput(int Button)
{

}
void IdleState::Update()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "Idle Update!");
}
IdleState::~IdleState()
{

}