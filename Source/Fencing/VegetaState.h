// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Vegeta.h"
/**
 * 
 */
class FENCING_API VegetaState
{
public:
	//virtual VegetaState() {}
	virtual void Enter() {}
	virtual void HandleInput(int Button) {}
	virtual void Update() {}
	virtual ~VegetaState() {}


	enum class State { Idle, Attack };
	virtual State getSid() { return SID; }
protected:
	class AVegeta *Vegeta;
	State SID;
};
