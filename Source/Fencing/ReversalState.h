// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
#include "StateFactory.h"
/**
*
*/
class FENCING_API ReversalState : public VegetaState
{
	friend class StateFactory;

public:
	virtual void Enter();
	virtual void Update();
	virtual ~ReversalState();
	void SetAnimation(UAnimationAsset *AnimationAsset_);
	virtual bool IsActive();
protected:
	ReversalState(class AVegeta *Vegeta_) { SID = EVegetaState::Reversal, Vegeta = Vegeta_; }
	static UAnimationAsset *AnimationAsset;
};