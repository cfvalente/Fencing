// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
#include "StateFactory.h"
/**
*
*/
class FENCING_API RecoveryState : public VegetaState
{
	friend class StateFactory;

public:
	virtual void Enter();
	virtual void Update();
	virtual ~RecoveryState();
	void SetAnimation(UAnimationAsset *AnimationAsset_);
protected:
	RecoveryState(class AVegeta *Vegeta_) { SID = EVegetaState::Recovery, Vegeta = Vegeta_; }
	static UAnimationAsset *AnimationAsset;
};
