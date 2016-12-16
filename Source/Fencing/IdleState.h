// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
#include "StateFactory.h"
/**
 * 
 */
class FENCING_API IdleState : public VegetaState
{
	friend class StateFactory;

public:
	virtual void Enter();
	virtual void HandleButton1();
	virtual void HandleButton2();
	virtual void Update();
	virtual ~IdleState();
	void SetAnimation(UAnimationAsset *AnimationAsset_);
protected:
	IdleState(class AVegeta *Vegeta_) { SID = EVegetaState::Idle, Vegeta = Vegeta_; }
	static UAnimationAsset *AnimationAsset;
};
