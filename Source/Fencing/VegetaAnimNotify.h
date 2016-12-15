// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimNotifies/AnimNotify.h"
#include "VegetaAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class FENCING_API UVegetaAnimNotify : public UAnimNotify
{
	GENERATED_BODY()

		UVegetaAnimNotify(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
};

UCLASS()
class FENCING_API UVegetaAnimEnd : public UAnimNotify
{
	GENERATED_BODY()

		UVegetaAnimEnd(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
};

UCLASS()
class FENCING_API UVegetaAnimBegin : public UAnimNotify
{
	GENERATED_BODY()

		UVegetaAnimBegin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
};
