// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
#include "StateFactory.h"
/**
 * 
 */
class FENCING_API PunchState : public VegetaState
{
	friend class StateFactory;

public:
	virtual void Enter();
	virtual void Update();
	virtual ~PunchState();
	void SetAnimation(UAnimationAsset *AnimationAsset_);
protected:
	PunchState(class AVegeta *Vegeta_) { SID = EVegetaState::Punch, Vegeta = Vegeta_; }
	static UAnimationAsset *AnimationAsset;
};