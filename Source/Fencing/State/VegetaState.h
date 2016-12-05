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
};
