// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"

#include "State/VegetaState.h"
#include "State/IdleState.h"


// Sets default values
AVegeta::AVegeta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	SetActorLocation(FVector::ZeroVector);
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> VegetaMeshObject(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin")); // wherein /Game/ is the Content folder.
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> VegetaAnimationObject(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP'")); // wherein /Game/ is the Content folder.
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
	GetCharacterMovement()->AddInputVector(MovementVector, true);
	MovementVector = FVector::ZeroVector;
}

void AVegeta::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction("Attack", IE_Pressed, this, &AVegeta::BeginAttack);
	InputComponent->BindAction("Attack", IE_Released, this, &AVegeta::EndAttack);
	InputComponent->BindAxis("MoveY", this, &AVegeta::MoveY);
}

void AVegeta::BeginAttack()
{
	Jump();
}

void AVegeta::EndAttack()
{
	MovementVector -= FVector(0.0f, 100.0f, 0.0f);
}

void AVegeta::MoveY(float AxisValue)
{
	MovementVector += FVector(0.0f, AxisValue, 0.0f);
}

bool AVegeta::IsIdle()
{
	return (VegetaState->getSid() == VegetaState::State::Idle);
}