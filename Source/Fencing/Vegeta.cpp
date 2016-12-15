// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"

#include "VegetaState.h"
#include "StateFactory.h"

bool Punching = false;

// Sets default values
AVegeta::AVegeta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	SetActorLocation(FVector::ZeroVector);
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> VegetaMeshObject(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin")); // wherein /Game/ is the Content folder.
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> VegetaAnimationObject(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP'")); // wherein /Game/ is the Content folder.

	static ConstructorHelpers::FObjectFinder<UAnimationAsset> VegetaAnimationIdleObject(TEXT("AnimSequence'/Game/Mannequin/Animations/ThirdPersonIdle.ThirdPersonIdle'")); // wherein /Game/ is the Content folder.
	StateFactory::SetIdleAnimation(VegetaAnimationIdleObject.Object);

	GetMesh()->SetSkeletalMesh(VegetaMeshObject.Object);
	//GetMesh()->SetAnimInstanceClass(VegetaAnimationObject.Object->GeneratedClass);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetMesh());
	SpringArm->SetRelativeLocation(FVector::ZeroVector);

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetupAttachment(SpringArm);
	OurCamera->SetRelativeLocation(FVector::ZeroVector);
	OurCamera->Activate();

	VegetaState = StateFactory::CreateIdle(this);
}

// Called when the game starts or when spawned
void AVegeta::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.AddPrerequisite(GetMesh(), GetMesh()->PrimaryComponentTick);
	VegetaState->Enter();
	//GetMesh()->Play(0);
}

// Called every frame
void AVegeta::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	GetCharacterMovement()->AddInputVector(MovementVector, true);
	VegetaState->Update();
	MovementVector = FVector::ZeroVector;
}

void AVegeta::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction("Button1", IE_Pressed, this, &AVegeta::HandleButton1);
	InputComponent->BindAction("Button2", IE_Pressed, this, &AVegeta::HandleButton2);
	//InputComponent->BindAction("Attack", IE_Released, this, &AVegeta::EndAttack);
	InputComponent->BindAxis("MoveY", this, &AVegeta::MoveY);
}

void AVegeta::HandleButton1()
{
	VegetaState = VegetaState->HandleButton1();
}

void AVegeta::HandleButton2()
{

}

void AVegeta::MoveY(float AxisValue)
{
	MovementVector += FVector(0.0f, AxisValue, 0.0f);
}

bool AVegeta::IsIdle()
{
	return (VegetaState->getSid() == VegetaState::State::Idle);
}

bool AVegeta::IsPunching()
{
	bool aux = Punching;
	Punching = false;
	return aux;
}