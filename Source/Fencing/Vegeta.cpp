// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"

#include "State/VegetaState.h"
#include "State/IdleState.h"
class VegetaState *teste;

// Sets default values
AVegeta::AVegeta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	SetActorLocation(FVector::ZeroVector);



	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent->SetRelativeLocation(FVector::ZeroVector);

	VegetaMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VegetaMesh"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> VegetaMeshObject(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin")); // wherein /Game/ is the Content folder.
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> VegetaAnimationObject(TEXT("/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP")); // wherein /Game/ is the Content folder.
	VegetaMesh->SetupAttachment(RootComponent);
	VegetaMesh->SetAnimInstanceClass(VegetaAnimationObject.Object->GeneratedClass);
	VegetaMesh->SetSkeletalMesh(VegetaMeshObject.Object);
	VegetaMesh->SetRelativeLocation(FVector::ZeroVector);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(VegetaMesh);
	SpringArm->SetRelativeLocation(FVector::ZeroVector);

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetupAttachment(SpringArm);
	OurCamera->SetRelativeLocation(FVector::ZeroVector);
	OurCamera->Activate();

	teste = new IdleState();
	/*
	auto StateMachine = CreateDefaultSubobject<UStateMachineComponent>(TEXT("StateMachine"));
	if (StateMachine->IsValidLowLevel()) {
		StateMachine->AddState(0, FName("Idle"));
		StateMachine->AddState(1, FName("Stand"));
		StateMachine->AddState(2, FName("Run"));
		StateMachine->AddState(3, FName("Push"));
	};
	*/


}

// Called when the game starts or when spawned
void AVegeta::BeginPlay()
{
	Super::BeginPlay();
	teste->Update(this);
	VegetaMesh->Play(0);
}

// Called every frame
void AVegeta::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool AVegeta::IsIdle()
{
	return (teste->getSid() == VegetaState::State::Idle);
}

