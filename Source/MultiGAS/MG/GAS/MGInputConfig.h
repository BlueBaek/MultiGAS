// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "MGInputConfig.generated.h"

class UInputAction;

USTRUCT(BlueprintType)
struct FMGInputAction
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<const UInputAction> InputAction = nullptr;
	
	UPROPERTY(EditDefaultsOnly, Meta=(Categories="MG|Input"))
	FGameplayTag InputTag;
};

UCLASS()
class MULTIGAS_API UMGInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// 태그로 입력 액션을 찾는 헬퍼 함수
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = true) const;
	
	// 에디터에서 입력 액션들을 리스트 형태로 등록함
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (TitleProperty = "InputTag"))
	TArray<FMGInputAction> AbilityInputActions;
};
