// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"

#include "State/VegetaState.h"
#include "State/IdleState.h"


// Sets default values
AVegeta::AVegeta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	SetActorLocation(FVector::ZeroVector);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> VegetaMeshObject(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin")); // wherein /Game/ is the Content folder.
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> VegetaAnimationObject(TEXT("/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP")); // wherein /Game/ is the Content folder.
	GetMesh()->SetSkeletalMesh(VegetaMeshObject.Object);
	GetMesh()->SetAnimInstanceClass(VegetaAnimationObject.Object->GeneratedClass);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetMesh());
	SpringArm->SetRelativeLocation(FVector::ZeroVector);

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetupAttachment(SpringArm);
	OurCamera->SetRelativeLocation(FVector::ZeroVector);
	OurCamera->Activate();

	VegetaState = new IdleState();
}

// Called when the game starts or when spawned
void AVegeta::BeginPlay()
{
	Super::BeginPlay();
	VegetaState->Update(this);
	GetMesh()->Play(0);
}

// Called every frame
void AVegeta::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AVegeta::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction("Attack", IE_Pressed, this, &AVegeta::BeginAttack);
	/*
	InputComponent->BindAxis("MoveZ", this, &APlayerCannon::MoveZ);
	InputComponent->BindAxis("MoveY", this, &APlayerCannon::MoveY);
	InputComponent->BindAxis("Zoom", this, &APlayerCannon::Zoom);
	InputComponent->BindAxis("BarrelRotationRoll", this, &APlayerCannon::MoveTurretRoll);
	InputComponent->BindAxis("BarrelRotationYaw", this, &APlayerCannon::MoveTurretYaw);
	InputComponent->BindAction("CannonFire", IE_Pressed, this, &APlayerCannon::BeginFire);
	InputComponent->BindAction("CannonFire", IE_Released, this, &APlayerCannon::EndFire);
	InputComponent->BindAction("ToggleCamera", IE_Pressed, this, &APlayerCannon::ToggleCamera);
	*/
}

void AVegeta::BeginAttack()
{
	//MovementComponent->Velocity = FVector(0.0f, 0.0f, 10000.0f);
	//MovementComponent->AddImpulse(FVector(0.0f, 100.0f, 0.0f), true);
	//MovementComponent->AddInputVector(FVector(0.0f, 0.0f, 100000.0f));
}

bool AVegeta::IsIdle()
{
	return (VegetaState->getSid() == VegetaState::State::Idle);
}

