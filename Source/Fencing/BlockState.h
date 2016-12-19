// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VegetaState.h"
#include "StateFactory.h"
/**
*
*/
class FENCING_API BlockState : public VegetaState
{
	friend class StateFactory;

public:
	virtual void Enter();
	virtual void Update();
	virtual ~BlockState();
	void SetAnimation(UAnimationAsset *AnimationAsset_);
protected:
	BlockState(class AVegeta *Vegeta_) { SID = EVegetaState::Block, Vegeta = Vegeta_, Block = false; }
	static UAnimationAsset *AnimationAsset;
	bool Block;
};
