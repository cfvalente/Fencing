// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Animation/AnimInstance.h"
#include "Animation/AnimNotifies/AnimNotify.h"
/**
 * 
 */
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EVegetaState : uint8
{
	Idle 		UMETA(DisplayName = "Idle"),
	AttackIdle 	UMETA(DisplayName = "AttackIdle"),
	Punch		UMETA(DisplayName = "Punch"),
	Feint 		UMETA(DisplayName = "Feint"),
	Jump 		UMETA(DisplayName = "Jump"),
	Move		UMETA(DisplayName = "Move"),
	DefendIdle 	UMETA(DisplayName = "DefendIdle"),
	Block 		UMETA(DisplayName = "Block"),
	Reversal	UMETA(DisplayName = "Reversal")
};


class FENCING_API VegetaState
{
public:
	//virtual VegetaState() {}
	virtual void Enter() {}
	virtual void HandleButton1() {}
	virtual void HandleButton2() {}
	virtual void Update() {}
	virtual ~VegetaState() {}


	virtual EVegetaState getSid() { return SID; }
protected:
	class AVegeta *Vegeta;
	EVegetaState SID;
};
