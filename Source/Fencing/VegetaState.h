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
	virtual class VegetaState * HandleButton1() { return this; }
	virtual class VegetaState * HandleButton2() { return this; }
	virtual void Update() {}
	virtual ~VegetaState() {}


	enum class State { Idle, Attack };
	virtual State getSid() { return SID; }
protected:
	class AVegeta *Vegeta;
	State SID;
};
