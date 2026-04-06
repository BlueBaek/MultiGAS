// Fill out your copyright notice in the Description page of Project Settings.


#include "MG/Actors/MGCharacterBase.h"

#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMGCharacterBase::AMGCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	
	FPMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPerson Mesh"));
	FPMesh->SetupAttachment(GetMesh());
	FPMesh->SetOnlyOwnerSee(true);
	FPMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FPMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	FPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPerson Camera"));
	FPCamera->SetupAttachment(FPMesh, FName("head"));
	FPCamera->SetRelativeLocationAndRotation(FVector(-2.8f, 5.89f, 0.0f), FRotator(0.0f, 90.0f, -90.0f));
	FPCamera->bUsePawnControlRotation = true;
	FPCamera->bEnableFirstPersonFieldOfView = true;
	FPCamera->bEnableFirstPersonScale = true;
	FPCamera->FirstPersonFieldOfView = 70.0f;
	FPCamera->FirstPersonScale = 0.6f;

	// configure the character comps
	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::WorldSpaceRepresentation;

	GetCapsuleComponent()->SetCapsuleSize(34.0f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->AirControl = 0.5f;
}

// Called when the game starts or when spawned
void AMGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
/*
void AMGCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
*/

void AMGCharacterBase::MoveInput(const FInputActionValue& Value)
{
	/*
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (GetController())
	{
		AddMovementInput(GetActorRightVector(), MovementVector.X);
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	}
	*/
}

void AMGCharacterBase::LookInput(const FInputActionValue& Value)
{
}

void AMGCharacterBase::DoJumpStart()
{
}

void AMGCharacterBase::DoJumpEnd()
{
}
