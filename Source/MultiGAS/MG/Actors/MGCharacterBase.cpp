// Fill out your copyright notice in the Description page of Project Settings.


#include "MG/Actors/MGCharacterBase.h"

#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MG/GAS/MGGameplayTags.h"
#include "MG/GAS/MGInputComponent.h"
#include "MG/GAS/MGInputConfig.h"

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

	// 컨트롤러의 회전 값을 캐릭터(Pawn)가 사용하도록 설정
	bUseControllerRotationYaw = true; // 캐릭터가 좌우로 회전해야 함
	bUseControllerRotationRoll = false;

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

void AMGCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	checkf(LocalPlayer, TEXT("[MGCharacterBase] LocalPlayer Error!"));

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	checkf(Subsystem, TEXT("[MGCharacterBase] No Subsystem!"));

	Subsystem->AddMappingContext(InputConfigDA->DefaultMappingContext, 0);

	UMGInputComponent* InputComp = CastChecked<UMGInputComponent>(PlayerInputComponent);

	InputComp->BindNativeinputAction(InputConfigDA, MGGameplayTags::MG_Input_Move, ETriggerEvent::Triggered, this,
	                                 &AMGCharacterBase::MoveInput);
	InputComp->BindNativeinputAction(InputConfigDA, MGGameplayTags::MG_Input_Look, ETriggerEvent::Triggered, this,
	                                 &AMGCharacterBase::LookInput);
	InputComp->BindNativeinputAction(InputConfigDA, MGGameplayTags::MG_Input_Jump, ETriggerEvent::Started, this,
	                                 &AMGCharacterBase::DoJumpStart);
	InputComp->BindNativeinputAction(InputConfigDA, MGGameplayTags::MG_Input_Jump, ETriggerEvent::Completed, this,
	                                 &AMGCharacterBase::DoJumpEnd);
}

void AMGCharacterBase::MoveInput(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
	if (GetController())
	{
		AddMovementInput(MovementRotation.RotateVector(FVector::RightVector), MovementVector.X);
		AddMovementInput(MovementRotation.RotateVector(FVector::ForwardVector), MovementVector.Y);
	}
}

void AMGCharacterBase::LookInput(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (GetController())
	{
		AddControllerYawInput(-LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AMGCharacterBase::DoJumpStart()
{
	Jump();
}

void AMGCharacterBase::DoJumpEnd()
{
	StopJumping();
}
