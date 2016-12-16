// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
#include "StateFactory.h"
/**
*
*/
class FENCING_API FeintState : public VegetaState
{
	friend class StateFactory;

public:
	virtual void Enter();
	virtual void Update();
	virtual ~FeintState();
	void SetAnimation(UAnimationAsset *AnimationAsset_);
protected:
	FeintState(class AVegeta *Vegeta_) { SID = EVegetaState::Feint, Vegeta = Vegeta_; Active = false; }
	static UAnimationAsset *AnimationAsset;
};
