// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MGCharacterBase.generated.h"

struct FInputActionValue;

UCLASS()
class MULTIGAS_API AMGCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMGCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MG|Components")
	TObjectPtr<USkeletalMeshComponent> FPMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MG|Components")
	TObjectPtr<class UCameraComponent> FPCamera;

	/** Called from Input Actions for movement input */
	void MoveInput(const FInputActionValue& Value);

	/** Called from Input Actions for looking input */
	void LookInput(const FInputActionValue& Value);
	
	void DoJumpStart();

	void DoJumpEnd();
};
