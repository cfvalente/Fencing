// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "VegetaState.h"
#include "Vegeta.generated.h"



UCLASS()
class FENCING_API AVegeta : public ACharacter
{
	GENERATED_BODY()


private:
	class VegetaState *VegetaState;
	FVector MovementVector = FVector::ZeroVector;


	void HandleButton1();
	void HandleButton2();
	void MoveY(float AxisValue);
public:	
	// Sets default values for this actor's properties
	AVegeta();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Called to bind functionality to input */
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void SetState(class VegetaState *VegetaState_);

	UPROPERTY(BlueprintReadWrite, EditAnywhere) class UCameraComponent* OurCamera;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) class USpringArmComponent* SpringArm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere) class AVegeta* Enemy;

	/** Variaveis com valor padrao */
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, category="Defaults") float SpeedMultiplier;

	/** Funcoes usadas para controlar maquina de estados da animacao */
	UFUNCTION(BlueprintCallable, BlueprintPure, category = "State") EVegetaState GetState();
	UFUNCTION(BlueprintCallable, BlueprintPure, category = "State") bool IsStateActive();
};
