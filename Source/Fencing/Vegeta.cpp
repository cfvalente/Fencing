// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"


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

	vegeta_mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CannonBarrel"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> vegeta_object(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin")); // wherein /Game/ is the Content folder.
	vegeta_mesh->SetupAttachment(RootComponent);
	vegeta_mesh->SetSkeletalMesh(vegeta_object.Object);

	spring_arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	spring_arm->SetupAttachment(vegeta_mesh);
	spring_arm->SetRelativeLocation(FVector(0.0f, 0.0f, 90.0f));
	spring_arm->SetRelativeRotation(FRotator(-10.0f, 90.0f, 0.0f));

	our_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	our_camera->SetupAttachment(spring_arm);
	our_camera->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	our_camera->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	our_camera->Activate();

	//camera_direction = FVector(0.0f, 0.0f, 0.0f);


}

// Called when the game starts or when spawned
void AVegeta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVegeta::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

