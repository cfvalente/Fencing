// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Vegeta.generated.h"

UCLASS()
class FENCING_API AVegeta : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVegeta();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//UCameraComponent* OurCamera;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) UCameraComponent* our_camera;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) USpringArmComponent* spring_arm;


	/** Sekeletal Mesh Comp, Set In BP Default Properties */
	UPROPERTY(BlueprintReadWrite, EditAnywhere) USkeletalMeshComponent* vegeta_mesh;
	
};