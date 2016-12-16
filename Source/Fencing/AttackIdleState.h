// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
#include "StateFactory.h"
/**
 * 
 */
class FENCING_API AttackIdleState : public VegetaState
{
	friend class StateFactory;

public:
	virtual void Enter();
	virtual void HandleButton1();
	virtual void HandleButton2();
	virtual void Update();
	virtual ~AttackIdleState();
	void SetAnimation(UAnimationAsset *AnimationAsset_);
protected:
	AttackIdleState(class AVegeta *Vegeta_) { SID = EVegetaState::AttackIdle, Vegeta = Vegeta_; Active = false; }
	static UAnimationAsset *AnimationAsset;
};