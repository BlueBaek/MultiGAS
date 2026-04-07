// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MGCharacterBase.generated.h"

class UMGInputConfig;
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
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	// 입력 설정을 위한 데이터 에셋 (에디터에서 할당)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MG|Input")
	TObjectPtr<UMGInputConfig> InputConfigDA;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MG|Components")
	TObjectPtr<USkeletalMeshComponent> FPMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MG|Components")
	TObjectPtr<class UCameraComponent> FPCamera;
	
	/** 입력 핸들러 함수 */
	void MoveInput(const FInputActionValue& Value);
	void LookInput(const FInputActionValue& Value);
	void DoJumpStart();
	void DoJumpEnd();
};
