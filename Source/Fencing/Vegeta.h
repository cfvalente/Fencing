// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Vegeta.generated.h"

UCLASS()
class FENCING_API AVegeta : public ACharacter
{
	GENERATED_BODY()
private:
	class VegetaState *VegetaState;

	void BeginAttack();
public:	
	// Sets default values for this actor's properties
	AVegeta();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Called to bind functionality to input */
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere) class UCameraComponent* OurCamera;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) class USpringArmComponent* SpringArm;

	/** Sekeletal Mesh Comp, Set In BP Default Properties */
	//UPROPERTY(BlueprintReadWrite, EditAnywhere) class USkeletalMeshComponent* VegetaMesh;

	/** Collision component */
	//UPROPERTY(BlueprintReadWrite, EditAnywhere) class USphereComponent* CollisionComponent;

	/** Movement Comp */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true")) class UPawnMovementComponent* MovementComponent;

	/** Funcoes usadas para controlar maquina de estados da animacao */
	UFUNCTION(BlueprintCallable, BlueprintPure, category="State") bool IsIdle();
};
