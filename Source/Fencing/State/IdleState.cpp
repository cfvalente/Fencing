// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "IdleState.h"


void IdleState::HandleInput(class UInputComponent *InputComponent)
{

}
void IdleState::Update(class AVegeta *Vegeta)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "Idle Update!");
}
IdleState::~IdleState()
{

}