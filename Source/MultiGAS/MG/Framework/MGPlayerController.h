// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MULTIGAS_API AMGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMGPlayerController();
	
protected:
	virtual void BeginPlay() override;
	
	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MG|Input")
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;
	
	// 캐릭터를 조종하기 시작할 때 호출 (서버에서 실행)
	virtual void OnPossess(APawn* PossessedPawn) override;
};
