// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
/**
 * 
 */
class FENCING_API IdleState : public VegetaState
{
public:
	IdleState() { SID = State::Idle; }
	virtual void HandleInput(class UInputComponent *InputComponent);
	virtual void Update(class AVegeta *Vegeta);
	virtual ~IdleState();
};
