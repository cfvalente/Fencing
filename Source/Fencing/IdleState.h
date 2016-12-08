// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
/**
 * 
 */
class FENCING_API IdleState : public VegetaState
{
public:
	virtual void Enter();
	virtual void HandleInput(int Button);
	virtual void Update();
	virtual ~IdleState();

protected:
	IdleState(class AVegeta *Vegeta_) { SID = State::Idle, Vegeta = Vegeta_; }
	static UAnimationAsset *AnimationAsset;
};
