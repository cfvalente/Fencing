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
	virtual void HandleInput(class UInputComponent *InputComponent) {}
	virtual void Update(class AVegeta *Vegeta) {}
	virtual ~VegetaState() {}


	enum class State { Idle, Attack };
	virtual State getSid() { return SID; }
protected:
	State SID;
};
